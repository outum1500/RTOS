void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD=0x00;// 0x00 = input, 0x01 = (0번핀)output
  EICRA=0x01; //01이므로 change
  EIMSK=0x01; //1은 enable, 0은 disable
}

void loop() {
  // put your main code here, to run repeatedly:

}

unsigned long after;
unsigned long before;

SIGNAL(INT0_vect){
  char input = PIND;
  
  if(input&0x04){  //2번핀이니까 0x04     rising, pull up : 뗐을 때
    after=millis();
    Serial.println(after-before);
  }
  else{ // 눌렀을 때
    before = millis();
  }
}
