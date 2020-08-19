#ifndef _GLSK_PERIPHERY_H_
#define _GLSK_PERIPHERY_H_
#include "gpio_modul.h"

// SWT1
extern struct  pin button1;


// SWT2
extern struct  pin button2;

// SWT3
extern struct  pin button3;

// SWT4
extern struct  pin button4;

// SWT5
extern struct  pin button5;

bool button_is_pressed(const struct pin button);

#endif