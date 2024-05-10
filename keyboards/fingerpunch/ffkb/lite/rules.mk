# If using svlinky, uncomment the first 2 lines, comment the "Other" MCU and BOOTLOADER and use FP_CONVERT_TO=svlinky

# svlinky
# MCU = RP2040
# BOOTLOADER = rp2040
# WS2812_DRIVER = vendor

# Other
MCU = atmega32u4
BOOTLOADER = atmel-dfu

ifeq ($(strip $(FP_CONVERT_TO)), svlinky)
   VIK_ENABLE = yes
   OPT_DEFS += -DFP_CONVERT_TO_SVLINKY
endif

# $(info $(MCU))
# $(info $(BOOTLOADER))

PIN_COMPATIBLE=elite_c

include keyboards/fingerpunch/src/rules.mk