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
#include "SDCard.h"
#include "Gpio.h"
#include "spi_flash_sfud.h"
#include "drv_spi.h"
#include "spi_msd.h"

u8 sdcard_task[1024];
struct rt_thread sdcard_thread;

#define SD_NAME       "sd0"


/**
 * 总线上挂载设备 spi10
 * @return
 */
static int rt_hw_spi_tfcard(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    rt_hw_spi_device_attach("spi1", "spi10", GPIOA, GPIO_PIN_4);// spi10 表示挂载在 spi3 总线上的 0 号设备,PA4是片选，这一步就可以将从设备挂在到总线中。

    return msd_init("sd0", "spi10");
}

INIT_COMPONENT_EXPORT(rt_hw_spi_tfcard);


void SDCardEntry(void* parameter)
{

}

void SDCardInit(void)
{
    //1.先将spi挂载在总线上
//    rt_hw_spi_tfcard();

//    if(RT_NULL != rt_device_find(SD_NAME))
//    {
//        rt_kprintf("find sdcard ok\r\n");
//    }
//    else
//    {
//        rt_kprintf("find sdcard fail\r\n");
//    }
//
//    //2.将sd挂载(sd实际上是使用spi传输数据)
//    if (0 != dfs_mount(SD_NAME, "/", "elm", 0, 0))
//    {
//        //flash 格式化
//        if(0 == dfs_mkfs("elm", SD_NAME))
//        {
//            dfs_mount(SD_NAME, "/", "elm", 0, 0);
//        }
//    }
//    else
//    {
//        LedTest(3, SET_PIN_LOW);//Justin debug
//    }

    if (dfs_mount("sd0", "/", "elm", 0, 0) == 0)
    {
        LOG_I("Filesystem initialized!");
    }
    else
    {
        LOG_E("Failed to initialize filesystem!");
    }

    if(RT_EOK != rt_thread_init(&sdcard_thread,
            "sdcard_task", SDCardEntry, RT_NULL, sdcard_task, sizeof(sdcard_task), 20, 10))
    {
        LOG_E("uart thread fail");
    }
}
