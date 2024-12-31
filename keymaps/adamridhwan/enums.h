#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER_SYMBOL = 2,
};

enum macros {
    SEARCH = SAFE_RANGE,
};

#endif
