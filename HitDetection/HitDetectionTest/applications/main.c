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
#include "SDCard.h"
#include "Gpio.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

//Justin debug需要注意 sdio是通过spi去读取数据的因此要在spi指定sd0

int main(void)
{
    int count = 1;

    GpioInit();
    SDCardInit();

    while (count++)
    {
        LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
