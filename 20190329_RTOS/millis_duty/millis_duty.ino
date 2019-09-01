int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long previousMicros = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

int count=0, i=0, duty=0;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();
  
  if(currentMicros - previousMicros >= 100){ //현재까지의 시간-마지막으로 LED상태를 바꾼 시간이 100마이크로보다 큰 경우
    previousMicros = currentMicros;

    count++;
    
    if(count==100){
      digitalWrite(13, HIGH);
      count=0;
    }
    
    if(count==duty)
      digitalWrite(13, LOW);   
  }

  if(currentMillis - previousMillis >= 10){
    previousMillis = currentMillis;

    duty++;
    if(duty==100){
      duty=0;
    }
  }
}
