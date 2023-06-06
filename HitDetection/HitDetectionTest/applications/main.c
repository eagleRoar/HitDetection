/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-05-29     RT-Thread    first version
 */

#include "GlobalConfig.h"
#include "Gpio.h"
#include "SDCard.h"
#include "Oled.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>


int main(void)
{
    int count = 1;

    GpioInit();
    SDCardInit();
    OledInit();

    while (count++)
    {
        LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
