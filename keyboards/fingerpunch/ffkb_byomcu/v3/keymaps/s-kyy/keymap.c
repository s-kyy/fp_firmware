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
    _SYM,     //2
    _FN,      //3
    _NAV,     //4
    _RGB,     //5
    _LAYER6,  //6
    _LAYER7  //7
    // _LAYER8   
    // _GAME, //2
};

//Layer mods
#define COLDH TO(_COLEMAK)
#define QWERTY TO(_QWERTY)
// #define GAME  TO(_GAME)
// #define SYM MO(_SYM)
// #define MSYM LT(_SYM,KC_BTN1)
// #define NAV LT(_NAV,KC_BSPC)
#define RGB TO(_RGB)
// #define SP_SYM LT()

// Basic custom keycodes
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define WPAST G(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)
// #define SFTT LSFT_T(KC_TAB) //Tab-tap Shift-hold
// #define SPSFT LSFT_T(KC_SPC) //Space-tap Shift-hold
// #define SFTE LSFT_T(KC_ENT) //Enter-tap Shift-hold
#define LDESK G(C(KC_LEFT)) 
#define RDESK G(C(KC_RIGHT))
#define EXITPARSEC C(A(KC_TILD))
#define TASKMAN C(A(KC_DEL))
#define MBEE C(S(A(KC_BSLS)))
#define MBEEL C(S(KC_LBRC))
#define MBEER C(S(KC_RBRC))

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_W LGUI_T(KC_W)
#define HOME_F LALT_T(KC_F)
#define HOME_T LSFT_T(KC_T)

#define HOME_E LALT_T(KC_E)
#define HOME_FS LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_U LALT_T(KC_U)
#define HOME_Y RGUI_T(KC_Y)
#define HOME_O RCTL_T(KC_O)

#define HOME_J RSFT_T(KC_J)
#define HOME_I LALT_T(KC_I)
#define HOME_OG RGUI_T(KC_O)
#define HOME_SCLN LSFT_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ============================================================
// Layer 0 - Colemak-DH
// ============================================================
[_COLEMAK] = LAYOUT_ffkb(
  FP_SCROLL_TOG,  KC_Q,     HOME_W,   HOME_F,   KC_P,    KC_B,                  KC_J,   KC_L,    HOME_U,   HOME_Y,   KC_SCLN,    KC_ESC,
  KC_MS_BTN1,     HOME_A,   KC_R,     KC_S,     HOME_T,  KC_G,                  KC_M,   HOME_N,  KC_E,     KC_I,     HOME_O,     KC_QUOT,
  KC_MS_BTN2,     KC_Z,     KC_X,     KC_C,     KC_D,    KC_V,                  KC_K,   KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,    KC_APP,
                  KC_MUTE,  KC_DEL,  LT(_SYM, KC_ENT),   LT(_FN,KC_TAB),        LT(_RGB,KC_BSPC), LT(_NAV,KC_SPC),  KC_GRV,     KC_RALT
),

// ============================================================
// Layer 1 - QWERTY
// ============================================================
[_QWERTY] = LAYOUT_ffkb(
  _______, KC_Q,     HOME_W,   HOME_E,   KC_R,     KC_T,        KC_Y,     KC_U,     HOME_I,     HOME_OG,  KC_P,       _______,
  _______, HOME_A,   KC_S,     KC_D,     HOME_FS,  KC_G,        KC_H,     HOME_J,   KC_K,       KC_L,     HOME_SCLN,  _______,
  _______, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     _______,    _______,  _______,    _______,
                   _______,  _______,   _______,  _______,      _______,  _______,  _______,  _______
),

// ============================================================
// Layer 2 - SYM
// ============================================================
[_SYM] = LAYOUT_ffkb(
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                   KC_CIRC,  KC_AMPR,               KC_ASTR,  KC_UNDS, KC_EQL, KC_SLEP,
  _______, KC_PMNS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK,                  KC_RABK,  KC_RPRN,               KC_RBRC,  KC_RCBR, KC_PPLS, KC_CAPS,
  _______, _______, _______, KC_PIPE, FP_SUPER_CTRL_TAB, LDESK,          RDESK,    S(FP_SUPER_CTRL_TAB),  KC_BSLS,  _______, _______, FP_SNIPE_TOG,
                    _______, _______, _______, _______,                  KC_BSPC,  KC_SPC,  KC_TILD,  EE_CLR
),

// ============================================================
// Layer 3 - FN
// ============================================================
[_FN] = LAYOUT_ffkb(
  KC_ESC, TASKMAN,  KC_MYCM,  UNDO,    WPAST,   C(KC_PLUS),     KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_SLEP,
  MBEER, KC_CALC,   CUT,      COPY,    PASTE,   C(KC_MINS),     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_CAPS,
  MBEEL, MBEE,      KC_BRID,  REDO,    KC_BRIU, KC_INS,         KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15, FP_SNIPE_TOG,
                    _______,  _______, _______, _______,        KC_BSPC, KC_SPC,  _______,  EE_CLR
),

// ============================================================
// Layer 4 - NAV
// ============================================================
[_NAV] = LAYOUT_ffkb(
  KC_ESC,   KC_PSLS,     KC_7,   KC_8,     KC_9,   KC_PMNS,     KC_HOME,     A(KC_UP),     KC_UP,       A(KC_DOWN),    KC_END,         KC_SLEP,
  KC_BSPC,  KC_PAST,     KC_4,   KC_5,     KC_6,   KC_PPLS,     KC_PGUP,     KC_LEFT,      KC_DOWN,     KC_RGHT,       OSM(MOD_LCTL),  OSM(MOD_LALT),
  _______,  KC_EQL,      KC_1,   KC_2,     KC_3,   KC_0,        KC_PGDN,     C(KC_LEFT),   C(KC_BSPC),  C(KC_RIGHT),   C(KC_DEL),      OSM(MOD_LSFT),
                  QK_BOOT,     KC_DOT, KC_SPC,   KC_TAB,        _______,     _______,      _______,  _______
),

// ============================================================
// Layer  5 - RGB
// ============================================================
[_RGB] =  LAYOUT_ffkb(
  KC_ESC,  RGB_TOG, RGB_MOD,  RGB_RMOD, _______,  COLDH,        S(KC_HOME),  C(A(KC_UP)),    S(KC_UP),    C(A(KC_DOWN)),   S(KC_END),     KC_SLEP,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI,  RGB_VAI,  QWERTY,       KC_PGUP,     S(KC_LEFT),     S(KC_DOWN),  S(KC_RGHT),      OSM(MOD_LCTL), OSM(MOD_LALT),
  _______, RGB_SPD, RGB_HUD,  RGB_SAD,  RGB_VAD,  EXITPARSEC,   KC_PGDN,     C(S(KC_LEFT)),  C(KC_BSPC),  C(S(KC_RIGHT)),  C(KC_DEL),     OSM(MOD_LSFT),
                QK_BOOT, _______,   KC_ENT,  KC_BSPC,                _______,  _______,  _______,  _______
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
// Mod-tap settings
// ============================================================
// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(1, KC_BSPC):
//             return true;
//         default:
//             return false;
//     }
// }

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