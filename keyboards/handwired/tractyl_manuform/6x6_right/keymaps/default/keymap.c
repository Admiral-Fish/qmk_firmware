// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    _COLEMAK,
    _GAME,
    _MOUSE,
    _LOWER,
    _RAISE
};

enum {
    TD_PLUS_GAME,
    TD_SFT_CAPS
};

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define MOUSE   TT(_MOUSE)
#define TG_GAME TG(_GAME)

#define HOME_R LCTL_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_T LGUI_T(KC_T)

#define HOME_N LGUI_T(KC_N)
#define HOME_E LALT_T(KC_E)
#define HOME_I LCTL_T(KC_I)

#define SPC_RAISE LT(_RAISE, KC_SPC)
#define ENT_LOWER LT(_LOWER, KC_ENT)

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_PLUS_GAME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PLUS, _GAME),
    [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_6x6_right(
        KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,                                  KC_F7,           KC_F8,     KC_F9,   KC_F10, KC_F11,  KC_F12,
        KC_GRV,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,            KC_7,      KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,                                   KC_J,            KC_L,      KC_U,    KC_Y,   KC_SCLN, KC_MINS,
        KC_LSFT, KC_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                                   KC_M,            HOME_N,    HOME_E,  HOME_I, KC_O,    KC_QUOT,
        KC_LCTL, KC_Z,  KC_X,    KC_C,    KC_D,    KC_V,                                   KC_K,            KC_H,      KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                        KC_LBRC, KC_RBRC,                                                                              TD(TD_PLUS_GAME), KC_EQL,
                                          KC_BSPC, SPC_RAISE,                                               ENT_LOWER,
                                                   KC_TAB,    TD(TD_SFT_CAPS),             TD(TD_SFT_CAPS),
                                                   KC_DEL,    MOUSE,                MOUSE, KC_ESC
    ),

    [_GAME] = LAYOUT_6x6_right(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        KC_ESC,  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,                           _______, _______, _______, _______, _______, _______,
        KC_F1,   KC_K,    KC_Q,    KC_W,    KC_E,    KC_R,                           _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                           _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_H,                           _______, _______, _______, _______, _______, _______,
                          KC_I,    KC_T,                                                               TG_GAME, KC_NO,
                                            KC_V,    KC_SPC,                                  _______,
                                                     KC_O,   KC_P,                  _______,
                                                     KC_H,   KC_LGUI,      _______, _______
    ),

    [_MOUSE] = LAYOUT_6x6_right(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                        _______, DPI_RMOD,DPI_MOD, S_D_RMOD,S_D_MOD, SNP_TOG,
        _______, _______, _______, _______, _______, _______,                        _______, KC_WH_U, KC_WH_D, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                        DRGSCRL, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN6, SNIPING,
        _______, _______, _______, _______, _______, _______,                        KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
                          _______, _______,                                                            _______, _______,
                                            _______, _______,                                 _______,
                                                     _______, _______,               _______,
                                                     _______, _______,      _______, _______
    ),

    [_LOWER] = LAYOUT_6x6_right(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, _______, _______, _______, _______, KC_LBRC,                        KC_RBRC, KC_P7,   KC_P8,   KC_P9,   _______, KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,                        KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,                        _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                          _______, KC_PSCR,                                                            _______, KC_P0,
                                            _______, _______,                                 _______,
                                                     _______, _______,               _______,
                                                     _______, _______,      _______, QK_BOOT

    ),

    [_RAISE] = LAYOUT_6x6_right(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______,     _______, _______,        _______,
        _______, _______, _______, _______, _______, KC_LBRC,                        KC_RBRC, _______, KC_NUM_LOCK, KC_INS,  KC_SCROLL_LOCK, KC_MUTE,
        _______, _______, _______, _______, _______, KC_LPRN,                        KC_RPRN, KC_MPRV, KC_MPLY,     KC_MNXT, _______,        KC_VOLU,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,                        _______, _______, _______,     _______, _______,        KC_VOLD,
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______,     _______, _______,        _______,
                          _______, _______,                                                            KC_EQL,      _______,
                                            _______, _______,                                 _______,
                                                     _______, _______,               _______, 
                                                     QK_BOOT, _______,      _______, _______
    )
};
