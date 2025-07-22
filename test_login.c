#include <stdio.h>
#include <string.h>
#include "src/user_auth.h"

// 简单的包装函数，返回布尔值并设置当前用户
bool simple_login(const char * username, const char * password, user_type_t type)
{
    auth_result_t result = user_login(username, password, type);
    if(result == AUTH_SUCCESS) {
        set_current_user(username, type);
        return true;
    }
    return false;
}

int main()
{
    printf("=== 用户认证和余额测试 ===\n\n");

    // 测试客户登录
    printf("测试客户登录 (123456/123456):\n");
    if(simple_login("123456", "123456", USER_TYPE_CUSTOMER)) {
        printf("✓ 登录成功\n");
        printf("当前用户: %s, 余额: %.2f\n", current_user.username,
               user_get_balance(current_user.username, current_user.type));
    } else {
        printf("✗ 登录失败\n");
    }

    printf("\n");

    // 测试商户登录
    printf("测试商户登录 (666666/666666):\n");
    if(simple_login("666666", "666666", USER_TYPE_MERCHANT)) {
        printf("✓ 登录成功\n");
        printf("当前用户: %s, 余额: %.2f\n", current_user.username,
               user_get_balance(current_user.username, current_user.type));
    } else {
        printf("✗ 登录失败\n");
    }

    printf("\n");

    // 测试错误密码
    printf("测试错误密码 (123456/wrong_password):\n");
    if(simple_login("123456", "wrong_password", USER_TYPE_CUSTOMER)) {
        printf("✓ 登录成功\n");
    } else {
        printf("✗ 登录失败（预期结果）\n");
    }

    printf("\n");

    // 测试余额操作
    if(strlen(current_user.username) > 0) {
        printf("测试余额操作:\n");
        float original_balance = user_get_balance(current_user.username, current_user.type);
        printf("原始余额: %.2f\n", original_balance);

        user_set_balance(current_user.username, current_user.type, original_balance + 50.0);
        printf("添加50.0后余额: %.2f\n", user_get_balance(current_user.username, current_user.type));

        user_set_balance(current_user.username, current_user.type, original_balance);
        printf("恢复原始余额: %.2f\n", user_get_balance(current_user.username, current_user.type));
    }

    return 0;
}
