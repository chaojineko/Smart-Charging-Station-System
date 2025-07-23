#include "merchant_console.h"
#include "user_auth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/select.h>

static bool console_active = false;
static char input_buffer[256];
static int buffer_pos = 0;

// 设置终端为非阻塞模式
static void set_terminal_nonblocking(bool enable)
{
    static struct termios old_termios;
    static bool saved = false;

    if(enable) {
        if(!saved) {
            tcgetattr(STDIN_FILENO, &old_termios);
            saved = true;
        }

        struct termios new_termios = old_termios;
        new_termios.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

        int flags = fcntl(STDIN_FILENO, F_GETFL);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    } else {
        if(saved) {
            tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
        }

        int flags = fcntl(STDIN_FILENO, F_GETFL);
        fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
    }
}

// 显示帮助信息
void show_console_help(void)
{
    printf("\n=== 商家控制台命令 ===\n");
    printf("help                    - 显示此帮助信息\n");
    printf("list                    - 查看所有客户信息\n");
    printf("balance <用户名>        - 查看指定用户余额\n");
    printf("set <用户名> <金额>     - 设置指定用户余额\n");
    printf("add <用户名> <金额>     - 为指定用户充值\n");
    printf("exit                    - 退出控制台\n");
    printf("===================\n");
    printf("请输入命令: ");
    fflush(stdout);
}

// 处理list命令
static void handle_list_command(void)
{
    printf("\n=== 客户列表 ===\n");
    user_info_t users[100];
    int count = get_all_users(USER_TYPE_CUSTOMER, users, 100);

    if(count == 0) {
        printf("没有找到客户记录\n");
    } else {
        printf("%-15s %-15s %10s\n", "用户名", "密码", "余额");
        printf("----------------------------------------------\n");
        for(int i = 0; i < count; i++) {
            printf("%-15s %-15s %10.2f元\n", users[i].username, users[i].password, users[i].balance);
        }
    }
    printf("=============\n");
}

// 处理balance命令
static void handle_balance_command(const char * username)
{
    if(!username || strlen(username) == 0) {
        printf("错误: 请指定用户名\n");
        return;
    }

    double balance = user_get_balance(username, USER_TYPE_CUSTOMER);
    if(balance < 0) {
        printf("错误: 用户 '%s' 不存在\n", username);
    } else {
        printf("用户 '%s' 余额: %.2f元\n", username, balance);
    }
}

// 处理set命令
static void handle_set_command(const char * username, const char * amount_str)
{
    if(!username || strlen(username) == 0) {
        printf("错误: 请指定用户名\n");
        return;
    }

    if(!amount_str || strlen(amount_str) == 0) {
        printf("错误: 请指定金额\n");
        return;
    }

    double amount = atof(amount_str);
    if(amount < 0) {
        printf("错误: 金额不能为负数\n");
        return;
    }

    if(user_set_balance(username, USER_TYPE_CUSTOMER, amount)) {
        printf("成功设置用户 '%s' 余额为 %.2f元\n", username, amount);
    } else {
        printf("错误: 用户 '%s' 不存在或操作失败\n", username);
    }
}

// 处理add命令
static void handle_add_command(const char * username, const char * amount_str)
{
    if(!username || strlen(username) == 0) {
        printf("错误: 请指定用户名\n");
        return;
    }

    if(!amount_str || strlen(amount_str) == 0) {
        printf("错误: 请指定充值金额\n");
        return;
    }

    double amount = atof(amount_str);
    if(amount <= 0) {
        printf("错误: 充值金额必须大于0\n");
        return;
    }

    double old_balance = user_get_balance(username, USER_TYPE_CUSTOMER);
    if(old_balance < 0) {
        printf("错误: 用户 '%s' 不存在\n", username);
        return;
    }

    if(user_add_balance(username, USER_TYPE_CUSTOMER, amount)) {
        double new_balance = user_get_balance(username, USER_TYPE_CUSTOMER);
        printf("成功为用户 '%s' 充值 %.2f元，余额从 %.2f元 变为 %.2f元\n", username, amount, old_balance, new_balance);
    } else {
        printf("错误: 充值操作失败\n");
    }
}

// 处理命令
static void handle_command(const char * command)
{
    char cmd[256];
    strncpy(cmd, command, sizeof(cmd) - 1);
    cmd[sizeof(cmd) - 1] = '\0';

    // 分割命令参数
    char * token = strtok(cmd, " ");
    if(!token) return;

    if(strcmp(token, "help") == 0) {
        show_console_help();
    } else if(strcmp(token, "list") == 0) {
        handle_list_command();
        printf("请输入命令: ");
        fflush(stdout);
    } else if(strcmp(token, "balance") == 0) {
        char * username = strtok(NULL, " ");
        handle_balance_command(username);
        printf("请输入命令: ");
        fflush(stdout);
    } else if(strcmp(token, "set") == 0) {
        char * username = strtok(NULL, " ");
        char * amount   = strtok(NULL, " ");
        handle_set_command(username, amount);
        printf("请输入命令: ");
        fflush(stdout);
    } else if(strcmp(token, "add") == 0) {
        char * username = strtok(NULL, " ");
        char * amount   = strtok(NULL, " ");
        handle_add_command(username, amount);
        printf("请输入命令: ");
        fflush(stdout);
    } else if(strcmp(token, "exit") == 0) {
        printf("退出商家控制台\n");
        merchant_console_stop();
    } else {
        printf("未知命令: %s\n", token);
        printf("输入 'help' 查看可用命令\n");
        printf("请输入命令: ");
        fflush(stdout);
    }
}

// 初始化商家控制台
bool merchant_console_init(void)
{
    if(console_active) return true;

    console_active = true;
    buffer_pos     = 0;
    memset(input_buffer, 0, sizeof(input_buffer));

    set_terminal_nonblocking(true);

    printf("\n=== 商家控制台启动 ===\n");
    show_console_help();

    return true;
}

// 处理控制台输入（在定时器中调用）
void merchant_console_process(void)
{
    if(!console_active) return;

    char c;
    while(read(STDIN_FILENO, &c, 1) > 0) {
        if(c == '\n' || c == '\r') {
            // 处理命令
            if(buffer_pos > 0) {
                input_buffer[buffer_pos] = '\0';
                handle_command(input_buffer);
                buffer_pos = 0;
                memset(input_buffer, 0, sizeof(input_buffer));
            } else {
                printf("请输入命令: ");
                fflush(stdout);
            }
        } else if(c == '\b' || c == 127) { // 退格键
            if(buffer_pos > 0) {
                buffer_pos--;
                input_buffer[buffer_pos] = '\0';
                printf("\b \b");
                fflush(stdout);
            }
        } else if(c >= 32 && c <= 126) { // 可打印字符
            if(buffer_pos < sizeof(input_buffer) - 1) {
                input_buffer[buffer_pos] = c;
                buffer_pos++;
                printf("%c", c);
                fflush(stdout);
            }
        }
    }
}

// 停止商家控制台
void merchant_console_stop(void)
{
    if(!console_active) return;

    console_active = false;
    set_terminal_nonblocking(false);

    printf("\n=== 商家控制台已关闭 ===\n");
}
