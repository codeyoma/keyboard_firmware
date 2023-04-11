/* Copyright 2018 MakotoKurauchi
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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _YOMA
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LOWER,
    RAISE,
    ADJUST,
    YOMA,
    BACKLIT,
    EISU,
    KANA,
    RGBRST,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOV_L_NERD,
	MOV_R_NERD,
};

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

// Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------.             ,-----------------------------------------.
     * | GEsc |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | Enter|
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * | Ctlr | Alt  |Adjust| Yoma | GUI  |Space |Lower |Raise |Space | GUI  | Yoma | GUI  | Alt  | Ctrl |
     * `-------------------------------------------------------------------------------------------------'
     */

    [_QWERTY] = LAYOUT(
        QK_GESC,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,                     KC_Y,   KC_U,    KC_I,      KC_O,     KC_P,     KC_BSPC, \
        KC_TAB,    KC_A,     KC_S,     KC_D,    KC_F,     KC_G,                     KC_H,   KC_J,    KC_K,      KC_L,     KC_SCLN,  KC_ENT, \
        KC_LSFT,   KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,                     KC_N,   KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,  KC_RSFT, \
        KC_LCTL,   KC_LALT,  ADJUST,   YOMA,    KC_LGUI,  KC_SPC,    LOWER,  RAISE, KC_SPC, KC_RGUI, YOMA,      KC_RGUI,  KC_RALT,  KC_RCTL),
    /* Colemak
     * ,-----------------------------------------.             ,-----------------------------------------.
     * | GESC |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Tab  |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  | Enter|
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * | Ctlr | Alt  |Adjust| Yoma | GUI  |Space |Lower |Raise |Space | GUI  | Yoma | GUI  | Alt  | Ctrl |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT(
        QK_GESC,    KC_Q,      KC_W,     KC_F,   KC_P,    KC_G,                      KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC, \
        KC_TAB,     KC_A,      KC_R,     KC_S,   KC_T,    KC_D,                      KC_H,   KC_N,    KC_E,    KC_I,    KC_O,     KC_ENT, \
        KC_LSFT,    KC_Z,      KC_X,     KC_C,   KC_V,    KC_B,                      KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
        KC_LCTL,   KC_LALT,  ADJUST,   YOMA,    KC_LGUI,  KC_SPC,    LOWER,  RAISE, KC_SPC, KC_RGUI, YOMA,      KC_RGUI,  KC_RALT,  KC_RCTL),

    /* Lower
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |             |  6 ^ | 7 &  |  8 * |  9 ( |  0 ) | Del  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | CAPS |      |  Ins |PageUp| Home |Cmd+[ |             |Cmd+] |  - _ |   +  |  [ { |  ] } |  ' " |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |  Del |PageDn|  End |Ctl+wh|             |Ctl+wu|   _  |   =  |      |  \ | |      |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | KANA |      | EISU |      |      |      |      |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______, \
        KC_CAPS,    _______,    KC_INS,     KC_HOME,    KC_PGUP,    MOVE_LEFT,                          MOVE_RIGHT, KC_MINS,    KC_PPLS,    KC_LBRC,    KC_RBRC,    KC_QUOT, \
        _______,    _______,    KC_DEL,     KC_END,     KC_PGDN,    MOV_L_NERD,                         MOV_R_NERD, KC_UNDS,    KC_EQL,     _______,    KC_BSLS,    _______, \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_INT2,    _______,    KC_INT1,    _______,    _______,    _______,    _______),

    /* Raise
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |  F9  |  F10 |  F11 |  F12 | Home |             |      |  Ins |  Del |      |PageUp| Home |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  | End  |             | Left | Down |  Up  |Right |PageDn| End  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |      |             |M Play| Vol+ |M Next|      |      |      |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |M Mute| Vol- |M Prev| Vol- | Vol+ |M Next|
     * `-------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        _______,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_HOME,                            _______,    KC_INS,     KC_DEL,     _______,    KC_PGUP,    KC_HOME, \
        _______,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_END,                             KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_PGDN,    KC_END, \
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      _______,                            KC_MPLY,    KC_VOLU,    KC_MNXT,    _______,    _______,    _______, \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MUTE,    KC_VOLD,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------.             ,-----------------------------------------.
     * | Reset|Qwerty|Colemk|MU TOG|CK TOG|Au TOG|             |RGB SN|RGB SW|RGB G |RGB RM|RGBMOD|RGBTOG|
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |MU Nxt| CK UP|Au Prv|             |RGB K |RGB B |RGB T | HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      | CK DN|Au Nxt|             |RGB X |RGB R |RGB P | HUE- | SAT- | VAL- |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |RGBRST|
     * `-------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT(
        QK_RBT,     QWERTY,     COLEMAK,    MU_TOGG,    CK_TOGG,    AU_TOGG,                            RGB_M_SN,   RGB_M_SW,   RGB_M_G,    RGB_RMOD,    RGB_MOD,    RGB_TOG,\
        _______,    _______,    _______,    MU_NEXT,    CK_UP,      AU_PREV,                            RGB_M_K,    RGB_M_B,    RGB_M_T,    RGB_HUI,    RGB_SAI,    RGB_VAI,\
        _______,    _______,    _______,    _______,    CK_DOWN,    AU_NEXT,                            RGB_M_X,    RGB_M_R,    RGB_M_P,   RGB_HUD,    RGB_SAD,    RGB_VAD,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGBRST),

    /* Yoma (For Macro)
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |      |      |      |      |      |             |      |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |      |      |      |      |      |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_YOMA] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______)
};

#ifdef AUDIO_ENABLE

float tone_qwerty[][2] = SONG(QWERTY_SOUND);
// float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]   = SONG(COLEMAK_SOUND);
float tone_plover[][2]    = SONG(PLOVER_SOUND);
float tone_plover_gb[][2] = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]    = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int  RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
		#ifdef RGBLIGHT_ENABLE
        // rgblight_mode(RGB_current_mode);
		#endif
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case QWERTY:
            if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_qwerty);
				#endif
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
            break;

        case COLEMAK:
            if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_colemak);
				#endif
                persistent_default_layer_set(1UL << _COLEMAK);
            }
            return false;
            break;

        case LOWER:
            if (record->event.pressed) {
                // not sure how to have keyboard check mode and set it to a variable, so my work around
                // uses another variable that would be set to true after the first time a reactive key is pressed.
                if (TOG_STATUS) {  // TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
                } else {
                    TOG_STATUS = !TOG_STATUS;
					#ifdef RGBLIGHT_ENABLE
                    // rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
					#endif
                }
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
				#ifdef RGBLIGHT_ENABLE
                // rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
				#endif
                TOG_STATUS = false;
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                // not sure how to have keyboard check mode and set it to a variable, so my work around
                // uses another variable that would be set to true after the first time a reactive key is pressed.
                if (TOG_STATUS) {  // TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
                } else {
                    TOG_STATUS = !TOG_STATUS;
					#ifdef RGBLIGHT_ENABLE
                    // rgblight_mode(RGBLIGHT_MODE_SNAKE);
					#endif
                }
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
				#ifdef RGBLIGHT_ENABLE
                // rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
				#endif
                layer_off(_RAISE);
                TOG_STATUS = false;
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;

        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;

        case YOMA:
            if (record->event.pressed) {
                layer_on(_YOMA);
            } else {
                layer_off(_YOMA);
            }
            return false;
            break;

            // led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
        case RGB_MOD:
			#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                rgblight_mode(RGB_current_mode);
                rgblight_step();
                RGB_current_mode = rgblight_config.mode;
            }
			#endif
            return false;
            break;

        case EISU:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui == false) {
                    register_code(KC_INT2);
                } else {
                    SEND_STRING(SS_LALT("`"));
                }
            } else {
                unregister_code(KC_INT2);
            }
            return false;
            break;

        case KANA:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui == false) {
                    register_code(KC_INT1);
                } else {
                    SEND_STRING(SS_LALT("`"));
                }
            } else {
                unregister_code(KC_INT1);
            }
            return false;
            break;

        case RGBRST:
			#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
			#endif
            return false;
            break;

        case MOVE_LEFT:
            if (record->event.pressed)  {
                SEND_STRING(SS_LGUI("["));
            }   else    {
                // when keycode QMKBEST is released
            }
            return false;
            break;

          case MOVE_RIGHT:
            if (record->event.pressed)  {
                SEND_STRING(SS_LGUI("]"));
            }   else    {
                // when keycode QMKBEST is released
            }
            return false;
            break;

          case MOV_L_NERD:
            if (record->event.pressed)	{
                SEND_STRING(SS_LCTL("w")"h");
            }   else    {
                // when keycode QMKBEST is released
            }
            return false;
            break;

          case MOV_R_NERD:
            if (record->event.pressed)  {
                SEND_STRING(SS_LCTL("w")"u");
            }   else    {
                // when keycode QMKBEST is released
            }
            return false;
            break;

	break;
    }
    return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user(void)
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user(void)
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
