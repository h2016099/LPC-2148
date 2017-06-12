#include <LPC214x.H>                       /* LPC214x definitions */
#include <stdio.h>
#include "lcd.h"
#include "i2c.h"
#include "type.h"

int read_buffer[1];
//uint8 write_buffer[1];
extern int count;
//extern uint8 r;
extern unsigned char main1(void);
extern void init_ext_interrupt(void);
__irq extern void Ext_ISR(void);
unsigned int main2();

uint8 main2 (void) 
{ 
	return (read_buffer[0]);
}

/**
**************************************************************************

****1111
  Function Name : delay()

  Description :This function suspends the tasks for specified ticks.	

  Input :  ticks:no of ticks in multiple of 1 usec
            task: task to be suspended

  Output : void

  Note :
*******************************************************************************
*/

/**
********************************************************************************************
	Function Name :	main()

	Description :
	
	Input :	Void

	Output : 

	Note :
**********************************************************************************************
*/

void eeprom(void)
{
	
	
	
	read_buffer[0] = count;
		
	m24xx_write(EEPROM_24XX256, 0 , 0 ,(char *)read_buffer,sizeof(read_buffer));
		
	
}

int main(void)
{ 
	
	int read_buffer1[1];
	uint32 delay1;

//	PINSEL0 |= 0x00000005 ;
	
	init_lcd();
	
	i2c_lpc_init(I2C_SPEED_100);		// Initialize I2C

	//eeprom();
	lcd_putstring(0,"EEPROM");
	
	m24xx_read(EEPROM_24XX256, 0 , 0 ,(char *)read_buffer , sizeof(read_buffer));	// Type, Starting address,Hardware Values A2,A1,A0 ,Data dst buf,Bytes to read qty
	
		

		

		init_ext_interrupt(); 

		

		
while(1)
	{ 	

		
		sprintf((char *)read_buffer1, "I2C:%d", count);
			
	  lcd_putstring(1,(char *)read_buffer1);
		
		
		for(delay1=0;delay1<=500;delay1++);
		
		eeprom();
	
	}
	

}