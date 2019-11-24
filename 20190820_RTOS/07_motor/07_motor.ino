unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, var = 6;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 192;
  TIMSK2 = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 20){
    previous_millis = current_millis;
    var++;
    if(var == 72){
      var = 22;
    }
  }
}

SIGNAL(TIMER2_OVF_vect){
  TCNT2 = 192; 
  count++;
  if(count == 625){
    count = 0;
    PORTB = 0x20;
  }
  else if(count == var){
    PORTB = 0x00;
  }
}

SIGNAL(TIMER2_COMPA_vect){
}
