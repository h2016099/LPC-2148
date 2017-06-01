#include <LPC214x.h> 			//LPC 2148 definitions

void delay_sec(unsigned int x);

void delay_sec(unsigned int x)
{
	
	int s,j;
	for(s=0;s<=x;s++)
	{
		for(j=0;j<=1000;j++);
	}
}

int main(void)
{
	int i;
	unsigned int j=0;
	i=j;
	PINSEL0 = 0x00001100;//mosi o/p and sclck select p0.4 as GPIO
	IODIR0 = 0x00000080;//port0.4 as output
	S0SPCCR = 8;// clock divide by 8
	S0SPCR = 0x0860;//lsb first 8 bit transmission,enable spi
	while(1)
	{//i=0;
	for(i=0;i<=255;i++)
	{
		IOCLR0 = 0x00000080;// shcp low
		S0SPDR = i;//variable data
		while(!(S0SPSR&(0x80)));//spif check
		delay_sec(10000);
		IOSET0 = 0x00000080;//shcp high
		j=S0SPSR;//spif low dummy bit
		j=S0SPDR;
	}
}
	return 0;
}
