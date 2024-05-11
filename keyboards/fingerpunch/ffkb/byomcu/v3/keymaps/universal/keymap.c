/* Copyright 2024 Samantha Yuen <samantha.y.twentyfourteen@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published bynnnn
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

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// ============================================================
// Defines names for use in layer keycodes and the keymap
// ============================================================
enum layer_names {
    _COLEMAK, //0
    _QWERTY,  //1
    _SYM,     //2
    _MCR,     //3
    _NAV,     //4
    // _RGB,     //5
    // _MOUSE,  //6
    _NEW_SAFE_LAYER  //7
};

// ============================================================
// Basic custom keycodes
// ============================================================
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define WPAST G(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)
#define LDESK G(C(KC_LEFT)) 
#define RDESK G(C(KC_RIGHT))
#define EXITPARSEC C(A(S(KC_TILD)))
#define TASKMAN C(A(KC_DEL))
#define MBEE C(S(A(KC_BSLS)))
#define MBEEL C(S(KC_LBRC))
#define MBEER C(S(KC_RBRC))
#define MBEEVU C(S(A(KC_UP)))
#define MBEEVD C(S(A(KC_DOWN)))

// ============================================================
// Combos
// ============================================================
enum combos {
  // LEFT - COLDH
  ZX_WIN,
  XC_ALT,
  TG_TICK,
  // CD_M2,
  // RIGHT - COLDH
  SDOT_WIN,
  MN_TILDE,
  GM_CAPS,

  COMBO_LENGTH, 
};

uint16_t COMBO_LEN = COMBO_LENGTH; 

// LEFT - COLDH
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
// const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
// RIGHT - COLDH
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
// MOUSE SCROLL
const uint16_t PROGMEM gm_combo[] = {KC_G, KC_M, COMBO_END};

combo_t key_combos[] = {
  // LEFT - COLDH
  [ZX_WIN] = COMBO(zx_combo, OSM(MOD_LGUI)),
  [XC_ALT] = COMBO(xc_combo, OSM(MOD_LALT)),
  [TG_TICK] = COMBO(tg_combo, KC_GRV),
  // RIGHT - COLDH
  [SDOT_WIN] = COMBO(ds_combo, OSM(MOD_RGUI)),
  [MN_TILDE] = COMBO(mn_combo, KC_TILD),
  // BOTH - COLDH
  [GM_CAPS] = COMBO(gm_combo, KC_CAPS)
};

// ============================================================
// Keymap
// ============================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ============================================================
// Layer 0 - Colemak-DH
// ============================================================
[_COLEMAK] = LAYOUT(
  KC_ESC,         KC_Q,     KC_W,        KC_F,     KC_P,    KC_B,                  KC_J,   KC_L,    KC_U,     KC_Y,     KC_SCLN,      KC_BSPC,
  OSM(MOD_LCTL),  KC_A,     KC_R,        KC_S,     KC_T,    KC_G,                  KC_M,   KC_N,    KC_E,     KC_I,     KC_O,         KC_QUOT,
  OSM(MOD_LSFT),  KC_Z,     KC_X,        KC_C,     KC_D,    KC_V,                  KC_K,   KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,      KC_APP,
                  KC_MUTE,  KC_BTN1,  LT(_SYM, KC_ENT),   LT(_MCR,KC_BTN2),     KC_TAB, LT(_NAV,KC_SPC), KC_LALT, KC_RALT
),

// ============================================================
// Layer 1 - QWERTY
// ============================================================
[_QWERTY] = LAYOUT(
  KC_TAB,  KC_Q,   KC_W,   KC_E,     KC_R,     KC_T,    KC_Y,                KC_U,     KC_I,     KC_O,     KC_P,       _______,
  _______, KC_A,   KC_S,   KC_D,     KC_F,     KC_G,    KC_H,                KC_J,     KC_K,     KC_L,     KC_SCLN,    _______,
  _______, KC_Z,   KC_X,   KC_C,     KC_V,     KC_B,    KC_N,                KC_M,     _______,  _______,  _______,    KC_BTN2,
                _______,  _______,   LT(_SYM,KC_SPC),   LT(_MCR, KC_ENT),    KC_SPC,  _______,  _______,  _______
),

// ============================================================
// Layer 2 - SYM_New
// ============================================================
[_SYM] = LAYOUT(
  KC_ESC,  KC_LBRC, KC_7,    KC_8,     KC_9, KC_RBRC,        _______,     FP_SUPER_TAB,  FP_SUPER_CTRL_TAB,   _______,        KC_BSPC,       KC_DEL,
  LDESK,   KC_EQL,  KC_1,    KC_2,    KC_3, KC_0,            KC_CALC,  OSM(MOD_LCTL), OSM(MOD_LSFT),       OSM(MOD_LALT),  OSM(MOD_LGUI), RDESK,
  _______, KC_PIPE, KC_4,    KC_5,    KC_6, KC_MINS,         _______,     KC_UNDS,       KC_SCLN,             _______,        KC_BSLS, _______,
                    _______, _______, _______, _______,      _______,     KC_MINS,  KC_UNDS,  EE_CLR
),

// ============================================================
// Layer 3 - FN_New
// ============================================================
[_MCR] = LAYOUT(
  KC_ESC,   TASKMAN,  C(S(KC_V)), UNDO,   WPAST,        TO(_QWERTY),      KC_NUM,   KC_BRID,  KC_BRIU,  MBEEVD, MBEEVU, KC_DEL, 
  _______,  _______,  CUT,        COPY,   PASTE,        C(KC_A),          _______,  MBEEL,   MEH(KC_P), MBEER,   MBEE,    _______,
  _______,  _______,  KC_MYCM,    REDO,   G(S(KC_S)),   TO(_COLEMAK),          _______,  KC_PSCR,   KC_SCRL, KC_PAUS, _______, _______,
                                 _______,  _______, _______, _______,     KC_BTN3,  C(KC_MINS),  C(KC_EQL),  EE_CLR
),

// ============================================================
// Layer 4 - NAV_NEW
// ============================================================
[_NAV] = LAYOUT(
  KC_ESC,      _______, RGB_TOG, RGB_MOD, RGB_RMOD, EXITPARSEC,                             KC_PGUP, KC_HOME,   KC_UP,    KC_END,   KC_DEL,   _______,
  _______,     OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_MEH),    KC_PGDN, KC_LEFT,   KC_DOWN,  KC_RGHT,  KC_BSPC,  KC_INS,
  KC_F12,      KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,                                         KC_F6,   KC_F7,     KC_F8,    KC_F9,    KC_F10,   KC_F11,
                     QK_BOOT, _______, _______, _______,                                    _______, _______,   _______,  _______
),

// ============================================================
// Layer  5 - RGB_NEW
// ============================================================
// [_RGB] =  LAYOUT(
//   _______, RGB_TOG, RGB_MOD,  RGB_RMOD, _______,  TO(_COLEMAK),  _______, KC_F7,  KC_F8, KC_F9, KC_F10, KC_F13,
//   _______, RGB_SPI, RGB_HUI,  RGB_SAI,  RGB_VAI,  TO(_QWERTY),   _______, KC_F4,  KC_F5, KC_F6, KC_F11, _______,
//   _______, RGB_SPD, RGB_HUD,  RGB_SAD,  RGB_VAD,  EXITPARSEC,    _______, KC_F1,  KC_F2, KC_F3, KC_F12, _______,
//                 QK_BOOT, _______,   _______,  _______,            _______,  _______,  _______,  _______
// ),

// ============================================================
// Layer 6 - Mouse
// ============================================================
// [_MOUSE] = LAYOUT(
//   _______, _______, _______,    KC_WH_U,  _______,    _______,            _______,  _______,  KC_C,  _______, _______, _______,
//   _______, _______, KC_MS_BTN2, KC_WH_D,  KC_MS_BTN1, _______,            KC_N,  KC_A,  KC_E,  KC_I, KC_O, KC_U,
//   _______, _______, _______, _______, _______, _______,                   KC_PCMM,  KC_QUOT,  KC_GRV,   KC_CIRC, KC_DQUO, _______,
//                                    _______, _______, _______, _______,    _______,  _______,  _______,  _______
// ),
// ============================================================
// Empty Layer
// ============================================================

[_NEW_SAFE_LAYER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
                    _______, _______, _______, _______,         _______,  _______,  _______,  _______
)
};


// ============================================================
// Encoder button settings
// ============================================================
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } 
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        tap_code16(MBEEVU);
      }
      else{
        tap_code16(MBEEVD);
      }
    }

    return true;
}
#endif
        
// ============================================================
// Change RGB based on CAPSLOCK & NUMLOCK status
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#common-configuration-idcommon-configuration
// Generate Perfect Per-key RGB effects: see v3.c
// QMK RGB Tutorial: https://github.com/sadekbaroudi/keyboard-guides/blob/master/firmware/qmk/RGB_MATRIX.md
// RGB CODES: https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch#layer-lighting
// ============================================================
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(16, 242, 242, 0); // CAPSLOCK ON | yellow / MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 242, 242, 0); // CAPSLOCK ON | yellow / MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(16, 0, 0, 0); // CAPSLOCK OFF | BLANK
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 0, 0, 0); // CAPSLOCK OFF | BLANK
    }
    if (host_keyboard_led_state().num_lock) {
        // RGB_MATRIX_INDICATOR_SET_COLOR(26, 242, 191, 180); // NUMLOCK ON | Reaper Master New Gold (9051) #e7bd42 https://encycolorpedia.com/e7bd42
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 242, 242, 0); // NUMLOCK ON | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(25, 242, 242, 0); // CALC | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(23, 242, 242, 0); // DOT | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(37, 242, 242, 0); // PLUS | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(36, 242, 242, 0); // EQUALS | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(40, 242, 242, 0); // TIMES | yellow
        // RGB_MATRIX_INDICATOR_SET_COLOR(38, 242, 242, 0); // MINUS | yellow
        
        // RGB_MATRIX_INDICATOR_SET_COLOR(24, 252, 252, 252); // 0 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(29, 252, 252, 252); // 1 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(30, 252, 252, 252); // 2 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(35, 252, 252, 252); // 3 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(28, 252, 252, 252); // 4 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(31, 252, 252, 252); // 5 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(34, 252, 252, 252); // 6 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(27, 252, 252, 252); // 7 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(32, 252, 252, 252); // 8 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(33, 252, 252, 252); // 9 | WHITE
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 0, 0, 0); // NUMLOCK OFF | BLANK
        // RGB_MATRIX_INDICATOR_SET_COLOR(25, 0, 0, 0); // CALC 
        // RGB_MATRIX_INDICATOR_SET_COLOR(23, 0, 0, 0); // DOT 
        // RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 0); // PLUS 
        // RGB_MATRIX_INDICATOR_SET_COLOR(36, 0, 0, 0); // EQUALS 
        // RGB_MATRIX_INDICATOR_SET_COLOR(40, 0, 0, 0); // TIMES 
        // RGB_MATRIX_INDICATOR_SET_COLOR(38, 0, 0, 0); // MINUS 
        
        // RGB_MATRIX_INDICATOR_SET_COLOR(29, 0, 0, 0); // 1 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(24, 0, 0, 0); // 0 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, 0, 0); // 2 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(35, 0, 0, 0); // 3 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(28, 0, 0, 0); // 4 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(31, 0, 0, 0); // 5 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(34, 0, 0, 0); // 6 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(27, 0, 0, 0); // 7 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(32, 0, 0, 0); // 8 | WHITE
        // RGB_MATRIX_INDICATOR_SET_COLOR(33, 0, 0, 0); // 9 | WHITE
    }

    return false;
}