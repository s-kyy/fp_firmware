ifeq ($(strip $(FP_CONVERT_TO)), "svlinky")
   VIK_ENABLE = yes
   OPT_DEFS += -DFP_CONVERT_TO_SVLINKY
   ## Uncomment these two lines for svlinky
   MCU := RP2040
   BOOTLOADER := rp2040
else
   MCU := atmega32u4
   BOOTLOADER := atmel-dfu
endif

# $(info $(MCU))
# $(info $(BOOTLOADER))

PIN_COMPATIBLE=elite_c

include keyboards/fingerpunch/src/rules.mk