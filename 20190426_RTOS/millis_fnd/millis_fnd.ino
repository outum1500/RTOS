void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  /////////////////////////////////////
  pinMode(10, OUTPUT);   // 중간
  pinMode(11, OUTPUT);   // 젤 위 왼쪽
  pinMode(12, OUTPUT);   // 젤 위
  pinMode(14, OUTPUT);   // Power 5
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);   // Power 10
  
}
int number, number2;
int fnd_char[9][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1},
  {1, 1, 0, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 1, 1}
};
unsigned long curr_millis;
unsigned long pre_millis=0;
int i=0, j=0, k=0, cnt=0;
int flag[4][4]={0, };
int arr[4]={0, };
int arrcheck=0;

void loop() {
  // put your main code here, to run repeatedly:
  curr_millis = millis();
  if(curr_millis - pre_millis > 10){
    pre_millis=curr_millis;
  }
  Light(number, number2);
  for(j=0;j<4;j++){     // row
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);

      digitalWrite(6+i, HIGH);

      arr[j]=digitalRead(j+2);

      if(arr[j]==1){
        if(flag[j][i]==0){
          Serial.println("HIGH   " + String(j+1) + "  " + String(i+1)); 
          number = j;
          number2 = i;          
          //Light(j, i);
          flag[j][i]=1;
        }
      }
      else if(arr[j]==0){
        if(flag[j][i]==1){
          Serial.println("LOW   " + String(j+1) + "  " + String(i+1));
          flag[j][i]=0;
        }
      }
  }
  i++;        //cal
      
  if(i==4)
    i=0;
}

void Light(int first, int second){
  for(k=0;k<8;k++){  //첫번째칸
    digitalWrite(18, LOW);
    digitalWrite(19, HIGH);
    digitalWrite(k+10, !(fnd_char[first][k]));
  }
  delay(10);

  for(k=0;k<8;k++){  //두번째칸
    digitalWrite(18, HIGH);
    digitalWrite(19, LOW);
    digitalWrite(k+10, !(fnd_char[second][k]));
  }
  delay(10);

  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
}
