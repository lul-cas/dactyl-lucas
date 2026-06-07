#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _L1,
    _L2,
    _L3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_NO,
        KC_LSFT, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_NO,
        KC_LCTL, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,
        KC_NO,   KC_NO,    KC_LGUI,  MO(_L1),  KC_LALT,  MO(_L1),  KC_SPC,

        KC_BSPC, KC_P,     KC_O,     KC_I,     KC_U,     KC_Y,     KC_NO,
        KC_QUOT, KC_SCLN,  KC_L,     KC_K,     KC_J,     KC_H,     KC_NO,
        KC_ESC,  KC_SLSH,  KC_DOT,   KC_COMM,  KC_M,     KC_N,     KC_NO,
        KC_NO,   KC_NO,    KC_NO,  KC_NO,    KC_RALT,    MO(_L2),   KC_ENT
    ),

    [_L1] = LAYOUT(
        KC_TAB,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_NO,
        KC_LSFT, KC_GRV,   _______,  _______,  _______,  _______,  KC_NO,
        KC_LCTL, KC_LALT,  _______,  _______,  _______,  _______,  KC_NO,
        KC_NO,   KC_NO,    KC_LGUI,  _______,  KC_LALT,  _______,  KC_SPC,

        KC_BSPC, KC_0,     KC_9,     KC_8,     KC_7,     KC_6,     KC_NO,
        _______, KC_RGHT,  KC_UP,    KC_DOWN,  KC_LEFT,  _______,  KC_NO,
        KC_ESC,  _______,  _______,  _______,  _______,  KC_N,     KC_NO,
        KC_NO,   KC_NO,    KC_RALT,  KC_NO,    KC_NO,    KC_ENT,   KC_ENT
    ),

    [_L2] = LAYOUT(
        KC_TAB,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_NO,
        KC_LSFT, KC_BSLS,  _______,  _______,  _______,  _______,  KC_NO,
        KC_LCTL, _______,  _______,  _______,  _______,  _______,  KC_NO,
        KC_NO,   KC_NO,    KC_LALT,  _______,  _______,  _______,  KC_SPC,

        KC_BSPC, KC_RPRN,  KC_LPRN,  KC_ASTR,  KC_AMPR,  KC_CIRC,  KC_NO,
        KC_TILD, KC_BSLS,  KC_RCBR,  KC_LCBR,  KC_PLUS,  KC_EQL,   KC_NO,
        KC_MINS, KC_PIPE,  KC_RBRC,  KC_LBRC,  KC_PLUS,  KC_UNDS,  KC_NO,
        KC_NO,   KC_NO,    KC_RALT,  KC_NO,    KC_NO,    KC_ENT,   KC_ENT
    ),

    [_L3] = LAYOUT(
        QK_BOOT, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_NO,
        _______, _______,  _______,  _______,  _______,  _______,  KC_NO,
        _______, _______,  _______,  _______,  _______,  _______,  KC_NO,
        KC_NO,   KC_NO,    KC_LGUI,  _______,  _______,  _______,  KC_SPC,

        KC_PSCR, KC_F10,   KC_F9,    KC_F8,    KC_F7,    KC_F6,    KC_NO,
        _______, KC_DEL,   _______,  _______,  _______,  KC_F12,   KC_NO,
        _______, _______,  _______,  _______,  _______,  _______,  KC_NO,
        KC_NO,   KC_NO,    KC_RALT,  KC_NO,    KC_NO,    KC_ENT,   KC_ENT
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _L1) && layer_state_cmp(state, _L2)) {
        state |= (1UL << _L3);
    } else {
        state &= ~(1UL << _L3);
    }

    return state;
}
