void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

int i=0;

void loop() {
  // put your main code here, to run repeatedly:

  for(i=0;i<100;i++){
    digitalWrite(13, HIGH);     //25%
    delayMicroseconds(2500);
    digitalWrite(13, LOW);
    delayMicroseconds(7500);
  }

  for(i=0;i<100;i++){
    digitalWrite(13, HIGH);     //50%
    delayMicroseconds(5000);
    digitalWrite(13, LOW);
    delayMicroseconds(5000);
  }

  for(i=0;i<100;i++){
    digitalWrite(13, HIGH);     //75%
    delayMicroseconds(7500);
    digitalWrite(13, LOW);
    delayMicroseconds(2500);
  }

}
