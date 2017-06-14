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

static int cdcm6208_rx(I2CSlave *i2c)
{
    return 0;
}

static int cdcm6208_tx(I2CSlave *i2c, uint8_t data)
{
    return 0;
}

static int cdcm6208_event(I2CSlave *i2c, enum i2c_event event)
{
    return 0;
}

static int cdcm6208_post_load(void *opaque, int version_id)
{
    return 0;
}

static const VMStateDescription vmstate_cdcm6208 = {
    .name = "CDCM6208",
    .version_id = 0,
    .minimum_version_id = 0,
    .post_load = cdcm6208_post_load,
    .fields = (VMStateField[]) {
        VMSTATE_I2C_SLAVE(i2c, CDCM6208State),
        VMSTATE_UINT8(resetn_pwr, CDCM6208State),
        VMSTATE_UINT8(pdn, CDCM6208State),
        VMSTATE_END_OF_LIST()
    }
};

static void cdcm6208_reset(I2CSlave *i2c)
{
}

static void cdcm6208_gpio_set(void *opaque, int line, int level)
{
    CDCM6208State *s = (CDCM6208State *) opaque;

    assert(s);

    switch (line) {
        case 0:
            s->resetn_pwr = level;
            break;
        case 1:
            s->pdn = level;
            break;
        default:
            /* FIXME: Add error handling */
	    break;
    }
}

static int cdcm6208_init(I2CSlave *i2c)
{
    DeviceState *dev = DEVICE(i2c);
    CDCM6208State *s = CDCM6208(i2c);

    qdev_init_gpio_in(dev, cdcm6208_gpio_set, 2);

    cdcm6208_reset(&s->i2c);

    return 0;
}

static void cdcm6208_initfn(Object *obj)
{
}

static void cdcm6208_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    I2CSlaveClass *k = I2C_SLAVE_CLASS(klass);

    k->init = cdcm6208_init;
    k->event = cdcm6208_event;
    k->recv = cdcm6208_rx;
    k->send = cdcm6208_tx;
    dc->vmsd = &vmstate_cdcm6208;
}

static const TypeInfo cdcm6208_info = {
    .name          = TYPE_CDCM6208,
    .parent        = TYPE_I2C_SLAVE,
    .instance_size = sizeof(CDCM6208State),
    .instance_init = cdcm6208_initfn,
    .class_init    = cdcm6208_class_init,
};

static void cdcm6208_register_types(void)
{
    type_register_static(&cdcm6208_info);
}

type_init(cdcm6208_register_types)
