# Objective

To convert the data given through potentiometer and display it on LCD and also send it over Asynchronous serial (UART) link. Enable serial communication between PC and LPC 2148 asynchronously

# Methodology

LPC 2148 is configured to ADC-0 mode using PINSEL0 register by giving it corresponding bits. Configured ADC to channel 3 using AD0CR register. The given data through potentiometer is converted to digital in controlled mode. The converted is displayed on LCD and is sent over Asynchronous serial (UART) link. Serial Communication between PC and LPC 2148 is made asynchronously using UART0 with a baud rate of 9600bps.

# Schematic

![image](https://user-images.githubusercontent.com/25156625/26948136-e8d8a236-4cb2-11e7-9a6b-328b119be639.png)

# Register Description

For register description go through the LPC 2148 user manual (UART & ADC)

# Explanation

1. Header <LPC214X.h> is containing all the register definitions which enables us to use register names instead of Memory location of   every SFR.
2. Delay function is implemented to provide delay between data display on the led.
3. In the main function PINSEL1 Register is used to enable the ADC and PINSELECT0 Register is used to enable the UART and the AD0CR 
4. register is configured for channel, mode and to start the conversion. AD0GDR acknowledges the finish of the conversion.
5. LCD is initialized using basic instructions and the LCD is changed from Command Mode to Data Write mode by using LCDRS. lcd_putstring function is used to print the given string on a specific line (1 or 2).
6. UART is initialized using basic instructions and uart0_init function is used to set the baud rate to 9600bps. Uart0_puts function is used to send the specific string of data over asynchronous serial link.
7. UART, LCD and ADC initialisations were took from www.electroons.com

# References

* LPC 2148 USER MANUAL
* www.ngxtechnologies.com
* www.electroons.com






