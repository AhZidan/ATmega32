#include "Dio.h"
#include "avr\io.h"
/*****************************************************************************************
! Description: Set the direction of a DIO pin                                            *
! Name       : Dio_vidSetPinDirection                                                    *
! Input      : Port ID, Direction (IN, OUT), Pin Number                                  *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
void Dio_vidSetPinDirection(enuDioPort Port, enuDioDirection Direction, uint8 Pin)
{
	switch(Port)
	{
		case Dio_PORTA:
			if(Direction == Dio_Input)
			{
				Set_Bit(DDRA, Pin);
			}
			else if(Direction == Dio_Output)
			{
				Clear_Bit(DDRA, Pin);
			}
			break;
		case Dio_PORTB:
			if(Direction == Dio_Input)
			{
				Set_Bit(DDRB, Pin);
			}
			else if(Direction == Dio_Output)
			{
				Clear_Bit(DDRB, Pin);
			}
			break;
		case Dio_PORTC:
			if(Direction == Dio_Input)
			{
				Set_Bit(DDRC, Pin);
			}
			else if(Direction == Dio_Output)
			{
				Clear_Bit(DDRC, Pin);
			}
			break;
		case Dio_PORTD:
			if(Direction == Dio_Input)
			{
				Set_Bit(DDRD, Pin);
			}
			else if(Direction == Dio_Output)
			{
				Clear_Bit(DDRD, Pin);
			}
			break;
		default:
			break;
	}
}

/*****************************************************************************************
! Description: Set the direction of a DIO port                                           *
! Name       : Dio_vidSetPortDirection                                                   *
! Input      : Port ID, Direction (IN, OUT)                                              *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
void Dio_vidSetPortDirection(enuDioPort Port, enuDioDirection Direction)
{
	switch(Port)
	{
		case Dio_PORTA:
			if(Direction == Dio_Input)
			{
				DDRA = 0xFFU;
			}
			else if(Direction == Dio_Output)
			{
				DDRA = 0x00U;
			}
			break;
		case Dio_PORTB:
			if(Direction == Dio_Input)
			{
				DDRB = 0xFF;
			}
			else if(Direction == Dio_Output)
			{
				DDRB = 0x00U;
			}
			break;
		case Dio_PORTC:
			if(Direction == Dio_Input)
			{
				DDRC = 0xFFU;
			}
			else if(Direction == Dio_Output)
			{
				DDRC = 0x00U;
			}
			break;
		case Dio_PORTD:
			if(Direction == Dio_Input)
			{
				DDRD = 0xFFU;
			}
			else if(Direction == Dio_Output)
			{
				DDRD = 0x00U;
			}
			break;
		default:
			break;
	}
}

/*****************************************************************************************
! Description: Write a specific logic state to DIO pin                                   *
! Name       : Dio_vidWritePin                                                           *
! Input      : Port ID, Pin Number, Pin Logic State                                      *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
void Dio_vidWritePin(enuDioPort Port, uint8 Pin, enuDioState State)
{
	switch(Port)
	{
		case Dio_PORTA:
			if(State == Dio_High)
			{
				Set_Bit(PORTA, Pin);
			}
			else if(State == Dio_Low)
			{
				Clear_Bit(PORTA, Pin);
			}
			break;
		case Dio_PORTB:
			if(State == Dio_High)
			{
				Set_Bit(PORTB, Pin);
			}
			else if(State == Dio_Low)
			{
				Clear_Bit(PORTB, Pin);
			}
			break;
		case Dio_PORTC:
			if(State == Dio_High)
			{
				Set_Bit(PORTC, Pin);
			}
			else if(State == Dio_Low)
			{
				Clear_Bit(PORTC, Pin);
			}
			break;
		case Dio_PORTD:
			if(State == Dio_High)
			{
				Set_Bit(PORTD, Pin);
			}
			else if(State == Dio_Low)
			{
				Clear_Bit(PORTD, Pin);
			}
			break;
		default:
			break;
	}
}

/*****************************************************************************************
! Description: Write value to a specific DIO port                                        *
! Name       : Dio_vidWritePort                                                          *
! Input      : Port ID, Pin Number, Pin Logic State                                      *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
void Dio_vidWritePort(enuDioPort Port, uint8 Pin, uint8 Value)
{
	switch(Port)
	{
		case Dio_PORTA:
			PORTA = Value;
			break;
		case Dio_PORTB:
			PORTB = Value;
			break;
		case Dio_PORTC:
			PORTC = Value;
			break;
		case Dio_PORTD:
			PORTD = Value;
			break;
		default:
			break;
	}
}

/*****************************************************************************************
! Description: Read a specific logic state of a DIO pin                                  *
! Name       : Dio_u8ReadPin                                                             *
! Input      : Port ID, Pin Number, Pin Logic State                                      *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
uint8 Dio_u8ReadPin(enuDioPort Port, uint8 Pin)
{
	uint8 u8Result = 0U;
	
	switch(Port)
	{
		case Dio_PORTA:
			if (Get_Bit(DDRA, Pin) == Dio_Input)
			{
				u8Result = Get_Bit(PINA, Pin);
			}
			else if (Get_Bit(DDRA, Pin) == Dio_Output)
			{
				u8Result = Get_Bit(PORTA, Pin);
			}
			break;
		case Dio_PORTB:
			if (Get_Bit(DDRB, Pin) == Dio_Input)
			{
				u8Result = Get_Bit(PINB, Pin);
			}
			else if (Get_Bit(DDRB, Pin) == Dio_Output)
			{
				u8Result = Get_Bit(PORTB, Pin);
			}
			break;
		case Dio_PORTC:
			if (Get_Bit(DDRC, Pin) == Dio_Input)
			{
				u8Result = Get_Bit(PINC, Pin);
			}
			else if (Get_Bit(DDRC, Pin) == Dio_Output)
			{
				u8Result = Get_Bit(PORTC, Pin);
			}
			break;
		case Dio_PORTD:
			if (Get_Bit(DDRD, Pin) == Dio_Input)
			{
				u8Result = Get_Bit(PIND, Pin);
			}
			else if (Get_Bit(DDRD, Pin) == Dio_Output)
			{
				u8Result = Get_Bit(PORTD, Pin);
			}
			break;
		default:
			break;
	}
}

/*****************************************************************************************
! Description: Read a specific logic state of a DIO port                                 *
! Name       : Dio_u8ReadPort                                                            *
! Input      : Port ID, Control Register(0: PIN, 1: PORT)                                *
! Output     : None                                                                      *
! Last_Author: Ahmed.Yasser                                                              *
/*****************************************************************************************/
uint8 Dio_u8ReadPort(enuDioPort Port, Control)
{
	uint8 u8Result = 0U;
	
	switch(Port)
	{
		case Dio_PORTA:
			if (Control == 0U)
			{
				u8Result = PINA;
			}
			else if (Control == 1)
			{
				u8Result = PORTA;
			}
			break;
		case Dio_PORTB:
			if (Control == 0U)
			{
				u8Result = PINB;
			}
			else if (Control == 1)
			{
				u8Result = PORTB;
			}
			break;
		case Dio_PORTC:
			if (Control == 0U)
			{
				u8Result = PINC;
			}
			else if (Control == 1)
			{
				u8Result = PORTC;
			}
			break;
		case Dio_PORTD:
			if (Control == 0U)
			{
				u8Result = PIND;
			}
			else if (Control == 1)
			{
				u8Result = PORTD;
			}
			break;
		default:
			break;
	}
}
