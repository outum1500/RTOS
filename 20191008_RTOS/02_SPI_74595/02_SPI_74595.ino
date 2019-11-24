void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT); // latch pin
  pinMode(10, OUTPUT); // SS output
  pinMode(11, OUTPUT); // MOSI, 74595의 data
  pinMode(13, OUTPUT); // SCK

  SPCR = 0x51;
}

void loop() {
  // put your main code here, to run repeatedly:
  char data = 0x30;
  SPDR = 0x00; // RS low
  while(!(SPSR & 0x80));
  SPDR = data; // data 0x30
  while(!(SPSR & 0x80));
  SPDR = data | 0x04; // 0x04 : enable high
  while(!(SPSR & 0x80));
  SPDR = data &(~0x04); // enable low
  while(!(SPSR & 0x80));
  SPDR = data | 0x01; // RS high
  while(!(SPSR & 0x80));
}
