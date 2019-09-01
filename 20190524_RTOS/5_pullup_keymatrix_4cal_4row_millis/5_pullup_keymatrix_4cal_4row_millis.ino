void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT); // row 1~4번
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT); // cal 1~4번
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

int readrow[4] = {0, 0, 0, 0}; // row 상태를 읽는 배열
int flag[4][4] = {0, }; // 플래그
int i=0, j=0;
unsigned long long Cmillis=0, Pmillis=0;
// pull-up 회로이므로 row는 high일 때 0이다.

void loop() {
  // put your main code here, to run repeatedly:
  Cmillis=millis();
  if(Cmillis-Pmillis>10){
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

    if(readrow[i]==0){  // row가 HIGH이면?
      if(flag[i][j]==1){ //cal 1번은 flag[0], 2번은 flag[1] ...
        Serial.println("LOW " + String(i+1) + "  " + String(j+1));
      }
      flag[i][j]=0;
    }
    else if(readrow[i]==1){
      if(flag[i][j]==0){
        Serial.println("HIGH " + String(i+1) + "  " + String(j+1));
      }
      flag[i][j]=1;
    }
    
  }
  i++;
  if(i>=4){
    i=0;
  }
  }
}
