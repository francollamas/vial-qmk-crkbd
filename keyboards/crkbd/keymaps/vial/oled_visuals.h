/*
 Copyright 2026 Franco

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define OLED_ICON_BASE   '\xE0'
#define OLED_ICON_NAV    '\xE1'
#define OLED_ICON_MOUSE  '\xE2'
#define OLED_ICON_MEDIA  '\xE3'
#define OLED_ICON_NUM    '\xE4'
#define OLED_ICON_SYM    '\xE5'
#define OLED_ICON_FUN    '\xE6'
#define OLED_ICON_BUTTON '\xE7'
#define OLED_ICON_TAP    '\xE8'
#define OLED_ICON_CAPS   '\xE9'
#define OLED_ICON_CTRL   '\xEA'
#define OLED_ICON_ALT    '\xEB'
#define OLED_ICON_GUI    '\xEC'
#define OLED_ICON_SHIFT  '\xED'

#define OLED_ICON_WIDTH              15
#define OLED_ICON_HEIGHT             21
#define OLED_HISTORY_FONT_START      32
#define OLED_HISTORY_FONT_WIDTH      8
#define OLED_HISTORY_FONT_HEIGHT     16
#define OLED_HISTORY_TOP_PADDING     8
#define OLED_HISTORY_LINE_HEIGHT     22
#define OLED_HISTORY_GLYPH_SPACING   12
#define OLED_HISTORY_TEXT_X          0
#define OLED_HISTORY_IDLE_TIMEOUT    5000
#define OLED_HISTORY_LIFE_INTERVAL   250
#define OLED_HISTORY_PIXEL_WIDTH     32
#define OLED_HISTORY_PIXEL_HEIGHT    128
#define OLED_STATUS_CENTER_X         8
#define OLED_STATUS_LEFT_X           0
#define OLED_STATUS_RIGHT_X          17
#define OLED_STATUS_LAYER_Y          0
#define OLED_STATUS_CAPS_Y           42
#define OLED_STATUS_TOP_MODS_Y       84
#define OLED_STATUS_BOTTOM_MODS_Y    105

#include "fonts/spleen-8x16.h"

static const uint16_t PROGMEM oled_large_icons[][OLED_ICON_HEIGHT] = {
    {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0080, 0x01C0, 0x03E0, 0x0000, 0x0808, 0x180C, 0x380E, 0x180C, 0x0808, 0x0000, 0x03E0, 0x01C0, 0x0080, 0x0000, 0x0000, 0x24C9, 0x3529, 0x2DE9, 0x2526, 0x0000},
    {0x0000, 0x007C, 0x00C4, 0x0086, 0x03E2, 0x0492, 0x094B, 0x0949, 0x0889, 0x0BE9, 0x0C18, 0x0808, 0x0808, 0x0410, 0x03E0, 0x0000, 0x36E9, 0x2AA9, 0x2AA9, 0x22EF, 0x0000},
    {0x0000, 0x0000, 0x01F8, 0x0104, 0x0104, 0x0104, 0x0104, 0x0104, 0x0104, 0x071C, 0x0F3C, 0x0618, 0x0000, 0x0000, 0x0000, 0x0000, 0x36EE, 0x2A89, 0x2AC9, 0x22EE, 0x0000},
    {0x0000, 0x0000, 0x0318, 0x0318, 0x0FFE, 0x0FFE, 0x0318, 0x0318, 0x0318, 0x0318, 0x0FFE, 0x0FFE, 0x0318, 0x0318, 0x0000, 0x0000, 0x255B, 0x3555, 0x2D55, 0x25D1, 0x0000},
    {0x0000, 0x0630, 0x0808, 0x0808, 0x0808, 0x0808, 0x1004, 0x2002, 0x1004, 0x0808, 0x0808, 0x0808, 0x0808, 0x0630, 0x0000, 0x0000, 0x3A5B, 0x219B, 0x1915, 0x3911, 0x0000},
    {0x0000, 0x0FF8, 0x1004, 0x2002, 0x2002, 0x2002, 0x2772, 0x2412, 0x2622, 0x2442, 0x2442, 0x2002, 0x2002, 0x1004, 0x0FF8, 0x0000, 0x0F48, 0x0868, 0x0E58, 0x0848, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0080, 0x01C0, 0x03E0, 0x07F0, 0x0FF8, 0x1FFC, 0x3FFE, 0x07F0, 0x07F0, 0x07F0, 0x07F0, 0x07F0, 0x07F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0000, 0x0080, 0x01C0, 0x0360, 0x0630, 0x0C18, 0x180C, 0x3006, 0x2002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0000, 0x1E3E, 0x0200, 0x0300, 0x0100, 0x0180, 0x0080, 0x00C0, 0x0040, 0x0060, 0x0020, 0x0030, 0x0010, 0x001E, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x1C1C, 0x2222, 0x2222, 0x2222, 0x1FFC, 0x0220, 0x0220, 0x0220, 0x1FFC, 0x2222, 0x2222, 0x2222, 0x1C1C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    {0x0000, 0x0000, 0x0000, 0x0080, 0x0140, 0x0220, 0x0410, 0x0808, 0x1004, 0x3C1E, 0x0410, 0x0410, 0x0410, 0x0410, 0x0410, 0x07F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
};

static uint16_t oled_icon_glyph_row(char glyph, uint8_t row) {
    if ((uint8_t)glyph < (uint8_t)OLED_ICON_BASE || (uint8_t)glyph > (uint8_t)OLED_ICON_SHIFT) {
        return 0;
    }
    return pgm_read_word(&oled_large_icons[(uint8_t)glyph - (uint8_t)OLED_ICON_BASE][row]);
}

static void oled_draw_icon(uint8_t x, uint8_t y, char icon) {
    for (uint8_t row = 0; row < OLED_ICON_HEIGHT; row++) {
        const uint16_t pixels = oled_icon_glyph_row(icon, row);
        for (uint8_t column = 0; column < OLED_ICON_WIDTH; column++) {
            if (pixels & ((uint16_t)1 << (OLED_ICON_WIDTH - 1 - column))) {
                oled_write_pixel(x + column, y + row, true);
            }
        }
    }
}

static void oled_draw_history_glyph(uint8_t x, uint8_t y, char glyph) {
    const uint8_t cast_glyph = (uint8_t)glyph;

    if (cast_glyph < 32 || cast_glyph > 126) {
        return;
    }
    for (uint8_t row = 0; row < OLED_HISTORY_FONT_HEIGHT; row++) {
        const uint8_t pixels = pgm_read_byte(&oled_history_font[cast_glyph - OLED_HISTORY_FONT_START][row]);

        for (uint8_t column = 0; column < OLED_HISTORY_FONT_WIDTH; column++) {
            if (pixels & ((uint8_t)1 << (OLED_HISTORY_FONT_WIDTH - 1 - column))) {
                oled_write_pixel(x + column, y + row, true);
            }
        }
    }
}

static void oled_draw_history_line(uint8_t line, char first, char second, char third) {
    const uint8_t y = OLED_HISTORY_TOP_PADDING + line * OLED_HISTORY_LINE_HEIGHT;

    oled_draw_history_glyph(OLED_HISTORY_TEXT_X, y, first);
    oled_draw_history_glyph(OLED_HISTORY_TEXT_X + OLED_HISTORY_GLYPH_SPACING, y, second);
    oled_draw_history_glyph(OLED_HISTORY_TEXT_X + OLED_HISTORY_GLYPH_SPACING * 2, y, third);
}

static void oled_draw_status_icon(uint8_t x, uint8_t y, char icon) {
    oled_draw_icon(x, y, icon);
}

static void oled_draw_layer_icon(char icon) {
    oled_draw_icon(OLED_STATUS_CENTER_X, OLED_STATUS_LAYER_Y, icon);
}
