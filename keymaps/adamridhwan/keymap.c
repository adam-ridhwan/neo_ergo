#include QMK_KEYBOARD_H
#include "tap_dance.h"
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
        case TD(LTB):
            return true;

        default:
            return false;
    }
};

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, NAVIGATION));
    rgblight_set_layer_state(2, layer_state_cmp(state, SYMBOL));
    rgblight_set_layer_state(3, layer_state_cmp(state, NUMBER));
    rgblight_set_layer_state(4, layer_state_cmp(state, JAVASCRIPT));
    rgblight_set_layer_state(5, layer_state_cmp(state, FUNCTION));

    return layer_state_set_user(state);
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_hot(
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
            XXXXXXX , KC_CAPS ,   KC_1  ,   KC_2  ,   KC_3  ,   KC_4  ,   KC_5  ,   KC_6  ,      KC_7  ,   KC_8  ,   KC_9  ,   KC_0  , KC_MINS ,  KC_EQL , KC_BSLS ,  KC_GRV ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX ,  KC_TAB ,   KC_Q  ,   KC_W  ,   KC_E  ,   KC_R  ,   KC_T  ,                KC_Y  ,   KC_U  ,   KC_I  ,   KC_O  ,   KC_P  , KC_LBRC , KC_RBRC , KC_BSPC ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX ,  KC_ESC ,  SFT_A  ,  CTL_S  ,  OPT_D  ,  CMD_F  ,   KC_G  ,                KC_H  ,   CMD_J ,  OPT_K  ,  CTL_L  ,  SFT_C  , KC_QUOT ,       KC_ENT      , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            KC_LSFT , KC_LSFT ,   KC_Z  ,   KC_X  ,   KC_C  ,   KC_V  ,   KC_B  ,                KC_B  ,   KC_N  ,  ALL_M  , KC_COMM ,  KC_DOT , KC_SLSH , KC_RSFT , KC_RSFT ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                      KC_LCTL , KC_LALT ,                     KC_LCMD , TD(LTB) ,              TD(RTB) , KC_RCMD ,                     KC_RALT , XXXXXXX , KC_LCTL
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),

   [NAVIGATION] = LAYOUT_hot(
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , KC_HOME ,  KC_UP  ,  KC_END , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,              KC_PGUP , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX ,      _______      , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , KC_PGDN , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                      XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
   ),

   [NUMBER] = LAYOUT_hot(
      //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX ,   KC_7  ,   KC_8  ,   KC_9  , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
          XXXXXXX , CW_TOGG , XXXXXXX ,   KC_4  ,   KC_5  ,   KC_6  , XXXXXXX ,              XXXXXXX , KC_RGUI , KC_RALT , KC_RCTL , KC_RSFT , XXXXXXX ,      XXXXXXX      , XXXXXXX ,
      //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,   KC_1  ,   KC_2  ,   KC_3  , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                    XXXXXXX , XXXXXXX ,                     XXXXXXX ,   KC_0  ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
      //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
   ),

    [FUNCTION] = LAYOUT_hot(
       //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
       //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
           XXXXXXX , XXXXXXX ,  KC_F12 ,  KC_F7  ,  KC_F8  ,  KC_F9  , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
       //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
           XXXXXXX , XXXXXXX ,  KC_F11 ,  KC_F4  ,  KC_F5  ,  KC_F6  , XXXXXXX ,              XXXXXXX , KC_RGUI , KC_RALT , KC_RCTL , KC_RSFT , XXXXXXX ,      XXXXXXX      , XXXXXXX ,
       //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
           XXXXXXX , XXXXXXX , XXXXXXX ,  KC_F10 ,  KC_F1  ,  KC_F2  ,  KC_F3  , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
       //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                     XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
       //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),

    [JAVASCRIPT] = LAYOUT_hot(
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              KC_PLUS , KC_AMPR , KC_PIPE ,  KC_GRV , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,              KC_MINS , KC_LPRN , KC_RPRN ,  KC_EQL ,  KC_GT  , KC_BSLS ,      XXXXXXX      , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , KC_UNDS , KC_LCBR , KC_RCBR , KC_LBRC , KC_RBRC , XXXXXXX , XXXXXXX ,
        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
                      XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
    ),

//     [] = LAYOUT_hot(
//        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
//            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
//            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
//            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      XXXXXXX      ,
//        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
//  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//        //|---------+---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------+---------|
//                      XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX
//        //,-------------------------------------------------------------------------------,  ,-------------------------------------------------------------------------------,
//     ),
};