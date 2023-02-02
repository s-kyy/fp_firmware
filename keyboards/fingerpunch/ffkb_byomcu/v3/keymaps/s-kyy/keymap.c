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
    _COLEMAK, //0
    _QWERTY,  //1
    _GAME,    //2
    _RAISE,   //3
    _LOWER,   //4
    _RGB_NUM, //5
    _LAYER6,  //6
    _LAYER7,  //7
    _LAYER8,  //8
};

//custom keycodes
#define COLDH TO(_COLEMAK)
#define QWERTY TO(_QWERTY)
#define GAME  TO(_GAME)
#define RAISE MO(_RAISE)
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
  KC_ESC,         KC_Q,     KC_W,     KC_F,   KC_P,   KC_B,       KC_J,   KC_L,   KC_U,     KC_Y,     KC_SCLN,    KC_BSPC,
  OSM(MOD_LCTL),  KC_A,     KC_R,     KC_S,   KC_T,   KC_G,       KC_M,   KC_N,   KC_E,     KC_I,     KC_O,       KC_QUOT,
  KC_LWIN,        KC_Z,     KC_X,     KC_C,   KC_D,   KC_V,       KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_APP,
                            KC_MUTE,  KC_BTN1,  SFTE, RAISE,      LOWER,  SPSFT, MT(MOD_LALT,KC_TAB),    KC_RALT
),

// ============================================================
// Layer 1 - QWERTY
// ============================================================
[_QWERTY] = LAYOUT_ffkb(
  _______, KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
  _______, KC_A,   KC_S,     KC_D,   KC_F,     KC_G,         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
  _______, KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,         KC_N,     KC_M,     _______,  _______,  _______,  _______,
                   _______,  _______,_______,  _______,      _______,  _______,  _______,  _______
),

// ============================================================
// Layer 2 - Game
// ============================================================
[_GAME] = LAYOUT_ffkb(
  _______, _______, KC_1, KC_2, KC_3, KC_4,                 KC_5,  KC_6,    KC_7,     KC_8,    KC_9,     _______,
  KC_TAB,  KC_BTN1, KC_Q, KC_W, KC_E, KC_R,                 KC_Y,  KC_M,    KC_WH_U,  _______, _______,  COLDH,
  KC_LSFT, KC_V,    KC_A, KC_S, KC_D, KC_F,                 KC_C,  KC_WH_L, KC_WH_D,  KC_WH_R, _______,  QWERTY,
           _______, _______, KC_SPC,  _______,              _______, LALT_T(KC_ENT),  KC_LWIN,  EXITPARSEC 
),

// ============================================================
// Layer 3 - RAISE
// ============================================================
// Pointing Device Zoom Layer
[_RAISE] = LAYOUT_ffkb(
  KC_SLEP, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  
  KC_F11,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          KC_TILD,   KC_LBRC,  KC_RBRC,  KC_MINS,  KC_PLUS,  KC_UNDS,
  KC_F12,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,          KC_GRV,    KC_LPRN,  KC_RPRN,  KC_PSLS,  KC_BSLS,  KC_EQL,
                    _______, _______, _______, _______,      RGB_NUM,   SFTE,     KC_BTN2,    KC_RALT
),  


// ============================================================
// Layer 4 - LOWER
// ============================================================
// Pointing Device Scroll Layer
[_LOWER] = LAYOUT_ffkb(
  KC_ESC,        KC_MYCM,       TASKMAN,     UNDO,    WPAST,     _______,         C(KC_MINS),  KC_HOME,       KC_UP,              KC_END,      KC_BRIU,  KC_DEL,
  OSM(MOD_LCTL), OSM(MOD_LSFT), CUT,         COPY,    PASTE,     _______,          C(KC_PLUS),  KC_LEFT,       KC_DOWN,            KC_RGHT,     KC_LALT,  KC_PGUP,
  KC_LWIN,       KC_CAPS,      LDESK,       REDO,    RDESK,      _______,            _______,     C(KC_LEFT),    FP_SUPER_CTRL_TAB,  C(KC_RIGHT),  KC_BRID,  KC_PGDN,
                                KC_RALT,     KC_BTN1, SFTE,      RGB_NUM,              _______,     _______,       _______,     _______
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
// Generate Perfect Per-key RGB effects: see v3.c
// QMK RGB Tutorial: https://github.com/sadekbaroudi/keyboard-guides/blob/master/firmware/qmk/RGB_MATRIX.md
// RGB CODES: https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch#layer-lighting
// ============================================================
// #ifdef RGB_MATRIX_ENABLE
// led_config_t g_led_config = { {
//     { 2,   8,  14, 9, 15, 26, 27, 3   },
//     { 1,   7,  13, 10, 16, 25, 28, 4   },
//     { 0,   6,  12, 11, 17, 24, 29, 5   },
//     { NO_LED, 31,  33, 35, 37, 36, 39, NO_LED },
//     { NO_LED, 30,  34, 32, 38, 41, 40, NO_LED },
//     { NO_LED,   23,  19, 18, 20, 21, 22, NO_LED }
// }, {
//     {0,32},{3,19},{7,5},{25,4},{21,18},{17,31},{35,26},{39,12},{43,0},{60,0},{56,12},{52,26},
//     {66,33},{70,20},{74,6},{89,12},{85,25},{81,38},{61,50},{77,55},{93,63},{129,63},{145,55},{161,50},
//     {141,38},{137,25},{133,12},{148,6},{152,20},{156,33},{170,26},{166,12},{162,0},{179,0},{183,12},{187,26},
//     {205,31},{201,18},{197,4},{215,5},{219,19},{223,32}
// }, {
//     1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 1, 1, 1
// } };
// #endif

// Per-key RGB Per Layer
// void rgb_matrix_indicators_user(void) {
//   uint8_t layer = biton32(layer_state);
//     switch (layer) {

//       case 0: //_COLEMAK
//         // rgb_matrix_set_color_all(0, 0, 255); //Light up all the keys in blue
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//           rgb_matrix_set_color(2, 250, 100, 0); //  ESC | orange
//           rgb_matrix_set_color(1, 3, 200, 0); //    CTRL | yosemite green
//           rgb_matrix_set_color(0, 255, 0, 0); //    SFTT | red

//           rgb_matrix_set_color(3, 7, 145, 95); //   Q | teal, aurora borealis
//           rgb_matrix_set_color(4, 7, 145, 95); //   A| teal, aurora borealis
//           rgb_matrix_set_color(5, 7, 145, 95); //   Z| teal, aurora borealis

//           rgb_matrix_set_color(8, 7, 145, 95); //   W| teal, aurora borealis
//           rgb_matrix_set_color(7, 7, 145, 95); //   R| teal, aurora borealis
//           rgb_matrix_set_color(6, 7, 145, 95); //   X| teal, aurora borealis

//           rgb_matrix_set_color(9, 7, 145, 95); //   F| teal, aurora borealis
//           rgb_matrix_set_color(10, 7, 145, 95); //   S| teal, aurora borealis
//           rgb_matrix_set_color(11), 7, 145, 95); //   C| teal, aurora borealis

//           rgb_matrix_set_color(14, 7, 145, 95); //   P| teal, aurora borealis
//           rgb_matrix_set_color(13, 7, 145, 95); //   T| teal, aurora borealis
//           rgb_matrix_set_color(12, 7, 145, 95); //   D| teal, aurora borealis

//           rgb_matrix_set_color(15, 7, 145, 95); //   B| teal, aurora borealis
//           rgb_matrix_set_color(16, 7, 145, 95); //   G| teal, aurora borealis
//           rgb_matrix_set_color(17, 7, 145, 95); //   V| teal, aurora borealis


//           rgb_matrix_set_color(26, 7, 145, 95); //   J| teal, aurora borealis
//           rgb_matrix_set_color(25, 7, 145, 95); //   M| teal, aurora borealis
//           rgb_matrix_set_color(24, 7, 145, 95); //   K| teal, aurora borealis

//           rgb_matrix_set_color(3, 7, 145, 95); //   L| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   N| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   H| teal, aurora borealis

//           rgb_matrix_set_color(3, 7, 145, 95); //   U| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   E| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   ,| teal, aurora borealis

//           rgb_matrix_set_color(3, 7, 145, 95); //   Y| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   I| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   .| teal, aurora borealis

//           rgb_matrix_set_color(3, 7, 145, 95); //   ;| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   O| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   /| teal, aurora borealis

//           rgb_matrix_set_color(3, 7, 145, 95); //   BckSp | teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   "| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   App | teal, aurora borealis


//           rgb_matrix_set_color(3, 7, 145, 95); //   LFn1| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   LFn2| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   LFn3| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   RFn1| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   RFn2| teal, aurora borealis
//           rgb_matrix_set_color(3, 7, 145, 95); //   RFn3| teal, aurora borealis
          
//       break;

//       case 1:
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//       break;
      
//       case 2:
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//       break;

//       case 3:
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//       break;

//       case 4:
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//       break;

//       case 5:
//         rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
//       break;
//     }
// }

// Change RGB based on CAPSLOCK & NUMLOCK status
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#common-configuration-idcommon-configuration
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 242, 191, 180); // CAPSLOCK ON | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0); // CAPSLOCK OFF | BLANK
    }
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 242, 191, 180); // NUMLOCK ON | Reaper Master New Gold (9051) #e7bd42 https://encycolorpedia.com/e7bd42
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 242, 191, 180); // CALC | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(23, 242, 191, 180); // DOT | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(37, 242, 191, 180); // PLUS | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 242, 191, 180); // EQUALS | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 242, 191, 180); // TIMES | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 242, 191, 180); // MINUS | MCORRICK PAINTS CORAL #f2bfb4 https://encycolorpedia.com/f2bfb4
        
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
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0); // EQUALS 
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0); // TIMES 
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0); // MINUS 
        
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