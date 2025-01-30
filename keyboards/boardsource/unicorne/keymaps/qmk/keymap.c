// keymap.c
#include QMK_KEYBOARD_H
#include "song_list.h"
#include "layers.h"
#include "combos.h"

// Enum for custom keycodes
enum custom_keycodes {
    SECURE_MACRO = SAFE_RANGE,
};
// Use the SECURE_MACRO_VALUE compilation flag or a default value
#ifndef SECURE_MACRO_VALUE
#define SECURE_MACRO_VALUE "Default Value"
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

  //////////////////////////////////////////////////////////////
 /////////// LAYER LIGHTS + SOUND + CAPS LOCK INDICATOR ///////
//////////////////////////////////////////////////////////////

// Define Caps Lock LED index
#define CAPS_LOCK_LED 26

// Define the sounds
float caps_on[][2]  = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);

bool is_caps_active(void) {
    return host_keyboard_led_state().caps_lock || is_caps_word_on();
}

void update_caps_state(void) {
    static bool caps_state = false;
    bool new_caps_state = is_caps_active();

    if (new_caps_state != caps_state) {
        caps_state = new_caps_state;

        // Play sounds when Caps Lock or Caps Word state changes
        if (caps_state) {
            // Caps Lock or Caps Word was just turned on
            PLAY_SONG(caps_on);
        } else {
            // Caps Lock and Caps Word were just turned off
            PLAY_SONG(caps_off);
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static bool last_caps_state = false; // Track the previous Caps state

    // Check the current Caps state
    bool current_caps_state = is_caps_active();

    // If the state has changed, call update_caps_state
    if (current_caps_state != last_caps_state) {
        update_caps_state();
        last_caps_state = current_caps_state;
    }

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    // Set base colors based on the active layer
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (layer) {
            case 9:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case 8:
                rgb_matrix_set_color(i, RGB_PINK);
                break;
            case 7:
                rgb_matrix_set_color(i, RGB_WHITE);
                break;
            case 6:
                rgb_matrix_set_color(i, RGB_ORANGE);
                break;
            case 5:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            case 4:
                rgb_matrix_set_color(i, RGB_CYAN);
                break;
            case 3:
                rgb_matrix_set_color(i, RGB_PURPLE);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_GOLD);
                break;
            default:
                break;
        }
    }

    // Check if Caps Lock or Caps Word is active
    if (is_caps_active()) {
        // Set all keylight LEDs to red, excluding Caps Lock key (LED 26)
        for (uint8_t i = led_min; i < led_max; i++) {
            if ((g_led_config.flags[i] & LED_FLAG_KEYLIGHT) && (i != 26)) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
        // Set Caps Lock key LED (LED 26) to white
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 255, 255, 255);
    } else {
        // Turn off Caps Lock key LED when inactive
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 0, 0, 0);
    }

    return false;
}

void led_set_user(uint8_t usb_led) {
    update_caps_state();
}

void caps_word_set_user(bool active) {
    update_caps_state();
}

  ////////////////////////////////////////////////////////////////
 ///////////////////// CUSTOM KEY HANDLING //////////////////////
////////////////////////////////////////////////////////////////



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SECURE_MACRO:
            if (record->event.pressed) {
                send_string(SECURE_MACRO_VALUE);
            }
            return false; // Skip further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}



  //////////////////////////////////////////////////////////////
 //////////////////////// KEY OVERRIDES ///////////////////////
//////////////////////////////////////////////////////////////

// shift+backspace > delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};
