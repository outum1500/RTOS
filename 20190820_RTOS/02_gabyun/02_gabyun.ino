void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  /* 인풋 모드로 바꾸고 싶다면?
  DDRB &= ~0x20; // 이렇게, 다시 아웃풋 모드로 바꾸고 싶다면?
  DDRB |= 0x20;
  */
}

unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, limit = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  /*
  PORTA = 0x20;
  delay(1000);
  PORTA = 0x00;
  delay(1000);
  */
  current_micros = micros();

  if(current_micros - previous_micros > 100){
    previous_micros = current_micros;

    count++;
    
    if(limit == 100){
      limit = 0;
    }
    if(count == 100){
      PORTB = 0x20;
      count = 0;
      limit++;
    }
    else if(count == limit)
      PORTB = 0x00;
  }
}
