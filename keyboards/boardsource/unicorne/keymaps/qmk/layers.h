// layers.h
#pragma once
#define LAYERS_H

// Define the layers
enum layers {
    _QWTY,
    _GALM,
    _MOUS,
    _NUMB,
    _SYMB,
    _NAVI,
    _FUNC,
    _LOWR,
    _RAIS,
    _MENU,
    _LAYER_COUNT  // Total number of layers
};

// Layer names stored in regular memory
static const char *const layer_names[] = {
    "QWTY",
    "GALM",
    "MOUS",
    "NUMB",
    "SYMB",
    "NAVI",
    "FUNC",
    "LOWR",
    "RAIS",
    "MENU"
};

// Function to get layer name
const char *get_layer_name(uint8_t layer);
