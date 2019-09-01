void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, remocon_ISR, FALLING);
}

int count=0;
int i=0;
char space = ' ';
unsigned long remocon_micro=0;
unsigned long remocon_time_array[50];
unsigned int offset_value[50];

void loop() {
  // put your main code here, to run repeatedly:
  

//  if(count>=34){
//    printf("34 이상의 인터럽트\n");
//  }
}

void remocon_ISR(){
  remocon_micro=micros();
  remocon_time_array[count]=remocon_micro;

  if(count>0){
    offset_value[count]=remocon_time_array[count]-remocon_time_array[count-1];
  }
  
  count++;
  
  if(count>33){
    
    for(int i=0; i<50; i++){
      Serial.println(offset_value[i] + String(space) + String(i));
    }
    count=0;
    
  }
  
}
