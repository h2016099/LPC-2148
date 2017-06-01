**Objective**

To send continuous data to 74HC595 from 0 - 255 with a delay of 1 second between 2 consecutive values. 8 LEDs should display the count from 0-255 with 1 second interval between changing values. System should repeat this task infinitely.

**Project Workspace**

1. Used keil uvison5 with arm embedded c coding, libraries for the project taken from manufacturer’s website which is mentioned in the references.
2. The project explains about inter chip communication using SPI, sending it to serial to parallel data converter(74HC595) and display it on LEDs present on the board.
