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

#include "qemu/osdep.h"
#include "hw/hw.h"
#include "hw/i2c/i2c.h"
#include "cdcm6208.h"
#include "qapi/error.h"
#include "qapi/visitor.h"
