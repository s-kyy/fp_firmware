/* Copyright 2023 Samantha Yuen <samantha.y.twentyfourteen@gmail.com>

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

// =============================================
// Key config
// =============================================
#define FP_SUPER_TAB_TIMEOUT 500 // 500 default 
#define FP_SUPER_CTRL_TAB_TIMEOUT 500 // 750 default
// #define ENCODER_RESOLUTION 4 //input commands more than once.
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 3000
#define TAPPING_TOGGLE 3 // into mouse layer

// Home Row Mods
// #define TAPPING_TERM 230
// #define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
#define USB_SUSPEND_WAKEUP_DELAY 3000
// #define COMBO_COUNT 1 // DONE automatically
#define COMBO_TERM 40 //40 default
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 140 //150 default
#define COMBO_ONLY_FROM_LAYER 0

// =============================================
// Trackball config
// =============================================
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 6
#define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY 3 //3 default
//     //if mouse moves while typing: 
//     // Higher = mouse needs to move more to trigger mouse layeros
// #define MOUSE_EXTENDED_REPORT
    //Mouse trackball acceleration
    // #define FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE
// #define FP_POINTING_DEFAULT_DPI 750 //1000 set to general v3 config file in increments of 100
#define FP_POINTING_SCROLLING_DPI 1
    // Dareu LM108 = 1000/1600
// #define FP_POINTING_LAYER_ENABLE 
// #define FP_POINTING_ZOOM_LAYER 2 // 
// #define FP_POINTING_SCROLLING_LAYER_ENABLE
// #define FP_POINTING_SCROLLING_LAYER 6 //INACCESSIBLE
// #define FP_POINTING_SNIPING_LAYER_ENABLE
// #define FP_POINTING_SNIPING_LAYER 8 //INACCESSIBLE
// #define FP_POINTING_SNIPING_DPI 50 
// =============================================
// RGB config
// =============================================
#ifdef RGB_MATRIX_ENABLE //udate vial.json if using it. 
    #define FP_STARTUP_ANIMATION_DISABLE
    #define FP_LAYER_LIGHT_MODE RGB_MATRIX_ALPHAS_MODS
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_DEFAULT_SPD 55
    #define FP_LAYER_LIGHTING_AUTO_MOUSE_HUE HSV_BLACK
    #define FP_LAYER_LIGHTING_AUTO_MOUSE_MODE RGB_MATRIX_PIXEL_RAIN

    // #define DISABLE_RGB_MATRIX_BREATHING
    #define DISABLE_RGB_MATRIX_BAND_SA
    #define DISABLE_RGB_MATRIX_BAND_VAL
    // #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    // #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define DISABLE_RGB_MATRIX_CYCLE_ALL
    #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define DISABLE_RGB_MATRIX_DUAL_BEACON
    #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    // #define DISABLE_RGB_MATRIX_RAINDROPS
    // #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    // #define DISABLE_RGB_MATRIX_SPLASH
    // #define DISABLE_RGB_MATRIX_MULTISPLASH
    // #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    // #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

    #define FP_LAYER_LIGHTING_HUE_0 HSV_ORANGE
    // #define FP_LAYER_LIGHTING_HUE_1 HSV_WHITE    
    #define FP_LAYER_LIGHTING_HUE_2 FP_HSV_MELON 
    #define FP_LAYER_LIGHTING_HUE_3 HSV_GOLDENROD
    #define FP_LAYER_LIGHTING_HUE_4 FP_HSV_LAVENDER
    #define FP_LAYER_LIGHTING_HUE_5 HSV_CORAL
    // #define FP_LAYER_LIGHTING_HUE_6 HSV_LEMON
    // #define FP_LAYER_LIGHTING_HUE_7 FP_HSV_LAVENDER
    // #define FP_LAYER_LIGHTING_MODE_0 RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  
    // #define FP_LAYER_LIGHTING_MODE_0 RGB_MATRIX_SOLID_COLOR
    #define FP_LAYER_LIGHTING_MODE_0 RGB_MATRIX_BREATHING
    #define FP_LAYER_LIGHTING_MODE_1 RGB_MATRIX_JELLYBEAN_RAINDROPS
    // #define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_BAND_PINWHEEL_VAL
    #define FP_LAYER_LIGHTING_MODE_3 RGB_MATRIX_BAND_PINWHEEL_SAT
    #define FP_LAYER_LIGHTING_MODE_4 RGB_MATRIX_BAND_PINWHEEL_VAL
    #define FP_LAYER_LIGHTING_MODE_5 RGB_MATRIX_BAND_PINWHEEL_SAT
    #define FP_LAYER_LIGHTING_MODE_6 RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define FP_LAYER_LIGHTING_CAPS_LOCK_HUE FP_HSV_PEACH_ORANGE
    #define FP_LAYER_LIGHTING_CAPS_LOCK_MODE RGB_MATRIX_PIXEL_RAIN
#endif
