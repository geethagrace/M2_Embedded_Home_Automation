#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void user_delay();
unsigned volatile overflow;

void user_delay()
{
    TCCR1B |= (1<<CS10);
    TIMSK1 |= (1<<TOIE1);
    TCNT1 = 0;
    overflow = 0;
    sei();
    while(1)
    {
        if(overflow >= 219729)
        {
            if(TCNT1 >= 59985)
            {
                PORTB &= ~(1<<PORTB3);
                USARTSendString("Heater is off\n");
                TCNT1 = 0;
                overflow = 0;
            }
        }
    }
}

ISR(TIMER1_OVF_vect)
{
    overflow++;
}
