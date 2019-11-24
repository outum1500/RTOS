void setup() {
  // put your setup code here, to run once:
  DDRC = 0x30; // 4 : SDA, 5 : SCL
  PORTC |= 0x10;  // Data High
  PORTC |= 0x20; // Clock HIGH

  Serial.begin(9600);
}

int i = 0, j = 0;
int arr[3] = {0xA0, 0x00, 0x31};

void loop() {
  // put your main code here, to run repeatedly:

  start_setting();
  writedata();
  stop_setting();
  delay(5000);
}


void ack() {

}

void writedata() {
  for (j = 0; j < 3; j++) {
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

    //////////////////////////ack////////////////////////
    DDRC &= ~0x10;
    delayMicroseconds(5);

    PORTC |= 0x20; // Clock High-Low
    delayMicroseconds(5);

    Serial.println(PINC & 0x10);
    PORTC &= ~0x20;
    delayMicroseconds(5);

    DDRC |= 0x10;
    delayMicroseconds(5);
  }
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

void stop_setting() {
  PORTC &= ~0x10; // Data Low
  delayMicroseconds(5);

  PORTC |= 0x20;  // Clock High
  delayMicroseconds(5);

  PORTC |= 0x10;  // Data High
  delayMicroseconds(5);
}
