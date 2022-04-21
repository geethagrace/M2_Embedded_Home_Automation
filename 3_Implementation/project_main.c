/*
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>


void USARTInit(uint16_t );
char USARTReadChar();
void USARTWriteChar(char);
void USARTSendString(char *str)
void user_delay();
//void sensor_level();
unsigned char input;
unsigned volatile overflow;
//static volatile int pulse;
//static volatile int i;


void USARTInit(uint16_t ubrr_value)
{
    //Set Baud rate
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0X00ff ;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable Transmitter Receiver
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

char USARTReadChar()
{
    //Wait until data is available
    while(!(UCSR0A & (1<<RXC0)))
    {
        //DO NOTHING
    }
    return UDR0;
}

void USARTWriteChar(char data)
{
    //wait until transmitter is ready
    while (!(UCSR0A & (1<<UDRE0)))
    {
        //DO  NOTHING
    }
    //TO WRITE THE DATA TO USART BUFFER
    UDR0 = data;
}

void USARTSendString(char *str)
{
	uint8_t j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		USARTWriteChar(str[j]);
		j++;
	}
}

/*void sensor_level()
{
    GICR |= (1<<INT0);
    MCUCR |= (ISC00);
    int count = 0;
    pulse=0;
    sei();
    while(1)
    {
        PORTB |=(1<<PORTB0);
        _delay_ms(15);
        PORTB &= ~(1<<PORTB0);
        count = pulse/58;
        if(pulse == 60)
        {
            USARTSendString("Motor is off\n");
        }

    }
}
ISR(INT0_vect)
{
    if(i==1)
    {
        TCCR0B = 0;
        pulse = TCNT0;
        TCNT0 = 0;
        i = 0;

    }
    else if(i==0)
    {
        TCCR0B |= (1<<CS00);
        i = 1;
    }

}*/

 //timer for 15mins
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
