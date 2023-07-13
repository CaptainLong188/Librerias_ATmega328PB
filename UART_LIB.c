#include "UART_LIB.h"

void UART0_Init(uint32_t baudRate){
    
    // Configuración de pines RX y Tx
    
    DDRD |=  (1 << 1); // TxD0 -> Salida
    DDRD &= ~(1 << 0); // RxD0 -> Entrada
    
    // Configuración de parámetros de UART0
    
    UCSR0A |= (1 << U2X0); // Doble velocidad
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); // Habilitar Rx y Tx
    UCSR0C &= ~((1 << UMSEL01) || (1 << UMSEL00)); // Modo asíncrono
    UCSR0C &= ~((1 << UPM01) || (1 << UPM00)); // Sin paridad
    UCSR0C &= ~(1 << USBS0); // 1 bit de Stop
    UCSR0B &= ~(1 << UCSZ02);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Modo de 8 bits
    
    // Configuración de la velocidad en baudios
    
    UBRR0 = (uint16_t)((F_CPU/ 8UL/ baudRate) - 1UL);
}

void UART0_Transmit_Char(char byte){
    
    while(!(UCSR0A & (1 << UDRE0))); // Espera a que el registro de transmisión este vacío
    UDR0 = byte; // Carga el dato en el registro de transmisión
}

void UART0_Transmit_String(const char *str){
    
    while(*str != '\0'){
        UART0_Transmit_Char(*str++);
    }
}

bool UART0_Data_Available(){
    return (UCSR0A & (1 << RXC0));
}

char UART0_Read_Char(void){
    while(!(UCSR0A & (1 << RXC0)));
    return (char)(UDR0);
}

void UART1_Init(uint32_t baudRate){
    
    // Configuración de pines RX y Tx
    
    DDRB |=  (1 << PB3); // TxD1 -> Salida  (PB3)
    DDRB &= ~(1 << PB4); // RxD1 -> Entrada (PB4)
    
    // Configuración de parámetros de UART0
    
    UCSR1A |= (1 << U2X1); // Doble velocidad
    UCSR1B |= (1 << RXEN1) | (1 << TXEN1); // Habilitar Rx y Tx
    UCSR1C &= ~((1 << UMSEL11) || (1 << UMSEL10)); // Modo asíncrono
    UCSR1C &= ~((1 << UPM11) || (1 << UPM10)); // Sin paridad
    UCSR1C &= ~(1 << USBS1); // 1 bit de Stop
    UCSR1B &= ~(1 << UCSZ12);
    UCSR1C |= (1 << UCSZ11) | (1 << UCSZ10); // Modo de 8 bits
    
    // Configuración de la velocidad en baudios
    
    UBRR1 = (uint16_t)((F_CPU/ 8UL/ baudRate) - 1UL);
}

void UART1_Transmit_Char(char byte){
    
    while(!(UCSR1A & (1 << UDRE1))); // Espera a que el registro de transmisión este vacío
    UDR1 = byte; // Carga el dato en el registro de transmisión
}

void UART1_Transmit_String(const char *str){
    
    while(*str != '\0'){
        UART1_Transmit_Char(*str++);
    }
}

bool UART1_Data_Available(){
    return (UCSR1A & (1 << RXC1));
}

char UART1_Read_Char(void){
    while(!(UCSR1A & (1 << RXC1)));
    return (char)(UDR1);
}
