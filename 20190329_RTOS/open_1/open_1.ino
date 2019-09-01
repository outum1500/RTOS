void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

int i=0, j=0;

void loop() {
  // put your main code here, to run repeatedly:

  for(j=0;j<100;j++){
    for(i=0;i<10;i++){
      digitalWrite(13, HIGH);
      delayMicroseconds(j);
      digitalWrite(13, LOW);
      delayMicroseconds(100-j);
    }
  }
}
