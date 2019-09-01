void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
}

int count=0;
int count1=0;
int duty=0;

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  count1++;

  if(count==100){
    count=0;
    digitalWrite(13, HIGH);
  }
  else if(count==duty){
    digitalWrite(13, LOW);
  }
  
//  if(count1==100){
//    count1=0;
//    digitalWrite(4, HIGH);
//  }
//  else if(count1==90){
//    digitalWrite(4, LOW);
//  }

  if(count1==100){
    duty++;
    count1=0;
    if(duty==100){
      duty=0;
    }
  }

  delayMicroseconds(100);
  
}
