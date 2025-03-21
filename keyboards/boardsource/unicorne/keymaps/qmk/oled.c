// oled.c

#include QMK_KEYBOARD_H
#include "layers.h"
#include "../../../../../modules/drashna/display_menu/oled_render_menu.h"
#include "../../../../../modules/drashna/display_menu/display_menu.h" // Include this for menu_state_t
#ifdef OLED_ENABLE

bool is_display_menu_active(void) {
    extern menu_state_t menu_state; // Ensure this matches the external declaration
    return menu_state.is_in_menu;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_270;
    }

    return OLED_ROTATION_90;
}

void render_feature_status(const char* label, bool active) {
    oled_write_P(label, active);
    oled_write_P(PSTR(" "), false);
}

void render_status(void) {
    // Get the keyboard LED status
    led_t led_state = host_keyboard_led_state();

    // Clear the OLED display
    oled_clear();

    // First line
    oled_set_cursor(0, 0);
    render_feature_status(PSTR("NUM"), led_state.num_lock);
    oled_set_cursor(0, 2);
    render_feature_status(PSTR("CAPS"), led_state.caps_lock);
    oled_set_cursor(0, 4);
    render_feature_status(PSTR("CW"), is_caps_word_on());
    oled_set_cursor(0, 6);
    render_feature_status(PSTR("SCR"), led_state.scroll_lock);
    oled_set_cursor(0, 8);
    render_feature_status(PSTR("CTL >"), keymap_config.swap_lctl_lgui);
    oled_set_cursor(0, 9);
    render_feature_status(PSTR("WIN"), keymap_config.swap_lctl_lgui);
    oled_set_cursor(0, 11);
    render_feature_status(PSTR("ALT >"), keymap_config.swap_lalt_lgui);
    oled_set_cursor(0, 12);
    render_feature_status(PSTR("WIN"), keymap_config.swap_lalt_lgui);
}

bool oled_task_user(void) {
    // Check if display menu is active
    if (is_display_menu_active()) {
        if (is_keyboard_left()) {
            // Render menu on the left side (menu_render_side = 1)
            oled_render_menu(0, 0, 16, 1);
        } else {
            // Render menu on the right side (menu_render_side = 2)
            oled_render_menu(0, 0, 16, 2);
        }
    } else {
        render_status();  // Display status
    }

    return false; // Skip default rendering
}

#if defined(COMMUNITY_MODULE_DISPLAY_MENU_ENABLE)
bool process_record_display_menu_handling_user(uint16_t keycode, bool keep_processing) {
    // Only process menu navigation if the menu is active
    if (!is_display_menu_active() && keycode != DISPLAY_MENU) {
        return keep_processing;
    }

    switch (keycode) {
        case KC_D:
            return menu_handle_input(menu_input_down);
        case KC_E:
            return menu_handle_input(menu_input_up);
        case KC_F:
            return menu_handle_input(menu_input_right);
        case KC_S:
            return menu_handle_input(menu_input_left);
        case DISPLAY_MENU:
            return menu_handle_input(menu_input_exit);
        case KC_ESC:
        case KC_BSPC:
        case KC_DEL:
            return menu_handle_input(menu_input_back);
        case KC_SPACE:
        case KC_ENTER:
        case KC_RETURN:
            return menu_handle_input(menu_input_enter);
        case KC_UP:
            return menu_handle_input(menu_input_up);
        case KC_DOWN:
            return menu_handle_input(menu_input_down);
        case KC_LEFT:
            return menu_handle_input(menu_input_left);
        case KC_RIGHT:
            return menu_handle_input(menu_input_right);
        default:
            return keep_processing;
    }

    // Note: menu_handle_input returns:
    // - true if the key should be processed by QMK
    // - false if the key was consumed by the menu
}
#endif

#endif // OLED_ENABLE
