#include "ergo.h"

#ifdef RGBLIGHT_ENABLE

#define WHITE_COLOR RGBLIGHT_LAYER_SEGMENTS({0, 17, HSV_WHITE})

const rgblight_segment_t PROGMEM caps_lock_layer[] = WHITE_COLOR;
const rgblight_segment_t PROGMEM navigation_layer[] = WHITE_COLOR;
const rgblight_segment_t PROGMEM number_layer[] = WHITE_COLOR;
const rgblight_segment_t PROGMEM symbol_layer[] = WHITE_COLOR;
const rgblight_segment_t PROGMEM javascript_layer[] = WHITE_COLOR;
const rgblight_segment_t PROGMEM function_layer[] = WHITE_COLOR;

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    caps_lock_layer,
    navigation_layer,
    number_layer,
    symbol_layer,
    javascript_layer,
    function_layer
);

void keyboard_post_init_kb(void) {
    rgblight_layers = my_rgb_layers;
    keyboard_post_init_user();
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        rgblight_set_layer_state(0, led_state.caps_lock);
    }
    return res;
};

#endif
