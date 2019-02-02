#ifndef TMR0_H
#define TMR0_H
#include "STD_Types.h"

void TMR0_vidInit(void);
uint8 TMR0_u8GetTimer(void);
void TMR0_vidSetTimer(uint8 Value);
void TMR0_vidSetCompareValue(uint8 Value);
#endif
