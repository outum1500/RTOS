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

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:

}

SIGNAL(TIMER1_OVF_vect){ // 32us마다 count++
  TCNT1 = 960;
  count++;
  if(count == 625){
    count = 0;
    PORTB |= 0x01;
  }
  else if(count == 22){ // 모터의 방향이 맨 왼쪽일 때
    PORTB &= ~0x01;
  }
}
