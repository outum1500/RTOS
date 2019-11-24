void setup() {
  // put your setup code here, to run once:
  DDRC = 0x30; // 4 : SDA, 5 : SCL
  PORTC |= 0x10;  // Data High
  PORTC |= 0x20; // Clock HIGH

  Serial.begin(9600);
}

int i = 0, j = 0;
int arr[3] = {0xA0, 0x00, 0x30};

void loop() {
  // put your main code here, to run repeatedly:

  // start
  PORTC &= ~0x10; // Data Low

  // stand by
  PORTC &= ~0x20; // Clock Low

  
  // device address (1010000 + 0(write))
  for (i = 0; i < 8; i++) {
    if (0xA0 & 0x80 >> i) { // 1이면 데이터를 High로 올려줘야 하므로 검사
      PORTC |= 0x10; // Data High
    }
    else // 0일 때
      PORTC &= ~0x10; // Data Low

    PORTC |= 0x20;  // Clock High-Low
    PORTC &= ~0x20;
  }

  // ack clock
  PORTC |= 0x20; // Clock High-Low
  Serial.println(PINC & 0x10);
  PORTC &= ~0x20;

  // while(1)
  
  // memory address
  for (i = 0; i < 8; i++) {
    if (0x00 & 0x80 >> i) { // 1이면 데이터를 High로 올려줘야 하므로 검사
      PORTC |= 0x10; // Data High
    }
    else // 0일 때
      PORTC &= ~0x10; // Data Low

    PORTC |= 0x20;  // Clock High-Low
    PORTC &= ~0x20;
  }

  // ack clock
  PORTC |= 0x20; // Clock High-Low
  Serial.println(PINC & 0x10);
  PORTC &= ~0x20;


  // data
  for (i = 0; i < 8; i++) {
    if (0x30 & 0x80 >> i) { // 1이면 데이터를 High로 올려줘야 하므로 검사
      PORTC |= 0x10; // Data High
    }
    else // 0일 때
      PORTC &= ~0x10; // Data Low

    PORTC |= 0x20;  // Clock High-Low
    PORTC &= ~0x20;
  }

  // ack clock
  PORTC |= 0x20; // Clock High-Low
  Serial.println(PINC & 0x10);
  PORTC &= ~0x20;
  

  // stop
  PORTC &= ~0x10; // Data Low
  PORTC |= 0x20;  // Clock High
  PORTC |= 0x10;  // Data High

  delay(5000);
}
