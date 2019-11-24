void setup() {
  // put your setup code here, to run once:
  delay(1000);

  DDRD &= ~0x01; // uart RX
  DDRD |= 0x02;  // uart TXd

  UBRR0 = 103; // 9600 baudrate
  //UBRR0 = 8;
  UCSR0A = 0x00; // U2X = 0
  UCSR0B = 0x18; // TX/RX enabble
  UCSR0C = 0x06; // Async, no Parity, 1 stop, 8 bit
}

int i = 0;
unsigned char data[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

void loop() {
  for(i=0; i<10; i++){
    while(!(UCSR0A & 0x20));
    UDR0 = data[i];
  }

  delay(1000);
}
