// layers.c
#include "layers.h"

const char *get_layer_name(uint8_t layer) {
    switch (layer) {
        case _QWTY:
            return "QWERTY";
        case _NUMB:
            return "Numbers";
        case _SYMB:
            return "Symbols";
        case _NAVI:
            return "Navigation";
        case _FUNC:
            return "Functions";
        case _MOUS:
            return "Mouse";
        case _LOWR:
            return "Lower";
        case _RAIS:
            return "Raise";
        case _MENU:
            return "Menu";
        default:
            return "Undefined";
    }
}
