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

#define     PIN_HIGH        1
#define     PIN_LOW         0

#define     LCD_CS          GET_PIN(C, 9)
#define     LCD_RST         GET_PIN(D, 0)
#define     LCD_A0          GET_PIN(D, 2)
#define     LCD_BK          GET_PIN(D, 4)
#define     CTL_LCD         GET_PIN(C, 6)

void GpioInit(void);

#endif /* APPLICATIONS_INCLUDES_GPIO_H_ */
