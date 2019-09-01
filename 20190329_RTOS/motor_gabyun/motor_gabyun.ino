void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}
int count=0;
int i=0, a=0;

void loop() {
  // put your main code here, to run repeatedly:
  count++;

  if(count==625){
    count=0;
    digitalWrite(9, HIGH);
  }
  else if(count==22){
    digitalWrite(9, LOW);
  }
  delayMicroseconds(32);

}


  
//  for(i=0;i<50;i++){
//  
//  delayMicroseconds(2300-a);
//  
//  delay(17);                // 17000 micro
//  delayMicroseconds(700+a);
//  }
//
//  a+=32;
//  if(a>1600) //2300-700이 1600이므로.
//    a=0;
//}
