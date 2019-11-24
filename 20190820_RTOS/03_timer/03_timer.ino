unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, limit = 0;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 64;
  TIMSK2 = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}

SIGNAL(TIMER2_OVF_vect){
    count++;

    if(count == 100){
      PORTB = 0x20;
      count = 0;
    }
    else if(count == 25)
      PORTB = 0x00;
}
