#include "bubble75.h"

// bool led_update_user(led_t led_state) {
//   if (led_state.caps_lock) {
//     if (!rgb_matrix_is_enabled()) {
//       /* Turn ON the RGB Matrix for CAPS LOCK */
//       rgb_matrix_set_flags(LED_FLAG_NONE);
//       rgb_matrix_enable();
//     }
//   } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
//     /* RGB Matrix was only ON because of CAPS LOCK. Turn it OFF. */
//     rgb_matrix_set_flags(LED_FLAG_ALL);
//     rgb_matrix_disable();
//   }

//   return true;
// }


#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix_types.h"

led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, NO_LED, 13 },
    { 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14 },
    { 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43 },
    { 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, NO_LED, 44 },
    { 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, NO_LED, 70, 71 },
    { 80, 79, 78, NO_LED, NO_LED, 77, NO_LED, NO_LED, 76, 75, NO_LED, 74, NO_LED, 73, 72 }
  },
  {
    /* LED Index to Physical Position */
    // Switch LEDs
    {0,0},     {23,0},    {38,0},    {54,0},    {69,0},    {75,0},    {90,0},    {105,0},   {120,0},  {143,0},  {158,0},  {173,0},  {188,0},            {225,0},
    {225,18},  {203,18},  {180,18},  {165,18},  {150,18},  {135,18},  {120,18},  {105,18},  {90,18},  {75,18},  {60,18},  {45,18},  {30,18},  {15,18},  {0,18},
    {4,30},    {19,30},   {34,30},   {49,30},   {64,30},   {79,30},   {84,30},   {99,30},   {114,30}, {129,30}, {144,30}, {159,30}, {174,30}, {219,30}, {225,30},
    {225,41},  {201,41},  {191,41},  {161,41},  {146,41},  {131,41},  {116,41},  {101,41},  {86,41},  {71,41},  {56,41},  {41,41},  {26,41},            {6,41},
    {13,52},   {34,52},   {49,52},   {64,52},   {79,52},   {94,52},   {109,52},  {124,52},  {139,52}, {154,52}, {169,52}, {189,52},           {210,52}, {225,52},
    {225,64},  {210,64},  {195,64},                        {186,64},                        {167,64}, {94,64},            {39,64},            {21,64},  {2,64}
  },
  {
    4,4,4,4,4,4,4,4,4,4,4,4,4,  4,  // 14
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,  // 15
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,  // 15
    4,4,4,4,4,4,4,4,4,4,4,4,4,  4,  // 14
    4,4,4,4,4,4,4,4,4,4,4,4,  4,4,  // 14
    4,4,4,    4,    4,4,  4,  4,4   // 9
  }
};


/* Key Matrix to LED Index */
// { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, NO_LED, 13 },
// { 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14 },
// { 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43 },
// { 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, NO_LED, 44 },
// { 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, NO_LED, 70, 71 },
// { 80, 79, 78, NO_LED, NO_LED, 77, NO_LED, NO_LED, 76, 75, NO_LED, 74, NO_LED, 73, 72 }
void rgb_matrix_indicators_kb(void) {
  if (host_keyboard_led_state().caps_lock) {
    int leds[4] = {29, 56, 57, 58};
    int i;
    int size = (int)(sizeof(leds)/sizeof(leds[0]));

    for (i = 0; i < size; i++) {
      rgb_matrix_set_color(leds[i], 255, 255, 159);
    }
  }

  uint8_t layer = get_highest_layer(layer_state);
  if (layer > 0) {
    int leds[4] = {44, 70, 71, 72};
    int i;
    int size = (int)(sizeof(leds)/sizeof(leds[0]));

    for (i = 0; i < size; i++) {
      rgb_matrix_set_color(leds[i], 255, 255, 159);
    }

    rgb_matrix_set_color((28 - layer), 255, 255, 159);
  }
}

// void rgb_matrix_indicators_kb(void) {
//     if (host_keyboard_led_state().caps_lock) {  // Capslock = WHITE
//         rgb_matrix_set_color(57, 255, 255, 255);
//     }
// }

void suspend_power_down_kb(void) {
  rgb_matrix_set_suspend_state(true);
  suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
  rgb_matrix_set_suspend_state(false);
  suspend_wakeup_init_user();
}
#endif // RGB_MATRIX_ENABLE
