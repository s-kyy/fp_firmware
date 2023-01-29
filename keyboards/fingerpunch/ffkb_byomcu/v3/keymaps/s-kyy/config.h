// =============================================
// Key config
// =============================================
#define FP_SUPER_TAB_TIMEOUT 1000

// =============================================
// Trackball config
// =============================================
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 5
#define MOUSE_EXTENDED_REPORT
    //Mouse trackball acceleration
#define FP_POINTING_SCROLLING_DPI 50 
    // Dareu LM108 = 1000/1600
#define FP_POINTING_LAYER_ENABLE 
#define FP_POINTING_ZOOM_LAYER 1
#define FP_POINTING_SCROLLING_LAYER_ENABLE
#define FP_POINTING_SCROLLING_LAYER 2

// Default Settings
// #define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY 3 //default
//     //if mouse moves while typing: 
//     // Higher = mouse needs to move more to trigger mouse layer
// #define FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE
// #define FP_POINTING_DEFAULT_DPI 1000

// =============================================
// RGB config
// =============================================
#ifdef RGB_MATRIX_ENABLE //udate vial.json if using it. 
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_LED_COUNT 42
    // #define DISABLE_RGB_MATRIX_BREATHING
    // #define DISABLE_RGB_MATRIX_BAND_SAT
    // #define DISABLE_RGB_MATRIX_BAND_VAL
    // #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    // #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    // #define DISABLE_RGB_MATRIX_CYCLE_ALL
    // #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    // #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    // #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    // #define DISABLE_RGB_MATRIX_DUAL_BEACON
    // #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    // #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
    // #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    // #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
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
#endif



// =============================================
// Define macros & custom keycodes
// =============================================
// #    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
// #else
// #    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
// #endif

// enum userspace_custom_keycodes {
//     YOUR_KEYCODE_1 = PLACEHOLDER_SAFE_RANGE,
//     YOUR_KEYCODE_2,
// ...
//     NEW_SAFE_RANGE,
// }