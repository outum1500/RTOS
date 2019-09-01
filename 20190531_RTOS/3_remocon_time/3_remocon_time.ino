void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0, myISR, CHANGE);
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
unsigned long remocon_time_array[34];
int cnt=0;

void loop() {
  // put your main code here, to run repeatedly:

}

void myISR()
{
  remocon_start=micros();
  remocon_time_array[cnt]=remocon_start;
  cnt++;
  
  if(cnt==34){
    for(int i=0; i<34; i++){
      Serial.println((String)i + "   " + (String)remocon_time_array[i]);
    }
    cnt=0;
  }
}
