#include "pitches.h"

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);

  pinMode(2, INPUT); // row 1~4번
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT); // cal 1~4번
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

int readrow[4] = {0, 0, 0, 0}; // row 상태를 읽는 배열
int flag[4][4] = {0, }; // 플래그
int i=0, j=0;
int buzzerflag = 0;
unsigned long long Pmicros = 0;
unsigned long long Pmillis = 0, Cmillis = 0;
int toggle = 0;
int melody[7]={NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4};
int ch = 0;
// pull-up 회로이므로 row는 high일 때 0이다.

void loop() {
  // put your main code here, to run repeatedly:
  Cmillis = millis();
  if(Cmillis - Pmillis > 10){
    Pmillis=Cmillis;
    for(j=0; j<4; j++){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
    
      digitalWrite(6+j, LOW); //cal 하나 on

      readrow[i] = !digitalRead(2+i);  // row 읽기

      if(readrow[i]==0){  // row가 LOW이면?
        if(flag[i][j]==1){ //cal 1번은 flag[0], 2번은 flag[1] ...
          //Serial.println("LOW " + String(i+1) + "  " + String(j+1));
          flag[i][j]=0;
          buzzerflag=0;
        }
      }
      else if(readrow[i]==1){
        if(flag[i][j]==0){
          //Serial.println("HIGH " + String(i+1) + "  " + String(j+1));
          ch = i * 4 + j;
          //Serial.println("ch is " + String(ch));
          flag[i][j]=1;
          buzzerflag=1;
        }
      }
    }
    i++;
    if(i>=4){
      i=0;
    }
  }
  
  
  unsigned long long Cmicros = micros();
  if(buzzerflag){
    if(Cmicros - Pmicros > 1000000/melody[ch]/2){ // PWM은 HIGH-LOW가 1번이므로 나누기 2
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

}
