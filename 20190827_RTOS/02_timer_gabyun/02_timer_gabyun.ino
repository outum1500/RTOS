---- 8분주 ----
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;

  TCCR1A = 0x03;
  TCCR1B = 0x0A;
  TCNT1 = 960;
  TIMSK1 = 0x01;
}
int count = 0;
int limit = 22;
int flag = 0;
unsigned long current_millis = 0;
unsigned long previous_millis = 0;

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 20){
    previous_millis = current_millis;
    if(flag == 0){
      limit++;
      if(limit >= 72){
        flag = 1;
      }
    }
    else if(flag == 1){
      limit--;
      if(limit <= 22){
        flag = 0;
      }
    }
  }
}

SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB = 0x20;
  }
  else if(count == limit){
    PORTB = 0x00;  // var : 22 -> 72
  }
}

SIGNAL(TIMER1_COMPA_vect){
  
}
