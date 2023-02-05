/* @author Samantha Yuen 
 * 
 */

#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK, //0
    _QWERTY,  //1
    _GAME,    //2
    _RAISE,   //3
    _LOWER,   //4
    _RGB_NUM, //5
    _LAYER6,  //6
    _LAYER7,  //7
    _LAYER8   //8
};

//custom keycodes
#define COLDH TO(_COLEMAK)
#define QWERTY TO(_QWERTY)
#define GAME  TO(_GAME)
#define RAISE MO(_RAISE)
#define MRAISE LT(_RAISE,KC_BTN1)
#define LOWER MO(_LOWER)
#define RGB_NUM TO(_RGB_NUM)
// #define REDO LCTL(KC_Y)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define WPAST G(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)
#define SFTT LSFT_T(KC_TAB) //Tab-tap Shift-hold
#define SPSFT LSFT_T(KC_SPC) //Space-tap Shift-hold
#define SFTE LSFT_T(KC_ENT) //Enter-tap Shift-hold
#define LDESK G(C(KC_LEFT)) 
#define RDESK G(C(KC_RIGHT))
#define EXITPARSEC C(A(KC_TILD))
#define TASKMAN C(A(KC_DEL))
#define MBEE C(S(A(KC_BSLS)))
#define MBEEL C(S(KC_LBRC))
#define MBEER C(S(KC_RBRC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ============================================================
// Layer 0 - Colemak-DH
// ============================================================
[_COLEMAK] = LAYOUT_ffkb(
  KC_ESC,         KC_Q,     KC_W,     KC_F,   KC_P,   KC_B,     KC_J,   KC_L,   KC_U,     KC_Y,     KC_SCLN,    KC_BSPC,
  OSM(MOD_LCTL),  KC_A,     KC_R,     KC_S,   KC_T,   KC_G,     KC_M,   KC_N,   KC_E,     KC_I,     KC_O,       KC_QUOT,
  KC_LWIN,        KC_Z,     KC_X,     KC_C,   KC_D,   KC_V,     KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_APP,
                            KC_MUTE,  KC_BTN1,  SFTE, MRAISE,   LOWER,  SPSFT, MT(MOD_LALT,KC_TAB),    KC_RALT
),

// ============================================================
// Layer 1 - QWERTY
// ============================================================
[_QWERTY] = LAYOUT_ffkb(
  _______, KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
  _______, KC_A,   KC_S,     KC_D,   KC_F,     KC_G,        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
  _______, KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,        KC_N,     KC_M,     _______,  _______,  _______,  _______,
                   _______,  _______,_______,  _______,     _______,  _______,  _______,  _______
),

// ============================================================
// Layer 2 - Game
// ============================================================
[_GAME] = LAYOUT_ffkb(
  _______, _______, KC_1, KC_2, KC_3, KC_4,          KC_5,     KC_6,    KC_7,     KC_8,    KC_9,     _______,
  KC_TAB,  KC_T,    KC_Q, KC_W, KC_E, KC_R,          KC_BTN1,  KC_Y,    KC_B,     _______, _______,  COLDH,
  KC_LSFT, KC_V,    KC_A, KC_S, KC_D, KC_F,          KC_LSFT,  KC_M,    _______,  _______, _______,  QWERTY,
           _______, _______, KC_SPC,  _______,       _______, LALT_T(KC_ENT),  KC_LWIN,  EXITPARSEC 
),

// ============================================================
// Layer 3 - RAISE
// ============================================================
[_RAISE] = LAYOUT_ffkb(
  KC_SLEP,        _______,     MBEEL,  UNDO,    WPAST,   MBEER,          TASKMAN,   KC_MYCM,  C(KC_MINS),  C(KC_PLUS),   KC_INS,   KC_DEL,  
  OSM(MOD_LCTL),  KC_CALC,     CUT,    COPY,    PASTE,   MBEE,           KC_TILD,   KC_LBRC,  KC_RBRC,     KC_UNDS,      KC_AT,  KC_CAPS,  
  OSM(MOD_LSFT),  _______,     LDESK,  REDO,    RDESK,   KC_INS,         KC_GRV,    KC_LPRN,  KC_RPRN,     KC_HASH,      KC_PERC,  KC_CIRC,
                  _______,     _______, _______, _______,                RGB_NUM,   SFTE,     KC_BTN2,     KC_RALT
),  

// ============================================================
// Layer 4 - LOWER
// ============================================================
[_LOWER] = LAYOUT_ffkb(
  KC_ESC,         KC_PSLS,     KC_7,  KC_8,    KC_9,   KC_PAST,        KC_NUM,            KC_HOME,       KC_UP,              KC_END,      KC_BRIU,        KC_DEL,
  OSM(MOD_LCTL),  KC_DOT,      KC_4,  KC_5,    KC_6,   KC_EQL,         FP_SCROLL_MOMENT,  KC_LEFT,       KC_DOWN,            KC_RGHT,     OSM(MOD_LALT),  KC_PGUP,
  OSM(MOD_LSFT),  KC_0,        KC_1,  KC_2,    KC_3,   KC_MINS,        FP_SNIPE_MOMENT,   C(KC_LEFT),    FP_SUPER_CTRL_TAB,  C(KC_RIGHT), KC_BRID,        KC_PGDN,
                  KC_RALT,            KC_BTN2, SFTE,   RGB_NUM,        _______,  _______,  _______,  _______
),

// ============================================================
// Layer 5 - RGB-Num
// ============================================================
[_RGB_NUM] =  LAYOUT_ffkb(
  _______,       RGB_TOG, RGB_MOD,  RGB_RMOD, _______, COLDH,      KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_BSPC,
  OSM(MOD_LCTL), RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI,  QWERTY,     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
  OSM(MOD_LSFT), RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD,  GAME,       KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15, _______,
                 QK_BOOT, FP_SNIPE_MOMENT, SPSFT, KC_BTN1,         KC_BTN2,  FP_SCROLL_MOMENT, MT(MOD_LALT,KC_TAB),   EE_CLR
),

// ============================================================
// Empty Layers
// ============================================================
[_LAYER6] = LAYOUT_ffkb(
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
                    _______, _______, _______, _______,         _______,  _______,  _______,  _______
),

[_LAYER7] = LAYOUT_ffkb(
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,         _______,  _______,  _______,  _______, _______, _______,
                    _______, _______, _______, _______,         _______,  _______,  _______,  _______
),

[_LAYER8] = LAYOUT_ffkb(
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
        // tap_code16(FP_SUPER_TAB);
        // tap_code16(KC_TAB);
        // tap_code16(KC_PGUP);
        press_super_tab(false);
      }
      else{
        // tap_code16(LSFT_T(FP_SUPER_TAB));
        // tap_code16(LSFT_T(KC_TAB));
        // tap_code16(KC_PGDN);
        press_super_tab(true);
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
        RGB_MATRIX_INDICATOR_SET_COLOR(40, 242, 242, 0); // CAPSLOCK ON | yellow / MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(40, 0, 0, 0); // CAPSLOCK OFF | BLANK
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