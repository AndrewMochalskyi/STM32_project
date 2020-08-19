#ifndef _GPIO_MODUL_H_
#define _GPIO_MODUL_H_


#include <stdint.h>
#include <stdbool.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/cortex.h>
#include <libopencm3/stm32/exti.h>
#include <stdint.h>



struct pin {
	/** GPIO ports GPIOA...GPIOK */
	uint8_t port : 4;

	/* GPIO PIN Number 0..15 */
	uint8_t num : 4;

	/** 
	 GPIO PIN direction
	  GPIO_MODE_INPUT or GPIO_MODE_OUTPUT
	 */
	uint8_t dir :2;

	/** GPIO PIN Analog or Dogotal mode
		GPIO_MODE_AF or GPIO_MODE_ANALOG
	*/
	uint8_t mode : 2;

	/* 
	GPIO Output Pin Driver Type
	 Can be GPIO_OTYPE_OD (open drain), GPIO_OTYPE_PP (push pull)
	 */
	uint8_t otype : 1;

	/*
	GPIO Output Pin speed
	 * Can be GPIO_OSPEED_2MHZ, GPIO_OSPEED_25MHZ, GPIO_OSPEED_50MHZ, GPIO_OSPEED_100MHZ

	*/
	uint8_t speed : 2;

	/*
	GPIO Output Pin Pullup
	Can be GPIO_PUPD_NONE, GPIO_PUPD_PULLDOWN, GPIO_PUPD_PULLUP 
	*/
	uint8_t pull_up_down : 2;

	/** Flag that specify if the pin is inversed
	If true, abst_digital_write and abst_digital_read function inverse the value at the pin/
	*/

	uint8_t is_inverse : 1;

};

typedef enum e_pin_port {
    ES_GPIOA = 0,
    ES_GPIOB = 1,
    ES_GPIOC = 2,
    ES_GPIOD = 3,
    ES_GPIOE = 4,
    ES_GPIOF = 5,
    ES_GPIOG = 6,
    ES_GPIOH = 7,
    ES_GPIOI = 8,
    ES_GPIOJ = 9,
    ES_GPIOK = 10
} pin_port;



void easylib_digital_write(const struct pin pin, bool value);
void easylib_gpio_init(const struct pin pin);
void easylib_gpio_toggle(const struct pin pin);
bool easylib_digital_read(const struct pin pin);




#endif