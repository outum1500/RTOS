unsigned long in, out;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(1, myISR, CHANGE);
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
int cnt=0;

void loop() {
  // put your main code here, to run repeatedly:

}

void myISR()
{
  remocon_start=micros();

  cnt++;
  if(cnt==34){
    Serial.println(cnt);
    cnt=0;
  }
}
