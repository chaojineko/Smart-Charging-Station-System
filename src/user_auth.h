#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <stdbool.h>

// 账号类型枚举
typedef enum {
    USER_TYPE_CUSTOMER = 0, // 顾客
    USER_TYPE_MERCHANT = 1  // 商家
} user_type_t;

// 验证结果枚举
typedef enum {
    AUTH_SUCCESS = 0,    // 验证成功
    AUTH_USER_NOT_FOUND, // 用户不存在
    AUTH_WRONG_PASSWORD, // 密码错误
    AUTH_FILE_ERROR      // 文件操作错误
} auth_result_t;

// 用户结构体
typedef struct
{
    char username[32];
    char password[32];
    user_type_t type;
    double balance; // 用户余额
} user_info_t;

// 全局当前用户信息
extern user_info_t current_user;
extern bool is_user_logged_in;

// 函数声明
/**
 * @brief 初始化用户认证系统
 * @return true 成功, false 失败
 */
bool user_auth_init(void);

/**
 * @brief 用户登录验证
 * @param username 用户名
 * @param password 密码
 * @param type 用户类型
 * @return auth_result_t 验证结果
 */
auth_result_t user_login(const char * username, const char * password, user_type_t type);

/**
 * @brief 用户注册
 * @param username 用户名
 * @param password 密码
 * @param type 用户类型
 * @return true 成功, false 失败
 */
bool user_register(const char * username, const char * password, user_type_t type);

/**
 * @brief 设置当前登录用户
 * @param username 用户名
 * @param type 用户类型
 * @return true 成功, false 失败
 */
bool set_current_user(const char * username, user_type_t type);

/**
 * @brief 获取当前用户信息
 * @return 当前用户信息指针，如果未登录返回NULL
 */
const user_info_t * get_current_user(void);

/**
 * @brief 用户登出
 */
void user_logout(void);

/**
 * @brief 刷新当前用户余额（从文件重新读取）
 * @return true 成功, false 失败
 */
bool refresh_current_user_balance(void);

/**
 * @brief 检查用户是否存在
 * @param username 用户名
 * @param type 用户类型
 * @return true 存在, false 不存在
 */
bool user_exists(const char * username, user_type_t type);

/**
 * @brief 获取认证结果的描述信息
 * @param result 认证结果
 * @return 描述字符串
 */
const char * auth_result_to_string(auth_result_t result);

/**
 * @brief 获取用户余额
 * @param username 用户名
 * @param type 用户类型
 * @return 用户余额，如果用户不存在返回-1.0
 */
double user_get_balance(const char * username, user_type_t type);

/**
 * @brief 设置用户余额
 * @param username 用户名
 * @param type 用户类型
 * @param balance 新余额
 * @return true 成功, false 失败
 */
bool user_set_balance(const char * username, user_type_t type, double balance);

/**
 * @brief 为用户充值
 * @param username 用户名
 * @param type 用户类型
 * @param amount 充值金额
 * @return true 成功, false 失败
 */
bool user_add_balance(const char * username, user_type_t type, double amount);

/**
 * @brief 扣除用户余额
 * @param username 用户名
 * @param type 用户类型
 * @param amount 扣除金额
 * @return true 成功, false 失败（余额不足或用户不存在）
 */
bool user_deduct_balance(const char * username, user_type_t type, double amount);

/**
 * @brief 获取所有用户信息（商家管理功能）
 * @param type 用户类型
 * @param users 用户信息数组
 * @param max_users 最大用户数量
 * @return 实际获取的用户数量
 */
int get_all_users(user_type_t type, user_info_t users[], int max_users);

#endif // USER_AUTH_H
