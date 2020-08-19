#include "gpio_modul.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/cortex.h>
#include <libopencm3/stm32/exti.h>
#include <stdint.h>


#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

volatile uint64_t _time_us_;
volatile bool _sleep_;

uint32_t easylib_opencm_port_conv(const struct pin pin)
{
    return PERIPH_BASE_AHB1 + 0x0400 * pin.port;
}

 uint32_t easylib_opencm_rcc_conv(const struct pin pin)
{
    return _REG_BIT(0x30, pin.port);
}






void easylib_digital_write(const struct pin pin, bool value)
{
    uint32_t opencm_port = easylib_opencm_port_conv(pin);
    value ^= pin.is_inverse;
    if (value)
        gpio_set(opencm_port, 1 << pin.num);
    else
        gpio_clear(opencm_port, 1 << pin.num);
}



void easylib_gpio_init(const struct pin pin) 
{
	uint32_t opencm_port = easylib_opencm_port_conv(pin); 

	rcc_periph_clock_enable(easylib_opencm_rcc_conv(pin));
	gpio_mode_setup(opencm_port, pin.dir | pin.mode, pin.pull_up_down, 1 << pin.num);
	gpio_set_output_options(opencm_port, pin.otype, pin.speed, 1 << pin.num);
	easylib_digital_write(pin, 0);
}

void easylib_gpio_toggle(const struct pin pin) 
{
    gpio_toggle(easylib_opencm_port_conv(pin), 1 << pin.num);
}

bool easylib_digital_read(const struct pin pin)
{
    bool ret = gpio_port_read(easylib_opencm_port_conv(pin)) & (1 << pin.num);
    if(pin.is_inverse)
        return !ret;
    else
        return ret;
    //return ret ^  pin.is_inverse;
}



