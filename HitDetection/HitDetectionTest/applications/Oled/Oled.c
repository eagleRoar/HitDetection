/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-06-05     Administrator       the first version
 */
#include "GlobalConfig.h"
#include "typedef.h"
#include "Oled.h"
#include "ascii_fonts.h"
#include "ST7567.h"

u8 oled_task[1024];
struct rt_thread oled_thread;

void clear_screen(void)
{
  ST7567_Fill(0);
//  ST7567_UpdateScreen();
}

void st7567Init(void)
{
    ST7567_Init();
    rt_thread_mdelay(100);
    clear_screen();
}

void OledEntry(void* parameter)
{

}

void OledInit(void)
{
    if(RT_EOK != rt_thread_init(&oled_thread,
            "oled_task", OledEntry, RT_NULL, oled_task, sizeof(oled_task), 22, 10))
    {
        LOG_E("uart thread fail");
    }
}



