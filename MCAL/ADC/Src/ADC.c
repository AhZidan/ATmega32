#include "ADC.h"
#include "avr/io.h"
#include "Bit_Op.h"

/**************************************************************
 * Description: Shall initialize ADC module
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 **************************************************************/
void ADC_vidInit(void)
{
	/*Configure Prescalar (Division Factor = 64)*/
	ADCSRA = (ADCSRA & 0xF8) | 0x06;

	/*Configure Vref (Internal Vref = VCC)*/
	ADMUX = (ADMUX & 0x3F) | 0x40;

	/*Configure Right ADjusted Result, No Interrupt, No Auto-Trigger*/
	Clear_Bit(ADMUX, 5);
	Clear_Bit(ADCSRA, 3);
	Clear_Bit(ADCSRA, 5);

	/*Enable ADC module*/
	Set_Bit(ADCSRA, 7);
}

/**************************************************************
 * Description: Shall Start conversion and return conversion result
 * Input      : Channel Number
 * Output     : Conversion Result
 * Last_Author: Ahmed.Yasser
 **************************************************************/
uint16 ADC_u16ReadChannel(uint8 Channel)
{
	uint16 u16Result;

	/*Check if the ADC is currently running a conversion*/
	if (Get_Bit(ADCSRA, 6) == 0)
	{
		if (Channel >=1 && Channel <= 8)
		{
			/*Select the required channel*/
			ADMUX = (ADMUX & 0xE0) | (Channel - 1);

			/*Start Conversion on the select channel*/
			Set_Bit(ADCSRA, 6);

			/*Wait for the conversion to finish*/
			while(Get_Bit(ADCSRA, 6) != 0)
			{

			}

			/*Read the lower segment of the result first*/
			u16Result = ADCL;

			/*Read the higher segment of the result*/
			u16Result |= (ADCH << 8);
		}
	}
	return u16Result;

}
