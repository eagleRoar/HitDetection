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
#include <u8g2_port.h>

u8 oled_task[1024];
struct rt_thread oled_thread;

#define OLED_SPI_PIN_CLK                   21  // PA5
#define OLED_SPI_PIN_MOSI                  23  // PA7
#define OLED_SPI_PIN_RES                   16  // PA2
#define OLED_SPI_PIN_DC                    15  // PA1
#define OLED_SPI_PIN_CS                    14  // PA0

void ssd1306_12864_4wire_sw_spi_example(void)
{
    u8g2_t u8g2;

    // Initialization
    u8g2_Setup_ssd1306_128x64_noname_f( &u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_rt_gpio_and_delay);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_SPI_CLOCK, OLED_SPI_PIN_CLK);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_SPI_DATA, OLED_SPI_PIN_MOSI);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_CS, OLED_SPI_PIN_CS);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_DC, OLED_SPI_PIN_DC);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_RESET, OLED_SPI_PIN_RES);

    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);

    // Draw Graphics
    /* full buffer example, setup procedure ends in _f */
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_baby_tf);
    u8g2_DrawStr(&u8g2, 1, 18, "U8g2 on RT-Thread");
    u8g2_SendBuffer(&u8g2);

    u8g2_SetFont(&u8g2, u8g2_font_unifont_t_symbols);
    u8g2_DrawGlyph(&u8g2, 112, 56, 0x2603 );
    u8g2_SendBuffer(&u8g2);
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



