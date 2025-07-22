#include "src/user_auth.h"
#include <stdio.h>

int main()
{
    // 初始化认证系统
    if(!user_auth_init()) {
        printf("认证系统初始化失败\n");
        return -1;
    }

    // 创建一些测试账户
    printf("创建测试账户...\n");

    // 创建顾客测试账户
    if(user_register("customer1", "123456", USER_TYPE_CUSTOMER)) {
        printf("顾客账户 customer1 创建成功\n");
    } else {
        printf("顾客账户 customer1 已存在\n");
    }

    if(user_register("customer2", "password", USER_TYPE_CUSTOMER)) {
        printf("顾客账户 customer2 创建成功\n");
    } else {
        printf("顾客账户 customer2 已存在\n");
    }

    // 创建商家测试账户
    if(user_register("merchant1", "admin123", USER_TYPE_MERCHANT)) {
        printf("商家账户 merchant1 创建成功\n");
    } else {
        printf("商家账户 merchant1 已存在\n");
    }

    if(user_register("admin", "admin", USER_TYPE_MERCHANT)) {
        printf("商家账户 admin 创建成功\n");
    } else {
        printf("商家账户 admin 已存在\n");
    }

    // 测试登录功能
    printf("\n测试登录功能...\n");

    auth_result_t result = user_login("customer1", "123456", USER_TYPE_CUSTOMER);
    printf("顾客登录测试 (customer1/123456): %s\n", auth_result_to_string(result));

    result = user_login("customer1", "wrong", USER_TYPE_CUSTOMER);
    printf("顾客登录测试 (customer1/wrong): %s\n", auth_result_to_string(result));

    result = user_login("notexist", "123456", USER_TYPE_CUSTOMER);
    printf("顾客登录测试 (notexist/123456): %s\n", auth_result_to_string(result));

    result = user_login("admin", "admin", USER_TYPE_MERCHANT);
    printf("商家登录测试 (admin/admin): %s\n", auth_result_to_string(result));

    printf("\n测试完成！\n");
    printf("你现在可以使用以下账户登录系统：\n");
    printf("顾客账户：customer1/123456, customer2/password\n");
    printf("商家账户：merchant1/admin123, admin/admin\n");

    return 0;
}
