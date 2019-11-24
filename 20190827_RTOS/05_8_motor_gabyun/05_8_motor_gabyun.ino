// ---- 64분주 ----
void setup() {
  // put your setup code here, to run once:
  DDRC = 0x3F; //13번 포트
  PORTC  = 0x00;
  TCCR1A = 0x03; 
  TCCR1B = 0x0B; // 64분주, fast-PWM모드
  TCNT1 = 399; 
  OCR1A = 574;
  TIMSK1 = 0x03;
}

int ovf_count = 0;
int i = 0;
int var = 0;
int var2 = 0;
unsigned long current_millis = 0;
unsigned long previous_millis = 0;
unsigned long previous_millis_two = 0;

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();
  if(current_millis - previous_millis > 20){
    previous_millis = current_millis;
    var += 4;
    if(var > 974){
      var = 574;
    }
//    OCR1A += 4;
//    if(var > 974){
//      var = 574;
//    }
  }

  if(current_millis - previous_millis_two > 40){
    previous_millis_two = current_millis;
    var2 += 4;
    if(var2 > 974){
      var2 = 574;
    }
  }
}

SIGNAL(TIMER1_OVF_vect){ // TCNT가 MAX가 되면 들어옴
  TCNT1 = 399;

  ovf_count++; // 오버플로우 번호
  if(ovf_count == 8){
    ovf_count = 0;
  }
  if(ovf_count == 0){ //574
    OCR1A = var2; // 1번에 적용
    PORTC |= 0x01; // 아날로그 0번 포트만 올리기
  }
  else if(ovf_count == 1){ //974
    PORTC |= 0x02;
  }
  else if(ovf_count == 7){
    OCR1A = var; // 0번에 적용
  }
}

SIGNAL(TIMER1_COMPA_vect){ // TCNT가 OCR이랑 값이 같아지면 들어옴
  if(ovf_count == 0)
    PORTC &= ~0x01; // 아날로그 0번 포트만 내리기
  else if(ovf_count == 1)
    PORTC &= ~0x02;
}
