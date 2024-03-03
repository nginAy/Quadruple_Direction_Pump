//
// Created by SmallRaw on 2020/3/26.
// ds1302.h
//
#ifndef __ds1302_H
#define __ds1302_H

#include "stm32f4xx_hal.h"

//DS1302 寄存器地址定义
#define DS1302_SEC_ADD              0x80    //秒：最高位 CH 是一个时钟停止标志位，如果是 1 表示时钟已经不正常,7位高3位是秒的十位，低4位是秒的个位。
#define DS1302_MIN_ADD              0x82    //分钟：最高位未使用，剩下的7位中高3位是分钟的十位，低4位是分钟的个位。
#define DS1302_HR_ADD               0x84    //小时：bit7 是1的话代表是12小时制，0代表是24小时制；bit6 固定是0，bit5 在12小时制下 0代表的是上午，1代表的是下午，在24小时制下 bit7 和 bit4 一起代表了小时的十位,12 小时下 bit4 代表了小时的十位，低4位代表的是小时的个位。
#define DS1302_DATE_ADD             0x86    //日期：高2位固定是0，bit5 和 bit4 是日期的十位，低4位是日期的个位。
#define DS1302_MONTH_ADD            0x88    //月份：高3位固定是0，bit4 是月的十位，低4位是月的个位。
#define DS1302_DAY_ADD              0x8a    //星期：高5位固定是0，低3位代表了星期。
#define DS1302_YEAR_ADD             0x8c    //年份：高4位代表了年的十位，低4位代表了年的个位。请特别注意，这里的00～99指的是2000年～2099年。
#define DS1302_CONTROL_ADD          0x8e    //保护位：最高位一个写保护位，如果这一位是1，那么是禁止给任何其它寄存器或者那31个字节的 RAM 写数据的。因此在写数据之前，这一位必须先写成0。

#define DS1302_CHARGER_ADD          0x90  //0b10010000
#define DS1302_CLKBURST_ADD         0xbe  //突击模式使用的寄存器

//单片机 IO 端口定义
#define DS1302_PIN_PORT GPIOB
#define DS1302_PIN_CLK GPIO_PIN_9
#define DS1302_PIN_CLK_PORT DS1302_PIN_PORT
#define DS1302_PIN_DAT GPIO_PIN_8
#define DS1302_PIN_DAT_PORT DS1302_PIN_PORT
#define DS1302_PIN_RST GPIO_PIN_5
#define DS1302_PIN_RST_PORT DS1302_PIN_PORT

//定义布尔变量
#define BOOL int
#define TRUE 1
#define FALSE 0

/**
 * year: 2000 - 2099
 * month: 1 - 12
 * date: 1 - 31
 * day: 1 - 7
 * isHourClock24: TRUE / FALSE
 * isAm: TRUE / FALSE ,如果 isHourClock24 为 TRUE 则该参数将失去作用。
 * hour: (isHourClock24 = TRUE: 0 - 23) / (isHourClock24 = FALSE: 1 - 12 , 配合 isAM)
 * min: 00 - 59
 * sec: 00 - 59
 */
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t date;
    uint8_t day;
    BOOL isHourClock24;
    BOOL isAm;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
} Time_Struct;

void DS1302_Init();

/**
 * 设置 DS1302 时间
 * @deprecated 偶尔情况秒数可能会有问题
 * @param timeStruct 时间结构
 */
void DS1302_SetTime_Struct(Time_Struct *timeStruct);

/**
 * 读取 DS1302 时间
 * @deprecated 偶尔情况秒数可能会有问题
 * @param timeStruct 时间结构
 */
Time_Struct DS1302_ReadTime_Struct();

/**
 * 设置 DS1302 时间 [推荐]
 * @param timeStruct 时间结构
 */
void DS1302_SetTime_Struct_Burst(Time_Struct *timeStruct);

/**
 * 读取 DS1302 时间 [推荐]
 * @param timeStruct 时间结构
 */
Time_Struct DS1302_ReadTime_Struct_Burst();

#endif //___ds1302_H
