#define INST 0 
#define DATA 1
#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)

  //--------------------------8 bit mode --------------------------------
  char_lcd_set_8(0x30, INST); // 0x30
  char_lcd_set_8(0x30, INST); // 0x30
  char_lcd_set_8(0x30, INST); // 0x30
  char_lcd_set_8(0x28, INST); // 0x28
  //--------------------------8 bit mode end ----------------------------


  //--------------------------4 bit mode --------------------------------
  char_lcd_set_4(0x02, INST); // 0x28 : 2
  char_lcd_set_4(0x08, INST); // 0x28 : 8
  char_lcd_set_4(0x00, INST); // 0x06 : 0
  char_lcd_set_4(0x06, INST); // 0x06 : 6
  char_lcd_set_4(0x00, INST); // 0x0C : 0
  char_lcd_set_4(0x0C, INST); // 0x0C : C
  char_lcd_set_4(0x08, INST); // 0x80 : 8
  char_lcd_set_4(0x00, INST); // 0x80 : 0
  char_lcd_set_4(0x00, INST); // 0x01 : 0
  char_lcd_set_4(0x01, INST); // 0x01 : 1
  delay(5);
  //--------------------------4 bit mode --------------------------------
}

void loop() {
  char_lcd_set_4(0x03, DATA);
  char_lcd_set_4(0x01, DATA);

  delay(1000);
}

void char_lcd_set_8(char data, char flag) {
  i2c_set(0x00 | flag);                // RS low
  i2c_set(data | flag);         // DATA
  i2c_set(data | flag | 0x04);  // enable high
  i2c_set(data | flag);         // enable low
  i2c_set(data | 0x01);         // RS high

  delayMicroseconds(100);
}

void char_lcd_set_4(char data, char flag) {
  data = data << 4;
  i2c_set(0x00 | flag);                // RS low
  i2c_set(data | flag);         // DATA
  i2c_set(data | flag | 0x04);  // enable high
  i2c_set(data | flag);         // enable low
  i2c_set(data | 0x01);         // RS high

  delayMicroseconds(100);
}

void i2c_set(char data) {
  Wire.beginTransmission(0x27); // transmit to device #8
  Wire.write(data);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
}
