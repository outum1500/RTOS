#include "pitches.h"
#define C 0
#define D 1
#define E 2
#define F 3
#define G 4
#define A 5
#define B 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

unsigned long long Pmicros = 0;
unsigned long long Pmillis = 0;
int toggle = 0; 
int melody[7]={NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4};
int school[24]={G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C};
int ch = 0;
int sch = 0;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long long Cmicros = micros();
  sch = school[ch];
  if(Cmicros - Pmicros > 1000000/melody[sch]/2){ // PWM은 HIGH-LOW가 1번이므로 나누기 2
    Pmicros = Cmicros;
    if(!toggle){ // toggle이 0이면 HIGH로
      digitalWrite(10, HIGH);
    }
    else if(toggle){ // toggle이 1이면 LOW로
      digitalWrite(10, LOW);
    }
    toggle = !toggle; // 동작한 후 다시 toggle 반전
  }
  if(ch==7){
    delay(500);
  }
  unsigned long long Cmillis = millis();
  
  if(Cmillis - Pmillis > 1000){ // 1초가 넘으면
    Pmillis = Cmillis;
    delay(75);
    ch++;
    if(ch >= 24){
      ch = 0;
    }
  }
}
