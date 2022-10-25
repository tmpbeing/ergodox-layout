#include QMK_KEYBOARD_H

#define WM_MOD MOD_LGUI
#define TMUX_PREFIX "a"

// Layers
enum {
    BASE = 0,
    GAMES,
    WM,
    TMUX,
    FN,
    FR,
    NUM,
};

// Custom keycodes
enum {
// TapDance
    CT_LBP,
    CT_RBP,
    CT_WM_TMUX,
// French characters
    CT_A_CIRCONFLEXE = SAFE_RANGE,
    CT_A_GRAVE,
    CT_A_TREMA,
    CT_E_AIGU,
    CT_E_CIRCONFLEXE,
    CT_E_GRAVE,
    CT_E_TREMA,
    CT_I_CIRCONFLEXE,
    CT_I_TREMA,
    CT_O_CIRCONFLEXE,
    CT_O_TREMA,
    CT_U_CIRCONFLEXE,
    CT_U_GRAVE,
    CT_U_TREMA,
    CT_C_CEDILLE,
// Other
    CT_REVERSE_BACKTICK_TILDE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           | Fn   |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   `    |   Q  |   W  |   E  |   R  |   T  | { (  |           | ) }  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------| < [  |           | ] >  |------+------+------+------+------+--------|
     * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |'       |
     * |--------+------+------+------+------+------|Tmux  |           | Tmux |------+------+------+------+------+--------|
     * | LShift |Z\Ctrl|   X  |   C  |   V  |   B  | WM   |           |  WM  |   N  |   M  |   ,  |   .  |/\Ctrl| Fn     |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      | Esc  |                                       | Esc  |      |      |      | Game |
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
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  CT_REVERSE_BACKTICK_TILDE,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TD(CT_LBP),
  KC_TAB,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,        LCTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    TD(CT_WM_TMUX),
  KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC,
                                                           KC_LALT, KC_LGUI,
                                                                          KC_CAPSLOCK,
                                                         KC_BSPC, KC_SFTENT, MO(NUM),
  // right hand
  TT(FN),         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS,
  TD(CT_RBP),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_BSLS,
                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT,
  TD(CT_WM_TMUX), KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), TT(FN),
                           KC_ESC,  KC_NO,   KC_NO,   KC_NO,           TG(GAMES),
  OSL(FR),         KC_DELT,
  KC_LEAD,
  TG(NUM),        KC_ENT,  KC_SPC
),


[GAMES] = LAYOUT_ergodox(
  // left hand
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
  KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LSFT, KC_Z, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT,
  KC_F1, KC_F2, KC_F3, KC_F4, KC_LALT,
                                               KC_KP_ASTERISK, KC_K,
                                                        KC_Y,
                                      KC_BSPC, KC_SLSH, KC_U,
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

/* Keymap 2: WM controls
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

/* Keymap 3: Tmux controls
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
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 4: FN : Media, mouse, arrows and function keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 | EE_CLR |
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
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_UP, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2,
                                               KC_TRNS,       KC_TRNS,
                                                              KC_MEDIA_PREV_TRACK,
                                               KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,     KC_F8,   KC_F9,    KC_F10,  EE_CLR,
  KC_TRNS, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
           KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                    KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_AUDIO_MUTE, KC_TRNS,
  KC_AUDIO_VOL_UP,
  KC_AUDIO_VOL_DOWN, KC_TRNS, KC_TRNS
),

/* Keymap 5: Special french characters
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  ä   |  ë   |  ï   |  ö   |  ü   |      |           |      |  ç   |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  à   |  ê   |  î   |  ô   |  û   |      |           |      |  ç   |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  à   |  à   |      |      |  ù   |------|           |------|  ç   |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  é   |      |      |      |      |           |      |  ç   |      |      |      |      |        |
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
  KC_TRNS, CT_A_TREMA, CT_E_TREMA, CT_I_TREMA, CT_O_TREMA, CT_U_TREMA, KC_TRNS,
  KC_TRNS, CT_A_CIRCONFLEXE, CT_E_CIRCONFLEXE, CT_I_CIRCONFLEXE, CT_O_CIRCONFLEXE, CT_U_CIRCONFLEXE, KC_TRNS,
  KC_TRNS, CT_A_GRAVE, CT_E_GRAVE, KC_TRNS, KC_TRNS, CT_U_GRAVE,
  KC_TRNS, KC_TRNS, CT_E_AIGU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, CT_C_CEDILLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, CT_C_CEDILLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           CT_C_CEDILLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, CT_C_CEDILLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

// TODO: Auto numlock when switching to this layer
/* Keymap 6: Numpad
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
)
};


void _td_brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            register_code16(KC_LBRC);
        else
            register_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            register_code16(KC_LPRN);
        else
            register_code16(KC_RPRN);
    } else if (state->count == 3) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            register_code16(KC_LABK);
        else
            register_code16(KC_RABK);
    }
}

void _td_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            unregister_code16(KC_LBRC);
        else
            unregister_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            unregister_code16(KC_LPRN);
        else
            unregister_code16(KC_RPRN);
    } else if (state->count == 3) {
        if (TAP_DANCE_KEYCODE(state) == TD(CT_LBP))
            unregister_code16(KC_LABK);
        else
            unregister_code16(KC_RABK);
    }
}

void _td_window_controls_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        set_oneshot_layer(WM, ONESHOT_START);
        set_oneshot_mods(WM_MOD);
    } else {
        set_oneshot_layer(TMUX, ONESHOT_START);
        SEND_STRING(SS_LCTRL(TMUX_PREFIX));
    }
}

void _td_window_controls_reset(qk_tap_dance_state_t *state, void *user_data) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_LBP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_RBP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_WM_TMUX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _td_window_controls_finished, _td_window_controls_reset)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
            break;
        case WM:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
            break;
        case TMUX:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
            break;
        case FN:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
            break;
        case FR:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
            break;
        case NUM:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
            break;
        case GAMES:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
            break;
        default:
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
            break;
    }
    return state;
}

void suspend_power_down_user(void) {
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    rgblight_enable();
}

bool is_shift_active(void) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    if ( (temp_mod | temp_osm) & MOD_MASK_SHIFT ) {
        return true;
    }
    return false;
}

void do_accentuated_character(char *accent, char *character, keyrecord_t *record) {
    bool is_shifted = is_shift_active();
    if (is_shifted) {
        clear_mods(); clear_oneshot_mods();
    }
    if (record->event.pressed) {
        clear_mods();
        SEND_STRING(SS_DOWN(X_RALT));
        send_string(accent);
        SEND_STRING(SS_UP(X_RALT));
        if (is_shifted) {
            SEND_STRING(SS_DOWN(X_LSHIFT));
        }
        send_string(character);
        if (is_shifted) {
            SEND_STRING(SS_UP(X_LSHIFT));
        }
        reset_oneshot_layer();
        layer_off(FR);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TRNS:
        case KC_NO:
            if (record->event.pressed && is_oneshot_layer_active()) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            return true;
        case CT_A_CIRCONFLEXE:
            do_accentuated_character("^", "a", record);
            return false;
        case CT_A_GRAVE:
            do_accentuated_character("`", "a", record);
            return false;
        case CT_A_TREMA:
            do_accentuated_character("\"", "a", record);
            return false;
        case CT_E_AIGU:
            do_accentuated_character("'", "e", record);
            return false;
        case CT_E_CIRCONFLEXE:
            do_accentuated_character("^", "e", record);
            return false;
        case CT_E_GRAVE:
            do_accentuated_character("`", "e", record);
            return false;
        case CT_E_TREMA:
            do_accentuated_character("\"", "e", record);
            return false;
        case CT_I_CIRCONFLEXE:
            do_accentuated_character("^", "i", record);
            return false;
        case CT_I_TREMA:
            do_accentuated_character("\"", "i", record);
            return false;
        case CT_O_CIRCONFLEXE:
            do_accentuated_character("^", "o", record);
            return false;
        case CT_O_TREMA:
            do_accentuated_character("\"", "o", record);
            return false;
        case CT_U_CIRCONFLEXE:
            do_accentuated_character("^", "u", record);
            return false;
        case CT_U_GRAVE:
            do_accentuated_character("`", "u", record);
            return false;
        case CT_U_TREMA:
            do_accentuated_character("\"", "u", record);
            return false;
        case CT_C_CEDILLE:
            do_accentuated_character(",", "c", record);
            return false;
        case CT_REVERSE_BACKTICK_TILDE:
            if (record->event.pressed) {
                if (is_shift_active()) {
                    SEND_STRING(SS_UP(X_LSHIFT)"`"SS_DOWN(X_LSHIFT));
                } else {
                    SEND_STRING("~");
                }
            }
            return false;
        default:
            return true;
    }
    return true;
}
