#ifndef HOMEROW_H
#define HOMEROW_H

#define NUM_SPC LT(NUMBER_SYMBOL, KC_SPC)

// homerow left keys
#define SFT_A  SFT_T(KC_A)
#define CTL_S  CTL_T(KC_S)
#define OPT_D  OPT_T(KC_D)
#define CMD_F  CMD_T(KC_F)

// homerow right keys
#define CMD_J  CMD_T(KC_J)
#define OPT_K  OPT_T(KC_K)
#define CTL_L  CTL_T(KC_L)
#define SFT_C  SFT_T(KC_SCLN)

#define ALL_M  ALL_T(KC_M)

#define HYP_Q  HYPR(KC_Q)
#define HYP_W  HYPR(KC_W)
#define HYP_E  HYPR(KC_E)
#define HYP_R  HYPR(KC_R)
#define HYP_T  HYPR(KC_T)

#define HS_A   LT(0, KC_NO)
#define HC_S   LT(1, KC_NO)
#define HO_D   LT(2, KC_NO)
#define HG_F   LT(3, KC_NO)
#define HYP_G  HYPR(KC_G)

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

#define ONE    SFT_T(KC_1)
#define TWO    CTL_T(KC_2)
#define THREE  OPT_T(KC_3)
#define FOUR   CMD_T(KC_4)
#define FIVE   KC_5

#define SIX    KC_6
#define SEVEN  CMD_T(KC_7)
#define EIGHT  OPT_T(KC_8)
#define NINE   CTL_T(KC_9)
#define ZERO   SFT_T(KC_0)


#define BSLSH  KC_BSLS
#define TILDE  KC_TILD

#define PIPE   KC_PIPE
#define MINUS  KC_MINS
#define PLUS   KC_PPLS

#endif
