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

#define OLED_LARGE_FONT_WIDTH  3
#define OLED_LARGE_FONT_HEIGHT 5
#define OLED_TEXT_SCALE         2
#define OLED_STATUS_ICON_SCALE  3
#define OLED_LINE_HEIGHT        15
#define OLED_GLYPH_SPACING      7
#define OLED_STATUS_ICON_X      11

static const uint8_t PROGMEM oled_large_font[][OLED_LARGE_FONT_HEIGHT] = {
    {2, 5, 7, 5, 5}, {6, 5, 6, 5, 6}, {3, 4, 4, 4, 3}, {6, 5, 5, 5, 6}, {7, 4, 6, 4, 7}, {7, 4, 6, 4, 4},
    {3, 4, 5, 5, 3}, {5, 5, 7, 5, 5}, {7, 2, 2, 2, 7}, {1, 1, 1, 5, 2}, {5, 5, 6, 5, 5}, {4, 4, 4, 4, 7},
    {5, 7, 7, 5, 5}, {5, 7, 7, 7, 5}, {2, 5, 5, 5, 2}, {6, 5, 6, 4, 4}, {2, 5, 5, 7, 3}, {6, 5, 6, 5, 5},
    {3, 4, 2, 1, 6}, {7, 2, 2, 2, 2}, {5, 5, 5, 5, 7}, {5, 5, 5, 5, 2}, {5, 5, 7, 7, 5}, {5, 5, 2, 5, 5},
    {5, 5, 2, 2, 2}, {7, 1, 2, 4, 7}, {2, 6, 2, 2, 7}, {6, 1, 2, 4, 7}, {6, 1, 2, 1, 6}, {5, 5, 7, 1, 1},
    {7, 4, 6, 1, 6}, {3, 4, 6, 5, 2}, {7, 1, 2, 4, 4}, {2, 5, 2, 5, 2}, {2, 5, 3, 1, 6}, {2, 5, 5, 5, 2},
};

static const uint8_t PROGMEM oled_large_icons[][OLED_LARGE_FONT_HEIGHT] = {
    {2, 7, 7, 5, 5}, {2, 3, 7, 3, 2}, {2, 7, 5, 5, 2}, {2, 3, 2, 2, 6}, {5, 7, 5, 7, 5}, {7, 5, 7, 4, 3}, {7, 4, 6, 4, 4},
    {2, 5, 5, 5, 2}, {2, 7, 2, 2, 2}, {2, 7, 2, 2, 7}, {2, 5, 0, 0, 0}, {1, 1, 7, 2, 4}, {2, 5, 2, 5, 2}, {2, 5, 2, 2, 2},
};

static const uint8_t PROGMEM oled_large_symbols[][OLED_LARGE_FONT_HEIGHT] = {
    {2, 2, 2, 0, 2}, {7, 5, 7, 4, 3}, {5, 7, 5, 7, 5}, {7, 6, 3, 6, 7}, {5, 1, 2, 4, 5}, {2, 5, 0, 0, 0}, {2, 5, 2, 5, 3}, {0, 5, 2, 5, 0},
    {1, 2, 2, 2, 1}, {4, 2, 2, 2, 4}, {0, 0, 0, 0, 7}, {0, 2, 7, 2, 0}, {0, 7, 0, 7, 0}, {6, 4, 4, 4, 6}, {3, 1, 1, 1, 3}, {3, 2, 6, 2, 3},
    {6, 2, 3, 2, 6}, {4, 2, 1, 2, 4}, {2, 2, 2, 0, 2}, {0, 2, 0, 2, 0}, {2, 2, 0, 0, 0}, {5, 5, 0, 0, 0}, {0, 0, 0, 2, 4}, {0, 0, 0, 0, 2},
    {1, 2, 4, 2, 1}, {4, 2, 1, 2, 4}, {1, 2, 4, 2, 1}, {6, 1, 2, 0, 2}, {0, 2, 5, 0, 0}, {2, 5, 0, 0, 0}, {2, 5, 0, 0, 0},
};

static uint8_t oled_large_glyph_row(char glyph, uint8_t row) {
    uint8_t glyph_index;

    if (glyph >= 'A' && glyph <= 'Z') {
        glyph_index = glyph - 'A';
        return pgm_read_byte(&oled_large_font[glyph_index][row]);
    }
    if (glyph >= '0' && glyph <= '9') {
        glyph_index = glyph - '0' + 26;
        return pgm_read_byte(&oled_large_font[glyph_index][row]);
    }
    if ((uint8_t)glyph >= (uint8_t)OLED_ICON_BASE && (uint8_t)glyph <= (uint8_t)OLED_ICON_SHIFT) {
        glyph_index = (uint8_t)glyph - (uint8_t)OLED_ICON_BASE;
        return pgm_read_byte(&oled_large_icons[glyph_index][row]);
    }
    if (glyph == '-') {
        return row == 2 ? 7 : 0;
    }
    switch (glyph) {
        case '!': glyph_index = 0; break;
        case '@': glyph_index = 1; break;
        case '#': glyph_index = 2; break;
        case '$': glyph_index = 3; break;
        case '%': glyph_index = 4; break;
        case '^': glyph_index = 5; break;
        case '&': glyph_index = 6; break;
        case '*': glyph_index = 7; break;
        case '(': glyph_index = 8; break;
        case ')': glyph_index = 9; break;
        case '_': glyph_index = 10; break;
        case '+': glyph_index = 11; break;
        case '=': glyph_index = 12; break;
        case '[': glyph_index = 13; break;
        case ']': glyph_index = 14; break;
        case '{': glyph_index = 15; break;
        case '}': glyph_index = 16; break;
        case '\\': glyph_index = 17; break;
        case '|': glyph_index = 18; break;
        case ';': glyph_index = 19; break;
        case ':': glyph_index = 20; break;
        case '\'': glyph_index = 21; break;
        case '"': glyph_index = 22; break;
        case ',': glyph_index = 23; break;
        case '.': glyph_index = 24; break;
        case '<': glyph_index = 25; break;
        case '>': glyph_index = 26; break;
        case '/': glyph_index = 27; break;
        case '?': glyph_index = 28; break;
        case '~': glyph_index = 29; break;
        case '`': glyph_index = 30; break;
        default: return 0;
    }
    return pgm_read_byte(&oled_large_symbols[glyph_index][row]);
}

static void oled_draw_glyph(uint8_t x, uint8_t y, char glyph, uint8_t scale) {
    for (uint8_t row = 0; row < OLED_LARGE_FONT_HEIGHT; row++) {
        const uint8_t pixels = oled_large_glyph_row(glyph, row);
        for (uint8_t column = 0; column < OLED_LARGE_FONT_WIDTH; column++) {
            if (pixels & (1 << (OLED_LARGE_FONT_WIDTH - 1 - column))) {
                for (uint8_t pixel_y = 0; pixel_y < scale; pixel_y++) {
                    for (uint8_t pixel_x = 0; pixel_x < scale; pixel_x++) {
                        oled_write_pixel(x + column * scale + pixel_x, y + row * scale + pixel_y, true);
                    }
                }
            }
        }
    }
}

static void oled_draw_large_line(uint8_t line, char first, char second, char third, char fourth) {
    const uint8_t y = line * OLED_LINE_HEIGHT;

    oled_draw_glyph(0, y, first, OLED_TEXT_SCALE);
    oled_draw_glyph(OLED_GLYPH_SPACING, y, second, OLED_TEXT_SCALE);
    oled_draw_glyph(OLED_GLYPH_SPACING * 2, y, third, OLED_TEXT_SCALE);
    oled_draw_glyph(OLED_GLYPH_SPACING * 3, y, fourth, OLED_TEXT_SCALE);
}

static void oled_draw_status_icon(uint8_t line, char icon) {
    oled_draw_glyph(OLED_STATUS_ICON_X, line * OLED_LINE_HEIGHT, icon, OLED_STATUS_ICON_SCALE);
}

static void oled_draw_layer_icon(char icon) {
    if (icon == OLED_ICON_FUN) {
        oled_draw_glyph(7, 0, 'F', OLED_STATUS_ICON_SCALE);
        oled_draw_glyph(17, 0, 'N', OLED_STATUS_ICON_SCALE);
        return;
    }
    oled_draw_glyph(OLED_STATUS_ICON_X, 0, icon, OLED_STATUS_ICON_SCALE);
}
