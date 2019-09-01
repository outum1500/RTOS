int count=0;
int i=0, j=0;
int remocon_callback=0;
char space = ' ';
unsigned long remocon_micro=0;
unsigned long remocon_time_array[50];
unsigned int offset_value[50];
int zero[8]={0, };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, remocon_ISR, FALLING);
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
    for(i=0;i<8;i++){
      Serial.println(zero[i]);
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
    Serial.println("R");
  }
  
  count++;
  //callback function

  if(count>33){
    remocon_callback=1;
    
    count=0;
    
  }
  
}
