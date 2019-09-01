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
char arr[10][8]={{0x00, 0x38, 0x44, 0x4C, 0x54, 0x64, 0x44, 0x38}, //0
                 {0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c}, //1
                 {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c}, //2
                 {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38}, //3
                 {0x00, 0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08}, //4
                 {0x00, 0x7C, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38}, //5
                 {0x00, 0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38}, //6
                 {0x00, 0x7C, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20}, //7
                 {0x00, 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38}, //8
                 {0x00, 0x38, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38} //9
  };
char one=0x00;
char two=0x38;
char three=0x44;
char four=0x04;
char five=0x08;
char six=0x10;
char seven=0x20;
char eight=0x7C;
int i, j, k, cnt=0;


void loop() {
  // put your main code here, to run repeatedly:
  for(k=0;k<10;k++){
    while(cnt<500){
      for(j=0;j<8;j++){
        for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
          digitalWrite(i+2, LOW); 
        }
  
        for(i=0;i<8;i++){
          if(arr[k][j] & (0x80>>i))
            digitalWrite(10+i, LOW);
      
          else
            digitalWrite(10+i, HIGH);
        }

        digitalWrite(2+j, HIGH);  //1번째 줄 킴
        delay(2);
        cnt++;
      }
    }
    cnt=0;
  }  
}
