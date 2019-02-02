#ifndef TMR0_CFG_H
#define TMR0_CFG_H

/*
 * 0: Normal Mode
 * 1: CTC Mode
 * 2: FastPWM
 * 3: PhaseCorrect
 */
#define TMR0_MODE 0

/*
 Description: Controls the state of PWM signal
 Values     : [0: Non-Inverted Output, 1: Inverted Output]
*/
#define TMR0_PWM_INVERTED 0

/*
  Description: Enables Timer Over Flow Interrupt
  Values     : [0: Interrupt on Over Flow is disabled, 1: Interrupt on Over Flow is enabled]
*/
#define TMR0_OVF_ENABLED 1

/*
 Description: Enable Compare-Match Interrupt
 Values     : [0: Interrupt on Compare-Match is disabled, 1: Interrupt on Compare-Match is enabled]
*/
#define TMR0_COM_ENABLED 0


#endif
