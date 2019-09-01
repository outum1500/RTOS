void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, OUTPUT); //트리거핀
  attachInterrupt(0, myISR, CHANGE);
}

unsigned long high=0;
unsigned long low=0;

void loop() {
  // put your main code here, to run repeatedly:

  
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);
  delay(1000);
}

void myISR(){
  if(digitalRead(2)==HIGH){
    high=micros();
  }
  if(digitalRead(2)==LOW){
    low=micros();
    Serial.println(low-high);
  }
}
