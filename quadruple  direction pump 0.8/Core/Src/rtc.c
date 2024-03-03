//
// Created by SmallRaw on 2020/3/26.
// ds1302.c
//

#include "rtc.h"

uint8_t DEC2BCD(uint8_t dec) {
    const uint8_t tens = dec / 10;
    const uint8_t ones = dec % 10;
    return (tens << 4u) | ones;
}

uint8_t BCD2DEC(uint8_t bcd) {
    return (10 * ((bcd & 0xF0) >> 4) + (bcd & 0x0F));
}

void write_data_set() {
    HAL_GPIO_WritePin(DS1302_PIN_DAT_PORT, DS1302_PIN_DAT, GPIO_PIN_SET);
}

void write_data_reset() {
    HAL_GPIO_WritePin(DS1302_PIN_DAT_PORT, DS1302_PIN_DAT, GPIO_PIN_RESET);
}

/**
 * 读取 dat 针脚的数据
 * @return dat 针脚的数据
 */
uint8_t read_data_pin() {
    if (HAL_GPIO_ReadPin(DS1302_PIN_DAT_PORT, DS1302_PIN_DAT) == GPIO_PIN_RESET) {
        return 0;
    } else {
        return 1;
    }
}

void write_clk_set() {
    HAL_GPIO_WritePin(DS1302_PIN_CLK_PORT, DS1302_PIN_CLK, GPIO_PIN_SET);
}

void write_clk_reset() {
    HAL_GPIO_WritePin(DS1302_PIN_CLK_PORT, DS1302_PIN_CLK, GPIO_PIN_RESET);
}

void write_rst_set() {
    HAL_GPIO_WritePin(DS1302_PIN_RST_PORT, DS1302_PIN_RST, GPIO_PIN_SET);
}

void write_rst_reset() {
    HAL_GPIO_WritePin(DS1302_PIN_RST_PORT, DS1302_PIN_RST, GPIO_PIN_RESET);
}

/**
 * 修改 dat 针脚为写入模式
 */
static void dat_pin_write_mode(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Pin = DS1302_PIN_DAT;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DS1302_PIN_DAT_PORT, &GPIO_InitStructure);

    write_data_reset();
}

/**
 * 修改 dat 针脚为读取模式
 */
static void dat_pin_read_mode(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Pin = DS1302_PIN_DAT;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DS1302_PIN_DAT_PORT, &GPIO_InitStructure);

    write_data_reset();
}

/**
 * 初始化针脚
 * @param GPIOx 针脚组
 * @param GPIO_Pin 具体针脚名称
 */
void ds1302_pin_init(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

/**
 * 初始化 DS1302 相关针脚
 */
void DS1302_Init() {
    /*Configure GPIO pins : PBPin PBPin PBPin */
    ds1302_pin_init(DS1302_PIN_CLK_PORT, DS1302_PIN_CLK);
    ds1302_pin_init(DS1302_PIN_DAT_PORT, DS1302_PIN_DAT);
    ds1302_pin_init(DS1302_PIN_RST_PORT, DS1302_PIN_RST);

    write_clk_reset();
    write_data_reset();
    write_rst_reset();

//    uint8_t sec = ds1302_single_read(DS1302_SEC_ADD);
//    if ((sec & 0x80) != 0) {
//        ds1302_single_write(DS1302_CONTROL_ADD, 0x00); // 解除保护
//        // todo 初始化时间
//    }
}

/**
 * 向 DS1302 写入数据
 * @param data 需要写入的数据
 */
void ds1302_byte_write(uint8_t data) {
    uint8_t detect;
    for (detect = 0x01; detect != 0; detect <<= 1) {
        if ((data & detect) != 0) { // 对 dat 端口写入数据
            write_data_set();
        } else {
            write_data_reset();
        }

        write_clk_set(); // 拉高 clk 时钟
        write_clk_reset(); // 拉低 clk 时钟
    }
    write_data_set();
}

/**
 * 从 DS1302 读取数据
 * @return 读取出的数据
 */
uint8_t ds1302_byte_read() {
    uint8_t data = 0;
    uint8_t detect;
    for (detect = 0x01; detect != 0; detect <<= 1) {
        if (read_data_pin() != 0) { // 读取 dat 端口数据
            data |= detect;
        }

        write_clk_set(); // 拉高 clk 时钟
        write_clk_reset(); // 拉低 clk 时钟
    }
    return data;
}

/**
 * 向 DS1302 写入一次数据
 * @param addr 寄存器地址
 * @param data 需要写入的数据
 */
void ds1302_single_write(uint8_t addr, uint8_t data) {
    write_rst_reset();
    write_clk_reset();

    write_rst_set(); // 拉高 rst 可以开始使用 DS1302

    dat_pin_write_mode(); // 切换 dat 端口为输出模式

    ds1302_byte_write(addr); // 告诉 DS1302 要写入的寄存器地址
    ds1302_byte_write(data); // 告诉 DS1302 要写入的内容

    write_rst_reset();
}

/**
 * 从 DS1302 读取一次数据
 * @param addr 寄存器地址
 * @return data 需要读取的数据
 */
uint8_t ds1302_single_read(uint8_t addr) {
    addr = addr | 0x01; // 变更寄存器地址

    write_rst_reset();
    write_clk_reset();

    write_rst_set();// 拉高 rst 可以开始使用 DS1302

    dat_pin_write_mode();// 切换 dat 端口为输出模式

    ds1302_byte_write(addr);// 告诉 DS1302 要读取的寄存器地址

    dat_pin_read_mode();// 切换 dat 端口为输入模式

    uint8_t data = ds1302_byte_read();// 从 DS1302 读取数据
    write_rst_reset();

    return data;
}

/**
 * 校验并转换 timeStruct
 * @param timeStruct
 * @return
 */
Time_Struct convert_time_struct(Time_Struct *timeStruct) {
    if (timeStruct->sec < 0 || timeStruct->sec > 59) {
        timeStruct->sec = 0;
    }
    if (timeStruct->min < 0 || timeStruct->min > 59) {
        timeStruct->min = 0;
    }
    if (timeStruct->isHourClock24) {
        if (timeStruct->hour < 0 || timeStruct->hour > 23) {
            timeStruct->hour = 0;
        }
    } else {
        if (timeStruct->hour < 1 || timeStruct->hour > 12) {
            timeStruct->hour = 1;
        }
    }
    if (timeStruct->date < 1 || timeStruct->date > 31) {
        timeStruct->date = 1;
    }
    if (timeStruct->day < 1 || timeStruct->day > 7) {
        timeStruct->day = 1;
    }
    if (timeStruct->month < 1 || timeStruct->month > 12) {
        timeStruct->month = 1;
    }
    if (timeStruct->year < 2000 || timeStruct->year > 2099) {
        timeStruct->year = 00;
    } else {
        timeStruct->year -= 2000;
    }

    uint8_t hour = 0;
    if (timeStruct->isHourClock24) {
        hour |= DEC2BCD(timeStruct->hour) & 0x3F;
    } else {
        hour |= 0x80;
        if (!timeStruct->isAm) {
            hour |= 0x20;
        }
        hour |= DEC2BCD(timeStruct->hour) & 0x1F;
    }
    timeStruct->hour = hour;

    return *timeStruct;
}

void DS1302_SetTime_Struct(Time_Struct *timeStruct) {
    Time_Struct time = convert_time_struct(timeStruct);

    ds1302_single_write(DS1302_CONTROL_ADD, 0x00); // 解除 DS1302 写入保护

    ds1302_single_write(DS1302_YEAR_ADD, DEC2BCD(time.year));
    ds1302_single_write(DS1302_MONTH_ADD, DEC2BCD(time.month));
    ds1302_single_write(DS1302_DAY_ADD, DEC2BCD(time.day));
    ds1302_single_write(DS1302_DATE_ADD, DEC2BCD(time.date));
    ds1302_single_write(DS1302_HR_ADD, time.hour);
    ds1302_single_write(DS1302_MIN_ADD, DEC2BCD(time.min));
    ds1302_single_write(DS1302_SEC_ADD, DEC2BCD(time.sec & 0x7f));

    ds1302_single_write(DS1302_CONTROL_ADD, 0x80); // 设置 DS1302 写入保护
}

Time_Struct DS1302_ReadTime_Struct() {
    Time_Struct timeStruct;
    uint8_t tmp;

    tmp = ds1302_single_read(DS1302_YEAR_ADD);
    timeStruct.year = BCD2DEC(tmp) + 2000;
    tmp = ds1302_single_read(DS1302_MONTH_ADD);
    timeStruct.month = BCD2DEC(tmp);
    tmp = ds1302_single_read(DS1302_DAY_ADD);
    timeStruct.day = BCD2DEC(tmp);
    tmp = ds1302_single_read(DS1302_DATE_ADD);
    timeStruct.date = BCD2DEC(tmp);
    uint8_t hour = ds1302_single_read(DS1302_HR_ADD);
    tmp = ds1302_single_read(DS1302_MIN_ADD);
    timeStruct.min = BCD2DEC(tmp);
    tmp = ds1302_single_read(DS1302_SEC_ADD) & 0x7f;
    timeStruct.sec = BCD2DEC(tmp);
    timeStruct.isAm = FALSE;

    if (hour & 0x80) {
        timeStruct.isHourClock24 = FALSE;
        if (hour & 0x20) {
            timeStruct.isAm = FALSE;
        } else {
            timeStruct.isAm = TRUE;
        }
        timeStruct.hour = BCD2DEC(hour & 0x1F);
    } else {
        timeStruct.isHourClock24 = TRUE;
        timeStruct.hour = BCD2DEC((hour & 0x1F) | (hour & 0x20));
    }

    return timeStruct;
}

/**
 * 使用突击模式对 DS1302 写入时间
 * @param data 时间数组
 */
void ds1302_burst_write(uint8_t *data) {
    write_rst_reset();
    write_clk_reset();

    write_rst_set(); // 拉高 rst 可以读取 DS1302

    dat_pin_write_mode(); // 切换 dat 端口为输出模式

    ds1302_byte_write(DS1302_CLKBURST_ADD); // 告诉 DS1302 要写入的寄存器地址
    for (int i = 0; i < 8; i++) {
        ds1302_byte_write(data[i]); // 告诉 DS1302 要写入的内容
    }

    write_rst_reset();
}

/**
 * 使用突击模式从 DS1302 读取时间
 * @param data 接收时间的数组 len: 8
 */
void ds1302_burst_read(uint8_t *data) {
    write_rst_reset();
    write_clk_reset();

    write_rst_set();// 拉高 rst 可以读取 DS1302

    dat_pin_write_mode();// 切换 dat 端口为输出模式

    ds1302_byte_write(DS1302_CLKBURST_ADD | 0x01);// 告诉 DS1302 要读取的寄存器地址

    dat_pin_read_mode();// 切换 dat 端口为输入模式
    for (int i = 0; i < 8; i++) {
        data[i] = ds1302_byte_read();// 从 DS1302 读取数据
    }
    write_rst_reset();
}

void DS1302_SetTime_Struct_Burst(Time_Struct *timeStruct) {
    Time_Struct time = convert_time_struct(timeStruct);

    uint8_t times[] = {
            DEC2BCD(time.sec & 0x7f),
            DEC2BCD(time.min),
            time.hour,
            DEC2BCD(time.date),
            DEC2BCD(time.month),
            DEC2BCD(time.day),
            DEC2BCD(time.year),
            0x80
    };
    ds1302_single_write(DS1302_CONTROL_ADD, 0x00); // 解除 DS1302 写入保护
    ds1302_burst_write(times);
    ds1302_single_write(DS1302_CONTROL_ADD, 0x80); // 设置 DS1302 写入保护
}

Time_Struct DS1302_ReadTime_Struct_Burst() {
    uint8_t times[8];

    ds1302_burst_read(times);

    Time_Struct timeStruct;
    timeStruct.year = BCD2DEC(times[6]) + 2000;
    timeStruct.month = BCD2DEC(times[4]);
    timeStruct.day = BCD2DEC(times[5]);
    timeStruct.date = BCD2DEC(times[3]);
    uint8_t hour = times[2];
    timeStruct.min = BCD2DEC(times[1]);
    timeStruct.sec = BCD2DEC(times[0] & 0x7f);
    timeStruct.isAm = FALSE;

    if (hour & 0x80) {
        timeStruct.isHourClock24 = FALSE;
        if (hour & 0x20) {
            timeStruct.isAm = FALSE;
        } else {
            timeStruct.isAm = TRUE;
        }
        timeStruct.hour = BCD2DEC(hour & 0x1F);
    } else {
        timeStruct.isHourClock24 = TRUE;
        timeStruct.hour = BCD2DEC((hour & 0x1F) | (hour & 0x20));
    }

    return timeStruct;
}
