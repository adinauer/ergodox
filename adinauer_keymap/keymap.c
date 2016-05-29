#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SPCL 1 // special characters
#define MOUS 2 // mouse
#define FKEY 3 // F-keys
#define NAVI 4 // navigation
#define NUMB 5 // numpad
#define MPTY 9 // empty (copy as template)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layer 0 : default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  -   |           |   =  |   6  |   7  |   8  |   9  |   0  | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~L4/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| ~L5  |           | +L5  |------+------+------+------+------+--------|
 * | LShift | Z/~L1|   X  |   C  |   V  |   B  |      |           |      | N/~L4|   M  |   ,  |   .  | //~L1| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  ~L3 | Caps | LGUI | ~L2  |                                       | Left |  ~L2 |  ~L2 |  ~L3 | RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | -L0  |       | Vol- | Vol+ |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       | Mute |      |      |
 *                                 |Space | Enter|------|       |------| Alt  | LGUI |
 *                                 |      |      |BSpace|       |  Esc |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [BASE] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_MINS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRC,
        LT(4, KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LSFT,        LT(1, KC_Z),    KC_X,           KC_C,           KC_V,           KC_B,           MO(5),
        KC_LCTL,        MO(3),          KC_CAPS,        KC_LGUI,        MO(2),
                                                                                        KC_NO,          M(100),
                                                                                                        KC_NO,
                                                                        KC_SPC,         KC_ENT,         KC_BSPC,
        // right hand
        KC_EQL,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
        KC_RBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
        TG(5),          LT(4, KC_N),    KC_M,           KC_COMM,        KC_DOT,         LT(1, KC_SLSH), KC_RSFT,
                                        KC_RGUI,        MO(2),          MO(2),          MO(3),          KC_RCTL,  
        KC_VOLD,        KC_VOLU,
        KC_MUTE,
        KC_ESC,         KC_LALT,        KC_LGUI
    ),

/* layer 1 : special characters
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |   @  |   _  |   [  |   ]  |   ^  |      |           |      |   !  |   <  |   >  |   =  |   &  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   #  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   $  |   |  |   ~  |   `  |      |           |      |   +  |   %  |   "  |   '  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [SPCL] = KEYMAP(
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_AT,          KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_CIRC,        KC_TRNS,
        KC_TRNS,        KC_BSLS,        KC_SLSH,        KC_LCBR,        KC_RCBR,        KC_ASTR,
        KC_TRNS,        KC_TRNS,        KC_DLR,         KC_PIPE,        KC_TILD,        KC_GRV,         KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_EXLM,        KC_LT,          KC_GT,          KC_EQL,         KC_AMPR,        KC_TRNS,
                        KC_QUES,        KC_LPRN,        KC_RPRN,        KC_MINS,        KC_HASH,        KC_TRNS,
        KC_TRNS,        KC_PLUS,        KC_PERC,        KC_DQT,         KC_QUOT,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  
        KC_TRNS,        KC_TRNS,
        KC_TRNS,    
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

/* layer 2 : mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        | ACL0 |      |      |      |      |      |           |      | MS ← | MS ↓ |   ↓  |   ↑  | MS ↑ | MS →   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ACL1 |  LMB | WhClk|  RMB |      |------|           |------| M ←  | M ↓  | M ↑  | M →  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ACL2 |      |      |      |      |      |           |      |      | LMB  | WhClk| RMB  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [MOUS] = KEYMAP(
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_ACL0,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_ACL1,        KC_BTN1,        KC_BTN3,        KC_BTN2,        KC_TRNS,    
        KC_TRNS,        KC_ACL2,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_WH_L,        KC_WH_D,        KC_DOWN,        KC_UP,          KC_WH_U,        KC_WH_R,
                        KC_MS_L,        KC_MS_D,        KC_MS_U,        KC_MS_R,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_BTN1,        KC_BTN3,        KC_BTN2,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  
        KC_TRNS,        KC_TRNS,
        KC_TRNS,    
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

/* layer 3 : F-Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F11  |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
 * |--------+------+------+------+------+------|  F11 |           |  F12 |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [FKEY] = KEYMAP(
        // left hand
        KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,    
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F11,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,
        KC_F12,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

/* layer 4 : navigation keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TEENSY |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |LGUI+←|LGUI+→|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Ctrl+A|  INS |  DEL |      |      |------|           |------|    ← |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgUp | PgDn |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [NAVI] = KEYMAP(
        // left hand
        RESET,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        LCTL(KC_A),     KC_INS,         KC_DELT,        KC_TRNS,        KC_TRNS,    
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        LGUI(KC_LEFT),  LGUI(KC_RIGHT), KC_TRNS,        KC_TRNS,
                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  
        KC_TRNS,        KC_TRNS,    
        KC_TRNS,        
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

/* layer 5 : numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   ,  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [NUMB] = KEYMAP(
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BSLS,        KC_ASTR,        KC_MINS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRNS,
                        KC_TRNS,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_1,           KC_2,           KC_3,           KC_ENT,         KC_TRNS,
                                        KC_0,           KC_TRNS,        KC_COMM,        KC_DOT,         KC_TRNS,  
        KC_TRNS,        KC_TRNS,
        KC_TRNS,    
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

/* empty layer (use as template)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
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
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [MPTY] = KEYMAP(
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  
        KC_TRNS,        KC_TRNS,
        KC_TRNS,    
        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 0:
        	if (record->event.pressed) {
        	    register_code(KC_RSFT);
        	} else {
        	    unregister_code(KC_RSFT);
        	}
        	break;
        case 100:
            clear_keyboard();
            layer_clear();
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // use LEDs to display current layer in binary representation
    switch (layer) {
        case 1: // [ ][ ][x]
        	ergodox_right_led_3_on();
        	break;
        case 2: // [ ][x][ ]
        	ergodox_right_led_2_on();
        	break;
        case 3: // [ ][x][x]
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 4: // [x][ ][ ]
            ergodox_right_led_1_on();
            break;
        case 5: // [x][ ][x]
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6: // [x][x][ ]
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 7: // [x][x][x]
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
        	// none
        	break;
    }
};
