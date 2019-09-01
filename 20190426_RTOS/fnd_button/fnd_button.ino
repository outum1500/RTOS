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

void loop() {
  // put your main code here, to run repeatedly:
  one();
  delay(1000);
  two();
  delay(1000);
  three();
  delay(1000);
  four();
  delay(1000);
  five();
  delay(1000);
  six();
  delay(1000);
  seven();
  delay(1000);
  eight();
  delay(1000);
  nine();
  delay(1000);
}

void one(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, HIGH);
  
  digitalWrite(11, HIGH); 
  digitalWrite(12, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
}

void two(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);

  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(18, LOW);
}

void three(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
  
  digitalWrite(11, HIGH);  //젤 위 왼쪽
  digitalWrite(12, LOW);
  digitalWrite(15, LOW);   //젤 아래
  digitalWrite(16, HIGH);  //젤 아래 왼쪽
  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
}

void four(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
  
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, HIGH);  //젤 위
  digitalWrite(15, HIGH);  //젤 아래
  digitalWrite(16, HIGH);  //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, LOW);   //젤 위 오른쪽
}

void five(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
  
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, LOW);   //젤 위
  digitalWrite(15, LOW);   //젤 아래
  digitalWrite(16, HIGH);  //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, HIGH);  //젤 위 오른쪽
}

void six(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
   
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, LOW);   //젤 위
  digitalWrite(15, LOW);   //젤 아래
  digitalWrite(16, LOW);   //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, HIGH);  //젤 위 오른쪽
}

void seven(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, HIGH);  //중간
   
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, LOW);   //젤 위
  digitalWrite(15, HIGH);  //젤 아래
  digitalWrite(16, HIGH);  //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, LOW);   //젤 위 오른쪽
}

void eight(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
   
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, LOW);   //젤 위
  digitalWrite(15, LOW);   //젤 아래
  digitalWrite(16, LOW);   //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, LOW);   //젤 위 오른쪽
}

void nine(){
  digitalWrite(14, HIGH);
  digitalWrite(19, LOW);
  
  digitalWrite(10, LOW);   //중간
   
  digitalWrite(11, LOW);  //젤 위 왼쪽
  digitalWrite(12, LOW);   //젤 위
  digitalWrite(15, LOW);   //젤 아래
  digitalWrite(16, HIGH);  //젤 아래 왼쪽
  digitalWrite(17, LOW);   //젤 아래 오른쪽
  digitalWrite(18, LOW);   //젤 위 오른쪽
}
