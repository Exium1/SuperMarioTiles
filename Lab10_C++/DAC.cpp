// put implementations for functions, explain how it works
// put your names here, date
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

#include "DAC.h"

// **************DAC_Init*********************
// Initialize 8-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
  	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_RCGCGPIO_R & 0x02) == 0) {};
		
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;
  
	GPIO_PORTB_DR8R_R |= 0xFF;
}

// **************DAC_Out*********************
// output to DAC
// Input: 8-bit data, 0 to 63 
// Input=n is converted to n*3.3V/63
// Output: none
void DAC_Out(uint8_t data){
	GPIO_PORTB_DATA_R = data & 0xFF;
}
