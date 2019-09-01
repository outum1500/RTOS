void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, remocon_ISR, FALLING);
}

int count=0;
int i=0;
unsigned long remocon_micro=0;
unsigned long remocon_time_array[50];
//unsigned int offset_value[50];

void loop() {
  // put your main code here, to run repeatedly:
  

//  if(count>=34){
//    printf("34 이상의 인터럽트\n");
//  }
}

void remocon_ISR(){
  remocon_micro=micros();  //HIGH인 신호가 LOW로 FALLING 할 때의 시간 저장
  remocon_time_array[count]=remocon_micro; //0부터 count를 늘리며 시간을 배열에 저장
  //remocon[count+1]=remocon_micro[count]-
  count++;
  
  if(count>33){   // FALLING을 33번 이상 한다면 리모컨 버튼 한번을 누른것
    count=0;
    for(int i=0; remocon_time_array[i]!=0; i++){
      Serial.println(remocon_time_array[i]);  //시간 출력
    }
    
  }
  
}
