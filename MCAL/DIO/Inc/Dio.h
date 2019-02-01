#ifndef DIO_H
#define DIO_H
#include "Std_Types.h"


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

void Dio_vidWritePin(enuDioPort Port, uint8 Pin, enuDioState State);
void Dio_vidSetPortDirection(enuDioPort Port, enuDioDirection Direction);
void Dio_vidSetPinDirection(enuDioPort Port, enuDioDirection Direction, uint8 Pin);
#endif