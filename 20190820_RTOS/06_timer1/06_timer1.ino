unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, var = 6;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;

  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCNT1 = 524;
  OCR1A = 524+50;
  TIMSK1 = 0x03;
}

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 10){
    previous_millis = current_millis;
    var++;
    if(var == 255){
      var = 6;
    }
  }
}

SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 6; 
  PORTB = 0x20;
  OCR1A = var; // 가변


}

SIGNAL(TIMER1_COMPA_vect){
  PORTB = 0x00;
}
