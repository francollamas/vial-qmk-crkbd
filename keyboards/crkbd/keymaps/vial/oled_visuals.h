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

#define OLED_ICON_WIDTH              9
#define OLED_ICON_HEIGHT             13
#define OLED_TEXT_FONT_START         0
#define OLED_TEXT_FONT_WIDTH         6
#define OLED_TEXT_FONT_HEIGHT        8
#define OLED_HISTORY_TEXT_SCALE      2
#define OLED_HISTORY_LINE_HEIGHT     22
#define OLED_HISTORY_GLYPH_SPACING   10
#define OLED_HISTORY_TEXT_X          1
#define OLED_STATUS_ICON_X           11
#define OLED_STATUS_LINE_HEIGHT      15

extern const unsigned char font[] PROGMEM;

static const uint16_t PROGMEM oled_large_icons[][OLED_ICON_HEIGHT] = {
    {0x010, 0x038, 0x07C, 0x0FE, 0x111, 0x111, 0x111, 0x1FF, 0x100, 0x100, 0x1FF, 0x000, 0x000},
    {0x000, 0x010, 0x018, 0x01C, 0x1FE, 0x1FF, 0x1FE, 0x01C, 0x018, 0x010, 0x000, 0x000, 0x000},
    {0x07C, 0x102, 0x102, 0x102, 0x102, 0x1FE, 0x102, 0x102, 0x102, 0x102, 0x07C, 0x000, 0x000},
    {0x1F0, 0x010, 0x010, 0x010, 0x010, 0x070, 0x088, 0x088, 0x070, 0x000, 0x000, 0x000, 0x000},
    {0x044, 0x044, 0x1FF, 0x044, 0x044, 0x044, 0x1FF, 0x044, 0x044, 0x000, 0x000, 0x000, 0x000},
    {0x07C, 0x102, 0x139, 0x149, 0x149, 0x179, 0x100, 0x102, 0x07C, 0x000, 0x000, 0x000, 0x000},
    {0x1FF, 0x100, 0x1F8, 0x100, 0x100, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000},
    {0x07C, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x07C, 0x000, 0x000, 0x000, 0x000},
    {0x010, 0x038, 0x038, 0x038, 0x07C, 0x07C, 0x07C, 0x010, 0x010, 0x000, 0x000, 0x000, 0x000},
    {0x010, 0x038, 0x07C, 0x0FE, 0x1FF, 0x010, 0x010, 0x010, 0x1FF, 0x000, 0x000, 0x000, 0x000},
    {0x010, 0x028, 0x044, 0x082, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000},
    {0x100, 0x100, 0x1FF, 0x010, 0x020, 0x040, 0x080, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000},
    {0x06C, 0x092, 0x092, 0x06C, 0x092, 0x092, 0x06C, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000},
    {0x010, 0x038, 0x054, 0x092, 0x010, 0x010, 0x010, 0x010, 0x000, 0x000, 0x000, 0x000, 0x000},
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
            if (pixels & (1 << (OLED_ICON_WIDTH - 1 - column))) {
                oled_write_pixel(x + column, y + row, true);
            }
        }
    }
}

static void oled_draw_text_glyph(uint8_t x, uint8_t y, char glyph, uint8_t scale) {
    const uint8_t cast_glyph = (uint8_t)glyph;

    if (cast_glyph < 32 || cast_glyph > 126) {
        return;
    }
    for (uint8_t column = 0; column < OLED_TEXT_FONT_WIDTH; column++) {
        const uint8_t pixels = pgm_read_byte(&font[(cast_glyph - OLED_TEXT_FONT_START) * OLED_TEXT_FONT_WIDTH + column]);
        for (uint8_t row = 0; row < OLED_TEXT_FONT_HEIGHT; row++) {
            if (pixels & (1 << row)) {
                for (uint8_t pixel_y = 0; pixel_y < scale; pixel_y++) {
                    for (uint8_t pixel_x = 0; pixel_x < scale; pixel_x++) {
                        oled_write_pixel(x + column * scale + pixel_x, y + row * scale + pixel_y, true);
                    }
                }
            }
        }
    }
}

static void oled_draw_history_line(uint8_t line, char first, char second, char third) {
    const uint8_t y = line * OLED_HISTORY_LINE_HEIGHT;

    oled_draw_text_glyph(OLED_HISTORY_TEXT_X, y, first, OLED_HISTORY_TEXT_SCALE);
    oled_draw_text_glyph(OLED_HISTORY_TEXT_X + OLED_HISTORY_GLYPH_SPACING, y, second, OLED_HISTORY_TEXT_SCALE);
    oled_draw_text_glyph(OLED_HISTORY_TEXT_X + OLED_HISTORY_GLYPH_SPACING * 2, y, third, OLED_HISTORY_TEXT_SCALE);
}

static void oled_draw_status_icon(uint8_t line, char icon) {
    oled_draw_icon(OLED_STATUS_ICON_X, line * OLED_STATUS_LINE_HEIGHT, icon);
}

static void oled_draw_layer_icon(char icon) {
    if (icon == OLED_ICON_FUN) {
        oled_draw_text_glyph(4, 1, 'F', 2);
        oled_draw_text_glyph(16, 1, 'N', 2);
        return;
    }
    oled_draw_icon(OLED_STATUS_ICON_X, 0, icon);
}
