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

int i, j=0, k=2, cnt=0;
unsigned long previousMillis=0;
unsigned long currentMillis=0;
unsigned long forprevious=0;
unsigned long forcurrent=0;
unsigned long rightprevious=0;
unsigned long rightcurrent=0;

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis=millis();
  rightcurrent=millis();

  if(currentMillis-previousMillis>1000){
    previousMillis=currentMillis;

    //k++;
    //if(k==10)
    //  k=0;
  }

  if(rightcurrent-rightprevious>300){
    rightprevious=rightcurrent;

    for(i=0;i<8;i++){
      arr[2][i]=arr[2][i]>>1;
    }
  }

  forcurrent=micros();

  if(forcurrent-forprevious>2000){
    forprevious=forcurrent;
    j++;
    if(j==8){
      j=0;
    }
    for(i=0;i<8;i++){  //ROW를 모두 LOW로 바꿈
      digitalWrite(i+2, LOW); 
    }
  
    for(i=0;i<8;i++){  //한줄씩 출력
      if(arr[k][j] & (0x80>>i))
        digitalWrite(10+i, LOW);
      
      else
        digitalWrite(10+i, HIGH);
    }
    digitalWrite(2+j, HIGH);
  } 
}
