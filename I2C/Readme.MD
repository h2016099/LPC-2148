# Objective

To Store the external interrupt counts in I2C serial EEPROM and update it continuously.

# PROJECT WORKSPACE
* Used keil uvison5 with arm embedded c coding, libraries for the project taken from manufacturer’s website which is mentioned in the references.
* The project explains about inter chip communication using I2C protocol, Servicing of external interrupts in real time, Memory Mapping of EEPROM.

# Critical Issues
* System should be able to retain the last count of the switch press even after power is lost and should start with the last updated value of count when the power resumes to the system.
* Display the current value of count on the LCD display and display should be refreshed fast enough to see count in real time.

# Register Description

Refer to the LPC2148 user manual for register addressing (I2C)

# Methodology

LPC 2148 is configured to I2C mode and external interrupt mode using PINSEL0 register by giving it corresponding bits. LPC2148 board has I2C serial EEPROM on it, we will use the external interrupt switch to raise an external interrupt request to LPC2148 CPU. Every time an external interrupt request is raised to the CPU, an integer type variable declared in the SRAM will be incremented by one.

# Schematic

![image](https://user-images.githubusercontent.com/25156625/27049476-1cd60d5e-4fcd-11e7-81f4-14ab5aec6925.png)


# Flow Chart

![image](https://user-images.githubusercontent.com/25156625/27049510-353bde78-4fcd-11e7-88b5-ce5b7211b44d.png)

# Project Explanation

* Header LPC214X.h, I2C.H, lcd.h, extint.c, stdio.h, type.h is containing all the register definitions which enables us to use register names instead of Memory location of every SFR.
* Delay function is implemented to provide delay between data display on the lcd.
* The SW1 is used to raise the external interrupt and in the ISR the count is raised every time.
* In the main function, first we have read the value that is previously present in EEPROM into a buffer and it is assigned to our count variable so that when power is interrupted latest value of count is read.
* Each time the count is incremented it is also written into EEPROM using write command.
* LCD is initialized using basic instructions and the LCD is changed from Command Mode to Data Write mode by using LCDRS. lcd_putstring function is used to print the given string on a specific line (1 or 2).

# References

* I2C, LCD and external interrupt initialisations we took from www.ngxtechnologies.com
* LPC 2148 data sheet UM10139
