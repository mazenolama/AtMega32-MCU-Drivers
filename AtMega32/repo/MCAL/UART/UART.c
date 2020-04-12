/*
 * UART.c
 *
 *
 *      Author: Mazen Olama
 */

#include "../../LIB/STDTYPES.h"
#include "UART.h"

/*
void USART_Init(void)
{
	// Set BaudRate --> 9600/16Mhz
	UBRRL =102;
	UBRRH = 0;
	// Set Frame Format -> 8 data 1 stop (bit) , No parity
	UCSRC = 0x86; // 0b1000 0110
	// Enable Rx and Tx
	UCSRB = 0x18; // 0b0001 1000
}

void USART_TransmitChar( u8 data)
{
	//Wait until empty tansmit buffer
	while((UCSRA & 0x02) == 0x00);
	//put Data in UDR Reg
		UDR = data;
}
u8 USART_ReceiveChar(void)
{
	u8 Result;
	//Wait until Reception finished
	while((UCSRA &0x08)== 0x00);
		Result=UDR ;
	// Clear Flag
	UCSRA = (1<<7);
	return Result;
}
*/
void USART_Init(u32 BAUDRATE)
{
	UCSRB |= (1 << 4) | (1 << 3);
	UCSRC |= (1 << 7)| (1 << 1) | (1 << 2);
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}

char USART_RxChar()
{
	while (!(UCSRA & (1 << 7)));
	return(UDR);
}

void USART_TxChar(u8 data)
{
	UDR = data;
	while (!(UCSRA & (1<<5)));
}

void USART_SendString(char* str)
{

	int i=0;
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						// Send each char of string till the NULL
		i++;
	}
}/*
void USART_ReceiveString(char *str)
{
	while (*str != '\0')                          // receive each char of string till the NULL
	{
		*str= USART_RxChar();
		str++;
	}
	//*str= '\0' ;
}*/

char USART_ReceiveString(char *str)
{char k, f;
f=sizeof(str);

	/*while (k!= '\0')                          // receive each char of string till the NULL
	{
		str= USART_RxChar();
		str++;
	}
	str= '\0' ;*/
return f;
}


