#define INST 0 
#define DATA 1
#include <Wire.h>

void setup() {
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

//void i2c_set(char data) {
//  Wire.beginTransmission(0x27); // transmit to device #8
//  Wire.write(data);        // sends five bytes
//  Wire.endTransmission();    // stop transmitting
//}

void i2c_set(char data){
  // Start condition /////////////////////////////////////////////////////
  TWCR = 0xA4; // start condition, TWI enable, flag clear

  //Serial.println("before int flag");
  while(!(TWCR & 0x80));
  if(TWSR & 0x08 == 0x08){
    Serial.println("Start OK !");
  }
  else
    Serial.println("Start Error !");
  // Start condition end /////////////////////////////////////////////////



  // Device Address //////////////////////////////////////////////////////
  TWDR = 0x27 << 1; // 8574 dev id : 0x27
  TWCR = 0x84; // twi inturrupt flag clear, TWI enable
  
  while(!(TWCR & 0x80));
  if(TWSR & 0x18 == 0x18){
    Serial.println("8574 Device Address send/ACK OK !");
  }
  else if(TWSR & 0x20 == 0x20){
    Serial.println("8574 Device Address send/Not OK !");
  }
  else
    Serial.println("8574 Device Address state Error !");
  // Device Address end //////////////////////////////////////////////////



  // EEPROM Memory Data State ////////////////////////////////////////////
  TWDR = data; // 보낼 데이터
  TWCR = 0x84; // 인터럽트 플래그 활성화, TWI enable
  while(!(TWCR & 0x80));
  if(TWSR & 0x28 == 0x28){
    Serial.println("8574 Data send/ACK OK !");
  }
  else if(TWSR & 0x30 == 0x20){
    Serial.println("8574 Data send/Not OK !");
  }
  else
    Serial.println("8574 Data state Error !");
  // EEPROM Memory Data State end ////////////////////////////////////////



  // Stop State //////////////////////////////////////////////////////////
  TWCR = 0x94;
  // Stop State end //////////////////////////////////////////////////////
}

void i2c_begin(){
  DDRC = 0x30; // 4번 5번 핀
  //PORTC = 0x30;

  TWBR = 18; // 100k로 만듦
  TWSR = 0x01; // twps : 1
  TWCR = 0x04; // I2C enable
}
