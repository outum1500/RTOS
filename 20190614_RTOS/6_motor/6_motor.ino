void setup() {
  // put your setup code here, to run once:
  DDRB=0x20; //5번, 13번pin
  TCCR2A=0x00; //모드 세팅
  TCCR2B=0x02; //010, 8분주
  TCNT2=192; //64마다 인터럽트
  TIMSK2=0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}

int i=0;

SIGNAL(TIMER2_OVF_vect){
  static int count=0;
  TCNT2=192;

  count++;
  if(count==625){
    count=0;
    PORTB=0x20;
  }
  if(count==22){
    PORTB=0x00;
  }
}
