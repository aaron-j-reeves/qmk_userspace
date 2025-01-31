# rules.mk
SRC += oled.c
SRC += layers.c

########################################################
#  enable one or the other, NOT BOTH

# enables cirque 40mm touchpad (right side) support
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c

# enables analog joystick support
# POINTING_DEVICE_DRIVER = ANALOG_JOYSTICK

########################################################

CFLAGS += -DSECURE_MACRO="\"$(SECURE_MACRO_VALUE)\""