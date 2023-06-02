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

u8 sdcard_task[1024];
struct rt_thread sdcard_thread;

void SDCardEntry(void* parameter)
{

}

void SDCardInit(void)
{
    //将sd挂载
    if (0 != dfs_mount(SDCARD_MEMORY_NAME, "/", "elm", 0, 0))
    {
        //flash 格式化
        if(0 == dfs_mkfs("elm", SDCARD_MEMORY_NAME))
        {
            dfs_mount(SDCARD_MEMORY_NAME, "/", "elm", 0, 0);
        }
    }
    else
    {
    }

    if(rt_device_find(SDCARD_MEMORY_NAME))
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
