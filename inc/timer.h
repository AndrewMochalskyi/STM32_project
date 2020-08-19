#ifndef __TIMER_H_
#define _TIMER_H_



void delay_timer_init(void);
void delay_us(uint16_t val);
void delay_ms(uint32_t val);
void tim7_isr(void);


#endif