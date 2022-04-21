#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"usart.h"
void USARTInit(uint16_t );
char USARTReadChar();
void USARTWriteChar(char);
void USARTSendString(char *str)

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
