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
int a=0, b=0, c=0, d=0, i;
int flag1=1;
int flag2=0;
int flag3=0;
int flag4=0;
int flag[4][4]={0, };
void loop() {
  // put your main code here, to run repeatedly:


  for(i=0;i<4;i++){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    digitalWrite(6+i, HIGH);

//------------------------------------1번 ROW
    a=digitalRead(2);

    if(a==1){
      if(flag[0][i]==0){
        Serial.println("HIGH 1  " + String(i+1));
        flag[0][i]=1;
      }
    }
    else if(a==0){
      if(flag[0][i]==1){
        Serial.println("LOW 1  " + String(i+1));
        flag[0][i]=0;
      }
    }

  //----------------------------------------2번 ROW
    b=digitalRead(3);
    
    if(b==1){
      if(flag[1][i]==0){
        Serial.println("HIGH 2  " + String(i+1));
        flag[1][i]=1;
      }
    }
    else if(b==0){
      if(flag[1][i]==1){
        Serial.println("LOW 2  " + String(i+1));
        flag[1][i]=0;
      }
    }
    //----------------------------------------3번 ROW
    c=digitalRead(4);
    
    if(c==1){
      if(flag[2][i]==0){
        Serial.println("HIGH 3  " + String(i+1));
        flag[2][i]=1;
      }
    }
    else if(c==0){
      if(flag[2][i]==1){
        Serial.println("LOW 3  " + String(i+1));
        flag[2][i]=0;
      }
    }


    //----------------------------------------4번 ROW
    d=digitalRead(5);
    
    if(d==1){
      if(flag[3][i]==0){
        Serial.println("HIGH 4  " + String(i+1));
        flag[3][i]=1;
      }
    }
    else if(d==0){
      if(flag[3][i]==1){
        Serial.println("LOW 4  " + String(i+1));
        flag[3][i]=0;
      }
    }

    delay(10);
  }

}
