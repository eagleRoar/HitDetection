/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-06-02     Administrator       the first version
 */
#ifndef APPLICATIONS_INCLUDES_GPIO_H_
#define APPLICATIONS_INCLUDES_GPIO_H_

#include "typedef.h"

#define     SET_PIN_HIGH        1
#define     SET_PIN_LOW         0

//OLED
#define     LCD_CS          GET_PIN(C, 9)
#define     LCD_RST         GET_PIN(D, 0)
#define     LCD_A0          GET_PIN(D, 2)
#define     LCD_BK          GET_PIN(D, 4)
#define     CTL_LCD         GET_PIN(C, 6)

//LED
#define     LED1            GET_PIN(B, 0)
#define     LED2            GET_PIN(B, 1)
#define     LED3            GET_PIN(B, 2)
#define     LED4            GET_PIN(B, 11)
#define     LED5            GET_PIN(B, 12)

//SD
#define     SD_CTL_PIN      GET_PIN(A, 9)

//SPI
#define     SPI1_NSS        GET_PIN(A, 4)

void GpioInit(void);
void LedTest(u8 index, u8 state);

#endif /* APPLICATIONS_INCLUDES_GPIO_H_ */
