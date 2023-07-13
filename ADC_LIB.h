#ifndef ADC_LIB_H
#define	ADC_LIB_H

#include "CONFIG.h"

// Canales analógicos

typedef enum{   CH_ADC0,
                CH_ADC1,
                CH_ADC2,
                CH_ADC3,
                CH_ADC4,
                CH_ADC5,
                CH_ADC6,
                CH_ADC7
}ADC_Channel_t;

#define ADC_VREF        5.0f
#define ADC_RESOLUTION  1024.f

void ADC_Init(void);
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_StartConversion(void);
bool ADC_StateConversion(void);
void ADC_SelectChannel(ADC_Channel_t);
uint16_t ADC_GetConversion(ADC_Channel_t);

#endif	/* ADC_LIB_H */

