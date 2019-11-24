void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int leftflag = 0;
int rightflag = 0;
int upflag = 0;
int downflag = 0;

void loop() {
  // put your main code here, to run repeatedly:

  int analog_x = 0, analog_y = 0;

  ADMUX = 0x40;
  ADCSRA = 0x87;
  ADCSRA |= 0x40; // start
  analog_x = ADC;

  while(ADCSRA & 0x40);
  ADMUX = 0x41;
  ADCSRA = 0x87;
  ADCSRA |= 0x40; // start
  analog_y = ADC;
  
  Serial.println(analog_x);
  Serial.println(analog_y);
  Serial.println();
  

  delay(100);
}

analog_R(int pin){
  
}
