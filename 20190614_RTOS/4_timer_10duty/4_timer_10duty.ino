void setup() {
  // put your setup code here, to run once:
  DDRB=0x20; //5번, 13번pin
  TCCR2A=0x00; //모드 세팅
  TCCR2B=0x02; //010, 8분주
  TCNT2=56;
  TIMSK2=0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}

SIGNAL(TIMER2_OVF_vect){
  int b=0;
  static int count=0;
  TCNT2=56;

  count++;
  if(count==100){
    count=0;
    PORTB=0x20;
  }
  if(count==20){
    PORTB=0x00;
  }
}
