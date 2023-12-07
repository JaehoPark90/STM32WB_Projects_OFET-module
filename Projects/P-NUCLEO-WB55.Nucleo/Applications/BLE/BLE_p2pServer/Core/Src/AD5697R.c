#include "main.h"
// CHANGE THIS FOR YOUR CHIP
#include "stm32wbxx_hal_conf.h"
#include <math.h>
#include <AD5697R.h>
#include <stdint.h>
extern I2C_HandleTypeDef hi2c1;

static HAL_StatusTypeDef AD5697R_write(uint8_t* writeBuffer)
{
	HAL_StatusTypeDef retval;
	uint8_t ex[3];

	ex[0] = *writeBuffer;
	ex[1] = *(writeBuffer+1);
	ex[2] = *(writeBuffer+2);
	retval = HAL_I2C_Master_Transmit(&hi2c1, (uint8_t)AD5697R_ADDRESS, ex, 3, 100);
	return retval;
}

void AD5697R_setDAC(uint8_t port, double Vout)
{
	uint16_t ADCval = AD5697R_retDACval(Vout);

	uint8_t writeBuffer[3];

	if(port == 0){
		writeBuffer[0] = AD5697R_COM_WRUP | AD5697R_PORT_DACA;
	}
	else{
		writeBuffer[0] = AD5697R_COM_WRUP | AD5697R_PORT_DACB;
	}

	uint8_t a = 0b00000000;
	uint8_t b = 0b00000000;

	writeBuffer[1] = a|(ADCval>>4);
	writeBuffer[2] = b|(ADCval<<4);

	AD5697R_write(writeBuffer);
}

void AD5697R_init()
{
	uint8_t writeBuffer[3];


	writeBuffer[0] = AD5697R_COM_PWDN | AD5697R_PWDN_NOOP;
	writeBuffer[1] = 0b00000000;
	writeBuffer[2] = AD5697R_PWDN_NOOP;

	AD5697R_write(writeBuffer);
}

static uint16_t AD5697R_retDACval(double Vout)
{
	double ADC_val = 0;
	ADC_val = Vout/2.5*4095;
	uint16_t retVal = (int)ADC_val;

	return retVal;
}
