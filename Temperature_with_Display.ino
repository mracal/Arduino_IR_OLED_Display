
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//IR Temperature
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//OLED Object
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//Button
const int buttonPin = 2;

//variable
int buttonState = 0; // push button state

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
  Serial.println("Adafruit MLX90614 test");  
  
   
  u8g2.begin();
  initializeDisplay();
 
}
void loop() {
  buttonState = digitalRead(buttonPin);
  
 
  if (buttonState == HIGH) {
    // read temperature and display
    readAndDisplay();
  }
}

void initializeDisplay () {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_t0_16b_tf);  // choose a suitable font
  u8g2.drawStr(20,20,"Temperature"); // write something to the internal memory
  u8g2.drawStr(40,40,"----");
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(500);  
}

void readAndDisplay(){
  mlx.begin(); // This declaration must be inside the reader function
  char tempC [10];
  float tempValue = 0;
  char *pointer_to_created_string;

  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.println();
  tempValue = mlx.readObjectTempC();
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.println();
  pointer_to_created_string = dtostrf(tempValue, 4, 2, tempC);
  Serial.print("converted to string: "); Serial.println(pointer_to_created_string);
  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_t0_16b_tf);  // choose a suitable font
  u8g2.drawStr(10,20,"Temperature *C"); // write something to the internal memory
  u8g2.drawStr(40,40,pointer_to_created_string);  // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(500);  
}
