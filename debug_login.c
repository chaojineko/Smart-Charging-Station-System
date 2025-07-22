#include <stdio.h>
#include <string.h>
#include "src/user_auth.h"

int main()
{
    printf("=== 调试用户认证 ===\n\n");

    // 直接测试 user_login 函数的返回值
    printf("测试客户登录 (123456/123456):\n");
    auth_result_t result = user_login("123456", "123456", USER_TYPE_CUSTOMER);
    printf("返回结果: %d (%s)\n", result, auth_result_to_string(result));

    printf("\n测试商户登录 (666666/666666):\n");
    result = user_login("666666", "666666", USER_TYPE_MERCHANT);
    printf("返回结果: %d (%s)\n", result, auth_result_to_string(result));

    printf("\n测试错误密码 (123456/wrong):\n");
    result = user_login("123456", "wrong", USER_TYPE_CUSTOMER);
    printf("返回结果: %d (%s)\n", result, auth_result_to_string(result));

    // 检查文件内容
    printf("\n=== 文件内容检查 ===\n");
    printf("customer_users.txt内容:\n");
    FILE * f = fopen("customer_users.txt", "r");
    if(f) {
        char line[128];
        while(fgets(line, sizeof(line), f)) {
            printf("'%s'", line); // 显示完整行包括换行符
        }
        fclose(f);
    } else {
        printf("无法打开文件\n");
    }

    return 0;
}
