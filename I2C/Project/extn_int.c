/************************************************************/
/* PROJECT NAME: EXTERNAL INTERRUPT	                       	*/
/* Device:       LPC2148                										*/
/* Filename:     ExtInt.c                                   */
/* Language:     C                      	                	*/
/* Compiler:     Keil ARM				                						*/
/* For more detail visit www.binaryupdates.com		        	*/
/************************************************************/

#include <LPC214x.H>  
#include "type.h"
#include "i2c.h"
#include "lcd.h"

void delay1(int count);
void init_ext_interrupt(void);
__irq void Ext_ISR(void);

//uint8 read_buffer[1];
//uint8 read_buffer[1];
int count;
//uint8 r=0x49;
extern uint8 main2();

uint8 main1 (void) 
{ 
	
	return (count);

}


void init_ext_interrupt()  // Initialize Interrupt
{
		//char write_buffer[1];
	
  EXTMODE = 0x4; 		//Edge sensitive mode on EINT2
  
  EXTPOLAR &= ~(0x4); 	//Falling Edge Sensitive

  PINSEL0 |= 0x80000000; //Select Pin function P0.15 as EINT2
  
  /* initialize the interrupt vector */
  VICIntSelect &= ~ (1<<16);        	// EINT2 selected as IRQ 16
  VICVectAddr5 = (unsigned int)Ext_ISR; // address of the ISR
  VICVectCntl5 = (1<<5) | 16;			// 
  VICIntEnable = (1<<16);           	// EINT2 interrupt enabled

  EXTINT &= ~(0x4);
	
//count = main2();
	
count = I2C0ADR;
	
	//	write_buffer[0] = main1();

	 // m24xx_write(EEPROM_24XX256, 0 , 0 ,write_buffer,sizeof(write_buffer));
	
}

__irq void Ext_ISR(void) // Interrupt Service Routine-ISR 
{
	
	//unsigned char i=0;
	
	//	IO1DIR |= (1<<25);
	//IO1CLR |= (1<<25); 	 // Turn ON Buzzer
	delay1(40000);
  //IO1SET |= (1<<25); 	 // Turn OFF Buzzer
 
	count++;
	//r++;
	EXTINT |= 0x4; 		 //clear interrupt
	VICVectAddr = 0; 	 // End of interrupt execution
	
		
//	read_buffer[0]=count;

}

void delay1(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}
