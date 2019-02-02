#include "LCD.h"
#include "Dio.h"
#include "util/delay.h"

/***************************************************************
 * Description: Shall Initialize LCD Module
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void LCD_vidInit(void)
{
    /*Wait for 30ms*/
    _delay_ms(30);

    /*Send Funcltion_Set Command*/
    LCD_vidWriteCommand(LCD_FUNCTION_SET);

    /*Wait for 1ms*/
    _delay_ms(1);

    /*Send Display Status Command*/
    LCD_vidWriteCommand(LCD_DISPLAY_ON);

    /*Wait for 1ms*/
    _delay_ms(1);

    /*Send Display_Clear Command*/
    LCD_vidWriteCommand(LCD_CLEAR);

    /*Wait for 2ms*/
    _delay_ms(2);

    /*Send the configured Entry Mode*/
    LCD_vidWriteCommand(LCD_ENTRY_MODE);
}

/***************************************************************
 * Description: Shall Write Command to LCD
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void LCD_vidWriteCommand(uint8 Command)
{
    /*Clear RS Signal*/
    Dio_vidWritePin(Dio_PORTC, 0U, Dio_Low);

    /*Clear R\W Signal*/
    Dio_vidWritePin(Dio_PORTC, 1U, Dio_Low);

    /*Write the Command to the Data Port*/
    Dio_vidWritePort(Dio_PORTD, Command);

    /*Set the Enable Signal*/
    Dio_vidWritePin(Dio_PORTC, 2U, Dio_High);

    /*Wait for a while (1ms)*/
    _delay_ms(1U);

    /*Clear Enable Signal*/
    Dio_vidWritePin(Dio_PORTC, 2U, Dio_Low);

    /*Wait for the LCD to finish executing*/
    _delay_ms(10U);
}

/*******************************************************************
 * Description: Shall Write Data to LCD                            *
 * Input      : None                                               *
 * Output     : None                                               *
 * Last_Author: Ahmed.Yasser                                       *
 *******************************************************************/
void LCD_vidWriteData(uint8 Data)
{
    /*Set RS Signal*/
    Dio_vidWritePin(Dio_PORTC, 0, Dio_High);

    /*Clear R\W Signal*/
    Dio_vidWritePin(Dio_PORTC, 1, Dio_Low);

    /*Write the Data to the Data Port*/
    Dio_vidWritePort(Dio_PORTD, Data);

    /*Set the Enable Signal*/
    Dio_vidWritePin(Dio_PORTC, 2, Dio_High);

    /*Wait for a while (1ms)*/
    _delay_ms(1);

    /*Clear Enable Signal*/
    Dio_vidWritePin(Dio_PORTC, 2, Dio_Low);

    /*Wait for the LCD to finish executing*/
    _delay_ms(10);
}

/***************************************************************
 * Description: Moves the cursors to a desired position        *
 * Input      : None                                           *
 * Output     : None                                           *
 * Last_Author: Ahmed.Yasser                                   *
 ***************************************************************/
void LCD_vidGoTo(uint8 Line, uint8 Column)
{
    uint8 LineBase;
    if (Column >= 1 && Column <= 16)
    {
        switch(Line)
        {
        case 1:
            LineBase = 0x00;
            break;
        case 2:
            LineBase = 0x40;
            break;
        }

        LCD_vidWriteCommand(LCD_MOVE_CURSOR + (LineBase + (Column - 1)));
    }
}
/***************************************************************
 * Description: Shall write a Null-Terminated string to the LCD
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void LCD_vidWriteString(uint8 * Message)
{
    while(*Message != '\0')
    {
        LCD_vidWriteData(*Message);
        Message++;
    }
}

/***************************************************************
 * Description: Shall Print a Number on the LCD
 * Input      : None
 * Output     : None
 * Last_Author: Ahmed.Yasser
 ***************************************************************/
void LCD_vidPrintNumber(uint32 Number)
{
    uint32 Factor = 1U;
    uint32 Digits = 0U;
    uint32 Temp   = Number;

    while (0U != Temp)
    {
        Digits++;
        Temp   = Temp / 10U;
        Factor = Factor * 10U;
    }

    /*Check if the number is equal to Zero*/
    if (0U != Digits)
    {
        for(Temp = 0U; Temp < Digits; Temp++)
        {
            Factor = Factor / 10U;
            LCD_vidWriteData((Number / Factor) + 0x30);
            Number = Number % Factor;
        }
    }
    else
    { /*Write the number if it is equal to zero*/
        LCD_vidWriteData(Number + 0x30);
    }
}
