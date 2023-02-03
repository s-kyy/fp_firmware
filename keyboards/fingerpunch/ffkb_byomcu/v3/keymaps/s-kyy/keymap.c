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
  _______, _______, KC_1, KC_2, KC_3, KC_4,          KC_5,  KC_6,    KC_7,     KC_8,    KC_9,     _______,
  KC_TAB,  KC_BTN1, KC_Q, KC_W, KC_E, KC_R,          KC_Y,  KC_M,    KC_WH_U,  _______, _______,  COLDH,
  KC_LSFT, KC_V,    KC_A, KC_S, KC_D, KC_F,          KC_C,  KC_WH_L, KC_WH_D,  KC_WH_R, _______,  QWERTY,
           _______, _______, KC_SPC,  _______,       _______, LALT_T(KC_ENT),  KC_LWIN,  EXITPARSEC 
),

// ============================================================
// Layer 3 - RAISE
// ============================================================
[_RAISE] = LAYOUT_ffkb(
  KC_SLEP, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  
  KC_F11,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          KC_TILD,   KC_LBRC,  KC_RBRC,  KC_MINS,  KC_PLUS,  KC_UNDS,
  KC_F12,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,          KC_GRV,    KC_LPRN,  KC_RPRN,  KC_PSLS,  KC_BSLS,  KC_EQL,
                    _______, _______, _______, _______,      RGB_NUM,   SFTE,     KC_BTN2,    KC_RALT
),  


// ============================================================
// Layer 4 - LOWER
// ============================================================
[_LOWER] = LAYOUT_ffkb(
  KC_ESC,        KC_MYCM,       TASKMAN,     UNDO,    WPAST,     _______,           _______,           KC_HOME,       KC_UP,              KC_END,      KC_BRIU,  KC_DEL,
  OSM(MOD_LCTL), OSM(MOD_LSFT), CUT,         COPY,    PASTE,     C(KC_MINS),        FP_SCROLL_MOMENT,  KC_LEFT,       KC_DOWN,            KC_RGHT,     KC_LALT,  KC_PGUP,
  KC_LWIN,       KC_CAPS,      LDESK,       REDO,     RDESK,     C(KC_PLUS),        FP_SNIPE_MOMENT,   C(KC_LEFT),    FP_SUPER_CTRL_TAB,  C(KC_RIGHT),  KC_BRID,  KC_PGDN,
                                KC_RALT,     KC_BTN1, SFTE,      RGB_NUM,           _______,           _______,       _______,     _______
),

// ============================================================
// Layer 5 - RGB-Num
// ============================================================
[_RGB_NUM] =  LAYOUT_ffkb(
  _______, RGB_TOG, RGB_MOD,  RGB_RMOD, _______,DF(_COLEMAK),    KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_BSPC,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, DF(_QWERTY),     KC_CALC,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, DF(_GAME),       KC_P0,    KC_P1,   KC_P2,   KC_P3, SFTE, KC_PMNS,
                    QK_BOOT, _______, SPSFT, TO(_QWERTY),        TO(_COLEMAK),  TO(_GAME), KC_PDOT,   EE_CLR
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
// Pointing Device SNIPING LAYER
// Pointing Device Zooming Layer 
// Pointing Device Scroll Layer
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
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 242, 242, 0); // CAPSLOCK ON | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0); // CAPSLOCK OFF | BLANK
    }
    if (host_keyboard_led_state().num_lock) {
        // RGB_MATRIX_INDICATOR_SET_COLOR(26, 242, 191, 180); // NUMLOCK ON | Reaper Master New Gold (9051) #e7bd42 https://encycolorpedia.com/e7bd42
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 242, 242, 0); // NUMLOCK ON | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 242, 242, 0); // CALC | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(23, 242, 242, 0); // DOT | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(37, 242, 242, 0); // PLUS | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(36, 242, 242, 0); // EQUALS | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(40, 242, 242, 0); // TIMES | yellow
        RGB_MATRIX_INDICATOR_SET_COLOR(38, 242, 242, 0); // MINUS | yellow
        
        RGB_MATRIX_INDICATOR_SET_COLOR(24, 252, 252, 252); // 0 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 252, 252, 252); // 1 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(30, 252, 252, 252); // 2 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(35, 252, 252, 252); // 3 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(28, 252, 252, 252); // 4 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(31, 252, 252, 252); // 5 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(34, 252, 252, 252); // 6 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(27, 252, 252, 252); // 7 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(32, 252, 252, 252); // 8 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(33, 252, 252, 252); // 9 | WHITE
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 0, 0, 0); // NUMLOCK OFF | BLANK
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 0, 0, 0); // CALC 
        RGB_MATRIX_INDICATOR_SET_COLOR(23, 0, 0, 0); // DOT 
        RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 0); // PLUS 
        RGB_MATRIX_INDICATOR_SET_COLOR(36, 0, 0, 0); // EQUALS 
        RGB_MATRIX_INDICATOR_SET_COLOR(40, 0, 0, 0); // TIMES 
        RGB_MATRIX_INDICATOR_SET_COLOR(38, 0, 0, 0); // MINUS 
        
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 0, 0, 0); // 1 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(24, 0, 0, 0); // 0 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, 0, 0); // 2 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(35, 0, 0, 0); // 3 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(28, 0, 0, 0); // 4 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(31, 0, 0, 0); // 5 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(34, 0, 0, 0); // 6 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(27, 0, 0, 0); // 7 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(32, 0, 0, 0); // 8 | WHITE
        RGB_MATRIX_INDICATOR_SET_COLOR(33, 0, 0, 0); // 9 | WHITE
    }

    return false;
}