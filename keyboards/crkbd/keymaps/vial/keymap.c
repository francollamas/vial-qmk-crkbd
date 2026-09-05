/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, TL_LOWR, KC_SPC, KC_ENT, TL_UPPR, KC_RALT
                                                                  //`--------------------------'  `--------------------------'

                                                                  ),

                                                              [1] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LCTL, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [2] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [3] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [4] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [5] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [6] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [7] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [8] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};

#ifdef OLED_ENABLE
#    include <string.h>

#    include "transactions.h"

#    include "oled_visuals.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    (void)rotation;
    return OLED_ROTATION_270;
}

#    define L_BASE 0
#    define L_LOWER 2
#    define L_RAISE 4
#    define L_ADJUST 8
#    define L_CUARTA 16
#    define L_QUINTA 32
#    define L_SEXTA 64
#    define L_SEPTIMA 128
#    define L_OCTAVA 256

#    define OLED_KEY_HISTORY_SIZE 5

typedef struct {
    uint16_t keycode;
    uint8_t  mods;
} oled_key_history_entry_t;

typedef struct {
    oled_key_history_entry_t keys[OLED_KEY_HISTORY_SIZE];
} oled_key_history_t;

static oled_key_history_t key_history;
static bool               key_history_needs_sync;


static void oled_render_layer_state(void) {
    static layer_state_t last_layer_state = (layer_state_t)-1;
    static uint8_t       last_mods        = 0xFF;
    static bool          last_caps_word;
    char          icon = OLED_ICON_BASE;
    const uint8_t mods = get_mods();
    const bool    caps_word_active = is_caps_word_on();

    if (layer_state == last_layer_state && mods == last_mods && caps_word_active == last_caps_word) {
        return;
    }

    if (layer_state & L_ADJUST) {
        icon = OLED_ICON_MEDIA;
    } else {
        switch (get_highest_layer(layer_state)) {
            case 1:
                icon = OLED_ICON_NAV;
                break;
            case 2:
                icon = OLED_ICON_MOUSE;
                break;
            case 4:
                icon = OLED_ICON_NUM;
                break;
            case 5:
                icon = OLED_ICON_SYM;
                break;
            case 6:
                icon = OLED_ICON_FUN;
                break;
            case 7:
                icon = OLED_ICON_BUTTON;
                break;
            case 8:
                icon = OLED_ICON_TAP;
                break;
        }
    }

    oled_clear();

    oled_draw_layer_icon(icon);
    if (caps_word_active) {
        oled_draw_status_icon(2, OLED_ICON_CAPS);
    }

    if (mods & MOD_MASK_CTRL) {
        oled_draw_status_icon(4, OLED_ICON_CTRL);
    }
    if (mods & MOD_MASK_ALT) {
        oled_draw_status_icon(5, OLED_ICON_ALT);
    }
    if (mods & MOD_MASK_GUI) {
        oled_draw_status_icon(6, OLED_ICON_GUI);
    }
    if (mods & MOD_MASK_SHIFT) {
        oled_draw_status_icon(7, OLED_ICON_SHIFT);
    }

    last_layer_state = layer_state;
    last_mods = mods;
    last_caps_word = caps_word_active;
}

static uint8_t oled_unpack_mods5(uint8_t mods) {
    return mods & 0x10 ? mods << 4 : mods;
}

static uint16_t oled_display_keycode(uint16_t keycode, uint8_t *mods) {
    if (IS_QK_MOD_TAP(keycode)) {
        return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (IS_QK_LAYER_TAP(keycode)) {
        return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (IS_QK_MODS(keycode)) {
        *mods |= oled_unpack_mods5(QK_MODS_GET_MODS(keycode));
        return QK_MODS_GET_BASIC_KEYCODE(keycode);
    }
    return keycode;
}

static char oled_symbol_for_keycode(uint16_t keycode, uint8_t mods) {
    const bool shifted = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case KC_1: return shifted ? '!' : '1';
        case KC_2: return shifted ? '@' : '2';
        case KC_3: return shifted ? '#' : '3';
        case KC_4: return shifted ? '$' : '4';
        case KC_5: return shifted ? '%' : '5';
        case KC_6: return shifted ? '^' : '6';
        case KC_7: return shifted ? '&' : '7';
        case KC_8: return shifted ? '*' : '8';
        case KC_9: return shifted ? '(' : '9';
        case KC_0: return shifted ? ')' : '0';
        case KC_MINS: return shifted ? '_' : '-';
        case KC_EQL: return shifted ? '+' : '=';
        case KC_LBRC: return shifted ? '{' : '[';
        case KC_RBRC: return shifted ? '}' : ']';
        case KC_BSLS: return shifted ? '|' : '\\';
        case KC_SCLN: return shifted ? ':' : ';';
        case KC_QUOT: return shifted ? '"' : '\'';
        case KC_GRV: return shifted ? '~' : '`';
        case KC_COMM: return shifted ? '<' : ',';
        case KC_DOT: return shifted ? '>' : '.';
        case KC_SLSH: return shifted ? '?' : '/';
        case KC_KP_SLASH: return '/';
        case KC_KP_ASTERISK: return '*';
        case KC_KP_MINUS: return '-';
        case KC_KP_PLUS: return '+';
        case KC_KP_EQUAL: return '=';
    }
    return '\0';
}

static void oled_write_key_label(uint8_t line, oled_key_history_entry_t entry) {
    uint8_t  mods    = entry.mods;
    uint16_t keycode = oled_display_keycode(entry.keycode, &mods);
    const char symbol = oled_symbol_for_keycode(keycode, mods);

    if (keycode == KC_NO) {
        return;
    }
    if (symbol) {
        oled_draw_text_line(line, symbol, ' ', ' ', ' ');
        return;
    }

    if (keycode >= KC_A && keycode <= KC_Z) {
        oled_draw_text_line(line, 'A' + keycode - KC_A, ' ', ' ', ' ');
        return;
    }

    switch (keycode) {
        case KC_SPC: oled_draw_text_line(line, 'S', 'P', 'C', ' '); break;
        case KC_ENT: oled_draw_text_line(line, 'E', 'N', 'T', ' '); break;
        case KC_BSPC: oled_draw_text_line(line, 'B', 'S', 'P', ' '); break;
        case KC_TAB: oled_draw_text_line(line, 'T', 'A', 'B', ' '); break;
        case KC_ESC: oled_draw_text_line(line, 'E', 'S', 'C', ' '); break;
        case KC_LEFT: oled_draw_text_line(line, 'L', 'E', 'F', 'T'); break;
        case KC_RGHT: oled_draw_text_line(line, 'R', 'G', 'H', 'T'); break;
        case KC_UP: oled_draw_text_line(line, 'U', 'P', ' ', ' '); break;
        case KC_DOWN: oled_draw_text_line(line, 'D', 'O', 'W', 'N'); break;
        case KC_LCTL:
        case KC_RCTL: oled_draw_text_line(line, 'C', 'T', 'R', 'L'); break;
        case KC_LALT:
        case KC_RALT: oled_draw_text_line(line, 'A', 'L', 'T', ' '); break;
        case KC_LGUI:
        case KC_RGUI: oled_draw_text_line(line, 'G', 'U', 'I', ' '); break;
        case KC_LSFT:
        case KC_RSFT: oled_draw_text_line(line, 'S', 'H', 'F', 'T'); break;
        case TL_LOWR: oled_draw_text_line(line, 'L', 'O', 'W', 'R'); break;
        case TL_UPPR: oled_draw_text_line(line, 'U', 'P', 'P', 'R'); break;
        default: oled_draw_text_line(line, '-', '-', '-', '-'); break;
    }
}

static void oled_render_keylog(void) {
    static oled_key_history_t rendered_history;
    static bool               rendered;

    if (rendered && memcmp(&rendered_history, &key_history, sizeof(key_history)) == 0) {
        return;
    }

    oled_clear();
    for (uint8_t index = 0; index < OLED_KEY_HISTORY_SIZE; index++) {
        oled_write_key_label(index, key_history.keys[index]);
    }
    memcpy(&rendered_history, &key_history, sizeof(key_history));
    rendered = true;
}

static void oled_key_history_sync_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    (void)out_buflen;
    (void)out_data;

    if (in_buflen == sizeof(key_history)) {
        memcpy(&key_history, in_data, sizeof(key_history));
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(OLED_KEY_HISTORY_SYNC, oled_key_history_sync_handler);
}

void housekeeping_task_user(void) {
    static uint32_t last_key_history_sync;

    if (is_keyboard_master() && key_history_needs_sync && timer_elapsed32(last_key_history_sync) >= 10) {
        if (transaction_rpc_send(OLED_KEY_HISTORY_SYNC, sizeof(key_history), &key_history)) {
            key_history_needs_sync = false;
        }
        last_key_history_sync = timer_read32();
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM mb_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0x70, 0x10, 0x08, 0x84, 0x82, 0xc6, 0xec, 0x78, 0x30, 0x10, 0x18, 0x08, 0x08, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xfc, 0xfe, 0xff, 0xff, 0xcf, 0x27, 0xb1, 0x9c, 0xce, 0xc7, 0xe7, 0xe3, 0x31, 0x08, 0x00, 0x80, 0x80, 0xcc, 0x63, 0x20, 0x90, 0x98, 0xcc, 0x44, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0x3c, 0x38, 0x30, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0xfe, 0xfe, 0xfc, 0x1c, 0x0e, 0x0e, 0x0e, 0x0e, 0x00, 0x00, 0xfe, 0xfe, 0xfc, 0x1c, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xde, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xde, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x7f, 0x9f, 0xe3, 0xfc, 0xff, 0x7f, 0x3f, 0x0f, 0x87, 0xc1, 0x68, 0x24, 0x32, 0x1b, 0x09, 0x8c, 0x46, 0x42, 0x23, 0x21, 0x90, 0x48, 0x28, 0x14, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x78, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x78, 0x3c, 0x1c, 0x0c, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x78, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x78, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x79, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x79, 0x3d, 0x1d, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x1c, 0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x10, 0x28, 0x44, 0x84, 0x82, 0x82, 0x41, 0x21, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(mb_logo, sizeof(mb_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_keylog();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (is_keyboard_master() && record->event.pressed) {
        for (uint8_t index = OLED_KEY_HISTORY_SIZE - 1; index > 0; index--) {
            key_history.keys[index] = key_history.keys[index - 1];
        }
        key_history.keys[0].keycode = keycode;
        key_history.keys[0].mods    = get_mods();
        key_history_needs_sync = true;
    }
    return true;
}
#endif // OLED_ENABLE
