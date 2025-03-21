// keymap.c
#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

#ifndef SECURE
    #define SECURE "null"
#endif

enum custom_keycodes {
    SENDPW = SAFE_RANGE,
    MOUSOFF,
};

socd_cleaner_t socd_opposing_pairs[] = {
    {{KC_E, KC_D}, SOCD_CLEANER_LAST},
    {{KC_S, KC_F}, SOCD_CLEANER_LAST},
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
#define CS_RGHT RCS(KC_RGHT)
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
#define MOVE_DN LALT(KC_DOWN)
#define SELCTAL C(S(KC_L))
#define MO_LOWR MO(_LOWR)
#define DEL_WRD C(KC_BSPC)
#define SFT_TAB S(KC_TAB)
#define CTL_TAB C(KC_TAB)
#define WINLOCK LGUI(KC_L)
#define CTALDEL LCA(KC_DEL)
#define CTSFESC RCS(KC_ESC)
#define SYMBTAB LT(_NUMB, KC_TAB)
#define LT_TAB LT(_SYMB, KC_TAB)
#define CASEON SENTENCE_CASE_ON
#define CASETOG SENTENCE_CASE_TOGGLE
#define CASEOFF SENTENCE_CASE_OFF

// For debugging: Show the value of SECURE during compilation
// #pragma message("SECURE is defined as: " SECURE)

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
[_NUMB] = LAYOUT_split_3x6_3(

     KC_GRV,  PALETTE,  COPY_DN,  MOVE_UP,  COPY_UP,  C(KC_D),/*       */ KC_GRV,     KC_7,     KC_8,     KC_9,  KC_PMNS,  KC_BSPC,
    MO_LOWR,  C(KC_A),  KC_LEFT,  MOVE_DN,  KC_RGHT,  SELCTAL,/*       */KC_LBRC,     KC_4,     KC_5,     KC_6,  KC_RBRC,  KC_DEL,
    KC_CAPS,  C(KC_Z),C(KC_DOT),  C(KC_C),  G(KC_V),  C(KC_Y),/*       */ KC_EQL,     KC_1,     KC_2,     KC_3,  KC_BSLS,  QK_LLCK,
    /*                          */KC_PGUP,  KC_PGDN,  _______,/*       */KC_MINS,     KC_0,   KC_DOT

    ),

// [2]
[_SYMB] = LAYOUT_split_3x6_3(

     KC_ESC,   KC_GRV,   KC_F13,   KC_F14,   KC_F15,   KC_F22,/*       */KC_TILD,  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),  DEL_WRD,
    _______,   KC_ENT,   KC_F16,   KC_F17,   KC_F18,   KC_F23,/*       */KC_LCBR,  S(KC_4),  S(KC_5),  S(KC_6),  KC_RCBR,  KC_DQUO,
    CW_TOGG,  C(KC_V),   KC_F19,   KC_F20,   KC_F21,   KC_F24,/*       */KC_PLUS,  S(KC_1),  S(KC_2),  S(KC_3),  KC_QUES,  QK_LLCK,
    /*                          */CTL_TAB,  SFT_TAB,  MO_LOWR,/*       */KC_UNDS,  KC_LABK,  KC_RABK

    ),

// [3]
[_NAVI] = LAYOUT_split_3x6_3(

       S_UP,  KC_HOME,   C_LEFT,    KC_UP,   C_RGHT,   KC_END,/*       */_______,  MS_WHLL,    MS_UP,  MS_WHLR,  MS_BTN5,  _______,
    SFT_TAB,   S_LEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT,   S_RGHT,/*       */MS_WHLU,  MS_LEFT,  MS_DOWN,  MS_RGHT,  MS_BTN4,  MO_RAIS,
    OSM_SFT,   S_HOME,  SELWBAK,   S_DOWN,  SELWORD,    S_END,/*       */MS_WHLD,  MS_BTN1,  MS_BTN3,  MS_BTN2,  MS_BTN4,  DS_MENU,
    /*                          */C(KC_C),  C(KC_V),  SELLINE,/*       */_______,  _______,  _______

    ),

// [4]
[_FUNC] = LAYOUT_split_3x6_3(

    _______,   KC_NUM,    KC_F7,    KC_F8,    KC_F9,   KC_F10,/*       */_______,   C_LEFT,    KC_UP,   C_RGHT,  KC_PGUP,   KC_DEL,
    _______,  KC_SCRL,    KC_F4,    KC_F5,    KC_F6,   KC_F11,/*       */KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,  _______,
    OSM_SFT,  KC_PAUS,    KC_F1,    KC_F2,    KC_F3,   KC_F12,/*       */_______,  C(KC_X),  C(KC_C),  C(KC_V),  KC_PGDN,  QK_LLCK,
    /*                        */OSM_CTL,  OSM_ALT,  MO(_LOWR),/*       */MO_RAIS,  _______,  _______

    ),

// [5]
[_MOUS] = LAYOUT_split_3x6_3(

    _______,  _______,  _______,  _______,  MS_WHLL,  MS_WHLR,/*       */MS_WHLL,  MS_WHLR,  _______,  _______,  _______,    TURBO,
    _______,  _______,  _______,  _______,  MS_BTN5,  MS_WHLU,/*       */MS_WHLU,  MS_BTN5,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  MS_BTN4,  MS_WHLD,/*       */MS_WHLD,  MS_BTN4,  _______,  _______,  _______,  QK_LLCK,
    /*                          */MOUSOFF,  MS_BTN2,  MS_BTN1,/*       */MS_BTN1,  MS_BTN2,  MOUSOFF

    ),

// [6]
[_LOWR] = LAYOUT_split_3x6_3(

    QK_BOOT,  _______,  WINLOCK,  CTALDEL,  CTSFESC,  _______,/*       */ SENDPW,  RM_HUED,  RM_VALU,  RM_HUEU,  RM_TOGG,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */RM_SPDU,  RM_PREV,  RM_VALD,  RM_NEXT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */RM_SPDD,  RM_SATD,  _______,  RM_SATU,  _______,  QK_LLCK,
    /*                         */ _______,  _______,  _______,/*       */MO_MENU,  _______,  _______

    ),

// [7]
[_RAIS] = LAYOUT_split_3x6_3(

    _______,  _______,  CASEOFF,  CASETOG,   CASEON,  _______,/*       */CG_TOGG,  GE_SWAP,  AU_TOGG,  _______,  _______,  QK_BOOT,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */AG_TOGG,  GE_NORM,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,/*       */GU_TOGG,  _______,  _______,  _______,  _______,  QK_LLCK,
    /*                          */_______,  _______,  MO_MENU,/*       */_______,  _______,  _______

    ),

// [8]
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
                rgb_matrix_set_color(i, 0, 255, 170);
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
                rgb_matrix_set_color(i, RGB_WHITE);
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

void keyboard_post_init_user(void) {
  // Set the effect.
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW);
  // Set the palette and maximize saturation and brightness.
  uint8_t palette_index = PALETTEFX_USER_0;  // Set first custom user palette.
  rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette_index, 255, 255);
  // Set speed to default.
  rgb_matrix_set_speed_noeeprom(128);
  // Make sure RGB Matrix is on.
  rgb_matrix_enable_noeeprom();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SENDPW:
            if (record->event.pressed) {
                SEND_SECURE_STRING();
                // #    if defined(AUDIO_ENABLE)
                // audio_play_melody(&send_pw, NOTE_ARRAY_SIZE(send_pw), false);
                // #    endif
            }
            return false;

        // case SYMBTAB:
        //     if (record->tap.count == 0) {           // On hold.
        //         if (record->event.pressed) {        // On press.
        //             register_mods(MOD_BIT(KC_LSFT)); // Hold left Shift.
        //         } else {                            // On release.
        //             unregister_mods(MOD_BIT(KC_LSFT)); // Release left Shift.
        //         }
        //     }
        //     return true;
        case MOUSOFF:
            if (record->event.pressed) {  // Check if the key is pressed
                if (IS_LAYER_ON(_MOUS)) {  // Check if the target layer is active
                    layer_off(_MOUS);  // Deactivate the target layer
                }
            }
            return false;  // Skip default processing for this key

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
    COMBO_PGUP, // Q + W + E -> Page Up
    COMBO_PGDN, // E + R + T -> Page Down
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
const uint16_t PROGMEM combo_q_w_e[] = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_e_r_t[] = {KC_E, KC_R, KC_T, COMBO_END};


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
    [COMBO_RCBR] = COMBO(combo_d_f_g, KC_RCBR),
    [COMBO_PGUP] = COMBO(combo_q_w_e, KC_PGUP),
    [COMBO_PGDN] = COMBO(combo_e_r_t, KC_PGDN)
};

#endif
