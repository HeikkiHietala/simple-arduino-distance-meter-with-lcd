# A simple Arduino and HCSR04 based distance meter with 2 line LCD display

This file uses the ubiquitous HC-SR04 distance sensor and a LCD1602 two-line LCD display to measure distances between 3cm and 550 cm with reasonable accuracy. All connections are listed in the code. 

This code uses the LCD1602 without the I2C backpack. 

There is also a switch directly between the battery and the Arduino's power pin, so it turns on when you push the button, and starts measuring at 500 ms intervals. 
