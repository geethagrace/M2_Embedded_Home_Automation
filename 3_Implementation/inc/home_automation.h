/**
 * @file home_automation.h
 * @author GEETHA
 * @brief Header file for Home Automation with automation features
 *
 */

#ifndef __HOME_AUTOMATION_H__
#define __HOME_AUTOMATION_H__

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

/**
* @brief usart initialization
* @param[in] ubrr_value
* @return 
*/
void USARTInit(uint16_t ubrr_value)

/**
* @brief reads character
* @return 
*/
char USARTReadChar()

/**
* @brief writes character.
* @return 
*/
void USARTWriteChar(char data)

/**
* @brief sends string
* @return displays in serial monitor
*/
void USARTSendString(char *str)

/**
* @brief timer for 15mins
* @return heater output
*/
void user_delay()

#endif  /* #define __HOME_AUTOMATION_H__ */
