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
} user_info_t;

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

#endif // USER_AUTH_H
