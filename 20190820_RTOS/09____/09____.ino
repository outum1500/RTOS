unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, var = 6, right_flag = 1;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  
  TCCR1A = 0x03;
  TCCR2A = 0x0b;
  TCNT1 = 399;
  OCR1A = 574;
  TIMSK1 = 0x03;
}

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 20){
    previous_millis = current_millis;
    if(right_flag == 1){
      var++;
      if(var == 72){
        right_flag = 0;
      }
    }
    else if(right_flag == 0){
      var--;
      if(var == 22){
        right_flag = 1;
      }
    }
    
  }
}

SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 399; 

  if(count == 0) {
    PORTB == 0x20;
  }
  count++;
  if(count == 8){
    count = 0;
  }
}

SIGNAL(TIMER1_COMPA_vect){
  if(count == 0){
    PORTB = 0x00;
  }
}
