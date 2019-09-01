void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT); // row 1번
  pinMode(6, OUTPUT); // cal 1~4번
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

int num = 0; // row 상태를 읽는 배열
int flag[4] = {0, 0, 0, 0}; // 플래그
int i=0, j=0;
// pull-up 회로이므로 row는 high일 때 0이다.

void loop() {
  // put your main code here, to run repeatedly:
  for(j=0; j<4; j++){
    digitalWrite(2, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    
    digitalWrite(6+j, LOW);

    num = digitalRead(2);  // row 읽기

    if(num==0){  // row가 HIGH이면?
      if(flag[j]==1){ //cal 1번은 flag[0], 2번은 flag[1] ...
        Serial.println("HIGH " + String(j));
      }
      flag[j]=0;
    }
    else if(num==1){
      if(flag[j]==0){
        Serial.println("LOW " + String(j));
      }
      flag[j]=1;
    }
    
  }
  delay(10);
}
