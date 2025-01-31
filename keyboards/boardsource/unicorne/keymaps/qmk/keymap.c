// keymap.c
#include QMK_KEYBOARD_H
#include "song_list.h"
#include "layers.h"

// Enum for custom keycodes
enum custom_keycodes {
    SECURE_MACRO = SAFE_RANGE,
};

#define LT_ESC LT(_SYMB, KC_ESC)
#define MT_C_DL LCTL_T(KC_DEL)
#define MT_A_BS LALT_T(KC_BSPC)
#define LT_ENTR LT(_NUMB, KC_ENTER)
#define LT_QUOT LT(_FUNC, KC_QUOT)
#define LT_SPAC LT(_NAVI, KC_SPACE)
#define LT_SLSH LT(_FUNC, KC_SLSH)
#define MO_MENU MO(_MENU)
#define MT_G_PS RGUI_T(KC_PSCR)
#define MEH_F24 MEH_T(KC_F24)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define CS_LEFT RCS(KC_LEFT)
#define CS_DOWN RCS(KC_DOWN)
#define CS_UP RCS(KC_UP)
#define CS_RGHT C(KC_RGHT)
#define C_LEFT C(KC_LEFT)
#define S_LEFT S(KC_LEFT)
#define S_RGHT S(KC_RGHT)
#define S_DOWN S(KC_DOWN)
#define S_UP S(KC_UP)
#define C_RGHT C(KC_RGHT)
#define S_PGDN S(KC_PGDN)
#define S_PGUP S(KC_PGUP)
#define S_HOME S(KC_HOME)
#define S_END S(KC_END)
#define PALETTE C(S(KC_P))
#define COPY_DN LSA(KC_DOWN)
#define COPY_UP LSA(KC_UP)
#define MOVE_UP LALT(KC_UP)
#define MOVE_DN LSA(KC_DOWN)
#define SELCTAL C(S(KC_L))
#define MO_LOWR MO(_LOWR)
#define DEL_WRD C(KC_BSPC)
#define SFT_TAB S(KC_TAB)
#define WINLOCK LGUI(KC_L)
#define CTALDEL LCA(KC_DEL)
#define CTSFESC RCS(KC_ESC)
#define SYMBTAB LT(_NUMB, KC_TAB)
#define SECURE_MACRO "SECURE_MACRO"

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
                send_string(SECURE_MACRO);
            }
            return false; // Skip further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}


  //////////////////////////////////////////////////////////////
 //////////////////////// KEY OVERRIDES ///////////////////////
//////////////////////////////////////////////////////////////

#if defined(KEY_OVERRIDE_ENABLE)

// Shift + backspace = delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));

// GUI + esc = `
const key_override_t gravegui_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

// CTRL + esc = `
const key_override_t gravectrl_esc_override = ko_make_basic(MOD_MASK_CTRL, KC_ESC, KC_GRV);

const key_override_t *key_overrides[] = {
	&tilde_esc_override,
    &delete_key_override,
    &gravegui_esc_override,
    &gravectrl_esc_override
};

#endif

  //////////////////////////////////////////////////////////////
 //////////////////////// COMBOS  /////////////////////////////
//////////////////////////////////////////////////////////////

#if defined(COMBO_ENABLE)

// Define combo indexes
enum combos {
    COMBO_1, // ESC + Q -> 1
    COMBO_2, // Q + W -> 2
    COMBO_3, // W + E -> 3
    COMBO_4, // E + R -> 4
    COMBO_5, // R + T -> 5
    COMBO_6, // Y + T -> 6
    COMBO_7, // U + I -> 7
    COMBO_8, // I + O -> 8
    COMBO_9, // O + P -> 9
    COMBO_0,  // P + Backspace -> 0
};

// Define key combo arrays
const uint16_t PROGMEM combo_esc_q[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_q_w[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_e_r[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_r_t[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_y_t[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_p_bsp[] = {KC_P, KC_BSPC, COMBO_END};

// Map combos to their resulting keycodes
combo_t combos[] = {
    [COMBO_1] = COMBO(combo_esc_q, KC_1),
    [COMBO_2] = COMBO(combo_q_w, KC_2),
    [COMBO_3] = COMBO(combo_w_e, KC_3),
    [COMBO_4] = COMBO(combo_e_r, KC_4),
    [COMBO_5] = COMBO(combo_r_t, KC_5),
    [COMBO_6] = COMBO(combo_y_t, KC_6),
    [COMBO_7] = COMBO(combo_u_i, KC_7),
    [COMBO_8] = COMBO(combo_i_o, KC_8),
    [COMBO_9] = COMBO(combo_o_p, KC_9),
    [COMBO_0] = COMBO(combo_p_bsp, KC_0)
};

#endif