/*
 * TI CDCM6208 2:8 Ultra Low Power, Low Jitter Clock Generator
 *
 * Copyright (C) 2017 Petre Pircalabu <petre.pircalabu@gmail.com>.
 *
 * Reference: http://www.ti.com/lit/ds/symlink/cdcm6208.pdf
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef QEMU_CDCM6208_H
#define QEMU_CDCM6208_H

#include "hw/i2c/i2c.h"

#define TYPE_CDCM6208 "cdcm6208"
#define CDCM6208(obj) OBJECT_CHECK(CDCM6208State, (obj), TYPE_CDCM6208)

typedef struct CDCM6208State {
    I2CSlave i2c;
    uint8_t resetn_pwr;
    uint8_t pdn;
} CDCM6208State;

#endif /* QEMU_CDCM6208_H */


