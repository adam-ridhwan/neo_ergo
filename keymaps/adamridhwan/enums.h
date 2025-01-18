#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    QWERTY = 0,
    COLEMAK = 1,
    NAVIGATION = 2,
    NUMBER = 3,
    SYMBOL = 4
    ,
};

enum macros {
    SEARCH = SAFE_RANGE,
};

#endif
