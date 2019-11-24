unsigned long previous_millis = 0;
unsigned long current_millis = 0;
unsigned long previous_micros = 0;
unsigned long current_micros = 0;
int count = 0, var = 6, right_flag = 1;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20; // -> pinMode
  
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

SIGNAL(TIMER2_OVF_vect){
  TCNT2 = 192; 
  count++;
  if(count == 625){
    count = 0;
    PORTB = 0x20; // -> digitalWrite
  }
  else if(count == var){
    PORTB = 0x00;
  }
}

SIGNAL(TIMER2_COMPA_vect){
}
