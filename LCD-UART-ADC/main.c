
#include <LPC214x.H>
#include <stdio.h>
#include "lcd.h"
#include "adc.h"
#include "serial.h"

void delay1(int count)
{
  int j=0,i=0;
	for(j=0;j<count;j++)
  {
   for(i=0;i<35;i++);
  }
}

int main (void) 
{
	unsigned short value = 0;
	unsigned char buf[16] = {0};
	init_lcd(); 
	uart0_init();
	while(1)
	{
   lcd_clear();
   value = ADC(0,3,CONTROLLED_MODE); // BURST_MODE or CONTROLLED_MODE
	 lcd_putstring(0, "channel:3");
   sprintf((char *)buf, "ADC:%d ", value);
   lcd_putstring(1, (char *)buf);
   delay1(300000);  
   uart0_puts((char *)buf); 
	}
}


