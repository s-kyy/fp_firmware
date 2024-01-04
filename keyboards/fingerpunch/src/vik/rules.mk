# See https://github.com/sadekbaroudi/vik

# rules.mk options
# VIK_ENABLE
# VIK_HAPTIC
# VIK_PER56_CIRQUE_LEDS
# VIK_PER56_CIRQUE_LEDS
# VIK_PER56_PMW3360_LEDS
# VIK_PMW3360
# VIK_WEACT_ST7735
# VIK_VIK_GC9A01
# VIK_WAVESHARE_22224

ifeq ($(strip $(VIK_HAPTIC)), yes)
   HAPTIC_ENABLE = yes
   OPT_DEFS += -DVIK_HAPTIC
endif

ifeq ($(strip $(VIK_PER56_CIRQUE_LEDS)), yes)
   CIRQUE_ENABLE = yes
   ENCODER_ENABLE = yes
#    RGBLIGHT_ENABLE = yes # you need to choose whether or not this is enabled within the keyboard or user rules.mk
   OPT_DEFS += -DVIK_PER56_CIRQUE_LEDS
endif

ifeq ($(strip $(VIK_PER56_PMW3360_LEDS)), yes)
   PMW3360_ENABLE = yes
   ENCODER_ENABLE = yes
#    RGBLIGHT_ENABLE = yes # you need to choose whether or not this is enabled within the keyboard or user rules.mk
   OPT_DEFS += -DVIK_PER56_PMW3360_LEDS
endif

ifeq ($(strip $(VIK_PMW3360)), yes)
   PMW3360_ENABLE = yes
   OPT_DEFS += -DVIK_PMW3360
endif

ifeq ($(strip $(VIK_WEACT_ST7735)), yes)
   # For LCD backlight toggling
   BACKLIGHT_ENABLE = yes
   BACKLIGHT_DRIVER = software

   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += st7735_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/st7735.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_WEACT_ST7735
endif

ifeq ($(strip $(VIK_GC9A01)), yes)
   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += gc9a01_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/gc9a01.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_GC9A01
endif

ifeq ($(strip $(VIK_WAVESHARE_22224)), yes)
   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += st7789_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/waveshare_22224.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_WAVESHARE_22224
endif

ifeq ($(strip $(PMW3360_ENABLE)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := pmw3360
   QUANTUM_LIB_SRC += spi_master.c
   OPT_DEFS += -DVIK_TRACKBALL_ENABLE
endif

ifeq ($(strip $(QUANTUM_PAINTER_ENABLE)), yes)
   SRC += keyboards/fingerpunch/src/display/fp_display.c
endif