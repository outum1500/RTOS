void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, myISR, FALLING);
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
unsigned long remocon_time_array[34];
unsigned long timecal[33];
int cnt=0, timecnt=0;

void loop() {
  // put your main code here, to run repeatedly:

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
  cnt++;
  if(cnt==34){
    for(int i=0; i<33; i++){
      Serial.println((String)i + "   " + (String)timecal[i]);
    }
    cnt=0;
  }
}
