// config.h
#pragma once

#include "config_joystick.h" // joystick configurations
#include "config_mousekey.h" // mousekey configurations
#include "config_touchpad.h" // cirque touchpad configurations

#define SPLIT_POINTING_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP22
#define I2C1_SCL_PIN GP23
