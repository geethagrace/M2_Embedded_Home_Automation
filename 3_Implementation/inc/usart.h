#ifndef _usart_h_
#define _usart_h_

void USARTInit(uint16_t );
char USARTReadChar();
void USARTWriteChar(char);
void USARTSendString(char *str)
  
#endif // _usart_h_
