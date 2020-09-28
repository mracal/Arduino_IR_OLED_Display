# Arduino_IR_OLED_Display
This is a quick tutorial on Arduino with IR Temperature Sensor and OLED Display
#===============================================================================================================
IR Sensor MLX90614
 	I2C Address 0x5A
	3.3V - 5Volts
	Built-in Resistors for I2C Pull Up 10K
	Temperature -40 to 125 C
	Accuracy 0.5 degrees
	https://github.com/adafruit/Adafruit-MLX90614-Library

#===============================================================================================================
OLED Module 
    	Address 0x78
	3.3V - 5Volts

Library
https://github.com/olikraus/u8g2

You can also install it using Library Manager

SPI and I2C version
SPI OLED is 0.96 and can be used upon declaring the object 

U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);

CLOCK – Pin 13
Data – Pin 11
Chip Select – Pin 10
DC/Data Command – Pin 9
Reset – Pin 8

I2C OLED is 1.3” and can be used upon declaring the object 
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
SDA – Pin A4
SCLOCK – Pin A5 
There is no need to have a 10K pull up

For the font, you can experiment by replacing the parameter 
u8g2.setFont(u8g2_font_t0_16b_tf);  // choose a suitable font

Fonts can be located at /libraries/U8g2/src/clib/u8g2_fonts.c 

