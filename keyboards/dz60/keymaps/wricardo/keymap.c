#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  SENDSEMICOLEQ = SAFE_RANGE,
  SENDBANGEQ,
  TMUXN,
  TMUXP,
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
    case TMUXN:
      if (record->event.pressed) {
				SEND_STRING(SS_LCTRL(" ") "l"); // ctrl + space + n in dvorak
      }
      break;
    case TMUXP:
      if (record->event.pressed) {
				SEND_STRING(SS_LCTRL(" ") "r"); // ctrl + space + n in dvorak
      }
      break;
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
		LT(1,KC_TAB),        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(1,KC_SCLN), KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   LT(2,KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
		KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,  KC_SPC,  KC_SPC,                    KC_RGUI, KC_RALT, XXXXXXX, KC_HYPR,   KC_RCTL),


	LAYOUT(
		RESET,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,          KC_F8,        KC_F9,      KC_F10,        KC_F11,        KC_F12,     _______, _______,
		_______,       KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______, LSFT(KC_8), LSFT(KC_MINUS), LSFT(KC_EQL), LSFT(KC_5), LSFT(KC_BSLS), LSFT(KC_2),    SENDBANGEQ, RESET,
		_______,       KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, LSFT(KC_6), KC_LPRN,     KC_RPRN,   LSFT(KC_7), KC_GRV,        XXXXXXX, _______,
		_______,       _______, SENDSEMICOLEQ, KC_MFFD, TMUXP, TMUXN, KC_MPLY,    XXXXXXX,     KC_MINUS,     KC_EQL,     LSFT(KC_GRV),  LSFT(KC_4),       _______, _______,
		_______,       _______, MO(2),          _______, _______, _______,    _______, _______, _______,   MO(2), _______),


	LAYOUT(
		_______, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, _______, _______, RESET,
		_______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,_______, KC_1,KC_2,KC_3,  _______, _______, _______,
		_______, _______, _______, _______, _______, KC_0, KC_0, KC_0, KC_0,  _______, _______),
};
