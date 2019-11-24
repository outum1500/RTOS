unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, var = 6;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR2A = 0x03;
  TCCR2B = 0x05;
  TCNT2 = 6;
  OCR2A = 25+6;
  TIMSK2 = 0x03;
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

SIGNAL(TIMER2_OVF_vect){
  TCNT2 = 6; 
  PORTB = 0x20;
  OCR2A = var; // 가변


}

SIGNAL(TIMER2_COMPA_vect){
  PORTB = 0x00;
}
