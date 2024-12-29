#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER = 2,
    FUNCTION = 3,
    SYMBOL = 4,
    JAVASCRIPT = 5,
};

enum td_keycodes {
    RTB,  // Right thumb
    LTB   // Left thumb
};

enum combos {
    CAPSLOCK_COMBO
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

#endif