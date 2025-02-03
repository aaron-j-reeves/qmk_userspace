// keymap.c
#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

// #ifndef SECURE
//     #define SECURE "INVALID_VALUE"
// #endif

enum custom_keycodes {
    SENDPW = SAFE_RANGE,
};

  //////////////////////////////////////////////////////////////
 //////////////////////// KEY DEFINITIONS ///////////////////// 
//////////////////////////////////////////////////////////////

#define LT_ESC LT(_SYMB, KC_ESC)
#define MT_C_DL LCTL_T(KC_DEL)
#define MT_A_BS LALT_T(KC_BSPC)
#define LT_ENTR LT(_NUMB, KC_ENTER)
#define LT_QUOT LT(_FUNC, KC_QUOT)
#define LT_SPAC LT(_NAVI, KC_SPACE)
#define LT_SLSH LT(_FUNC, KC_SLSH)
#define MO_MENU MO(_MENU)
#define MO_RAIS MO(_RAIS)
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
#define LT_TAB LT(_SYMB, KC_TAB)

// For debugging: Show the value of SECURE during compilation
#pragma message("SECURE is defined as: " SECURE)

// Use SECURE directly, as it should now be a properly quoted string
#define SEND_SECURE_STRING() SEND_STRING(SECURE)

  //////////////////////////////////////////////////////////////
 //////////////////////// TAP DANCE /////////////////////////// 
//////////////////////////////////////////////////////////////

// enum {
//     QUOLOCK,
// };

// Tap Dance definitions
// enum {
//     QUOLOCK,  // Tap Dance key for Quote and Layer Lock
// };

// Tap Dance functions
// void quolock_finished(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         tap_code(KC_QUOT);  // Send quote
//     } else if (state->count == 2) {
//         tap_code(KC_LLOCK); // Activate Layer Lock
//     }
// }

// void quolock_reset(qk_tap_dance_state_t *state, void *user_data) {
//     // No action needed on reset
// }

// Tap Dance actions array
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [QUOLOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quolock_finished, quolock_reset),
// };

  //////////////////////////////////////////////////////////////
 ////////////////////// KEYMAP DEFINITIONS ////////////////////
//////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [0]
[_QWTY] = LAYOUT_split_3x6_3(

     KC_ESC,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,/*       */   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
     LT_TAB,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,/*       */   KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  LT_QUOT,
    SC_LSPO,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,/*       */   KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  SC_RSPC,
    /*                          */MT_C_DL,  MT_A_BS,  LT_ENTR,/*       */LT_SPAC,  MT_G_PS,  MEH_F24

    ),

// [1]
[_GALM] = LAYOUT_split_3x6_3(

    _______,     KC_B,     KC_L,     KC_D,     KC_C,     KC_V,/*       */   KC_J,     KC_Y,     KC_O,     KC_U,  KC_COMM,  _______,
    _______,     KC_N,     KC_R,     KC_T,     KC_S,     KC_G,/*       */   KC_P,     KC_H,     KC_A,     KC_E,     KC_I,  LT_SLSH,
    _______,     KC_X,     KC_Q,     KC_M,     KC_W,     KC_Z,/*       */   KC_K,     KC_F,  LT_QUOT,  KC_SCLN,   KC_DOT,  _______,
    /*                          */_______,  _______,  _______,/*       */_______,  _______,  _______

    ),

// [2]
[_MOUS] = LAYOUT_split_3x6_3(

    _______,  _______,  _______,  _______,  _______,  _______,/*       */_______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_WH_U,/*       */_______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_WH_D,/*       */_______,  _______,  _______,  _______,  _______,  QK_LLCK,
    /*                          */_______,  KC_BTN2,  KC_BTN1,/*       */KC_BTN1,  KC_BTN2,  _______

    ),

// [3]
[_NUMB] = LAYOUT_split_3x6_3(

     KC_GRV,  PALETTE,  COPY_DN,  MOVE_UP,  COPY_UP,  C(KC_D),/*       */ KC_GRV,     KC_7,     KC_8,     KC_9,  KC_PMNS,  KC_BSPC,
    MO_LOWR,  C(KC_A),  KC_LEFT,  MOVE_DN,  KC_RGHT,  SELCTAL,/*       */KC_LBRC,     KC_4,     KC_5,     KC_6,  KC_RBRC,  KC_DEL,
    KC_CAPS,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  C(KC_Y),/*       */ KC_EQL,     KC_1,     KC_2,     KC_3,  KC_BSLS,  QK_LLCK,
    /*                          */KC_PGUP,  KC_PGDN,  _______,/*       */KC_MINS,     KC_0,   KC_DOT

    ),

// [4]
[_SYMB] = LAYOUT_split_3x6_3(

     KC_GRV,  _______,     KC_7,     KC_8,     KC_9,  _______,/*       */KC_TILD,  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),  DEL_WRD,
    _______,  _______,     KC_4,     KC_5,     KC_6,  _______,/*       */KC_LCBR,  S(KC_4),  S(KC_5),  S(KC_6),  KC_RCBR,  KC_DQUO,
    CW_TOGG,     KC_0,     KC_1,     KC_2,     KC_3,  _______,/*       */KC_PLUS,  S(KC_1),  S(KC_2),  S(KC_3),  KC_QUES,  QK_LLCK,
    /*                          */_______,  _______,  MO_LOWR,/*       */KC_UNDS,  KC_LABK,  KC_RABK

    ),

// [5]
[_NAVI] = LAYOUT_split_3x6_3(

       S_UP,  KC_HOME,   C_LEFT,    KC_UP,   C_RGHT,   KC_END,/*       */KC_ACL0,  KC_WH_L,  KC_MS_U,  KC_WH_R,  KC_ACL1,  KC_ACL2,
     KC_TAB,   S_LEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT,   S_RGHT,/*       */KC_WH_U,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN5,  MO_RAIS,
    SFT_TAB,   S_HOME,  CS_LEFT,   S_DOWN,  CS_RGHT,    S_END,/*       */KC_WH_D,  KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_BTN4,  QK_LLCK,
    /*                          */C(KC_C),  C(KC_V),   KC_ENT,/*       */_______,  _______,  _______

    ),

// [6]
[_FUNC] = LAYOUT_split_3x6_3(

    _______,   KC_NUM,    KC_F7,    KC_F8,    KC_F9,   KC_F10,/*       */_______,   C_LEFT,    KC_UP,   C_RGHT,  KC_PGUP,   KC_DEL,
    _______,  KC_SCRL,    KC_F4,    KC_F5,    KC_F6,   KC_F11,/*       */KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,  _______,
    OSM_SFT,  KC_PAUS,    KC_F1,    KC_F2,    KC_F3,   KC_F12,/*       */_______,  C(KC_X),  C(KC_C),  C(KC_V),  KC_PGDN,  QK_LLCK,
    /*                        */OSM_CTL,  OSM_ALT,  MO(_LOWR),/*       */MO_RAIS,  _______,  _______

    ),

// [7]
[_LOWR] = LAYOUT_split_3x6_3(

    QK_BOOT,  _______,  WINLOCK,  CTALDEL,  CTSFESC,  _______,/*       */ SENDPW,  RM_HUED,  RM_VALU,  RM_HUEU,  RM_TOGG,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */RM_SPDU,  RM_PREV,  RM_VALD,  RM_NEXT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */RM_SPDD,  RM_SATD,  _______,  RM_SATU,  _______,  QK_LLCK,
    /*                         */ _______,  _______,  _______,/*       */MO_MENU,  _______,  _______

    ),

// [8]
[_RAIS] = LAYOUT_split_3x6_3(

    _______,  _______,  _______,  _______,  _______,  _______,/*       */CG_TOGG,  GE_SWAP,  AU_TOGG,  _______,  _______,  QK_BOOT,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */AG_TOGG,  GE_NORM,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */GU_TOGG,  _______,  _______,  _______,  _______,  QK_LLCK,
    /*                          */_______,  _______,  MO_MENU,/*       */_______,  _______,  _______

    ),

// [9]
[_MENU] = LAYOUT_split_3x6_3(

    _______,  _______,  _______,  _______,  _______,  _______,/*       */_______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */_______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */_______,  _______,  _______,  _______,  _______,  QK_LLCK,
    /*                         */ _______,  _______,  _______,/*       */_______,  _______,  _______

    )
};

#    if defined(AUDIO_ENABLE)
#        ifdef USER_SONG_LIST
float caps_on[][2] = SONG(MARIO_POWERUP_BLOCK);
float caps_off[][2] = SONG(MARIO_KICK);
float send_pw[][2] = SONG(ZELDA_PUZZLE);
#        else // USER_SONG_LIST
float caps_on[][2]  = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float send_pw[][2] = SONG(PLOVER_GOODBYE_SOUND);
#        endif // USER_SONG_LIST
#    endif


  //////////////////////////////////////////////////////////////
 /////////// LAYER LIGHTS + SOUND + CAPS LOCK INDICATOR ///////
//////////////////////////////////////////////////////////////


bool is_caps_active(void) {
    return host_keyboard_led_state().caps_lock || is_caps_word_on();
}

void update_caps_state(void) {
    static bool caps_state = false;
    bool new_caps_state = is_caps_active();

    if (new_caps_state != caps_state) {
        caps_state = new_caps_state;

        // Play sounds when Caps Lock or Caps Word state changes
        #    if defined(AUDIO_ENABLE)
        if (caps_state) {

            // Caps Lock or Caps Word was just turned on
            audio_play_melody(&caps_on, NOTE_ARRAY_SIZE(caps_on), false);

        } else {

            // Caps Lock and Caps Word were just turned off
            audio_play_melody(&caps_off, NOTE_ARRAY_SIZE(caps_off), false);
        }
        #    endif
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

    uint8_t layer = get_highest_layer(layer_state);

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

    return true;
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

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SENDPW:
            if (record->event.pressed) {
                SEND_SECURE_STRING();
                #    if defined(AUDIO_ENABLE)
                audio_play_melody(&send_pw, NOTE_ARRAY_SIZE(send_pw), false);
                #    endif
            }
            return false;

        case SYMBTAB:
            if (record->tap.count == 0) {           // On hold.
                if (record->event.pressed) {        // On press.
                    register_mods(MOD_BIT(KC_LSFT)); // Hold left Shift.
                } else {                            // On release.
                    unregister_mods(MOD_BIT(KC_LSFT)); // Release left Shift.
                }
            }
            return true;

        default:
            return true;
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

// ALT + esc = ~
const key_override_t tildealt_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, S(KC_GRV));

// GUI + esc = `
const key_override_t gravegui_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

// CTRL + esc = `
const key_override_t gravectrl_esc_override = ko_make_basic(MOD_MASK_CTRL, KC_ESC, KC_GRV);

const key_override_t *key_overrides[] = {
    &delete_key_override,
	&tilde_esc_override,
    &tildealt_esc_override,
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
    COMBO_CUT, // Z + X + C -> Cut
    COMBO_COPY, // X + C + V -> Copy
    COMBO_PASTE, // C + V + B -> Paste
    COMBO_LCBR, // A + S + D -> {
    COMBO_DLR, // S + D + F -> }
    COMBO_RCBR, // D + F + G -> }
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
const uint16_t PROGMEM combo_z_x_c[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_x_c_v[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_c_v_b[] = {KC_C, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_a_s_d[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_s_d_f[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_d_f_g[] = {KC_D, KC_F, KC_G, COMBO_END};

// Map combos to their resulting keycodes
combo_t key_combos[] = {
    [COMBO_1] = COMBO(combo_esc_q, KC_1),
    [COMBO_2] = COMBO(combo_q_w, KC_2),
    [COMBO_3] = COMBO(combo_w_e, KC_3),
    [COMBO_4] = COMBO(combo_e_r, KC_4),
    [COMBO_5] = COMBO(combo_r_t, KC_5),
    [COMBO_6] = COMBO(combo_y_t, KC_6),
    [COMBO_7] = COMBO(combo_u_i, KC_7),
    [COMBO_8] = COMBO(combo_i_o, KC_8),
    [COMBO_9] = COMBO(combo_o_p, KC_9),
    [COMBO_0] = COMBO(combo_p_bsp, KC_0),
    [COMBO_CUT] = COMBO(combo_z_x_c, C(KC_X)),
    [COMBO_COPY] = COMBO(combo_x_c_v, C(KC_C)),
    [COMBO_PASTE] = COMBO(combo_c_v_b, C(KC_V)),
    [COMBO_LCBR] = COMBO(combo_a_s_d, KC_LCBR),
    [COMBO_DLR] = COMBO(combo_s_d_f, KC_DLR),
    [COMBO_RCBR] = COMBO(combo_d_f_g, KC_RCBR)
};

#endif





























