void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);  //ROW
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); //cal
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  
}
char one=0x00;
char two=0x38;
char three=0x44;
char four=0x04;
char five=0x08;
char six=0x10;
char seven=0x20;
char eight=0x7C;
int i;

void loop() {
  // put your main code here, to run repeatedly:
  //------------------------1번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(one & (0x80>>i))
      digitalWrite(10+i, LOW);
      
    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(2, HIGH);  //1번째 줄 킴
  delay(2);

  //------------------------2번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(two & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(3, HIGH);  //2번째 줄 킴
  delay(2);

  //------------------------3번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(three & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(4, HIGH);  //3번째 줄 킴
  delay(2);

  //------------------------4번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(four & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(5, HIGH);  //4번째 줄 킴
  delay(2);

  //------------------------5번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(five & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(6, HIGH);  //5번째 줄 킴
  delay(2);

  //------------------------6번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(six & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(7, HIGH);  //6번째 줄 킴
  delay(2);

  //------------------------7번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(seven & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(8, HIGH);  //7번째 줄 킴
  delay(2);

  //------------------------8번째 줄-------------------------
  for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
    digitalWrite(i+2, LOW); 
  }
  
  for(i=0;i<8;i++){
    if(eight & (0x80>>i))
      digitalWrite(10+i, LOW);

    else
      digitalWrite(10+i, HIGH);
  }
  digitalWrite(9, HIGH);  //8번째 줄 킴
  delay(2);
}
