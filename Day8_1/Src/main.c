

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32] = "";
	SystemInit();
	EEPROM_Init();

	UartInit(BAUD_9600);


	int choice;
	UartPuts("Enter your choice number:\n\r");
	while(1)
	{
		UartGets(str);
		sscanf(str,"%d",&choice);
		switch(choice)
		{
		case 1:
			UartPuts("Message write on EEPROM\n\r");
			EEPROM_Write(0x0020, (uint8_t*)"GOD BLESS YOU!\r\n", 16);
		    break;
		case 2:
			EEPROM_Read(0x0020, (uint8_t*)str, 16);
		    UartPuts(str);
		    break;
		}


	}


	return 0;
}









