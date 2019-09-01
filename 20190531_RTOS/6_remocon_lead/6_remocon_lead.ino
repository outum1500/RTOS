void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, myISR, FALLING);
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
unsigned long remocon_time_array[34];
unsigned long timecal[33];
char space = ' ';
int cnt=0, timecnt=0, flag=0;

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==1){   //버튼 한번 누르는 값이 다 들어오면 callback값 1로 변함
    flag=0;    // 다시 0으로 초기화하여 다음 버튼 받을 준비
    for(int i=0; i<33; i++){ //FALLING할때 저장한 시간과 그 전에 FALLING할때 저장한 시간 저장
      Serial.println(String(i) + (String)space + (String)timecal[i]);
    }
  }
}

void myISR()
{
  remocon_start=micros();
  remocon_time_array[cnt]=remocon_start;

  //-------------------------------------------
  if(cnt>=1){
    timecal[cnt-1]=remocon_time_array[cnt]-remocon_time_array[cnt-1];  
  }
  //-------------------------------------------

  // 리드 코드 판단
  if(timecal[cnt] > 13000 && timecal[cnt] < 14000){
    cnt=0;
  }
  
  cnt++;
  if(cnt==34){
    flag=1;
    cnt=0;
  }
}
