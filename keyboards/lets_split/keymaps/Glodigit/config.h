/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// VIAL
#define VIAL_KEYBOARD_UID {0x7E, 0x6F, 0x5B, 0x6B, 0x35, 0x21, 0x7C, 0x1D}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
//#define VIAL_COMBO_ENTRIES 4

// RGB
//#define RGBLIGHT_ANIMATIONS
#undef RGBLED_NUM
#define RGBLED_NUM 34 //5 + 7 + 5 on 3 sides of each case
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 127 //Just so that I don't max out power useage.

//#define ONESHOT_TAP_TOGGLE
//gateron clears are too sensitive and the o-rings dont help in that regard.
#undef  DEBOUNCING_DELAY 
#define DEBOUNCING_DELAY 30
