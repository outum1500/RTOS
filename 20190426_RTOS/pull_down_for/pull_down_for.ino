void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
int a, i;
int flag1=1;
int flag2=0;
int flag3=0;
int flag4=0;
int flag[4]={0, 0, 0, 0};
void loop() {
  // put your main code here, to run repeatedly:


  for(i=0;i<4;i++){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    digitalWrite(6+i, HIGH);

    a=digitalRead(2);

    if(a==1){
      if(flag[i]==0){
        Serial.println("HIGH " + String(i+1));
        flag[i]=1;
      }
    }
    else{
      if(flag[i]==1){
        Serial.println("LOW " + String(i+1));
        flag[i]=0;
      }
    }

    delay(10);
  }


 
}
