void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

int i=0;

void loop() {
  // put your main code here, to run repeatedly:

  for(i=0;i<50;i++){  //1초동안
  digitalWrite(9, HIGH);
  delayMicroseconds(700);  // 왼쪽으로 가있음
  digitalWrite(9, LOW);
  delay(17);                // 17000 micro
  delayMicroseconds(2300);
  }

  for(i=0;i<50;i++){
  digitalWrite(9, HIGH);
  delayMicroseconds(2300);
  digitalWrite(9, LOW);
  delay(17);
  delayMicroseconds(700);
  }

  delay(1000);
}
