/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-06-02     Administrator       the first version
 */
#include "GlobalConfig.h"
#include "typedef.h"
#include "Gpio.h"

void GpioInit(void)
{
    //LCD
    rt_pin_mode(LCD_CS, PIN_MODE_OUTPUT);
    rt_pin_mode(LCD_RST, PIN_MODE_OUTPUT);
    rt_pin_mode(LCD_A0, PIN_MODE_OUTPUT);
    rt_pin_mode(LCD_BK, PIN_MODE_OUTPUT);
    rt_pin_mode(CTL_LCD, PIN_MODE_OUTPUT);
    rt_pin_write(CTL_LCD, PIN_HIGH);        //开启LCD电源       //Jutin debug
    rt_pin_write(CTL_LCD, PIN_HIGH);        //开启LCD背光灯
}