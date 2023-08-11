#include QMK_KEYBOARD_H
#include "taipo.h"

//Glodigit Default Keymap v1.0

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE     0
#define _QWERTY   1
#define _F360     2
#define _TAIPO    3
#define _NUMBER   4
#define _FUNCTION 5

#define FN        MO(_FUNCTION)
#define XXXX      KC_NO
#define SNIPASTE  RCS(KC_GRAVE)
#define WOX       LGUI(KC_GRAVE)
#define O_DATE    LSA(KC_D)
#define O_TIME    LSA(KC_T)

//#define TAIPO_ENABLE

// Unicode
#define PLUSMIN   UC(0x00B1) // ±
#define DEGREE    UC(0x00B0) // °
#define EMDASH    UC(0X2014) // —
#define NOTEQUAL  UC(0X2260) // ≠


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,------------------------------------------  ------------------------------------------.
 * | ESC  | TAB  | C    | O    | D    | K    |  | Q    | L    | U    | P    | ENTER| UP   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | TAIPO| X    | S    | A    | R    | .    |  | ,    | H    | I    | N    | J    | DOWN |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Z    | E    | V    | W    | M    | ?    |  | !    | F    | Y    | B    | T    | G    |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | GUI  | SHIFT| ALT  | CTRL | NUM  | FN   |  | SPACE|BSPACE| LEFT | RIGHT| SHIFT| DEL  |
 * `------------------------------------------  ------------------------------------------'
 */ 
[_BASE] = LAYOUT_ortho_4x12( \
   KC_ESCAPE,    KC_TAB,    KC_C,     KC_O,        KC_D,    KC_K,     KC_Q,       KC_L,    KC_U,    KC_P,     KC_ENTER,  KC_UP,    \
  TG(_TAIPO),      KC_X,    KC_S,     KC_A,        KC_R,  KC_DOT,     KC_COMMA,   KC_H,    KC_I,    KC_N,     KC_J,      KC_DOWN,  \
        KC_Z,      KC_E,    KC_V,     KC_W,        KC_M, KC_QUES,     LSFT(KC_1), KC_F,    KC_Y,    KC_B,     KC_T,      KC_G,     \
     KC_LGUI,  KC_LSFT,  KC_LALT,  KC_LCTL, MO(_NUMBER),      FN,     KC_SPACE,   KC_BSPC, KC_LEFT, KC_RIGHT, KC_RSFT, KC_DELETE   \
),

/* Qwerty 
 * ,------------------------------------------  ------------------------------------------.
 * |      |      | W    | E    | R    | T    |  | Y    | U    | I    | O    |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |QWERTY| Q    | S    | D    | F    | G    |  | H    | J    | K    | L    | P    |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | GUI  | A    | X    | C    | V    | B    |  | N    | M    | ,    | .    | ;    | '    |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | SHIFT| Z    |      |      |      |      |  |      |      |      |      | /    | SHIFT|
 * `------------------------------------------  ------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
      _______, _______,       KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    _______, _______,  \
  TG(_QWERTY),    KC_Q,       KC_S,    KC_D,     KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P   , _______,  \
      KC_LGUI,    KC_A,       KC_X,    KC_C,     KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_QUOT,  \
    KC_LSFT,    KC_Z,    _______, _______,  _______,  _______,    _______, _______, _______, _______, KC_SLSH, KC_RSFT \
),

/* Autodesk Fusion 360 (and Trackmania) Layer [W.I.P.]
 * ,------------------------------------------  ------------------------------------------.
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | F360 |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `------------------------------------------  ------------------------------------------'
*/
[_F360] = LAYOUT_ortho_4x12( \
   _______,  _______, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E),       KC_E,     _______, _______, _______, _______, _______, _______,  \
  TG(_F360),    KC_C, LSFT(KC_A), LSFT(KC_S), LSFT(KC_D),       KC_F,     _______, _______, _______, _______, _______, _______,  \
       KC_R,    KC_D, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_R), LSFT(KC_C),     _______, _______, _______, _______, _______, _______,  \
       KC_S,    KC_L,    _______,    _______,    _______,    _______,     _______, _______, _______, _______, _______, _______   \
),


/* Taipo Layer
 * ,------------------------------------------  ------------------------------------------.
 * |      |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| TAB  | ESC  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | TAIPO| TR   | TM   | TI   |XXXXXX|XXXXXX|  |XXXXXX|XXXXXX| TI   | TM   | TR   | TAIPO|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | TP   | BR   | BM   | BI   |XXXXXX|XXXXXX|  |XXXXXX|XXXXXX| BI   | BM   | BR   | TP   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | LP   |XXXXXX|XXXXXX| IT   | OT   |      |  | FN   | IT   | OT   |XXXXXX|XXXXXX| LP   |
 * `------------------------------------------  ------------------------------------------'
*/
[_TAIPO] = LAYOUT_ortho_4x12( \
     _______, _______,    XXXX,    XXXX,     XXXX,    XXXX,     XXXX, XXXX,   XXXX,   XXXX,   KC_TAB, KC_ESCAPE,  \
  TG(_TAIPO),  TP_TLR,  TP_TLM,   TP_TLI,    XXXX,    XXXX,     XXXX, XXXX,   TP_TRI, TP_TRM, TP_TRR, TG(_TAIPO), \
      TP_TLP,  TP_BLR,  TP_BLM,   TP_BLI,    XXXX,    XXXX,     XXXX, XXXX,   TP_BRI, TP_BRM, TP_BRR, TP_TRP,     \
      TP_BLP,    XXXX,    XXXX,   TP_LIT,  TP_LOT, _______,     FN,   TP_ROT, TP_RIT, XXXX,   XXXX,   TP_BRP      \
),

/* Number Layer
 * ,------------------------------------------  ------------------------------------------.
 * |      |      | 7    | 8    | 9    | +    |  | ±    | N7   | N8   | N9   |NENTER|      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |BSPACE| ENTER| 4    | 5    | 6    | N.   |  | °    | N4   | N5   | N6   | ≠    |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | N/   | 0    | 1    | 2    | 3    | -    |  | —    | N3   | N2   | N1   | N0   | BSLSH|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |CT(N*)| ST(=)| ALT  | CTRL |      |      |  |      |      |      |      | ST(')|      |
 * `------------------------------------------  ------------------------------------------'
*/
[_NUMBER] = LAYOUT_ortho_4x12( \
                 _______,          _______,    KC_7,     KC_8,    KC_9, KC_KP_PLUS,     PLUSMIN, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ENTER,     _______,  \
                 KC_BSPC,         KC_ENTER,    KC_4,     KC_5,    KC_6,  KC_KP_DOT,     DEGREE,  KC_KP_4, KC_KP_5, KC_KP_6, NOTEQUAL,        _______,  \
             KC_KP_SLASH,             KC_0,    KC_1,     KC_2,    KC_3,   KC_MINUS,     EMDASH,  KC_KP_3, KC_KP_2, KC_KP_1, KC_KP_0,         KC_NUBS,  \
  LCTL_T(KC_KP_ASTERISK), LSFT_T(KC_EQUAL), KC_LALT,  KC_LCTL, _______,    _______,     _______, _______, _______, _______, RSFT_T(KC_QUOT), _______   \
),

/* Function Layer
 * ,------------------------------------------  ------------------------------------------.
 * | Reset| PSCRN| F7   | F8   | F9   | F10  |  | [    | ]    | WOX  | #    |      | PGUP |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | F360 | SNIP | F4   | F5   | F6   | F11  |  | (    | )    | ;    | :    | ODATE|PGDOWN|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | NLOCK| CLOCK| F1   | F2   | F3   | F12  |  | {    | }    |XXXXXX|XXXXXX| OTIME| -    |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      | NUM  |      |  |      |      | HOME | END  |      |      |
 * `------------------------------------------  ------------------------------------------'
 */ 
[_FUNCTION] = LAYOUT_ortho_4x12( \
      QK_BOOT,      KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     KC_LBRC, KC_RBRC, LGUI(KC_GRAVE), KC_NONUS_HASH, _______, KC_PGUP,  \
    TG(_F360),     SNIPASTE,   KC_F4,   KC_F5,   KC_F6,  KC_F11,     KC_LPRN, KC_RPRN, KC_SCLN,        KC_COLN,       O_DATE,  KC_PGDN,  \
  KC_NUM_LOCK, KC_CAPS_LOCK,   KC_F1,   KC_F2,   KC_F3,  KC_F12,     KC_LCBR, KC_RCBR, XXXX,           XXXX,          O_TIME,  KC_MINUS, \
      _______,      _______, _______, _______, _______, _______,     _______, _______, KC_HOME,        KC_END,        _______, _______   \
),


/* Blank Layer
 * ,------------------------------------------  ------------------------------------------.
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `------------------------------------------  ------------------------------------------'

[__] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______   \
),
 */ 

};


void matrix_init_user() {
    #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    rgblight_increase_val();
    #endif
}


void matrix_scan_user(void) {
  
  #ifdef TAIPO_ENABLE
  taipo_matrix_scan_user();
  #endif
  
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  static uint8_t old_lock[3] = {2, 2, 2};
  uint8_t new_lock[3] = {
    host_keyboard_leds() & (1<<USB_LED_NUM_LOCK),
    host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK),
    host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)
  };

  if (
    old_layer   != new_layer   || 
    old_lock[0] != new_lock[0] ||
    old_lock[1] != new_lock[1] ||
    old_lock[2] != new_lock[2]) {
    switch (new_layer) {
      case _BASE:
        //rgblight_setrgb(0x22, 0x22, 0x22);
        rgblight_enable(); //allows rgb brightness controls to work on layer
        if (new_lock[1]) {
            // Corner Pink
            rgblight_setrgb_range(0x9, 0x0, 0x3, 10, 14);
            rgblight_setrgb_range(0x9, 0x0, 0x3, 20, 24);
          } 
        break;

      case _QWERTY:
          rgblight_setrgb(0x12, 0x6, 0x00); //nice golden shade of yellow
          if (new_lock[1]) {
            // Corner Pink
            rgblight_setrgb_range(0x9, 0x0, 0x3, 10, 14);
            rgblight_setrgb_range(0x9, 0x0, 0x3, 20, 24);
          } 
          break;

      case _TAIPO:
          rgblight_setrgb(0x9, 0x03, 0x9);
          break;

      case _F360:
          rgblight_setrgb(0x18, 0x06, 0x00); //Orange
          // Corner whites
          rgblight_setrgb_range(0x9, 0x9, 0x9, 10, 14);
          rgblight_setrgb_range(0x9, 0x9, 0x9, 20, 24);
          break;

      case _NUMBER:
          rgblight_setrgb(0x00, 0x15, 0x9); //Mint
          if (new_lock[0]) {
            // Corner whites
            rgblight_setrgb_range(0x9, 0x9, 0x9, 10, 14);
            rgblight_setrgb_range(0x9, 0x9, 0x9, 20, 24);
          } 
          break;

      case _FUNCTION:
          rgblight_setrgb(0x00, 0x00, 0x15);
          break;      
      
    }

    //one of the leds is slightly defective, so make that one black.
    //other one is for symmetry
    //rgblight_setrgb_at(0x00, 0x00, 0x00, 2);
    //rgblight_setrgb_at(0x00, 0x00, 0x00, 31);


    old_layer = new_layer;
    old_lock[0] = new_lock[0];
    old_lock[1] = new_lock[1];
    old_lock[2] = new_lock[2];
  }

  #endif //RGBLIGHT_ENABLE
  
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      return false;
      break;
    case EXT_F360:
      if (record->event.pressed) {
        layer_off(_F360);
      }
      return false;
      break;
  }
  return true;
}*/

#ifdef TAIPO_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_TAIPO)) {
        return taipo_process_record_user(keycode, record);
    } else {
        return true;
    }
};
#endif

