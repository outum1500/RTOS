#include "pitches.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

unsigned long long Pmicros = 0;
int toggle = 0; 

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long long Cmicros = micros();
  if(Cmicros - Pmicros > 1000000/330/2){ // PWM은 HIGH-LOW가 1번이므로 나누기 2
    Pmicros = Cmicros;
    if(!toggle){ // toggle이 0이면 HIGH로
      digitalWrite(10, HIGH);
    }
    else if(toggle){ // toggle이 1이면 LOW로
      digitalWrite(10, LOW);
    }
    toggle = !toggle; // 동작한 후 다시 toggle 반전
  }
}
