#include "user_auth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用户数据文件路径
#define CUSTOMER_DATA_FILE "customer_users.txt"
#define MERCHANT_DATA_FILE "merchant_users.txt"

// 全局当前用户信息
user_info_t current_user;
bool is_user_logged_in = false;

// 函数声明
static bool write_user_info(const user_info_t * user_info);
static bool read_user_info(const char * username, user_type_t type, user_info_t * user_info);

// 获取对应用户类型的数据文件名
static const char * get_data_file(user_type_t type)
{
    return (type == USER_TYPE_CUSTOMER) ? CUSTOMER_DATA_FILE : MERCHANT_DATA_FILE;
}

// 初始化用户认证系统
bool user_auth_init(void)
{
    // 确保数据文件存在，如果不存在则创建
    FILE * customer_file = fopen(CUSTOMER_DATA_FILE, "a");
    FILE * merchant_file = fopen(MERCHANT_DATA_FILE, "a");

    if(!customer_file || !merchant_file) {
        if(customer_file) fclose(customer_file);
        if(merchant_file) fclose(merchant_file);
        return false;
    }

    fclose(customer_file);
    fclose(merchant_file);
    return true;
}

// 检查用户是否存在
bool user_exists(const char * username, user_type_t type)
{
    if(!username) return false;

    FILE * file = fopen(get_data_file(type), "r");
    if(!file) return false;

    char line[128];
    char stored_username[32];

    while(fgets(line, sizeof(line), file)) {
        // 解析用户名（格式：username:password）
        if(sscanf(line, "%31[^:]:", stored_username) == 1) {
            if(strcmp(username, stored_username) == 0) {
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}

// 用户注册
bool user_register(const char * username, const char * password, user_type_t type)
{
    if(!username || !password) return false;
    if(strlen(username) == 0 || strlen(password) == 0) return false;
    if(strlen(username) >= 32 || strlen(password) >= 32) return false;

    // 检查用户是否已存在
    if(user_exists(username, type)) {
        return false; // 用户已存在
    }

    // 创建新用户信息（默认余额100.00）
    user_info_t new_user;
    strncpy(new_user.username, username, 31);
    new_user.username[31] = '\0';
    strncpy(new_user.password, password, 31);
    new_user.password[31] = '\0';
    new_user.type         = type;
    new_user.balance      = 100.00; // 默认余额

    return write_user_info(&new_user);
}

// 用户登录验证
auth_result_t user_login(const char * username, const char * password, user_type_t type)
{
    if(!username || !password) return AUTH_FILE_ERROR;

    FILE * file = fopen(get_data_file(type), "r");
    if(!file) return AUTH_FILE_ERROR;

    char line[128];
    char stored_username[32];
    char stored_password[32];

    while(fgets(line, sizeof(line), file)) {
        // 去除换行符
        line[strcspn(line, "\n")] = 0;

        // 尝试解析新格式：username:password:balance
        double stored_balance;
        if(sscanf(line, "%31[^:]:%31[^:]:%lf", stored_username, stored_password, &stored_balance) == 3) {
            if(strcmp(username, stored_username) == 0) {
                fclose(file);
                if(strcmp(password, stored_password) == 0) {
                    return AUTH_SUCCESS;
                } else {
                    return AUTH_WRONG_PASSWORD;
                }
            }
        }
        // 兼容旧格式：username:password
        else if(sscanf(line, "%31[^:]:%31s", stored_username, stored_password) == 2) {
            if(strcmp(username, stored_username) == 0) {
                fclose(file);
                if(strcmp(password, stored_password) == 0) {
                    return AUTH_SUCCESS;
                } else {
                    return AUTH_WRONG_PASSWORD;
                }
            }
        }
    }

    fclose(file);
    return AUTH_USER_NOT_FOUND;
}

// 获取认证结果的描述信息
const char * auth_result_to_string(auth_result_t result)
{
    switch(result) {
        case AUTH_SUCCESS: return "登录成功";
        case AUTH_USER_NOT_FOUND: return "用户不存在";
        case AUTH_WRONG_PASSWORD: return "密码错误";
        case AUTH_FILE_ERROR: return "系统错误";
        default: return "未知错误";
    }
}

// 读取用户信息（包括余额）
static bool read_user_info(const char * username, user_type_t type, user_info_t * user_info)
{
    if(!username || !user_info) return false;

    FILE * file = fopen(get_data_file(type), "r");
    if(!file) return false;

    char line[256];
    char stored_username[32];
    char stored_password[32];
    double stored_balance;

    while(fgets(line, sizeof(line), file)) {
        // 去除换行符
        line[strcspn(line, "\n")] = 0;

        // 尝试解析新格式：username:password:balance
        if(sscanf(line, "%31[^:]:%31[^:]:%lf", stored_username, stored_password, &stored_balance) == 3) {
            if(strcmp(username, stored_username) == 0) {
                strncpy(user_info->username, stored_username, 31);
                user_info->username[31] = '\0';
                strncpy(user_info->password, stored_password, 31);
                user_info->password[31] = '\0';
                user_info->type         = type;
                user_info->balance      = stored_balance;
                fclose(file);
                return true;
            }
        }
        // 兼容旧格式：username:password（默认余额100.00）
        else if(sscanf(line, "%31[^:]:%31s", stored_username, stored_password) == 2) {
            if(strcmp(username, stored_username) == 0) {
                strncpy(user_info->username, stored_username, 31);
                user_info->username[31] = '\0';
                strncpy(user_info->password, stored_password, 31);
                user_info->password[31] = '\0';
                user_info->type         = type;
                user_info->balance      = 100.00; // 默认余额
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}

// 写入用户信息（包括余额）
static bool write_user_info(const user_info_t * user_info)
{
    if(!user_info) return false;

    const char * filename = get_data_file(user_info->type);
    FILE * file           = fopen(filename, "r");
    FILE * temp_file      = fopen("temp_users.txt", "w");

    if(!temp_file) {
        if(file) fclose(file);
        return false;
    }

    bool user_found = false;

    if(file) {
        char line[256];
        char stored_username[32];
        char stored_password[32];
        double stored_balance;

        while(fgets(line, sizeof(line), file)) {
            // 去除换行符
            line[strcspn(line, "\n")] = 0;

            // 解析现有记录
            if(sscanf(line, "%31[^:]:%31[^:]:%lf", stored_username, stored_password, &stored_balance) == 3) {
                if(strcmp(user_info->username, stored_username) == 0) {
                    // 更新找到的用户
                    fprintf(temp_file, "%s:%s:%.2f\n", user_info->username, user_info->password, user_info->balance);
                    user_found = true;
                } else {
                    // 保持其他用户不变
                    fprintf(temp_file, "%s:%s:%.2f\n", stored_username, stored_password, stored_balance);
                }
            }
            // 兼容旧格式，自动升级为新格式
            else if(sscanf(line, "%31[^:]:%31s", stored_username, stored_password) == 2) {
                if(strcmp(user_info->username, stored_username) == 0) {
                    // 更新找到的用户
                    fprintf(temp_file, "%s:%s:%.2f\n", user_info->username, user_info->password, user_info->balance);
                    user_found = true;
                } else {
                    // 升级其他用户格式（默认余额100.00）
                    fprintf(temp_file, "%s:%s:%.2f\n", stored_username, stored_password, 100.00);
                }
            }
        }
        fclose(file);
    }

    // 如果是新用户，添加到末尾
    if(!user_found) {
        fprintf(temp_file, "%s:%s:%.2f\n", user_info->username, user_info->password, user_info->balance);
    }

    fclose(temp_file);

    // 替换原文件
    remove(filename);
    rename("temp_users.txt", filename);

    return true;
}

// 获取用户余额
double user_get_balance(const char * username, user_type_t type)
{
    user_info_t user_info;
    if(read_user_info(username, type, &user_info)) {
        return user_info.balance;
    }
    return -1.0; // 用户不存在
}

// 设置用户余额
bool user_set_balance(const char * username, user_type_t type, double balance)
{
    user_info_t user_info;
    if(read_user_info(username, type, &user_info)) {
        user_info.balance = balance;
        return write_user_info(&user_info);
    }
    return false; // 用户不存在
}

// 为用户充值
bool user_add_balance(const char * username, user_type_t type, double amount)
{
    if(amount <= 0) return false;

    user_info_t user_info;
    if(read_user_info(username, type, &user_info)) {
        user_info.balance += amount;
        return write_user_info(&user_info);
    }
    return false; // 用户不存在
}

// 扣除用户余额
bool user_deduct_balance(const char * username, user_type_t type, double amount)
{
    if(amount <= 0) return false;

    user_info_t user_info;
    if(read_user_info(username, type, &user_info)) {
        if(user_info.balance >= amount) {
            user_info.balance -= amount;
            return write_user_info(&user_info);
        }
    }
    return false; // 用户不存在或余额不足
}

// 设置当前登录用户
bool set_current_user(const char * username, user_type_t type)
{
    if(read_user_info(username, type, &current_user)) {
        is_user_logged_in = true;
        return true;
    }
    is_user_logged_in = false;
    return false;
}

// 获取当前用户信息
const user_info_t * get_current_user(void)
{
    return is_user_logged_in ? &current_user : NULL;
}

// 用户登出
void user_logout(void)
{
    memset(&current_user, 0, sizeof(current_user));
    is_user_logged_in = false;
}

// 刷新当前用户余额（从文件重新读取）
bool refresh_current_user_balance(void)
{
    if(!is_user_logged_in) return false;

    user_info_t updated_user;
    if(read_user_info(current_user.username, current_user.type, &updated_user)) {
        current_user.balance = updated_user.balance;
        return true;
    }
    return false;
}
