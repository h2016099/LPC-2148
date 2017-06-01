**Objective**

To send continuous data to 74HC595 from 0 - 255 with a delay of 1 second between 2 consecutive values. 8 LEDs should display the count from 0-255 with 1 second interval between changing values. System should repeat this task infinitely.

**Project Workspace**
1. Used keil uvison5 with arm embedded c coding, libraries for the project taken from manufacturer’s website which is mentioned in the references.
2. The project explains about inter chip communication using SPI, sending it to serial to parallel data converter(74HC595) and display it on LEDs present on the board.

**Schematic**
![image](https://cloud.githubusercontent.com/assets/25156625/26692465/6e72d4ba-471e-11e7-8e0d-52b8310114ac.png)

**Methodology**

LPC 2148 is set to SPI mode using PINSEL0 register by giving it corresponding bits.

Configured SPI as Master, sending LSB first, Enabling SPI is done using S0SPCR register.

S0SPCCR register which used to set the frequency of SCK should be set to a value greater than or equal to 8. 

Port 0.7 is connected to SHCP. It is set and cleared using IOSET0 & IOCLR0 respectively.

**Register Description**

![image](https://cloud.githubusercontent.com/assets/25156625/26692594/e0cf5416-471e-11e7-9f15-966166d8484e.png)


**About Code**

1. In the main function PINSELECT0 Register is used to select the function MOSI , S clock and the P0.7 is used as a GPIO Configured as output using IODIR0. Basically this Gpio is used as SHCP clock To Latch the data on the parallel ports.
2. S0SPCCR is clock prescaling register which is being fed to the STCP. We have used the value as 8 for prescaling.
3. When the SHCP goes from Low to High the data is latched on the Parallel ports, the data transmission is checked through SPIF of S0SPSR register in the while loop.
4. Each time SPIF bit after Reading is made low by reading into S0SPSR and S0SPDR register.

**References**

  * www.electroons.com
  
  * LPC 2148 blueboard schematics user manual.
