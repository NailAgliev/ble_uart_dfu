#ifndef ADS1230_H__
#define ADS1230_H__


#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "nrf_delay.h"
#include "app_timer.h"
//#include "nrf_drv_pwm.h"



#define HX_DATA	4
#define HX_SCK	3


extern uint32_t adc_value;
extern char buffer[20];
static uint8_t adc_ready;
extern uint8_t adc_value_ready;

void ADS1230_init(void);
uint32_t Weighing(void);
void ConvertADC(void);

#endif
