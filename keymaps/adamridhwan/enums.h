#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER = 2,
    SYMBOL = 3,
};

enum macros {
    SEARCH = SAFE_RANGE,
};

#endif
