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

u8 sdcard_task[1024];
struct rt_thread sdcard_thread;

#define FLASH_MEMORY_NAME       "norflash0"


/**
 * 总线上挂载设备 spi10
 * @return
 */
int bsp_spi_attach_init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    rt_err_t ret = rt_hw_spi_device_attach("spi1", "spi10", GPIOA, GPIO_PIN_4);// spi10 表示挂载在 spi3 总线上的 0 号设备,PA4是片选，这一步就可以将从设备挂在到总线中。
    if(ret <0)
    {
        LOG_E("flash attach spi1 failed");
        return -RT_ERROR;
    }

    rt_sfud_flash_probe(FLASH_MEMORY_NAME, "spi10");// 注册nor flash

    return RT_EOK;
}

void SDCardEntry(void* parameter)
{

}

void SDCardInit(void)
{
    //1.先将spi挂载在总线上
    bsp_spi_attach_init();

    //2.将sd挂载(sd实际上是使用spi传输数据)
    if (0 != dfs_mount(FLASH_MEMORY_NAME, "/", "elm", 0, 0))
    {
        LedTest(1, SET_PIN_LOW);//Justin debug
        //flash 格式化
        if(0 == dfs_mkfs("elm", FLASH_MEMORY_NAME))
        {
            LedTest(2, SET_PIN_LOW);//Justin debug
            dfs_mount(FLASH_MEMORY_NAME, "/", "elm", 0, 0);
        }
    }
    else
    {

    }

    if(rt_device_find(FLASH_MEMORY_NAME))
    {
        rt_kprintf("find sdcard ok\r\n");
    }
    else
    {
        rt_kprintf("find sdcard fail\r\n");
    }

    if(RT_EOK != rt_thread_init(&sdcard_thread,
            "sdcard_task", SDCardEntry, RT_NULL, sdcard_task, sizeof(sdcard_task), 20, 10))
    {
        LOG_E("uart thread fail");
    }
}
