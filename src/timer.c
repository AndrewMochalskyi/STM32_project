#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/cortex.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/f4/rcc.h>
#include "timer.h"
void delay_timer_init(void) 
{
	rcc_periph_clock_enable(RCC_TIM7);

	//assume timer block is clocked @ 16 MHz
	// and we want 1 us tick time as delay function has 1 us resolution
	timer_set_prescaler(TIM7, 16 - 1);
	// timer_enable_preload(TIM7);
	timer_disable_preload(TIM7);
	timer_one_shot_mode(TIM7);

	// Set URS bit ti update only at overflow (when auto-reload value is reached)
	timer_update_on_overflow(TIM7);

	timer_enable_irq(TIM7, TIM_DIER_UIE);
	timer_clear_flag(TIM7, TIM_SR_UIF);  // jsut in case

	nvic_set_priority(NVIC_TIM7_IRQ, 2);
	nvic_enable_irq(NVIC_TIM7_IRQ);
}


void delay_us(uint16_t val)
{
	// return fast
	if(!val)
		return;

	timer_set_period(TIM7, val);
	// generate update event to transfer ARPE contents to shadow register
	timer_generate_event(TIM7, TIM_EGR_UG);

	__dmb(); // data memory barrier (asm instructtion DMB)
	// DMB acts as a data memory barrier. It ensure that all explicit ,e,ory accesses that
	// appear, in program order, before the DMB instruction are completed before any explicit

	timer_enable_counter(TIM7);
	__asm__ volatile ("wfi");  // Enter sleep mode, WFI -- wait for interrupt
}


void delay_ms(uint32_t val)
{
	while(val--)
		delay_us(1000);
}

void tim7_isr(void)
{
	timer_clear_flag(TIM7, TIM_SR_UIF);
}
