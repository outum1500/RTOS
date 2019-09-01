void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, myISR, FALLING);
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
unsigned long remocon_time_array[34];
unsigned long timecal[33];
int zero[8]={0, };
char space = ' ';
int cnt=0, flag=0, number=0, j=0, i=0;
int num[10][8]={{1, 0, 1, 0, 0, 0, 1, 0}, //0
               {1, 1, 0, 0, 0, 0, 1, 1},  //1
               {0, 1, 1, 0, 0, 0, 1, 1},  //2
               {1, 1, 1, 0, 1, 0, 1, 0},  //3
               {0, 1, 0, 0, 0, 0, 1, 1},  //4
               {1, 1, 1, 0, 0, 0, 1, 1},  //5
               {0, 1, 1, 0, 1, 0, 1, 0},  //6
               {0, 0, 0, 0, 1, 0, 1, 0},  //7
               {0, 0, 1, 0, 1, 0, 1, 0},  //8
               {0, 1, 0, 0, 1, 0, 1, 0},  //9
               };

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==1){   //버튼 한번 누르는 값이 다 들어오면 callback값 1로 변함
    flag=0;    // 다시 0으로 초기화하여 다음 버튼 받을 준비
    for(i=0; i<33; i++){ //FALLING할때 저장한 시간과 그 전에 FALLING할때 저장한 시간 저장
      if(i>=18 && i<=25){
        if(timecal[i] >1000 && timecal[i] < 1500){
          zero[i-18]=0;
        }
        else if(timecal[i] > 2000 && timecal[i] < 2500){
          zero[i-18]=1;
        }
      }
    }
    for(j=0; j<8; j++){
        //Serial.println(String(j) + (String)space + (String)zero[j]);
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
      }
    }
  }
}

void myISR()
{
  remocon_start=micros();
  remocon_time_array[cnt]=remocon_start;

  //-------------------------------------------
  if(cnt>0){
    timecal[cnt-1]=remocon_time_array[cnt]-remocon_time_array[cnt-1];  
  }
  //-------------------------------------------

  // 리드 코드 판단
  if(timecal[cnt-1] > 13000 && timecal[cnt-1] < 14000){
    cnt=0;
  }

  // 리핏 코드 판단
  if(timecal[cnt-1] > 11000 && timecal[cnt-1] < 12000){
    cnt=-1;
    Serial.println("R");
  }
  
  cnt++;
  if(cnt==34){
    flag=1;
    cnt=0;
  }
}
