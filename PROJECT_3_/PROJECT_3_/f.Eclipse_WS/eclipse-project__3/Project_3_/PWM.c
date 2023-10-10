/*
 * PWM.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Meriam Ehab
 */

#include "PWM.h"
#include "gpio.h"
#include<avr/io.h>
#include "std_types.h"


void PWM_Timer0_Init(uint8 set_duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle*2.55; // Set Compare Value

	GPIO_setupPinDirection(PWM_PORT, PWM_PIN,  LOGIC_HIGH);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM00) | (1<<COM01)| (1<<CS01);
}

