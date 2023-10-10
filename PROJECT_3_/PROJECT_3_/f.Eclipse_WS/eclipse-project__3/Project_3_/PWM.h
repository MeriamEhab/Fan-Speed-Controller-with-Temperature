/*
 * PWM.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Meriam Ehab
 */

#ifndef PWM_H_
#define PWM_H_

#pragma once
#include "std_types.h"

#define PWM_PORT               PORTB_ID
#define PWM_PIN                PIN3_ID

void PWM_Timer0_Init(uint8 set_duty_cycle);


#endif /* PWM_H_ */
