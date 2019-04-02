/* Copyright 2018 MechMerlin
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

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  SENDSEMICOLEQ = SAFE_RANGE,
  SENDBANGEQ,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SENDSEMICOLEQ:
      if (record->event.pressed) {
        SEND_STRING("Z]");// := in dvorak
      }
      break;
    case SENDBANGEQ:
      if (record->event.pressed) {
        SEND_STRING("!]");// != in dvorak
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
			KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      LT(1,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, LT(2,KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
      _______,  KC_LALT, KC_LGUI,                   KC_SPACE,                 KC_RGUI, KC_RALT,  _______
      ),

  [1] = LAYOUT(
      RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
      _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______, LSFT(KC_8), LSFT(KC_MINUS), LSFT(KC_EQL), LSFT(KC_5), LSFT(KC_BSLS), LSFT(KC_2),    SENDBANGEQ, RESET,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, LSFT(KC_6), KC_LPRN,     KC_RPRN,   LSFT(KC_7), KC_GRV,        XXXXXXX, _______,
      _______, SENDSEMICOLEQ, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY,    XXXXXXX,     KC_MINUS,     KC_EQL,     LSFT(KC_GRV),  LSFT(KC_4), _______, _______,
      _______, _______, _______,                   RGB_TOG,                   _______, _______, _______
      ),
  [2] = LAYOUT(
      RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
      _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______, LSFT(KC_8), KC_7, KC_8, KC_9, LSFT(KC_BSLS), LSFT(KC_2),    SENDBANGEQ, RESET,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, LSFT(KC_6), KC_4, KC_5, KC_6, KC_GRV,        XXXXXXX, _______,
      _______, SENDSEMICOLEQ, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,    KC_1,KC_2,KC_3,       LSFT(KC_4), _______, _______,
      _______, _______, _______,                   KC_0,                   _______, _______, _______
      ),
};
      /* KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, */


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   return true; */
/* } */

