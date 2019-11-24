int i = 0, j = 0, k = 0;
int line_index;
int count_timer2 = 0;
int number = 0;
int duty[8] = {0, };
int column_value = 0;
unsigned long current_millis = 0;
unsigned long previous_millis = 0;
unsigned long previous_millis2 = 0;
unsigned long previous_millis3 = 0;
int num[10][8] = {
  {0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7C},
  {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7C},
  {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38},
  {0x00, 0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08},
  {0x00, 0x7C, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38},
  {0x00, 0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38},
  {0x00, 0x7C, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20},
  {0x00, 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38},
  {0x00, 0x38, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38},
  {0x00, 0x38, 0x44, 0x4C, 0x54, 0x64, 0x44, 0x38}
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // output mode setting
  for (int i = 2; i < 18; i++) {
    pinMode(i, OUTPUT);
  }

  // col pin LOW(00000000)
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
  }

  // row pin LOW(off)
  for (int i = 10; i < 18; i++) {
    digitalWrite(i, LOW);
  }



  //  //----------------------------------------------------------------
  //  // Timer1
  //  TCCR1A = 0x03;
  //  TCCR1B = 0x0B;
  //  TCCR1C = 0x00;
  //  TCNT1 = 399;
  //  OCR1A = 399;
  //  TIMSK1 = 0x03;
  //  OCR1A = 459;
  //  //----------------------------------------------------------------



  //----------------------------------------------------------------
  // Timer2
  TCCR2A = 0x03;
  TCCR2B = 0x02;
  TCNT2 = 156;
  OCR2A = 206;
  TIMSK2 = 0x01;


  digitalWrite(10, HIGH);
  //----------------------------------------------------------------
}

void loop() {
  // put your main code here, to run repeatedly:

  current_millis = millis();

  if (current_millis - previous_millis > 1000) {
    previous_millis = current_millis;
    number++;
    if (number == 10) {
      number = 0;
    }
  }

  if (current_millis - previous_millis2 > 10) {
    previous_millis2 = current_millis;
    duty[0]++;

    if (duty[0] >= 100) {
      duty[0] = 0;
    }
  }

  if (current_millis - previous_millis3 > 15) {
    previous_millis3 = current_millis;
    duty[1]++;

    if (duty[1] >= 100) {
      duty[1] = 0;
    }
  }
}

ISR(TIMER1_OVF_vect) { // 2.5ms마다 진입
  TCNT1 = 399;

  line_index++;
  if (line_index == 8) line_index = 0;

  //================================================================
  // 1. 8개 row pin off
  // row pin LOW(off)
  for (int i = 10; i < 18; i++) {
    digitalWrite(i, LOW);
  }
  //----------------------------------------------------------------
  // 2. col value
  for (int i = 0; i < 8; i++) {
    if (num[number][line_index] & (0x80 >> i)) {
      digitalWrite(2 + i, LOW);
    }
    else
      digitalWrite(2 + i, HIGH);
  }
  //----------------------------------------------------------------
  // 3. row pin on
  digitalWrite(10 + line_index, HIGH);
  //================================================================



  //================================================================
  OCR1A = 399 + (line_index + 1) * 50;
  //================================================================

}

ISR(TIMER1_COMPA_vect) {

  //row pin off
  digitalWrite(10 + line_index, LOW);
}




ISR(TIMER2_OVF_vect) { // 25us마다 진입

  TCNT2 = 156;
  count_timer2++;

  //----------------------------------------------------------------
  // led0
  if (count_timer2 == 50) {
    count_timer2 = 0;

    line_index++;
    if (line_index == 8) line_index = 0;


    //----------------------------------------------------------------
    // 1. row pin off
    for (int i = 10; i < 18; i++) {
      digitalWrite(i, LOW);
    }
    //----------------------------------------------------------------



    //----------------------------------------------------------------
    // 2. col value
    column_value = 0xff;
    num[3][0] = column_value;

    for (int i = 0; i < 8; i++) {
      if (num[3][line_index] & (0x80 >> i)) {
        digitalWrite(2 + i, LOW);
      }
      else {
        digitalWrite(2 + i, HIGH);
      }
    }
    //----------------------------------------------------------------



    //----------------------------------------------------------------
    // 3. row pin on
    digitalWrite(10 + line_index, HIGH);
    //----------------------------------------------------------------
  }


  if (count_timer2 == duty[0]) {
    column_value &= ~0x80;
    num[3][0] = column_value;

    for (i = 0; i < 8; i++) {
      if (num[3][line_index] & (0x80 >> i)) {
        digitalWrite(2 + i, LOW);
      }
      else {
        digitalWrite(2 + i, HIGH);
      }
    }
  }

  if (count_timer2 == duty[1]) {
    column_value &= ~0x40;
    num[3][0] = column_value;

    for (i = 0; i < 8; i++) {
      if (num[3][line_index] & (0x80 >> i)) {
        digitalWrite(2 + i, LOW);
      }
      else {
        digitalWrite(2 + i, HIGH);
      }
    }
  }
}
