#include "src/user_auth.h"
#include <stdio.h>

int main()
{
    printf("=== 余额管理系统测试 ===\n\n");

    // 初始化用户认证系统
    user_auth_init();

    // 测试用户余额查询
    double balance = user_get_balance("123456", USER_TYPE_CUSTOMER);
    printf("123456 当前余额: %.2f\n", balance);

    // 测试余额充值
    printf("为 123456 充值 50.00...\n");
    if(user_add_balance("123456", USER_TYPE_CUSTOMER, 50.00)) {
        printf("充值成功！\n");
        balance = user_get_balance("123456", USER_TYPE_CUSTOMER);
        printf("123456 充值后余额: %.2f\n", balance);
    } else {
        printf("充值失败！\n");
    }

    // 测试余额扣除
    printf("从 123456 扣除 20.00...\n");
    if(user_deduct_balance("123456", USER_TYPE_CUSTOMER, 20.00)) {
        printf("扣费成功！\n");
        balance = user_get_balance("123456", USER_TYPE_CUSTOMER);
        printf("123456 扣费后余额: %.2f\n", balance);
    } else {
        printf("扣费失败！余额不足或用户不存在\n");
    }

    // 测试设置余额
    printf("设置 123456 余额为 100.00...\n");
    if(user_set_balance("123456", USER_TYPE_CUSTOMER, 100.00)) {
        printf("设置成功！\n");
        balance = user_get_balance("123456", USER_TYPE_CUSTOMER);
        printf("123456 设置后余额: %.2f\n", balance);
    } else {
        printf("设置失败！\n");
    }

    // 测试当前用户功能
    printf("\n=== 当前用户功能测试 ===\n");

    // 模拟用户登录
    if(set_current_user("123456", USER_TYPE_CUSTOMER)) {
        printf("123456 登录成功！\n");

        const user_info_t * current = get_current_user();
        if(current) {
            printf("当前用户: %s (类型: %s)\n", current->username,
                   current->type == USER_TYPE_CUSTOMER ? "客户" : "商户");
            printf("当前用户余额: %.2f\n", current->balance);
        }
    } else {
        printf("用户登录失败！\n");
    }

    // 测试用户登出
    user_logout();
    printf("用户已登出\n");

    const user_info_t * current = get_current_user();
    if(current == NULL) {
        printf("确认没有当前登录用户\n");
    }

    return 0;
}
