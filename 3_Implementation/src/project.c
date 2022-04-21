/*
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#include"usart.h"
#include"timer_delay.h"

unsigned char input;

int main(void)
{
    USARTInit(9600);
    DDRB |= (1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4)|(1<<DDB0);
    DDRD &= ~(1<<DDD7);
    DDRD &= ~(1<<DDD6);
    PORTD |= (1<<PD6);
    while(1){
        USARTInit(9600);
        input = USARTReadChar();
        if (input=='1')
        {
            PORTB |=(1<<PORTB1);
            USARTSendString("Light1 is on\n");
        }
        else if(input=='2')
        {
            PORTB &=~(1<<PORTB1);
            USARTSendString("Light1 is off\n");
        }
        else if(input=='3')
        {
            PORTB |= (1<<PORTB2);
            USARTSendString("Light2 is on\n");
        }
        else if(input=='4')
        {
            PORTB &=~(1<<PORTB2);
            USARTSendString("Light2 is off\n");
        }
        else if(input=='H')
        {
            PORTB |= (1<<PORTB3);
            USARTSendString("Heater is on and will automatically off after 15mins\n");
            user_delay();
        }
        else if(!(PIND&(1<<PD6)))
        {
            PORTB &= ~(1<<PORTB4);
            USARTSendString("Motor is off\n");
        }
        else if ((input=='M')&&((PIND&(1<<PD6))))
        {
            PORTB |= (1<<PORTB4);
            PORTB |= (1<<PORTB0);
            //sensor_level();
            USARTSendString("Motor is on and automaticallly off after level reached\n");
        }
        else
        {
            USARTSendString("Invalid instruction\n");
        }

    }
    return 0;
}
