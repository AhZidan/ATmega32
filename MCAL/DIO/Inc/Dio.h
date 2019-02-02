#ifndef DIO_H
#define DIO_H
#include "Std_Types.h"

#define PIN0
#define PIN1
#define PIN2
#define PIN3
#define PIN4
#define PIN5
#define PIN6
#define PIN7

typedef enum
{
    Dio_Low = 0,
    Dio_High
} enuDioState;

typedef enum
{
    Dio_Input = 0,
    Dio_Output
} enuDioDirection;

typedef enum
{
    Dio_PORTA, 
    Dio_PORTB,
    Dio_PORTC,
    Dio_PORTD
} enuDioPort;

uint8 Dio_u8ReadPin(enuDioPort Port, uint8 Pin);
void Dio_vidWritePort(enuDioPort Port, uint8 Pin, uint8 Value);
void Dio_vidWritePin(enuDioPort Port, uint8 Pin, enuDioState State);
void Dio_vidSetPortDirection(enuDioPort Port, enuDioDirection Direction);
void Dio_vidSetPinDirection(enuDioPort Port, enuDioDirection Direction, uint8 Pin);
#endif