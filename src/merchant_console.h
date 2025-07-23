#ifndef MERCHANT_CONSOLE_H
#define MERCHANT_CONSOLE_H

#include <stdbool.h>

/**
 * @brief 初始化商家控制台
 * @return true 成功, false 失败
 */
bool merchant_console_init(void);

/**
 * @brief 处理控制台命令（在定时器中调用）
 */
void merchant_console_process(void);

/**
 * @brief 停止商家控制台
 */
void merchant_console_stop(void);

/**
 * @brief 显示帮助信息
 */
void show_console_help(void);

#endif // MERCHANT_CONSOLE_H
