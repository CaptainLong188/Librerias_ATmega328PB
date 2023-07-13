#include "ADC_LIB.h"

void ADC_Init(){
    
    // ADMUX : VREF = AVCC -> 5V con capacitor de 100nF en el pin AREF
    // Justificación del resultado en la conversión a la derecha
    ADMUX &= ~((1 << REFS1) | (1 << ADLAR));
    ADMUX |= (1 << REFS0);
    
    // ADCSRA : Prescaler 128 [111] -> ADC Clock = Fosc/128 = 125 KHz [50 - 200]
    ADCSRA |= ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
    
    // DIDR0 : Todos los canales analógicos desactivan su entrada digital
    DIDR0 = 0xFF;
}

void ADC_Enable(void){
    ADCSRA |= (1 << ADEN); // ADC encendido
}

void ADC_Disable(void){
    ADCSRA &= ~(1 << ADEN); // ADC apagado
}

void ADC_StartConversion(void){
    ADCSRA |= (1 << ADSC);
}

bool ADC_StateConversion(void){
    return (bool)(ADCSRA & (1 << ADSC)); // 1 mientras la conversión está en progreso
                                         // 0 cuando esta este completada
}

void ADC_SelectChannel(ADC_Channel_t channel){
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
}

uint16_t ADC_GetConversion(ADC_Channel_t channel){
    
    // Paso 1 : Seleccionar canal
    ADC_SelectChannel(channel);
    
    // Paso 2 : Iniciar la conversión A/D
    ADC_Enable();
    ADC_StartConversion();
    
    // Paso 3 : Esperar a que la conversión termine
    while(ADC_StateConversion());
    
    // Paso 4 : Deshabilitar ADC
    ADC_Disable();
    
    return (ADC);
}
