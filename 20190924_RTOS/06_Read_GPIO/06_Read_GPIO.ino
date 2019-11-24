void setup() {
  // put your setup code here, to run once:
  DDRC = 0x30; // 4 : SDA, 5 : SCL
  PORTC |= 0x10; // Data High
  PORTC |= 0x20; // Clock High

  Serial.begin(9600);
}

int i = 0, j = 0;
int arr[3] = {0xA0, 0x00, 0xA1};
int data[8] = {0, };

void loop() {
  // put your main code here, to run repeatedly:

  start_setting();

  writedata();

  dataread();

  stop_setting();

  delay(2000);
}

void dataread() {
  DDRC &= ~0x10; // SDA input Mode

  for (int k = 0; k < 8; k++) {
    PORTC |= 0x20;
    PORTC &= ~(0x20);
    data[k] = (0x10 & PINC);
    Serial.print(data[k]);
    Serial.print(' ');
    delayMicroseconds(5);
  }

  Serial.println();
  DDRC |= 0x10; // SDA output Mode
  PORTC |= 0x10; // SDA High

  //convert(data);
}

void ack() {
  //////////////////////////ack////////////////////////
  DDRC &= ~0x10;
  delayMicroseconds(5);

  PORTC |= 0x20; // Clock High-Low
  delayMicroseconds(5);

  PORTC &= ~0x20;
  delayMicroseconds(5);

  DDRC |= 0x10;
  delayMicroseconds(5);
}

void start_setting() {
  PORTC |= 0x10; // Data High
  delayMicroseconds(5);
  PORTC |= 0x20; // Clock High
  delayMicroseconds(5);

  // start
  PORTC &= ~0x10; // Data Low
  delayMicroseconds(5);

  // stand by
  PORTC &= ~0x20; // Clock Low
  delayMicroseconds(5);
}

void writedata() {
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 8; i++) {
      if (arr[j] & 0x80 >> i) { // 1이면 데이터를 High로 올려줘야 하므로 검사
        PORTC |= 0x10; // Data High
      }
      else // 0일 때
        PORTC &= ~0x10; // Data Low

      delayMicroseconds(5);
      PORTC |= 0x20;  // Clock High-Low

      delayMicroseconds(5);
      PORTC &= ~0x20;

      delayMicroseconds(5);
    }

    ack();
  }

  start_setting();

  for (i = 0; i < 8; i++) {
    if (arr[2] & 0x80 >> i) { // 1이면 데이터를 High로 올려줘야 하므로 검사
      PORTC |= 0x10; // Data High
    }
    else // 0일 때
      PORTC &= ~0x10; // Data Low

    delayMicroseconds(5);
    PORTC |= 0x20;  // Clock High-Low

    delayMicroseconds(5);
    PORTC &= ~0x20;

    delayMicroseconds(5);
  }

  ack();
}


void stop_setting() {
  PORTC &= ~0x10; // Data Low
  delayMicroseconds(5);

  PORTC |= 0x20;  // Clock High
  delayMicroseconds(5);

  PORTC |= 0x10;  // Data High
  delayMicroseconds(5);
}

//void convert(int * data) {
//  int arr[8] = {0, };
//
//  for (int i = 0; i < 8; i++) {
//    if (data[i] == 16) {
//      arr[i] = 1;
//    }
//    else if (data[i] == 0) {
//      arr[i] = 0;
//    }
//
//    Serial.print(arr[i]);
//  }
//  Serial.println();
//
//  //convertint(arr);
//}

//void convertint(int * arr){
//  String myString;
//  char s[8];
//  int value = 0;
//  int result = 0;
//  for(int i = 0; i < 8; i++){
//    myString += ((String)arr[i]);
//  }
//
//  myString.toCharArray(s, 8);
//  
//  for(int i = 0; i < strlen(s); i++){
//    value *= 2;
//    if(s[i] == '1')
//      result += value;
//  }
//
//  Serial.println(result);
//}
