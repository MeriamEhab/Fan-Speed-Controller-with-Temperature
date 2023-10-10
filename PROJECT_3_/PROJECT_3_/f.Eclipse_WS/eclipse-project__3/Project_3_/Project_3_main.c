/*
 * Project_3_main.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Meriam Ehab
 */

#include "gpio.h"
#include<avr/io.h>
#include "std_types.h"
#include "LCD.h"
#include"ADC.h"
#include "lm35_sensor.h"
#include"DC_motor.h"


int main()
{
	LCD_init(); /* initialize LCD driver */
	DcMotor_Init(); /* initialize DC_motor driver */
	ADC_ConfigType Config_Ptr={INTERNAL,F_CPU_8};
	ADC_init(&Config_Ptr); /* initialize ADC driver */

	uint8 temp;
	LCD_moveCursor(0,2);
	 /* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Fan is ");

	LCD_moveCursor(1,2);
	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp=   C");

	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(1,7);
		if (temp>=100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(0,9);
		if(temp < 30)
		{
			LCD_displayString("OFF");

			DcMotor_Rotate(STOP,LOGIC_LOW);
		}
		else if(temp>=30 && temp<60)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,25);
		}
		else if(temp>=60 && temp<90)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,50);
		}
		else if(temp>=90 && temp<120)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,75);

		}
		else if(temp>120)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,100);

		}

	}
}


