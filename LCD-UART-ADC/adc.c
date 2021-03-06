/*SOURCE:- www.electroons.com*/
#include<LPC214x.H>
#include"adc.h"

unsigned int ADC(int adc_num,int channel,unsigned int mode)
{
   unsigned int val;
   if(adc_num==0)
   {
     AD0CR  = AD0CR|(0x0000FF00&(CLKDIV<<8)); // Dividing PCLK by CLKDIV 
     AD0CR  = AD0CR|PDN; // ADC is operational
     PINSEL0= PINSEL0| (3<<8)  ; // AD0_6 
     PINSEL0= PINSEL0| (3<<10) ; // AD0_7
     PINSEL1= (PINSEL1 & ~(3<<28))|(1<<28); //AD0_3
     PINSEL1= (PINSEL1 & ~(3<<18))|(1<<18); //AD0_4 
     PINSEL1= (PINSEL1 & ~(3<<24))|(1<<24); //AD0_1
     PINSEL1= (PINSEL1 & ~(3<<26))|(1<<26); //AD0_2
     
  
     AD0CR  = AD0CR|(1<<channel);
     if(mode==BURST_MODE)
     {
       AD0CR = AD0CR | (1<<16) ; // BURST_MODE Enable
       // NO need to give CLKS value because we are using 11clocks/10bits
       // NO need to give START bit value in BURST Mode
     }
     else if(mode==CONTROLLED_MODE)
     {
       AD0CR = (AD0CR & ~(7<<24))|(1<<24); // Start Conversion NOW
     }
     
     while(!(AD0GDR&(0x80000000))); // wait to finish conversion
     val = AD0GDR;
     val = val & DATA_MASK;
     return(val>>6);    
   }// ADC0 Code Ends Here
   else if(adc_num==1)
   {
      // Write Code for ADC1 Here
   }
   return(0);
}
