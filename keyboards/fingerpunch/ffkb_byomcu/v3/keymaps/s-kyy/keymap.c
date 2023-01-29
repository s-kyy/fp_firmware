/* @author Samantha Yuen
 * 
 */

// #include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _RAISE,
    _LOWER,
    _MOUSE_NUM,
    _GAME,
    _QWERTY
};

//custom keycodes
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define COLDH TO(_COLEMAK)
#define MOUSE TO(_MOUSE_NUM)
#define GAME  TO(_GAME)
#define QWERTY TO(_QWERTY)
#define REDO LCTL(KC_Y)
#define SFTT LSFT_T(KC_TAB) //Tab-tap Shift-hold
#define SALT LALT_T(KC_SPC) //Space-tap LALT-hold
#define SFTE LSFT_T(KC_ENT) //Enter-tap Shift-hold

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ============================================================
// Layer 0 - Colemak-DH
// ============================================================
[_COLEMAK] = LAYOUT_ffkb(
  KC_ESC,   KC_Q,     KC_W,     KC_F,   KC_P,   KC_B,       KC_J,   KC_L,   KC_U,     KC_Y,     KC_SCLN,    KC_BSPC,
  KC_LCTL,  KC_A,     KC_R,     KC_S,   KC_T,   KC_G,       KC_M,   KC_N,   KC_E,     KC_I,     KC_O,       KC_QUOT,
  SFTT,     KC_Z,     KC_X,     KC_C,   KC_D,   KC_V,       KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_APP,
                      KC_MUTE,  RAISE,  SFTE,   KC_BTN1,    KC_LWIN,  SALT, LOWER,    KC_RALT
),

// ============================================================
// Layer 1 - RAISE
// ============================================================
// Pointing Device Zoom Layer
[_RAISE] = LAYOUT_ffkb(
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          KC_TILD,   KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL,   KC_F11,
  _______,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,          KC_GRV,    KC_LPRN,  KC_RPRN,  KC_PSLS,  KC_BSLS,  KC_F12,
                    _______, _______, _______, _______,       KC_BTN2,   _______,  MOUSE,    _______
),  

// ============================================================
// Layer 2 - LOWER
// ============================================================
// Pointing Device Scroll Layer
[_LOWER] = LAYOUT_ffkb(
  _______, KC_MYCM, _______,  REDO,    _______, _______,      _______,            KC_HOME,       KC_UP,    KC_END,       _______, KC_DEL,
  _______, KC_CAPS, KC_CUT,   KC_COPY, KC_PSTE, _______,      FP_SUPER_CTRL_TAB,  KC_LEFT,       KC_DOWN,  KC_RGHT,      _______, _______,
  _______, _______, _______,  KC_UNDO, _______, _______,      _______,            LCTL(KC_BSPC), _______,  LCTL(KC_DEL), _______, _______,
                    KC_RALT,  MOUSE,   _______, _______,      _______,            _______,       _______,  _______
),

// ============================================================
// Layer 3 - Mouse-Num
// ============================================================
[_MOUSE_NUM] =  LAYOUT_ffkb(
  _______, KC_MYCM, _______,       KC_HASH, _______, _______,         KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, _______,
  _______, KC_CAPS, FP_SCROLL_TOG, KC_BTN1, KC_BTN2, _______,         KC_CALC,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  _______, _______, _______,       _______, _______, _______,         KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PEQL, KC_PMNS,
                    QK_RBT,        GAME,    _______, _______,         KC_PDOT,  _______, COLDH,   COLDH
),

// ============================================================
// Layer 4 - Game
// ============================================================
[_GAME] = LAYOUT_ffkb(
  _______, KC_MYCM, _______,       KC_HASH, _______, _______,         KC_NUM,   KC_P7,          KC_P8,   KC_P9, KC_PSLS, _______,
  _______, KC_CAPS, FP_SCROLL_TOG, KC_BTN1, KC_BTN2, _______,         KC_CALC,  KC_P4,          KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  _______, _______, _______,       _______, _______, _______,         KC_P0,    KC_P1,          KC_P2,   KC_P3, KC_PEQL, KC_PMNS,
                    _______,       QWERTY,  KC_SPC,  LOWER,           _______,  LALT_T(KC_ENT), COLDH,   COLDH
),

// ============================================================
// Layer 5 - QWERTY
// ============================================================
[_QWERTY] = LAYOUT_ffkb(
  _______,  KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
  _______,  KC_A,   KC_S,     KC_D,   KC_F,     KC_G,         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
  _______,  KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,         KC_N,     KC_M,     _______,  _______,  _______,  _______,
                    _______,  RAISE,  _______,  _______,      _______,  _______,  LOWER,    COLDH
)
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _RAISE, _LOWER, _MOUSE_NUM);
// }

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
        tap_code16(C(FP_SUPER_TAB));
      }
      else{
        tap_code16(C(LSFT_T(FP_SUPER_TAB)));
      }
    }

    return true;
}
#endif
