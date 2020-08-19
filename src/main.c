#include "GLSK_periphery.h"
#include "STM32_periphery.h"
#include "timer.h"




int main()
{
	
	//easylib_init();

	easylib_gpio_init(blue_led);
	easylib_digital_write(blue_led,1);
	easylib_gpio_init(red_led);
	easylib_digital_write(red_led,1);
	/// button 

	//rcc_periph_clock_enable(RCC_GPIOC);	
   //gpio_mode_setup(GPIOC, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, GPIO9 | GPIO11);

	easylib_gpio_init(button2);
	easylib_gpio_init(button1);
	//easylib_digital_write(blue_led,0);



	/////// timer config
	delay_timer_init();
	while(1) {
		delay_ms(5000);
		easylib_gpio_toggle(blue_led);

		}
}