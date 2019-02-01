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
