// ---- 64분주 ----
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCNT1 = 524;
  OCR1A = 574;
  TIMSK1 = 0x03;
}

unsigned long current_millis = 0;
unsigned long previous_millis = 0;

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 20){
    previous_millis = current_millis;
    OCR1A += 50;
    if(OCR1A > 1024){
      OCR1A = 524;
    }
  }
}

SIGNAL(TIMER1_OVF_vect){ // TCNT가 MAX가 되면 들어옴
  TCNT1 = 524;
  PORTB = 0x20;
}

SIGNAL(TIMER1_COMPA_vect){ // TCNT가 OCR이랑 값이 같아지면 들어옴
  PORTB = 0x00;
}
