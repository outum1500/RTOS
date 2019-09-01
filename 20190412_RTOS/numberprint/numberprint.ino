int count=0, number=0;
int i=0, j=0;
int remocon_callback=0;
char space = ' ';
unsigned long remocon_micro=0;
unsigned long remocon_time_array[50];
unsigned int offset_value[50];
int zero[8]={0, };
int num[10][8]={{0, 1, 1, 0, 1, 0, 0, 0}, //0
               {0, 0, 1, 1, 0, 0, 0, 0},  //1
               {0, 0, 0, 1, 1, 0, 0, 0},  //2
               {0, 1, 1, 1, 1, 0, 1, 0},  //3
               {0, 0, 0, 1, 0, 0, 0, 0},  //4
               {0, 0, 1, 1, 1, 0, 0, 0},  //5
               {0, 1, 0, 1, 1, 0, 1, 0},  //6
               {0, 1, 0, 0, 0, 0, 1, 0},  //7
               {0, 1, 0, 0, 1, 0, 1, 0},  //8
               {0, 1, 0, 1, 0, 0, 1, 0},  //9
               };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, remocon_ISR, FALLING);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  if(remocon_callback==1){
    remocon_callback=0;
    for(int i=1; i<=33; i++){
      //Serial.println(offset_value[i] + String(space) + String(i));

      if(i>=18 && i<=25){
          if(offset_value[i] >1000 && offset_value[i] < 1500){
            zero[i-18]=0;
          }
          else if(offset_value[i] > 2000 && offset_value[i] < 2500){
            zero[i-18]=1;
          }
      }
    }
    for(i=0;i<10;i++){
      for(j=0;j<8;j++){
        if(zero[j]!=num[i][j]){
          break;
        }
      }
      if(j==8){
        number=i;
        Serial.println(number);
        all(number);
        delay(1000);
      }
    }
  }
  

//  if(count>=34){
//    printf("34 이상의 인터럽트\n");
//  }
}

void remocon_ISR(){
  remocon_micro=micros();
  remocon_time_array[count]=remocon_micro;

  // 차이값 저장
  if(count>0){
    offset_value[count]=remocon_time_array[count]-remocon_time_array[count-1];
  }

  // 리드 코드 판단
  if(offset_value[count] > 13000 && offset_value[count] < 14000){
    count=1;
  }

  // 리핏 코드 판단
  if(offset_value[count] > 11000 && offset_value[count] < 12000){
    count=-1;
    Serial.println(number);
  }
  
  count++;
  //callback function

  if(count>33){
    remocon_callback=1;
    
    count=0;
    
  }
  
}



void all(int a){
  switch(a)
  {
    case 0:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;

    case 1:
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;

    case 2:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;

    case 3:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);   
      break;   

    case 4:
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;

    case 5:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;

    case 6:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;

    case 7:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;

    case 8:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;

    case 9:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;
  }
}
