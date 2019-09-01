void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
int a;
int flag1=1;
int flag2=0;
int flag3=0;
int flag4=0;
void loop() {
  // put your main code here, to run repeatedly:

    /////////////KEY 1번///////////////
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  a=digitalRead(2);
  if(a==1)
  {
    if(flag1==0){
      Serial.println("HIGH 1");
      flag1=1; 
    }
  }
  else{
    if(flag1==1){
      Serial.println("LOW 1");
      flag1=0;
    }
  }
  delay(10);

//////////////KEY 2번/////////////////
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  a=digitalRead(2);
  if(a==1)
  {
    if(flag2==0){
      Serial.println("HIGH 2");
      flag2=1; 
    }
  }
  else{
    if(flag2==1){
      Serial.println("LOW 2");
      flag2=0;
    }
  }

  //////////////KEY 3번/////////////////
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  a=digitalRead(2);
  if(a==1)
  {
    if(flag3==0){
      Serial.println("HIGH 3");
      flag3=1; 
    }
  }
  else{
    if(flag3==1){
      Serial.println("LOW 3");
      flag3=0;
    }
  }


  //////////////KEY 4번/////////////////
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  a=digitalRead(2);
  if(a==1)
  {
    if(flag4==0){
      Serial.println("HIGH 4");
      flag4=1; 
    }
  }
  else{
    if(flag4==1){
      Serial.println("LOW 4");
      flag4=0;
    }
  }
}
