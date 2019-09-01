unsigned long in, out;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0, myISR, CHANGE);
}

unsigned long button_start = 0;
unsigned long button_end = 0;

void loop() {
  // put your main code here, to run repeatedly:

}

void myISR()
{
  if(digitalRead(2)==LOW){
    button_start = millis();
  }
  else if(digitalRead(2)==HIGH){
    button_end=millis();
    Serial.println(button_end-button_start);
  }
}
