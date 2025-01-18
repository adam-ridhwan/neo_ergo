#ifndef HOMEROW_H
#define HOMEROW_H

#define NUM_SPC LT(NUMBER, KC_SPC)
#define NAV     MO(NAVIGATION)
#define SYM     MO(SYMBOL)

#define QWER    DF(QWERTY)
#define COLE    DF(COLEMAK)

// ──────────────────────────────────────────────────────────────
// QWERTY
// ──────────────────────────────────────────────────────────────

#define SFT_A  SFT_T(KC_A)
#define CTL_S  CTL_T(KC_S)
#define OPT_D  OPT_T(KC_D)
#define CMD_F  CMD_T(KC_F)

#define CMD_J  CMD_T(KC_J)
#define OPT_K  OPT_T(KC_K)
#define CTL_L  CTL_T(KC_L)
#define SFT_C  SFT_T(KC_SCLN)

// ──────────────────────────────────────────────────────────────
// COLEMAK-DH
// ──────────────────────────────────────────────────────────────

#define SFT_A  SFT_T(KC_A)
#define CTL_R  CTL_T(KC_R)
#define OPT_S  OPT_T(KC_S)
#define CMD_t  CMD_T(KC_T)

#define CMD_N  CMD_T(KC_N)
#define OPT_E  OPT_T(KC_E)
#define CTL_I  CTL_T(KC_I)
#define SFT_O  SFT_T(KC_O)

#define HYP_Q  HYPR(KC_Q)
#define HYP_W  HYPR(KC_W)
#define HYP_E  HYPR(KC_E)
#define HYP_R  HYPR(KC_R)
#define HYP_T  HYPR(KC_T)
#define HYP_G  HYPR(KC_G)
#define HYP_Z  HYPR(KC_Z)
#define HYP_X  HYPR(KC_X)
#define HYP_C  HYPR(KC_C)
#define HYP_V  HYPR(KC_V)
#define HYP_B  HYPR(KC_B)

// ─────────────────────────────────────────────────────────────────────────────
// NUMBER AND SYMBOL LAYER
// ─────────────────────────────────────────────────────────────────────────────

#define LSBRC  KC_LBRC
#define RSBRC  KC_RBRC
#define LCBRC  KC_LCBR
#define RCBRC  KC_RCBR
#define GRAVE  KC_GRV

#define UNDER  KC_UNDS
#define LPRN   KC_LPRN
#define RPRN   KC_RPRN
#define EQUAL  KC_EQL
#define GT     KC_GT

#define ONE    KC_1
#define TWO    KC_2
#define THREE  KC_3
#define FOUR   KC_4
#define FIVE   KC_5
#define SIX    KC_6
#define SEVEN  KC_7
#define EIGHT  KC_8
#define NINE   KC_9
#define ZERO   KC_0

#define BSLSH  KC_BSLS
#define TILDE  KC_TILD

#define PIPE   KC_PIPE
#define AMPR   KC_AMPR
#define MINUS  KC_MINS
#define PLUS   KC_PPLS

#define QUOTE  KC_QUOT
#define DQUOT  KC_DQUO

#define EXCLM  KC_EXLM
#define AT     KC_AT
#define HASH   KC_HASH
#define DLR    KC_DLR
#define PERCNT KC_PERC
#define CARET  KC_CIRC
#define ASTRSK KC_ASTR

#endif
