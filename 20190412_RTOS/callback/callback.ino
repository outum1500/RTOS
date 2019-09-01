int count=0;
int i=0;
int remocon_callback=0;
char space = ' ';
unsigned long remocon_micro=0;
unsigned long remocon_time_array[50];
unsigned int offset_value[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, remocon_ISR, FALLING);
}



void loop() {
  // put your main code here, to run repeatedly:
  if(remocon_callback==1){   //버튼 한번 누르는 값이 다 들어오면 callback값 1로 변함
    remocon_callback=0;    // 다시 0으로 초기화하여 다음 버튼 받을 준비
    for(int i=1; i<=33; i++){ //FALLING할때 저장한 시간과 그 전에 FALLING할때 저장한 시간 저장
      Serial.println(offset_value[i] + String(space) + String(i));
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
  if(count>0){  //FALLING할때 저장한 시간과 그 전에 FALLING할때 저장한 시간 저장
    offset_value[count]=remocon_time_array[count]-remocon_time_array[count-1];
  }

  // 리드 코드 판단
  if(offset_value[count] > 13000 && offset_value[count] < 14000){
    count=1;
  }

  // 리핏 코드 판단
  if(offset_value[count] > 11000 && offset_value[count] < 12000){
    count=-1;
    Serial.println("R");
  }
  
  count++;
  //callback function

  if(count>33){   //count가 33이상이 되면 리모컨 버튼 한번을 누르는 동안의 값이 다 들어온 것
    remocon_callback=1;  //callback 값 1로 변경하고 loop에서 작동하게 함
    
    count=0;  //count를 다시 0으로 초기화하여 다음 버튼 값 받을 준비
    
  }
  
}
