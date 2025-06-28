/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  INT_AE,
  INT_AO,
  INT_OE,
  TEST_AE,
  INT_UNICODE_SHRUGGIE,
  INT_UNICODE_TABLEFLIP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,               KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                                        KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,               KC_W,           KC_E,           KC_R,           KC_T,           TG(3),                                          TG(3),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_BSPC,        KC_A,               KC_S,           KC_D,           KC_F,           KC_G,           KC_HYPR,                                        KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           LT(2,KC_SCLN),  LGUI_T(KC_QUOTE),
    KC_LSFT,        LCTL_T(KC_Z),       KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSFT,
    LT(1,KC_GRAVE), LT(2, WEBUSB_PAIR), LALT(KC_LSFT),  KC_LEFT,        KC_RIGHT,                                   KC_LALT,         KC_RGUI,                                            KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        MO(1),
                                                                                    KC_SPACE,       KC_BSPC,        KC_LGUI,         KC_RGUI,            KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                                   HSV_172_255_255, RGB_TOG,
                                                                                    RGB_VAD,        RGB_VAI,        HSV_27_255_255, KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_MS_UP,       KC_TRANSPARENT, INT_UNICODE_TABLEFLIP, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, INT_UNICODE_SHRUGGIE, KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                        KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, WEBUSB_PAIR,    KC_TRANSPARENT,       KC_MS_BTN1,     KC_MS_BTN2,                                                                                                          KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE
  ),

  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TEST_AE, KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, INT_AO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      INT_OE,         INT_AE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                      KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


void tap_key(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

#define SEND_COMPOSED_STRING(string)  { \
        uint8_t temp_mods = get_mods(); \
        tap_key(KC_RALT); \
        SEND_STRING(string); \
        set_mods(temp_mods); \
    }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
    case INT_AE:
      if (record->event.pressed) {
        SEND_COMPOSED_STRING("a\"");
      }
      break;
    case INT_OE:
      if (record->event.pressed) {
        SEND_COMPOSED_STRING("o\"");
      }
      break;
    case INT_AO:
      if (record->event.pressed) {
        SEND_COMPOSED_STRING("a*");
      }
      break;
    case TEST_AE:
      if (record->event.pressed) {
          send_unicode_string("ä");
      }
      break;
    case INT_UNICODE_SHRUGGIE:
      if (record->event.pressed) {
          send_unicode_string("¯\\_(ツ)_/¯");
      }
      break;
    case INT_UNICODE_TABLEFLIP:
      if (record->event.pressed) {
          send_unicode_string("/ (╯°□°）╯︵ ┻━┻ ");
      }
      break;

  }
  return true;
}
