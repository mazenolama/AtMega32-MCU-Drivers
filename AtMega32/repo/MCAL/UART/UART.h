/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

//#ifndef REPO_MCAL_UART_UART_H_
//#define REPO_MCAL_UART_UART_H_

//          Define Reg.s
#define UDR *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)
#define UCSRC *((volatile u8*)0x40)

  //      Prototypes Func.s
/*
void USART_Init(void);
void USART_TransmitChar( u8 data);
u8 USART_ReceiveChar(void);
void USART_SendString(u8 *str);
void USART_ReceiveString(u8 *str);

**/

#define F_CPU 8000000UL
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_Init(u32 BAUDRATE);				 //USART initialize function
char USART_RxChar();						 //Data receiving function
void USART_TxChar(u8 data);					 //Data transmitting function
void USART_SendString(char *str);				 //Send string of USART data function
char USART_ReceiveString(char *str);

