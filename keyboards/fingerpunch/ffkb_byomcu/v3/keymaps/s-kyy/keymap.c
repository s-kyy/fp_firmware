/* @author Samantha Yuen 
 * 
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
    // _QWERTY,  //1
    _SYM,     //2
    _FN,      //3
    _NAV,     //4
    _RGB,     //5
    _MOUSE,  //6
    _LAYER7  //7
    // _LAYER8   
    // _GAME, //2
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

enum custom_keycodes {
  QMK_BEST = SAFE_RANGE,
  GITCOMM, 
  GITPUSH,
  R_ASSIGN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GITCOMM:
        if (record->event.pressed) {
          // when keycode is pressed
            SEND_STRING("git commit -m ''");
        } else {
          // when keycode is released
        }
        break;

    case GITPUSH:
        if (record->event.pressed) {
            SEND_STRING("git push -u origin ");
        } 
        break;
    case R_ASSIGN:
        if (record->event.pressed) {
            SEND_STRING("<- ");
        } 
        break;
    }
    return true;
};

// ============================================================
// Combos
// ============================================================
enum combos {
  // LEFT
  ZX_WIN,
  XC_ALT,
  CD_CTRL,
  ST_SFT,
  ZXCD_CTRL_ALT_SHIFT,

  // RIGHT
  HDOT_CTRL,
  CDOT_ALT,
  SDOT_WIN,
  NE_SFT,
  HCSDOT_CTRL_ALT_SHIFT,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; 

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM zxcd_combo[] = {KC_Z, KC_X, KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM hd_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM dc_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM hdcs_combo[] = {KC_H, KC_COMM, KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
  // LEFT
  [ZX_WIN] = COMBO(zx_combo, OSM(MOD_LGUI)),
  [XC_ALT] = COMBO(xc_combo, OSM(MOD_LALT)),
  [CD_CTRL] = COMBO(cd_combo, OSM(MOD_LCTL)),
  [ST_SFT] = COMBO(st_combo, OSM(MOD_LSFT)),
  [ZXCD_CTRL_ALT_SHIFT] = COMBO(zxcd_combo, OSM(MOD_MEH)),
  // RIGHT
  [HDOT_CTRL] = COMBO(hd_combo, OSM(MOD_RCTL)),
  [CDOT_ALT] = COMBO(dc_combo, OSM(MOD_LALT)),
  [SDOT_WIN] = COMBO(ds_combo, OSM(MOD_RGUI)),
  [NE_SFT] = COMBO(ne_combo, OSM(MOD_RSFT)),
  [HCSDOT_CTRL_ALT_SHIFT] = COMBO(hdcs_combo, OSM(MOD_MEH))
};



// ============================================================
// Keymap
// ============================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ============================================================
// Layer 0 - Colemak-DH
// ============================================================
[_COLEMAK] = LAYOUT_ffkb(
  FP_SCROLL_TOG,  KC_Q,     KC_W,        KC_F,     KC_P,    KC_B,                  KC_J,   KC_L,    KC_U,     KC_Y,     KC_SCLN,      KC_ESC,
  KC_MS_BTN1,     KC_A,     KC_R,        KC_S,     KC_T,    KC_G,                  KC_M,   KC_N,    KC_E,     KC_I,     KC_O,         KC_QUOT,
  KC_MS_BTN2,     KC_Z,     KC_X,        KC_C,     KC_D,    KC_V,                  KC_K,   KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,      KC_APP,
                  KC_MUTE,  TT(_MOUSE),  LT(_SYM, KC_ENT),   LT(_FN,KC_BSPC),      LT(_RGB,KC_TAB), LT(_NAV,KC_SPC),    KC_GRV, KC_RALT
),

// ============================================================
// Layer 1 - SYM
// ============================================================
[_SYM] = LAYOUT_ffkb(
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                   KC_CIRC,  KC_AMPR,               KC_ASTR,  KC_UNDS, KC_EQL,  KC_SLEP,
  _______, KC_PIPE, KC_LCBR, KC_LBRC, KC_PMNS, KC_LPRN,                  KC_RPRN,  KC_TILD,               KC_RBRC,  KC_RCBR, KC_EQUAL, KC_CAPS,
  _______, KC_INS, KC_DEL,  KC_PIPE, FP_SUPER_CTRL_TAB, LDESK,           RDESK,    S(FP_SUPER_CTRL_TAB),  KC_BSLS,  KC_DEL,  KC_INS,  FP_SNIPE_TOG,
                    _______, _______, _______, _______,                  KC_TAB,  KC_SPC,  _______,  EE_CLR
),

// ============================================================
// Layer 2 - FN
// ============================================================
[_FN] = LAYOUT_ffkb(
  KC_ESC,     TASKMAN,         KC_MYCM,  UNDO,    WPAST,   C(KC_PLUS),     KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_SLEP,
  _______,    MBEE,            CUT,      COPY,    PASTE,   C(KC_MINS),     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_CAPS,
  _______,    C(S(KC_V)),      MBEEL,    REDO,    MBEER,   C(KC_A),        KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15, FP_SNIPE_TOG,
                    _______,  _______, _______, _______,                KC_TAB, KC_SPC,  _______,  EE_CLR
),

// ============================================================
// Layer 3 - NAV
// ============================================================
[_NAV] = LAYOUT_ffkb(
  KC_ESC,   KC_PSLS,     KC_7,   KC_8,     KC_9,   KC_PMNS,     _______,        KC_HOME,      KC_UP,       KC_END,        _______,        KC_SLEP,
  KC_BSPC,  KC_PAST,     KC_4,   KC_5,     KC_6,   KC_PPLS,     C(A(KC_UP)),    KC_LEFT,      KC_DOWN,     KC_RGHT,       KC_LALT,        _______,
  _______,  KC_EQL,      KC_1,   KC_2,     KC_3,   KC_DOT,      C(A(KC_DOWN)),  C(KC_LEFT),   C(KC_BSPC),  C(KC_RIGHT),   C(KC_DEL),      _______,
                  QK_BOOT,     KC_SPC, KC_0,   KC_BSPC,        _______,     _______,      _______,  _______
),

// ============================================================
// Layer  4 - RGB
// ============================================================
[_RGB] =  LAYOUT_ffkb(
  KC_ESC,  RGB_TOG, RGB_MOD,  RGB_RMOD, _______,  _______,       _______,     S(KC_HOME),     S(KC_UP),    S(KC_END),       _______,       KC_SLEP,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,       KC_PGUP,     S(KC_LEFT),     S(KC_DOWN),  S(KC_RGHT),      KC_LALT,       _______,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD,  RGB_VAD,  EXITPARSEC,    KC_PGDN,     C(S(KC_LEFT)),  C(KC_BSPC),  C(S(KC_RIGHT)),  C(KC_DEL),     _______,
                QK_BOOT, _______,   KC_ENT,  KC_BSPC,           _______,  _______,  _______,  _______
),

// ============================================================
// Empty Layers
// ============================================================
[_MOUSE] = LAYOUT_ffkb(
  _______, _______, _______,    FP_SNIPE_TOG,   _______,    _______,    KC_NUM,   KC_BRID,  KC_BRIU,  _______, _______, _______,
  _______, KC_ESC, KC_MS_BTN2,  FP_SCROLL_TOG,  KC_MS_BTN1, _______,    KC_CALC,  GITCOMM,  GITPUSH,  R_ASSIGN, _______, _______,
  _______, _______, _______,    KC_WH_U,        KC_WH_D,    _______,    _______,  _______,  _______,  _______, _______, _______,
                    _______,    _______,    _______, _______,           _______,  _______,  _______,  _______
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
        tap_code16(KC_WH_U);
        // press_super_tab(false);
      }
      else{
        // tap_code16(LSFT_T(FP_SUPER_TAB));
        // tap_code16(LSFT_T(KC_TAB));
        // tap_code16(KC_PGDN);
        tap_code16(KC_WH_D);
        // press_super_tab(true);
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