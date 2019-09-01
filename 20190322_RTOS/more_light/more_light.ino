void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i,j;
  
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      digitalWrite(13, HIGH);
      digitalWrite(4, HIGH);
      delayMicroseconds(i);
      digitalWrite(13, LOW);
      digitalWrite(4, LOW);
      delayMicroseconds(100-i);
    }
  }
  
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      digitalWrite(13, HIGH);
      digitalWrite(4, HIGH);
      delayMicroseconds(100-i);
      digitalWrite(13, LOW);
      digitalWrite(4, LOW);
      delayMicroseconds(i);
    }
  }

  
}
