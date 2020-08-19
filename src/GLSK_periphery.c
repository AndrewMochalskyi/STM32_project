#include "GLSK_periphery.h"


// SWT1
 struct  pin button1  = {
	.port = ES_GPIOC,
    .num = 11,
    .dir = GPIO_MODE_INPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_PULLUP,
    .is_inverse = true
};


// SWT2
 struct  pin button2  = {
	.port = ES_GPIOA,
    .num = 15,
    .dir = GPIO_MODE_INPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_PULLUP,
    .is_inverse = true
};

// SWT3
 struct  pin button3 = {
	.port = ES_GPIOC,
    .num = 9,
    .dir = GPIO_MODE_INPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_PULLUP,
    .is_inverse = true
};

// SWT4
 struct  pin button4  = {
	.port = ES_GPIOC,
    .num = 6,
    .dir = GPIO_MODE_INPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_PULLUP,
    .is_inverse = true
};

// SWT5
 struct  pin button5  = {
	.port = ES_GPIOC,
    .num = 8,
    .dir = GPIO_MODE_INPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_PULLUP,
    .is_inverse = true
};

bool button_is_pressed(const struct pin button)
{
	if(easylib_digital_read(button) )
	{
		return true;
	}
	return false;
}
