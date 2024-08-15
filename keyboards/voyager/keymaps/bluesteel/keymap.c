#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  MAC_MISSION_CONTROL,
  MAC_SPOTLIGHT,
  MAC_SIRI,
  MAC_DND,
  CTRL_TAB,
  CTRL_BACK_TAB,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    TD(DANCE_0),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    TD(DANCE_1),    KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_DELETE,
    TD(DANCE_2),    KC_A,           MT(MOD_LSFT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LALT, KC_T),KC_D,                                           KC_H,           MT(MOD_RGUI, KC_N),MT(MOD_RALT, KC_E),MT(MOD_RCTL, KC_I),MT(MOD_RSFT, KC_O),KC_QUOTE,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLS,
                                                    LT(1,KC_MINUS), TD(DANCE_3),                                    LT(4,KC_ENTER), LT(2,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    LGUI(LSFT(KC_GRAVE)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    CTRL_TAB,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
    CTRL_BACK_TAB, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(3)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
    KC_TILD,        KC_GRAVE,       KC_NO,          KC_HASH,        KC_NO,          KC_NO,                                          KC_CIRC,        KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_EQUAL,       KC_DLR,         KC_PERC,                                        KC_AMPR,        KC_LPRN,        KC_LCBR,        KC_LBRC,        KC_ASTR,        KC_DQUO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_QUES,        KC_PIPE,        KC_LABK,        KC_RABK,        KC_NO,          KC_NO,
                                                    MO(3),          KC_TRANSPARENT,                                 LT(6,KC_ENTER), KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_F14),   LCTL(KC_F15),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,MAC_MISSION_CONTROL,MAC_SPOTLIGHT,  MAC_SIRI,                                       MAC_DND,        KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, LSFT(KC_F14),   LSFT(KC_F15),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          LGUI(KC_UP),    LGUI(KC_DOWN),  KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PAGE_UP,     ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    MO(5),                                          LGUI(KC_LEFT),  LALT(KC_LEFT),  KC_UP,          RALT(KC_RIGHT), RGUI(KC_RIGHT), KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          LCTL(KC_MINUS), LCTL(LSFT(KC_EQUAL)),KC_NO,                                          KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(6,KC_ENTER), LT(6,KC_SPACE)
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          ST_MACRO_3,     ST_MACRO_4,     KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(KC_BSPC),  LALT(KC_BSPC),  KC_NO,          RALT(KC_DELETE),RGUI(KC_DELETE),KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LBRC),  LGUI(KC_RBRC),  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_L),     LGUI(LSFT(KC_R)),KC_TRANSPARENT, LGUI(KC_Y),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(KC_J)),KC_TRANSPARENT, LGUI(KC_D),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_SAI,        RGB_HUI,        RGB_VAI,        KC_TRANSPARENT, RGB_SPI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_SAD,        RGB_HUD,        RGB_VAD,        KC_TRANSPARENT, RGB_SPD,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM combo1[] = { LT(2,KC_SPACE), LT(1,KC_MINUS), COMBO_END};
const uint16_t PROGMEM combo2[] = { LT(2,KC_SPACE), LT(4,KC_ENTER), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(7)),
    COMBO(combo1, OSL(3)),
    COMBO(combo2, OSL(6)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_R):
            return g_tapping_term + 15;
        case MT(MOD_RCTL, KC_I):
            return g_tapping_term + 35;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {144,255,255}, {204,223,253}, {204,223,253}, {99,232,255}, {144,255,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {85,255,255}, {204,225,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {0,255,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {0,255,255}, {99,232,255}, {204,223,253}, {204,223,253}, {204,223,253}, {144,255,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {99,232,255}, {60,255,255}, {21,255,255} },

    [1] = { {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255}, {74,255,255}, {0,0,0}, {21,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255}, {21,255,255}, {157,255,255}, {21,255,255}, {21,255,255}, {144,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255}, {86,255,255}, {0,255,255}, {41,255,255}, {186,255,255}, {0,0,0}, {157,255,255}, {86,255,255}, {0,255,255}, {41,255,255}, {0,245,245}, {143,255,255}, {41,255,255}, {193,218,204}, {130,255,255}, {130,255,255}, {41,255,255}, {193,218,204}, {229,255,255}, {0,0,0} },

    [3] = { {0,0,0}, {144,255,255}, {144,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,113,255}, {144,113,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,255,255}, {144,255,255}, {44,255,255}, {44,255,255}, {112,255,255}, {0,0,0}, {144,113,255}, {144,113,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {99,255,255}, {44,255,255}, {45,255,255}, {45,255,255}, {44,255,255}, {0,255,255}, {99,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,255,255}, {204,223,253}, {204,225,255}, {0,255,255}, {144,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,145}, {0,0,0}, {0,0,0}, {0,0,0}, {97,255,255}, {97,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {193,218,204}, {144,255,255}, {144,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {112,255,255}, {111,255,255}, {60,255,255}, {111,255,255}, {111,255,255}, {0,0,0}, {193,218,204}, {60,255,255}, {60,255,255}, {60,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {229,255,255} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {143,255,255}, {143,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {80,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255}, {0,0,0}, {118,235,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {21,255,255}, {85,255,255}, {144,255,255}, {0,0,0}, {186,255,255}, {0,0,0}, {21,255,255}, {85,255,255}, {144,255,255}, {0,0,0}, {186,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1,KC_MINUS):
    if (!record->tap.count && !record->event.pressed) {
      if (get_mods() == MOD_BIT(KC_LEFT_CTRL)) {
        unregister_code(KC_LEFT_CTRL);
      }
    }
    break;

    case CTRL_TAB:
    if (record->event.pressed){
        register_code(KC_LEFT_CTRL);
        register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
    }
    return false;

    case CTRL_BACK_TAB:
    if (record->event.pressed){
        register_code(KC_LEFT_CTRL);
        register_code16(LSFT(KC_TAB));
    } else {
        unregister_code16(LSFT(KC_TAB));
    }
    return false;

    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) SS_DELAY(MACRO_DELAY) SS_LALT(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(MACRO_DELAY) SS_LGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)) SS_DELAY(MACRO_DELAY) SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT))) SS_DELAY(MACRO_DELAY) SS_LGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_LGUI(SS_TAP(X_BSPC)));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(MACRO_DELAY) SS_TAP(X_BSPC));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_DOWN))) SS_DELAY(MACRO_DELAY) SS_TAP(X_BSPC));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) SS_DELAY(MACRO_DELAY) SS_LALT(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(MACRO_DELAY) SS_TAP(X_BSPC));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_RGUI(SS_TAP(X_BSPC)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_RGUI(SS_TAP(X_BSPC)));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_SPOTLIGHT:
      HCS(0x221);
    case MAC_SIRI:
      HCS(0xCF);
    case MAC_DND:
      HSS(0x9B);

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    default:
      if (record->event.pressed){
        if (IS_LAYER_ON(1)){
          if (get_mods() == MOD_BIT(KC_LEFT_CTRL)) {
            unregister_code(KC_LEFT_CTRL);
          }
          break;
        }
      }
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_ESCAPE, KC_GRAVE),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, KC_CAPS),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(LSFT(KC_TAB), KC_CAPS),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, KC_LEFT_GUI),
};
