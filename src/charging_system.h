#ifndef CHARGING_SYSTEM_H
#define CHARGING_SYSTEM_H

#include <stdbool.h>
#include <time.h>

// 充电模式枚举
typedef enum {
    CHARGING_MODE_FAST = 0, // 快充
    CHARGING_MODE_SLOW = 1  // 慢充
} charging_mode_t;

// 充电状态枚举
typedef enum {
    CHARGING_STATE_IDLE     = 0, // 空闲
    CHARGING_STATE_READY    = 1, // 准备充电
    CHARGING_STATE_CHARGING = 2, // 正在充电
    CHARGING_STATE_FINISHED = 3, // 充电完成
    CHARGING_STATE_ERROR    = 4  // 错误状态
} charging_state_t;

// 充电数据结构
typedef struct
{
    charging_mode_t mode;   // 充电模式
    charging_state_t state; // 充电状态

    // 充电参数
    double power;   // 功率 (kW)
    double voltage; // 电压 (V)
    double current; // 电流 (A)

    // 充电进度
    double energy_charged;   // 已充入电量 (kWh)
    double progress_percent; // 充电进度百分比

    // 时间和费用
    time_t start_time;   // 开始时间
    time_t current_time; // 当前时间
    double total_cost;   // 总费用

    // 用户信息
    char username[32]; // 当前用户名
} charging_data_t;

// 全局充电数据
extern charging_data_t g_charging_data;

// 函数声明

/**
 * @brief 初始化充电系统
 */
void charging_system_init(void);

/**
 * @brief 开始充电
 * @param mode 充电模式
 * @param username 用户名
 * @return true 成功, false 失败
 */
bool start_charging(charging_mode_t mode, const char * username);

/**
 * @brief 停止充电
 * @return true 成功, false 失败
 */
bool stop_charging(void);

/**
 * @brief 更新充电数据（模拟充电过程）
 */
void update_charging_data(void);

/**
 * @brief 获取充电模式字符串
 * @param mode 充电模式
 * @return 模式字符串
 */
const char * get_charging_mode_string(charging_mode_t mode);

/**
 * @brief 获取格式化的充电时长字符串
 * @param buffer 输出缓冲区
 * @param buffer_size 缓冲区大小
 */
void get_charging_duration_string(char * buffer, size_t buffer_size);

/**
 * @brief 计算充电费用
 * @return 当前费用
 */
double calculate_charging_cost(void);

/**
 * @brief 获取当前充电数据
 * @return 充电数据指针
 */
const charging_data_t * get_charging_data(void);

#endif // CHARGING_SYSTEM_H
