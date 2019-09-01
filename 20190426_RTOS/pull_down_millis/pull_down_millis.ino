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
}

unsigned long curr_millis;
unsigned long pre_millis=0;
int i=0, j=0;
int flag[4][4]={0, };
int arr[4]={0, };

void loop() {
  // put your main code here, to run repeatedly:
  curr_millis = millis();
  if(curr_millis - pre_millis > 10){
    pre_millis=curr_millis;
  }

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
