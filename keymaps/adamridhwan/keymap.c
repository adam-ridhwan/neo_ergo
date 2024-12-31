#include QMK_KEYBOARD_H
#include "definitions.h"
#include "enums.h"

// qmk flash -kb neo/ergo -km adamridhwan

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
        add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEARCH:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                register_mods(MOD_BIT(KC_LGUI));
                tap_code(KC_E);
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            break;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_A:
        case CTL_S:
        case OPT_D:
        case CMD_F:
        case CMD_J:
        case OPT_K:
        case CTL_L:
        case SFT_C:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_hot(
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
        XXXXXXX , KC_CAPS ,   KC_1  ,   KC_2  ,   KC_3  ,   KC_4  ,   KC_5  ,   KC_6  ,      KC_7  ,   KC_8  ,   KC_9  ,   KC_0  , KC_MINS ,  KC_EQL , KC_BSLS ,  KC_GRV ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX ,  KC_TAB ,   KC_Q  ,   KC_W  ,   KC_E  ,   KC_R  ,   KC_T  ,                KC_Y  ,   KC_U  ,   KC_I  ,   KC_O  ,   KC_P  , KC_LBRC , KC_RBRC , KC_BSPC ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX ,  KC_ESC ,  SFT_A  ,  CTL_S  ,  OPT_D  ,  CMD_F  ,   KC_G  ,                KC_H  ,  CMD_J  ,  OPT_K  ,  CTL_L  ,  SFT_C  , KC_QUOT ,       KC_ENT      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        KC_LSFT , XXXXXXX ,   KC_Z  ,   KC_X  ,   KC_C  ,   KC_V  ,   KC_B  , XXXXXXX ,      KC_N  ,  ALL_M  , KC_COMM ,  KC_DOT , KC_SLSH ,      KC_RSFT      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                  KC_LCTL , KC_LALT ,                     KC_LCMD ,   MO(1) ,              NUM_SPC , KC_LCMD ,                     KC_RALT , XXXXXXX , KC_LCTL
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),

    [NAVIGATION] = LAYOUT_hot(
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  SEARCH , XXXXXXX , XXXXXXX ,              XXXXXXX , KC_HOME ,  KC_UP  ,  KC_END , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,              KC_PGUP , KC_LEFT , KC_DOWN , KC_RGHT , KC_RSFT , XXXXXXX ,      _______      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    KC_PGDN , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      XXXXXXX      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                  XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),

    [NUMBER_SYMBOL] = LAYOUT_hot(
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX ,  GRAVE  ,  TILDE  ,  LCBRC  ,  RCBRC  ,   PLUS  ,               UNDER  ,   LPRN  ,   RPRN  ,  EQUAL  ,    GT   , XXXXXXX , XXXXXXX , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , CW_TOGG ,   ONE   ,   TWO   ,  THREE  ,   FOUR  ,   FIVE  ,                SIX   ,  SEVEN  ,  EIGHT  ,   NINE  ,   ZERO  , XXXXXXX ,      _______      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX ,  BSLSH  ,   PIPE  ,  LSBRC  ,  RSBRC  ,  MINUS  , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      XXXXXXX      , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                  XXXXXXX , XXXXXXX ,                     XXXXXXX ,  KC_SPC ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
    //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),
};
