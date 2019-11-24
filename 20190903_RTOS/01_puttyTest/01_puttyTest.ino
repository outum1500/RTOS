void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delayMicroseconds(102);

  //-------- 1 0 0 0 1 1 0 0 -------- (00110001 = 0x31 넣기)
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, LOW);
  delayMicroseconds(102);
  digitalWrite(1, HIGH);
  delayMicroseconds(102);
  delay(1500);
}
