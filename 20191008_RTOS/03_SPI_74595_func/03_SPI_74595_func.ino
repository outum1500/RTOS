#define INST 0 
#define DATA 1

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT); // latch pin
  pinMode(10, OUTPUT); // SS output
  pinMode(11, OUTPUT); // MOSI, 74595의 data
  pinMode(13, OUTPUT); // SCK
  SPCR = 0x51;



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
  // put your main code here, to run repeatedly:
  
  char_lcd_set_4(0x03, DATA);
  char_lcd_set_4(0x02, DATA);
  
  delay(1000);
}

void char_lcd_set_8(char data, char flag) {
  SPDR = 0x00 | flag; // flag가 1이면 rs high
  while (!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag; // 데이터 추가
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag | 0x04; // enable high
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag & (~0x04); // enable low
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | 0x01; // rs high
  while(!(SPSR & 0x80));
  latch();

  delayMicroseconds(50);
}

void char_lcd_set_4(char data, char flag) {
  data = data << 4; // 0000 0001 이면 0001 0000으로. 상위 비트로 이동
  
  SPDR = 0x00 | flag; // flag가 1이면 rs high
  while (!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag; // 데이터 추가
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag | 0x04; // enable high
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | flag & (~0x04); // enable low
  while(!(SPSR & 0x80));
  latch();
  
  SPDR = data | 0x01; // rs high
  while(!(SPSR & 0x80));
  latch();

  delayMicroseconds(50);
}


void latch(){
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
