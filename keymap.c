#include QMK_KEYBOARD_H

// readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum keymap_layout {
    VANILLA = 0,  // matches MF68 layout
    FUNC,         // 0x02
    SETTINGS,     // 0x04
};

// Colors of the layer indicator LED
// This list needs to define layer 0xFFFFFFFF, it is the end of the list, and the unknown layer
const Layer_Info layer_info[] = {
  // Layer     Mask           Red     Green   Blue
  {0x00000000, 0xFFFFFFFF, {0x0000, 0x0FFF, 0x0000}}, // base layer - green
  {0x00000002, 0xFFFFFFFE, {0x0000, 0x0000, 0x0FFF}}, // function layer - blue
  {0x00000004, 0xFFFFFFFC, {0x0FFF, 0x0000, 0x0FFF}}, // settings layer - magenta
  {0xFFFFFFFF, 0xFFFFFFFF, {0x0FFF, 0x0FFF, 0x0FFF}}, // unknown layer - REQUIRED - white
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap VANILLA: (Base Layer) Default Layer
   * ,---------.  ,------------------------------------------------------------.  ,---------.
   * |    |    |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa|  | Ins|PgUp|
   * |---------|  |------------------------------------------------------------|  |---------|
   * |    |    |  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     \|  | Del|PgDn|
   * |---------|  |------------------------------------------------------------|  `---------'
   * |    |    |  |CAPS    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |---------|  |------------------------------------------------------------|  ,----.
   * |    |    |  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |  | Up |
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |Ctrl|Alt |Mac |         Space              |Mac |Ctrl |    |Lft| Dn |Rig |
   * `---------'  `------------------------------------------------------'    `-------------'
   */
  [VANILLA] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_INS,  KC_PGUP, \
    XXXXXXX, XXXXXXX, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_DEL,  KC_PGDN, \
    XXXXXXX, XXXXXXX, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,                             \
    XXXXXXX, XXXXXXX, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,                     \
    XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    XXXXXXX, KC_RGUI, MO(FUNC),          KC_LEFT, KC_DOWN, KC_RGHT           \
  ),

  /* Keymap FUNCTION: Function Layer
   * ,---------.  ,-------------------------------------------------------------.  ,---------.
   * |    |    |  | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete   |  | Ins|Home|
   * |---------|  |-------------------------------------------------------------|  |---------|
   * |    |    |  |Tab  |   |   |   |   |   |   |   |   |   |   |>> |<< |       |  | Del|End |
   * |---------|  |-------------------------------------------------------------|  `---------'
   * |    |    |  |CAPS    |   |   |   |   |   |   |   |   |   |   |   | Ply/Pau|
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |Shift   |   |   |   |   |   |   |    |V- |V+ |  | Mute       |  |^Up |
   * |---------|  |--------------------------------------------------------------------------.
   * |    |    |  |SETTINGS|  |  |         Play/Pause        |Sleep|     |     |^Lf|^Dn |^Rig|
   * `---------'  `------------------------------------------------------'     `-------------'
   */
  [FUNC] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,            _______, KC_HOME, \
    XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MRWD, KC_MFFD, XXXXXXX,           _______, KC_END,  \
    XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_MPLY,                             \
    XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, KC_MUTE,                  RCTL(KC_UP),                 \
    XXXXXXX, XXXXXXX, TG(SETTINGS), XXXXXXX, XXXXXXX,                       KC_MPLY,                   XXXXXXX, KC_SLEP, _______,   RCTL(KC_LEFT), RCTL(KC_DOWN), RCTL(KC_RGHT) \
  ),

  /* Keymap SETTINGS: Settings Layer
   * ,---------.  ,-------------------------------------------------------------.  ,-------------.
   * |    |    |  |RESET |   |   |   |   |   |   |   |   |  |   |BL-|BL+|BL Togl|  |RGB Tog |Val+|
   * |---------|  |-------------------------------------------------------------|  |-------------|
   * |    |    |  |       |   |   |   |   |   |   |   |   |   |   |   |   |     |  |RGB Mode|Val-|
   * |---------|  |-------------------------------------------------------------|  `-------------'
   * |    |    |  |         |   |   |   |   |   |   |   |   |   |   |   |LyrClr |
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |         |   |   |   |   |   |   |   |   |   |   |           |  |Hue+|
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |      |  |  |                                |  |VANILLA|  |Sat-|Hue-|Sat+|
   * `---------'  `--------------------------------------------------------'  `--------------'
   */
  [SETTINGS] = LAYOUT(
    XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_INC,  BL_TOGG,          RGB_TOG, RGB_VAI, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_MOD, RGB_VAD, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_FN0,                             \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_HUI,                   \
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                           XXXXXXX,                   XXXXXXX, XXXXXXX, TG(VANILLA),      RGB_SAD, RGB_HUD, RGB_SAI           \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(LFK_CLEAR),                               // FN0 - reset layers
    /*
    ACTION_FUNCTION(LFK_CLICK_FREQ_HIGHER),                   // FN1 - Increase Freq of audio click
    ACTION_FUNCTION(LFK_CLICK_FREQ_LOWER),                    // FN2 - Decrease Freq of audio click
    ACTION_FUNCTION(LFK_CLICK_TIME_LONGER),                   // FN3 - Increase length of audio click
    ACTION_FUNCTION(LFK_CLICK_TIME_SHORTER),                  // FN4 - Decrease length of audio click
    ACTION_FUNCTION(LFK_CLICK_TOGGLE),                        // FN5 - Toggle audio click
    */
  };


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if(eeconfig_read_default_layer() > 1){
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
}
