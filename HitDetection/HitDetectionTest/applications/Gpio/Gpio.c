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
    rt_pin_write(CTL_LCD, SET_PIN_HIGH);        //开启LCD电源       //Jutin debug
    rt_pin_write(LCD_BK, SET_PIN_LOW);        //开启LCD背光灯

    //LED1
    rt_pin_mode(LED1, PIN_MODE_OUTPUT);
    rt_pin_mode(LED2, PIN_MODE_OUTPUT);
    rt_pin_mode(LED3, PIN_MODE_OUTPUT);
    rt_pin_mode(LED4, PIN_MODE_OUTPUT);
    rt_pin_mode(LED5, PIN_MODE_OUTPUT);
    rt_pin_write(LED1, SET_PIN_HIGH);
    rt_pin_write(LED2, SET_PIN_HIGH);
    rt_pin_write(LED3, SET_PIN_HIGH);
    rt_pin_write(LED4, SET_PIN_HIGH);
    rt_pin_write(LED5, SET_PIN_HIGH);

    //SD
    rt_pin_mode(SD_CTL_PIN, PIN_MODE_OUTPUT);

    //SPI
    rt_pin_mode(SPI1_NSS, PIN_MODE_OUTPUT);
}

void LedTest(u8 index, u8 state)
{
    switch(index)
    {

    case 1:
        rt_pin_write(LED1, state);
        break;
    case 2:
        rt_pin_write(LED2, state);
        break;
    case 3:
        rt_pin_write(LED3, state);
        break;
    case 4:
        rt_pin_write(LED4, state);
        break;
    case 5:
        rt_pin_write(LED5, state);
        break;

    default: break;
    }
}
