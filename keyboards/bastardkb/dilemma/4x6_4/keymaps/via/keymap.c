/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
// #undef POINTING_DEVICE_GESTURES_SCROLL_ENABLE

#ifdef MACCEL_ENABLE
#include "../../../../charybdis/4x6/keymaps/via/qmk_userspace_features/maccel/maccel.h"
#endif

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_FAST,
    LAYER_PTR,
};

enum {
    TD_GRV_ESC,
    TD_M_RBRC,
    TD_T_GRV,
    TD_PGUP_HOME,
    TD_PGDN_END,
    TD_BSPC_DEL,
    TD_SLSH_QM,
    TD_PLUS_MUL,
    TD_MINS_DIV,
    TD_TAB_CAPSWORD,
    TD_TG3_ALT,
    TD_CLAN_GUI,
    TD_TG_NUM_FAST,
    KC_SPCW = SAFE_RANGE,   // Macros part
    KC_FAST,
};

#define TD_GRES TD(TD_GRV_ESC)
#define TD_MRBR TD(TD_M_RBRC)
#define TD_TGRV TD(TD_T_GRV)
#define TD_UPHM TD(TD_PGUP_HOME)
#define TD_DNEN TD(TD_PGDN_END)
#define TD_SLQM TD(TD_SLSH_QM)
#define TD_PLML TD(TD_PLUS_MUL)
#define TD_MNDV TD(TD_MINS_DIV)
#define TD_TBCW TD(TD_TAB_CAPSWORD)
#define TD_TGAL TD(TD_TG3_ALT)
#define TD_CLGU TD(TD_CLAN_GUI)
#define TD_NUFA TD(TD_TG_NUM_FAST)

#define MT_DCTL MT(MOD_LCTL, KC_D)
#define MT_FSFT MT(MOD_LSFT, KC_F)
#define MT_JSFT MT(MOD_RSFT, KC_J)
#define MT_KCTL MT(MOD_RCTL, KC_K)
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3
#define MS_WHUP KC_MS_WH_UP
#define MS_WHDN KC_MS_WH_DOWN
#define MS_WHLT KC_MS_WH_LEFT
#define MS_WHRT KC_MS_WH_RIGHT

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_PTR

#define LOWER MO(LAYER_NUM)
#define RAISE MO(LAYER_FAST)
#define PT_Z LT(LAYER_PTR, KC_Z)
#define PT_SLSH LT(LAYER_PTR, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
#define DILEMMA_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       TD_GRES,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TD_TBCW,    KC_Q,    KC_W,    KC_E,    KC_R, TD_TGRV,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_EQL,    KC_A,    KC_S, MT_DCTL, MT_FSFT,    KC_G,       KC_H, MT_JSFT, MT_KCTL,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MINS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N, TD_MRBR, KC_COMM,  KC_DOT, TD_SLQM, KC_BSLS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         TD_CLGU,  KC_ENT,  KC_SPC, KC_BSPC,    TD_UPHM, TD_DNEN, TD_TGAL, TD_NUFA
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        EE_CLR,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CALC,   KC_NO,   KC_NO, RGB_MOD, KC_VOLU, KC_MNXT,    KC_PEQL,   KC_P7,   KC_P8,   KC_P9,  KC_TAB, KC_RGHT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_PSCR, RGB_SPI, RGB_VAI, RGB_TOG, KC_MUTE, KC_MPLY,    TD_PLML,   KC_P4,   KC_P5,   KC_P6,   KC_P0, KC_LEFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_SLEP, RGB_SPD, RGB_VAD,RGB_RMOD, KC_VOLD, KC_MPRV,    TD_MNDV,   KC_P1,   KC_P2,   KC_P3, KC_PCMM, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_FAST] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TD_TBCW,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         TD_CLGU,  KC_ENT,  KC_SPC, KC_BSPC,    TD_UPHM, TD_DNEN, TD_TGAL, TD_NUFA
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_PTR] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB, DRG_TOG, DRGSCRL, MS_BTN2, MS_BTN1, MS_BTN3,    MS_WHLT, MS_WHDN, MS_WHUP, MS_WHRT,   KC_NO,   KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_RSFT,   KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    MS_BTN3, MS_BTN1, MS_BTN2, DRGSCRL, DRG_TOG,   KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
{
#ifdef MACCEL_ENABLE
    mouse_report = pointing_device_task_maccel(mouse_report);
#endif

    if (abs(mouse_report.x) || abs(mouse_report.y))
    {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_PTR);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= DILEMMA_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_PTR);
    }
}
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NUM]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_FAST]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_PTR]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

// Tap dance part

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD_GRES:
        case TD_MRBR:
        case TD_TGRV:
        case TD_UPHM:
        case TD_DNEN:
        case TD_TBCW:
        case TD_SLQM:
        case TD_PLML:
        case TD_MNDV:
        {
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished)
            {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        }
        case TD_TGAL:
        case TD_NUFA:
        {
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished)
            {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                // Layer number passed via tap
                layer_invert(tap_hold->tap);
            }
            break;
        }
        case TD_CLGU:
        {
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_SPC) SS_DELAY(200) SS_UP(X_SPC) SS_UP(X_LGUI));
            }
            break;
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
            if (tap_hold->hold == KC_SPCW)
            {
                caps_word_on();
            }
            else if (tap_hold->hold == KC_FAST)
            {
                layer_invert(LAYER_FAST);
            }
            else
            {
                register_code16(tap_hold->hold);
            }
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
    [TD_GRV_ESC]        = ACTION_TAP_DANCE_TAP_HOLD(KC_GRV,     KC_ESC),
    [TD_M_RBRC]         = ACTION_TAP_DANCE_TAP_HOLD(KC_M,       KC_RBRC),
    [TD_T_GRV]          = ACTION_TAP_DANCE_TAP_HOLD(KC_T,       KC_GRV),
    [TD_PGUP_HOME]      = ACTION_TAP_DANCE_TAP_HOLD(KC_PGUP,    KC_HOME),
    [TD_PGDN_END]       = ACTION_TAP_DANCE_TAP_HOLD(KC_PGDN,    KC_END),
    [TD_SLSH_QM]        = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH,    S(KC_SLSH)),
    [TD_PLUS_MUL]       = ACTION_TAP_DANCE_TAP_HOLD(KC_PPLS,    KC_PAST),
    [TD_MINS_DIV]       = ACTION_TAP_DANCE_TAP_HOLD(KC_PMNS,    KC_PSLS),
    [TD_TAB_CAPSWORD]   = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB,     KC_SPCW),
    [TD_TG3_ALT]        = ACTION_TAP_DANCE_TAP_HOLD(LAYER_PTR,  KC_LALT),
    [TD_CLAN_GUI]       = ACTION_TAP_DANCE_TAP_HOLD(KC_NO,      KC_LGUI),
    [TD_TG_NUM_FAST]    = ACTION_TAP_DANCE_TAP_HOLD(LAYER_NUM,  KC_FAST),
};

// Overrides part

const key_override_t delete_key_override    = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t pgdn_key_override      = ko_make_basic(MOD_MASK_SHIFT, TD_DNEN, KC_MS_BTN4);
const key_override_t pgup_key_override      = ko_make_basic(MOD_MASK_SHIFT, TD_UPHM, KC_MS_BTN5);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
    &pgdn_key_override,
    &pgup_key_override,
	NULL // Null terminate the array of overrides!
};

// Caps Word part

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_SCLN:
        case KC_QUOT:
        case KC_RBRC:
        case KC_LBRC:
        case KC_GRV:
        case KC_DOT:
        case KC_COMM:
        case TD_TGRV:
        case TD_MRBR:
        case TD_SLQM:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
