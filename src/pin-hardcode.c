/*
 * pin-hardcode.c -- PIN input device support (hardcoded)
 *
 * Copyright (C) 2010, 2011, 2013 Free Software Initiative of Japan
 * Author: 
 *
 * This file is a part of Gnuk, a GnuPG USB Token implementation.
 *
 * Gnuk is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gnuk is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>
#include <string.h>

#include "config.h"
#include "board.h"
#include "gnuk.h"

uint8_t pin_input_buffer[MAX_PIN_CHARS];
uint8_t pin_input_len;

/*
 * Return length of the string.
 * The string itself is in PIN_INPUT_BUFFER.
 */
int
pinpad_getline (int msg_code, uint32_t timeout)
{
  uint8_t p2 = apdu.cmd_apdu_head[3];
  (void)msg_code;
  (void)timeout;

  if (p2 == 0x81 || p2 == 0x82)
    {
      pin_input_len = strlen(OPENPGP_CARD_INITIAL_PW1);
      memcpy(pin_input_buffer, OPENPGP_CARD_INITIAL_PW1, pin_input_len);
    }
  else
    {
      pin_input_len = strlen(OPENPGP_CARD_INITIAL_PW3);
      memcpy(pin_input_buffer, OPENPGP_CARD_INITIAL_PW3, pin_input_len);
    }
    return pin_input_len;
}

