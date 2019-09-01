void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD=0x00;// 0x00 = input, 0x01 = (0번핀)output
  EICRA=0x02; //02이므로 falling
  EIMSK=0x01; //1은 enable, 0은 disable
}

unsigned long remocon_start = 0;
unsigned long remocon_end = 0;
int cnt=0;

void loop() {
  // put your main code here, to run repeatedly:

}

SIGNAL(INT0_vect){
  char input=PIND;

    remocon_start=millis();
    cnt++;
    

  
  if(cnt==34){
    remocon_end=millis();
    Serial.println(remocon_end-remocon_start);
    cnt=0;
  }
}
