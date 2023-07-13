#ifndef UART_H
#define	UART_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define F_CPU 16000000UL


void UART0_Init(uint32_t baudrate);
void UART0_Transmit_Char(char byte);
void UART0_Transmit_String(const char *str);
bool UART0_Data_Available(void);
char UART0_Read_Char(void);

void UART1_Init(uint32_t baudrate);
void UART1_Transmit_Char(char byte);
void UART1_Transmit_String(const char *str);
bool UART1_Data_Available(void);
char UART1_Read_Char(void);

#endif	/* UART_H */

