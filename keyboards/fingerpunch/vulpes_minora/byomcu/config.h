/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

// For SPI
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

// wiring of each half
#define MATRIX_ROW_PINS { GP4, GP29, GP28, GP27 }
#define MATRIX_COL_PINS { GP5, GP6, GP7, GP8, GP9 }

// https://github.com/sadekbaroudi/vik/tree/master/pcb/pers60-cirque-leds or https://github.com/sadekbaroudi/vik/tree/master/pcb/pers60-pmw3360-leds
#ifdef FP_VIK_PERS60_MODULE
#define ENCODERS_PAD_A { GP14, GP3 }
#define ENCODERS_PAD_B { GP13, GP2 }
#define ENCODER_RESOLUTIONS { 2, 1 }
#define ENCODERS_PAD_A_RIGHT { GP14 }
#define ENCODERS_PAD_B_RIGHT { GP13 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }
// Switch the default for the PERS60 rotary encoder to scrolling
#define FP_ENC_1_LAYER_SCROLL_WHEEL 0
#define FP_ENC_1_LAYER_SUPER_TAB 5
#else
#define ENCODERS_PAD_A { GP14 }
#define ENCODERS_PAD_B { GP13 }
#define ENCODERS_PAD_A_RIGHT { GP14 }
#define ENCODERS_PAD_B_RIGHT { GP13 }
#endif

// Got help from https://www.eisbahn.jp/yoichiro/2022/08/luankey_pico_qmk_firmware.html
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_TX_PIN GP1     // USART TX pin

#define RGB_DI_PIN GP0

#ifdef AUDIO_ENABLE
    #define AUDIO_VOICES
    #define AUDIO_PIN GP12
    #define AUDIO_PWM_DRIVER PWMD6
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #define AUDIO_ENABLE_TONE_MULTIPLEXING
    #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
    #define FP_AUDIO_MOUSE_BUTTONS
    #define FP_AUDIO_CUT_COPY_PASTE
    #define FP_AUDIO_SAVE
    #define FP_STARTUP_DARK  HALF_DOT_NOTE(_B5), QUARTER_NOTE(_B5), HALF_NOTE(_E6), HALF_NOTE(_REST), QUARTER_NOTE(_C6), QUARTER_NOTE(_REST), QUARTER_NOTE(_G5), QUARTER_NOTE(_E5), QUARTER_NOTE(_F5), QUARTER_NOTE(_GS5), QUARTER_NOTE(_G5), QUARTER_NOTE(_F5), WHOLE_NOTE(_G5),
    #define STARTUP_SONG SONG(FP_STARTUP_DARK)
    #define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#ifdef CIRQUE_ENABLE
    // cirque trackpad config
    #define CIRQUE_PINNACLE_SPI_CS_PIN GP21
    // Uncomment 2 lines below to switch to relative mode and enable right click
    // Note that tap to click doesn't work on the slave side unless you enable relative mode
    // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_TASK_THROTTLE_MS 5
    #define POINTING_DEVICE_LEFT
#endif

#ifdef FP_TRACKBALL_ENABLE
    // Trackball config
    #define PMW33XX_CS_PIN GP21
    #define PMW33XX_CPI 1000
    #define PMW33XX_CS_DIVISOR 8

    /* SPI config for pmw3360 sensor. */
    #define SPI_DRIVER SPID0
    // #define SPI_SCK_PAL_MODE 5 // already defined in chibios
    // #define SPI_MOSI_PAL_MODE 5 // already defined in chibios
    // #define SPI_MISO_PAL_MODE 5 // already defined in chibios
    #define POINTING_DEVICE_LEFT
#endif
