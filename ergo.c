#include "ergo.h"

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM layer_all[] = RGBLIGHT_LAYER_SEGMENTS({0, 17, HSV_WHITE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_all
);

void keyboard_post_init_kb(void) {
    rgblight_layers = my_rgb_layers;
    keyboard_post_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        rgblight_set_layer_state(
            0,
            layer_state_is(1) ||
            layer_state_is(2) ||
            layer_state_is(3) ||
            led_state.caps_lock
        );
    }
    return res;
}

#endif
