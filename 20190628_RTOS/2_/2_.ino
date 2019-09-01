void setup() {
  // put your setup code here, to run once:
  TCCR2A=0x00;
  TCCR2B=0x02;
  TCNT2=56; // 200개째때 인터럽트 발생
  TIMSK2=0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

SIGNAL(TIMER2_OVF_vect){
  TCNT2=56;
  count++;
  if(count==100){
    count=0;
    digitalWrite(high);
  }
  if(count==25){
    digitalWrite(low);
  }
}
