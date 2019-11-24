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
  SPDR = 0x01;
  delay(1);
  digitalWrite(4, HIGH); // latch high
  digitalWrite(4, LOW); // latch low
  delay(1000);
  
  SPDR = 0x00;
  delay(1);
  digitalWrite(4, HIGH); // latch high
  digitalWrite(4, LOW); // latch low
  delay(1000);
}
