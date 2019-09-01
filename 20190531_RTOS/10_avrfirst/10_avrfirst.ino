void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);
  DDRB = 0x20;
  DDRB = 0x00;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PIND & 0x04){
    PORTB = 0x20;
  }
  else{
    //digitalWrite(13, LOW);
    PORTB = 0x00;
  }
    
  delay(100);
}
