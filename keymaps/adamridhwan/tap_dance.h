#ifndef TAP_DANCE_H
#define TAP_DANCE_H

#include QMK_KEYBOARD_H
#include "definitions.h"
#include "enums.h"

typedef struct {
    td_state_t state;
} td_tap_t;

static td_tap_t thumb_tap_state = {
    .state = TD_NONE
};

static inline td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    return TD_UNKNOWN;
}

static inline void perform_layer_toggle(
    td_state_t state,
    uint8_t layer_single_hold,
    uint8_t layer_double_hold
) {
    if (state == TD_SINGLE_HOLD) layer_on(layer_single_hold);
    else if (state == TD_DOUBLE_HOLD) layer_on(layer_double_hold);
}

static inline void perform_layer_reset(
    td_state_t state,
    uint8_t layer_single_hold,
    uint8_t layer_double_hold
) {
    if (state == TD_SINGLE_HOLD) layer_off(layer_single_hold);
    else if (state == TD_DOUBLE_HOLD) layer_off(layer_double_hold);
}

static inline void right_thumb_finished(
    tap_dance_state_t *state,
    void *user_data
) {
    thumb_tap_state.state = cur_dance(state);
    switch (thumb_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SPC);
            break;
        default:
            perform_layer_toggle(
                thumb_tap_state.state,
                NUMBER,
                FUNCTION
            );
            break;
    }
}

static inline void right_thumb_reset(
    tap_dance_state_t *state,
    void *user_data
) {
    perform_layer_reset(
        thumb_tap_state.state,
        NUMBER,
        FUNCTION
    );
    thumb_tap_state.state = TD_NONE;
}

static inline void left_thumb_finished(
    tap_dance_state_t *state,
    void *user_data
) {
    thumb_tap_state.state = cur_dance(state);
    switch (thumb_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_BSPC);
            break;
        default:
            perform_layer_toggle(
                thumb_tap_state.state,
                NAVIGATION,
                JAVASCRIPT
            );
            break;
    }
}

static inline void left_thumb_reset(
    tap_dance_state_t *state,
    void *user_data
) {
    perform_layer_reset(thumb_tap_state.state, NAVIGATION, JAVASCRIPT);
    thumb_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [RTB] = ACTION_TAP_DANCE_FN_ADVANCED(
                NULL,
                right_thumb_finished,
                right_thumb_reset
            ),
    [LTB] = ACTION_TAP_DANCE_FN_ADVANCED(
                NULL,
                left_thumb_finished,
                left_thumb_reset
            )
};

#endif
