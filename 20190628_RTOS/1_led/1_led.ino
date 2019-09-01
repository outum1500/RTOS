void setup() {
  // put your setup code here, to run once:
  DDRB=0x20; //5번, 13번pin
  //current_mill=previous_mill=millis(); //동기 맞춤
  //current=previous=micros();
}
unsigned long current=0, current_mill=0;
unsigned long previous=0, previous_mill=0, previous1=0, previous_mill1=0;
int count=0, count1=0, flag=0;
int duty=10, duty_servo=22;

void loop() {
  // put your main code here, to run repeatedly:
  current=micros();
  current_mill=millis();
//  if(current-previous>100){
//    previous=current;
//    count++;
//    if(count==100){
//      PORTB=0x20;
//      count=0;
//    }
//    if(count==duty)
//      PORTB=0x00;
//  }
//  if(current_mill - previous_mill > 20){
//    previous_mill=current_mill;
//    duty++;
//    if(duty==90)
//      duty=10;
//  }

//  if(current-previous1){
//    previous1=current;
//    count1++;
//    if(count1==625){
//      count1=0;
//      PORTB=0x20;
//    }
//    if(count1==duty_servo)
//      PORTB=0x00;
//  }
//  if(current_mill-previous_mill1>20){
//    previous_mill1=current_mill;
//    duty_servo++;
//    if(duty_servo==72) duty_servo=22;
//  }

  if(current_mill-previous_mill>10){
    flag=1;
    previous_mill=current_mill;
    PORTB=0x20;
    previous=current=micros();
  }
  if(flag==1){
    if(current-previous>2500){
      previous=current;
      PORTB=0x00;
      flag=0;
    }
  } 
}
