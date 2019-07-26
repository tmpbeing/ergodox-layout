#include QMK_KEYBOARD_H

// The idea : tmux/WM key when pressed once -> go to WM layer and add windows modifier
//                        when pressed twice -> go to tmyx layer and input ctrl-a

#define WM_MOD MOD_LGUI
#define TMUX_PREFIX "a"

// Layers
enum {
    BASE = 0,
    WM,
    TMUX,
    FN,
    FR,
    NUM,
};

// Custom keycodes
enum {
    CT_LBP,
    CT_RBP,
    CT_WM_TMUX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | ESC `|           | Fn   |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |      ~ |   Q  |   W  |   E  |   R  |   T  | { (  |           | ) }  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|   [  |           | ]    |------+------+------+------+------+--------|
     * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |'       |
     * |--------+------+------+------+------+------|Tmux  |           | Tmux |------+------+------+------+------+--------|
     * | LShift |Z\Ctrl|   X  |   C  |   V  |   B  | WM   |           |  WM  |   N  |   M  |   ,  |   .  |//Ctrl| Fn     |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      | Esc  |                                       | Esc  |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LAlt | LGui |       | FR   | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | CAPS |       | Lead |      |      |
     *                                 |Backsp|LShift|------|       |------| Enter|Space |
     *                                 |      |      |NumPad|       |NumLoc|      |      |
     *                                 `--------------------'       `--------------------'
     */

[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_GESC,
  KC_DELT,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TD(CT_LBP),
  KC_TAB,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,        LCTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    TD(CT_WM_TMUX),
  KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC,
                                                           KC_LALT, KC_LGUI,
                                                                          KC_CAPSLOCK,
                                                         KC_BSPC, KC_LSFT, MO(NUM),
  // right hand
  TT(FN),         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS,
  TD(CT_RBP),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_BSLS,
                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT,
  TD(CT_WM_TMUX), KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), TT(FN),
                           KC_ESC,  KC_NO,   KC_NO,   KC_NO,           KC_NO,
  TG(FR),         KC_DELT,
  KC_LEAD,
  TG(NUM),        KC_ENT,  KC_SPC
),

/* Keymap 1: WM controls
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[WM] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Tmux controls
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[TMUX] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 3: FN : Media, mouse, arrows and function keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MUP  |      |      |      |           |      | HOME | PGUP | PGDW | END  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MLEFT| MDOWN|MRIGHT|      |------|           |------| LEFT | DOWN |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |LCLICK|RCLICK|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | MUTE |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | PLAY | PREV |       | VOL+ |      |      |
 *                                 | STOP | PAUSE|------|       |------|      |      |
 *                                 |      |      | NEXT |       | VOL- |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FN] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS,       KC_TRNS,
                                                              KC_MEDIA_PREV_TRACK,
                                               KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,     KC_F8,   KC_F9,    KC_F10,  KC_TRNS,
  KC_TRNS, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
           KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                    KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_AUDIO_MUTE, KC_TRNS,
  KC_AUDIO_VOL_UP,
  KC_AUDIO_VOL_DOWN, KC_TRNS, KC_TRNS
),

/* Keymap 4: Special french characters
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FR] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

// TODO: Auto numlock when switching to this layer
/* Keymap 5: Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | KPLOC| KP/  | KP*  | KP-  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | KP1  | KP2  | KP3  | KP+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | KP6  | KP5  | KP4  | KP+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | KP7  | KP8  | KP9  | KPENT|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | KP0  | KP0  | KPDEL| KPENT|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_PLUS, KC_TRNS,
           KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ENTER, KC_TRNS,
                    KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};


static void _td_brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->keycode == TD(CT_LBP))
            register_code16(KC_LBRC);
        else
            register_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (state->keycode == TD(CT_LBP))
            register_code16(KC_LPRN);
        else
            register_code16(KC_RPRN);
    }
}

static void _td_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->keycode == TD(CT_LBP))
            unregister_code16(KC_LBRC);
        else
            unregister_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (state->keycode == TD(CT_LBP))
            unregister_code16(KC_LPRN);
        else
            unregister_code16(KC_RPRN);
    }
}

static void _td_window_controls(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        set_oneshot_layer(WM, ONESHOT_START);
        set_oneshot_mods(WM_MOD);
    } else {
        set_oneshot_layer(TMUX, ONESHOT_START);
        SEND_STRING(SS_LCTRL(TMUX_PREFIX));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_LBP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_RBP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_WM_TMUX] = ACTION_TAP_DANCE_FN(_td_window_controls)
};
