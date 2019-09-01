void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT); // row 1번
  pinMode(6, OUTPUT); // cal 1번
}

int num = 0;
// pull-up 회로이므로 row는 high일 때 0이다.
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(6, LOW);

  num = digitalRead(2);  // row 읽기

  if(num==0){  // row가 HIGH이면?
    Serial.println("HIGH");
  }
  else if(num==1){
    Serial.println("LOW");
  }
  
  delay(10);  
}
