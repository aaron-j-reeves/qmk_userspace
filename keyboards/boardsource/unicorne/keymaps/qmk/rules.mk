# rules.mk
SRC += oled.c
SRC += layers.c
BOOTLOADER = rp2040

########################################################
#  enable one or the other, NOT BOTH

# enables cirque 40mm touchpad (right side) support
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c

# enables analog joystick support
# POINTING_DEVICE_DRIVER = analog_joystick

########################################################

# uncomment to use --env option with qmk compile
# $(info *** Value of SECURE in rules.mk: '$(SECURE)' ***)
# CFLAGS += -DSECURE=\"$(SECURE)\"
