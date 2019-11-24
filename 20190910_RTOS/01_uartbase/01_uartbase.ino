void setup() {
  // put your setup code here, to run once:
  ////UART0////
  //Serial.begin(9600);
  
  ////UART0////
  UCSR0A = 0x00;
  UCSR0B = 0x18;
  UCSR0C = 0x06;
  UBRR0 = 103;
}

char data;

void loop() {
  // put your main code here, to run repeatedly:
  if(!(UCSR0A & 0x20)){
    data = UDR0;
    UDR0 = data;
    //Serial.println('a');
  }
}
