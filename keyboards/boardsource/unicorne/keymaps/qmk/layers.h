// layers.h
#pragma once
#define LAYERS_H

// Define the layers
enum layers {
    _QWTY,
    _NUMB,
    _SYMB,
    _NAVI,
    _FUNC,
    _MOUS,
    _LOWR,
    _RAIS,
    _MENU,
    _LAYER_COUNT  // Total number of layers
};

// Layer names stored in regular memory
static const char *const layer_names[] = {
    "QWTY",
    "NUMB",
    "SYMB",
    "NAVI",
    "FUNC",
    "MOUS",
    "LOWR",
    "RAIS",
    "MENU"
};

// Function to get layer name
const char *get_layer_name(uint8_t layer);
