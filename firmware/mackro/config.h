/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0F04
#define PRODUCT_ID      0x0099
#define DEVICE_VER      0x0001
#define MANUFACTURER    draforfrogan
#define PRODUCT         MACK-RO

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* 9Key PCB default pin-out */
#define MATRIX_ROW_PINS { F7, B1, B3 }
#define MATRIX_COL_PINS { F4, F5, F6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200

// CHANGES

/* Rotary encoder setup */

#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D7 }

/* ws2812 RGB LED */
#define RGB_DI_PIN B5

#define DIP_SWITCH_PINS { B6 }

#define RGBLED_NUM 9    // Number of LEDs

/* RGB LED Conversion macro from physical array to electric array */


/* RGB LED Conversion macro from physical array to electric array */
#define LED_LAYOUT(\
    L00, L01, L02, \
    L10, L11, L12, \
    L20, L21, L22) \
  { \
    L00, L01, L02,   \
    L12, L11, L10,   \
    L20, L21, L22   \
  }


/* RGB LED logical order map */
/* Top->Bottom, Right->Left */
#define RGBLIGHT_LED_MAP LED_LAYOUT( \
  1, 2, 3,      \
  6, 5, 4,      \
  7, 8, 9 )


/* 1000Hz USB polling - it's the default on stock firmware */
#define USB_POLLING_INTERVAL_MS 1

/* Send up to 4 key press events per scan */
#define QMK_KEYS_PER_SCAN 4

/* Set debounce time to 5ms */
#define DEBOUNCE 5
