//과제 : 2개의 LED를 millis 구조로(delay 다 빼고)

int ledPin = 13; //LED 연결 핀
int ledState = LOW; //LED는 끈 상태로 시작
unsigned long previousMillis = 0; //마지막으로 LED 상태를 바꾼 시간

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();   //현재까지의 시간
  //unsigned long currentMicros = micros(); //현재까지의 시간

  if(currentMillis - previousMillis > 1000) {  //지정한 시간을 초과한 경우
     previousMillis = currentMillis;    //마지막 상태 변화 시간 저장

     if(ledState==LOW) //상태 반전
       ledState = HIGH;
     else
       ledState = LOW;

      //상태가 바뀐 경우에만 디지털 핀으로 출력
     digitalWrite(ledPin, ledState);
  }
}
