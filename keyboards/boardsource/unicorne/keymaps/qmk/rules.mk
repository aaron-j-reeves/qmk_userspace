# rules.mk
SRC += oled.c
SRC += layers.c
SRC += combos.c

########################################################
#  enable one or the other, NOT BOTH

# enables cirque 40mm touchpad (right side) support
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c

# enables analog joystick support
# POINTING_DEVICE_DRIVER = ANALOG_JOYSTICK

########################################################

# This takes the SECURE environment variable (provided by GitHub Actions) and passes it to the compiler so it can be used as a #define during compilation.
CFLAGS += -DSECURE_MACRO="\"$(SECURE)\""

CAPS_WORD_ENABLE = yes
LAYER_LOCK_ENABLE = yes
COMMAND_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
SEND_STRING_ENABLE = yes