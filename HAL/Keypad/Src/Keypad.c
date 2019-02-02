#include "Dio.h"
#include "Keypad.h"
#include "util/delay.h"

static uint8 RowPins[4] = {4, 5, 6, 7};
static uint8 ColumnPins[4] = {3, 2, 1, 0};

/*******************************************************
 * Description: Scans Keypad
 * Input      : Decimal Numbers
 * Output     : ASCII Value
 * Last_Author: Ahmed.Yasser
 * ******************************************************/
uint8 Keypad_u8ReadKey(void)
{
	uint8 Key = 16;
	uint8 Row;
	uint8 Column;

	for(Column = 0; Column < 4; Column++)
	{
		Dio_vidWritePin(Dio_PORTA, ColumnPins[Column], Dio_Low);
		for(Row = 0; Row < 4; Row++)
		{
			if (Dio_u8ReadPin(Dio_PORTA, RowPins[Row]) == 0)
			{
				/*Return Key Number*/
				Key = (4 * Row) + Column;

				/*Delay for De-bouncing*/
				_delay_ms(250);

				/*Exit For*/
				break;
			}
		}
		Dio_vidWritePin(Dio_PORTA, ColumnPins[Column], Dio_High);
		if(Key != 16) break;
	}

	return Key;
}
