#include "TMR0.h"
#include "TMR0_Cfg.h"
#include "avr/io.h"
#include "Bit_Op.h"
#if TMR0_MODE == 2 || TMR0_MODE == 3
#include "Dio.h"
#endif

/***************************************************************
 * Description: Initializes Timer0 Module
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void TMR0_vidInit(void)
{
#if TMR0_MODE == 0
	/*Configure Timer Mode (Normal Mode)*/
	Clear_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);

	/*Configure Compare Match Mode(No Compare Mode, OC0 is PORTB)*/
	Clear_Bit(TCCR0, 4);
	Clear_Bit(TCCR0, 5);

#elif TMR0_MODE == 1
	/*Configure Timer Mode (CTC Mode)*/
	Set_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);

	/*Configure Compare Match Mode(No Compare Mode, OC0 is PORTB)*/
	Clear_Bit(TCCR0, 4);
	Clear_Bit(TCCR0, 5);
#elif TMR0_MODE == 2
	/*Configure Timer Mode (Fast PWM)*/
	Set_Bit(TCCR0, 3);
	Set_Bit(TCCR0, 6);

	/*Configure PB3(OC0) as an output*/
	Dio_vidSetPinDirection(Dio_PORTB, 3, Dio_Output);

	#if TMR0_PWM_INVERTED == 0
		/*Configure Compare Match Mode(Non-Inverted)*/
		Clear_Bit(TCCR0, 4);
		Set_Bit(TCCR0, 5);
	#elif TMR0_PWM_INVERTED == 1
		/*Configure Compare Match Mode(Inverted)*/
		Set_Bit(TCCR0, 4);
		Set_Bit(TCCR0, 5);
	#endif
#elif TMR0_MODE == 3

#endif

	/*Configure Pre-Scalar (N = 1024)*/
	TCCR0 = (TCCR0 & 0xF8) | 0x05;

#if TMR0_MODE == 0 || TMR0_MODE == 2
	#if TMR0_OVF_ENABLED == 1
		/*Clear TMR0 Over Flow Interrupt Flag*/
		Clear_Bit(TIFR, 0);

		/*Enable TMR0 Over Flow Interrupt*/
		Set_Bit(TIMSK, 0);
	#endif
#elif TMR0_MODE == 1 || TMR0_MODE == 3
	#if TMR0_COM_ENABLED == 1
		/*Clear TMR0 Compare-Match Interrupt Flag*/
		Clear_Bit(TIFR, 1);

		/*Enable TMR0 Compare-Match Interrupt*/
		Set_Bit(TIMSK, 1);
	#endif
#endif
}

/***************************************************************
 * Description: Updates the Timer Register
 * Input      : Timer Register Value
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void TMR0_vidSetTimer(uint8 Value)
{
	TCNT0 = Value;
}

/***************************************************************
 * Description: Retrieves the Timer Register
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
uint8 TMR0_u8GetTimer(void)
{
	return TCNT0;
}

#if TMR0_MODE != 0
/***************************************************************
 * Description: Updates the Compare Register
 * Input      : Compare Register Value
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void TMR0_vidSetCompareValue(uint8 Value)
{
	OCR0 = Value;
}
#endif
