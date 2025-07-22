#include "user_auth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用户数据文件路径
#define CUSTOMER_DATA_FILE "customer_users.txt"
#define MERCHANT_DATA_FILE "merchant_users.txt"

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

    // 将新用户添加到文件
    FILE * file = fopen(get_data_file(type), "a");
    if(!file) return false;

    fprintf(file, "%s:%s\n", username, password);
    fclose(file);

    return true;
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

        // 解析用户名和密码（格式：username:password）
        if(sscanf(line, "%31[^:]:%31s", stored_username, stored_password) == 2) {
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
