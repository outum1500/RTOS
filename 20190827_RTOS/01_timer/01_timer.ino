void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;

  TCCR1A = 0x03;
  TCCR1B = 0x0A;
  TCNT1 = 960;
  TIMSK1 = 0x01;
}
int count = 0;

void loop() {
  // put your main code here, to run repeatedly:

}

SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB = 0x20;
  }
  else if(count == 72){
    PORTB = 0x00;  // var : 22 -> 72
  }
}

SIGNAL(TIMER1_COMPA_vect){
  
}
