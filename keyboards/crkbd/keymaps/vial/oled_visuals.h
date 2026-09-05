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

#define OLED_ICON_WIDTH          3
#define OLED_ICON_HEIGHT         5
#define OLED_TEXT_FONT_START     0
#define OLED_TEXT_FONT_WIDTH     6
#define OLED_TEXT_FONT_HEIGHT    8
#define OLED_TEXT_LINE_HEIGHT    14
#define OLED_TEXT_GLYPH_SPACING  6
#define OLED_STATUS_ICON_SCALE   3
#define OLED_STATUS_LINE_HEIGHT  15
#define OLED_STATUS_ICON_X       11

extern const unsigned char font[] PROGMEM;

static const uint8_t PROGMEM oled_large_icons[][OLED_ICON_HEIGHT] = {
    {2, 7, 7, 5, 5}, {2, 3, 7, 3, 2}, {2, 7, 5, 5, 2}, {2, 3, 2, 2, 6}, {5, 7, 5, 7, 5}, {7, 5, 7, 4, 3}, {7, 4, 6, 4, 4},
    {2, 5, 5, 5, 2}, {2, 7, 2, 2, 2}, {2, 7, 2, 2, 7}, {2, 5, 0, 0, 0}, {1, 1, 7, 2, 4}, {2, 5, 2, 5, 2}, {2, 5, 2, 2, 2},
};

static uint8_t oled_icon_glyph_row(char glyph, uint8_t row) {
    if ((uint8_t)glyph < (uint8_t)OLED_ICON_BASE || (uint8_t)glyph > (uint8_t)OLED_ICON_SHIFT) {
        return 0;
    }
    return pgm_read_byte(&oled_large_icons[(uint8_t)glyph - (uint8_t)OLED_ICON_BASE][row]);
}

static void oled_draw_icon(uint8_t x, uint8_t y, char icon, uint8_t scale) {
    for (uint8_t row = 0; row < OLED_ICON_HEIGHT; row++) {
        const uint8_t pixels = oled_icon_glyph_row(icon, row);
        for (uint8_t column = 0; column < OLED_ICON_WIDTH; column++) {
            if (pixels & (1 << (OLED_ICON_WIDTH - 1 - column))) {
                for (uint8_t pixel_y = 0; pixel_y < scale; pixel_y++) {
                    for (uint8_t pixel_x = 0; pixel_x < scale; pixel_x++) {
                        oled_write_pixel(x + column * scale + pixel_x, y + row * scale + pixel_y, true);
                    }
                }
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

static void oled_draw_text_line(uint8_t line, char first, char second, char third, char fourth) {
    const uint8_t y = line * OLED_TEXT_LINE_HEIGHT;

    oled_draw_text_glyph(0, y, first, 1);
    oled_draw_text_glyph(OLED_TEXT_GLYPH_SPACING, y, second, 1);
    oled_draw_text_glyph(OLED_TEXT_GLYPH_SPACING * 2, y, third, 1);
    oled_draw_text_glyph(OLED_TEXT_GLYPH_SPACING * 3, y, fourth, 1);
}

static void oled_draw_status_icon(uint8_t line, char icon) {
    oled_draw_icon(OLED_STATUS_ICON_X, line * OLED_STATUS_LINE_HEIGHT, icon, OLED_STATUS_ICON_SCALE);
}

static void oled_draw_layer_icon(char icon) {
    if (icon == OLED_ICON_FUN) {
        oled_draw_text_glyph(4, 1, 'F', 2);
        oled_draw_text_glyph(16, 1, 'N', 2);
        return;
    }
    oled_draw_icon(OLED_STATUS_ICON_X, 0, icon, OLED_STATUS_ICON_SCALE);
}
