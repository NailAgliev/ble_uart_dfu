#include "ads1230.h"
#include "nrf_drv_gpiote.h"
#include "nrf_gpio.h"


//проверка русского
uint32_t adc_value;
uint8_t calib = 0;

void in_data_handler (nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)

{
	adc_ready = 1;
}

void ADS1230_init(void)
{
	nrf_drv_gpiote_init();
	nrf_drv_gpiote_in_config_t in_data_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
	in_data_config.pull = NRF_GPIO_PIN_PULLUP;
	
	nrf_drv_gpiote_in_init (HX_DATA, &in_data_config, in_data_handler);
	nrf_drv_gpiote_in_event_enable(HX_DATA, true);
	
	nrf_gpio_cfg_output(HX_SCK);
	

}

uint32_t Weighing(void)
{
	
	uint8_t i = 0;
	
	if (calib == 0)
	{
		if (adc_ready == 1)
		{
		 for(i = 0; i<26; i++)  
			
					nrf_gpio_pin_set(HX_SCK);
					nrf_delay_us(5);
					nrf_gpio_pin_clear(HX_SCK);
					nrf_delay_us(5);
		}
		calib = 1;
	}
	//adc_value = 0;
		
	nrf_gpio_pin_clear(HX_SCK);
	
	if (adc_ready == 1)
	{
		adc_value = 0;
		nrf_drv_gpiote_in_event_disable(HX_DATA);
				for(i = 0; i<23; i++)
				{
					
					nrf_gpio_pin_set(HX_SCK);
					nrf_delay_us(5);
					adc_value <<= 1;
					nrf_gpio_pin_clear(HX_SCK);
					nrf_delay_us(5);
				
					if(nrf_drv_gpiote_in_is_set(HX_DATA))
						{
							adc_value++;
						}
				}
						
		adc_ready = 0;
		nrf_drv_gpiote_in_event_enable(HX_DATA, true);
	}
	return adc_value;
}







