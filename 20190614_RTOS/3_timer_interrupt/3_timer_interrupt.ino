void setup() {
  // put your setup code here, to run once:
  DDRB=0x20; //5번, 13번pin
  TCCR2A=0x00;
  TCCR2B=0x04;
  TCNT2=6;
  TIMSK2=0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}

int toggle=0;
SIGNAL(TIMER2_OVF_vect){
  int b=0;
  static int count=0;

  count++;
  if(count>1000){
    if(toggle==0){
      PORTB=0x20; //켜기
      toggle=1;
      count=0;
    }
    else{
      PORTB=0x00; //끄기
      toggle=0;
      count=0;
    }
  }
}
