void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

int count=0, duty=0, count1=0;

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

 
   
  if(count1==10000){
    duty++;
    if(duty==100)
      duty=0;
  }

   delayMicroseconds(100);
}
