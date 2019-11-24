void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  DDRB = 0x03; // 8번 pin / 0번 bit : Servo 0, 1번 bit : Servo 1 ...
  PORTB = 0x00;
  
  TCCR1A = 0x03;
  TCCR1B = 0x0A;
  TCCR1C = 0x00;
  TCNT1 = 960;
  TIMSK1 = 0x01;
}

int leftflag = 0;
int rightflag = 0;
int upflag = 0;
int downflag = 0;
int count = 0;
int servo = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int analog_x = 0, analog_y = 0;
  
  ADMUX = 0x40;
  ADCSRA = 0x87;
  ADCSRA |= 0x40; // start
  analog_x = ADC;

  while(ADCSRA & 0x40);
  ADMUX = 0x41;
  ADCSRA = 0x87;
  ADCSRA |= 0x40; // start
  analog_y = ADC;
  
  if(analog_x >= 400 && analog_x <= 700 && analog_y >= 400 && analog_y <= 700){ // center
    if(leftflag == 1 || rightflag == 1 || upflag == 1 || downflag == 1){
      Serial.println("center");
      leftflag = 0;
      rightflag = 0;
      upflag = 0;
      downflag = 0;
    }
  }
  else if(analog_x < 400){ // left
    if(leftflag == 0){
      Serial.println("left");
      leftflag = 1;
      rightflag = 0;
      upflag = 0;
      downflag = 0;
      servo = 22;
    }
  }
  else if(analog_x > 700){ // right
    if(rightflag == 0){
      Serial.println("right");
      rightflag = 1;
      leftflag = 0;
      upflag = 0;
      downflag = 0;
      servo = 72;
    }
  }
  else if(analog_y < 400){ // up
    if(upflag == 0){
      Serial.println("up");
      upflag = 1;
      downflag = 0;
      leftflag = 0;
      rightflag = 0;
    }
  }
  else if(analog_y > 700){ // down
    if(downflag == 0){
      Serial.println("down");
      downflag = 1;
      upflag = 0;
      leftflag = 0;
      rightflag = 0;
    }
  }
  

  delay(10);
}


SIGNAL(TIMER1_OVF_vect){ // 32us마다 count++
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB |= 0x01;
  }
  else if(count == servo){ // 모터의 방향이 맨 왼쪽일 때
    PORTB &= ~0x01;
  }
}
