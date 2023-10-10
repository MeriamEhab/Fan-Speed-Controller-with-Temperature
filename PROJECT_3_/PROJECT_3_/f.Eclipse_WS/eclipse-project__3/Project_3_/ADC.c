/*
 * ADC.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Meriam Ehab
 */


#include "avr/io.h" /* To use the ADC Registers */
#include "ADC.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
//ADC_ConfigType Config_Ptr = { INTERNAL, F_CPU_8};

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=0;
	ADMUX = (Config_Ptr-> ref_volt <<6);
	ADCSRA |= (1<< ADEN);
	ADCSRA &= ~(1<< ADIE);
	ADCSRA |= Config_Ptr-> prescaler ;
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX &= 0xE0;
	ADMUX |= channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
