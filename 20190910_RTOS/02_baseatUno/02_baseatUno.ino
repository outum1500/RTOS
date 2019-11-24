void setup() {
  // put your setup code here, to run once:
  ////UART0////
  Serial.begin(9600);
  
  ////UART1////
  pinMode(19, INPUT);
  pinMode(18, OUTPUT);
  UCSR1A = 0x00;
  UCSR1B = 0x98;
  UCSR1C = 0x06;
  UBRR1L = 103;
  UBRR1H = 0;
}

char data;

void loop() {
  // put your main code here, to run repeatedly:
//  if(!(UCSR0A & 0x20)){
//    data = UDR1;
//    UDR1 = data;
//    //Serial.println('a');
//  }
}

ISR(USART1_RX_vect){
  data = UDR1;
  Serial.println(data);
}
