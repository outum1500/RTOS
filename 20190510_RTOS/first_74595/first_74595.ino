void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT); //data
  pinMode(11, OUTPUT); //shift clock
  pinMode(12, OUTPUT); //latch
  //reset 5v -> L이면 초기화
  //output enable gnd -> L일때 값을 output으로 보냄
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(10, LOW); //data
  digitalWrite(11, LOW); //clock
  digitalWrite(12, LOW); //latch
///////////////////////////////////

////LED ON
//data 8bit 1
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

  //data 8bit 2
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock
  
  //data 8bit 3
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

    //data 8bit 4
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

    //data 8bit 5
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

    //data 8bit 6
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

    //data 8bit 7
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

    //data 8bit 8
  digitalWrite(10, HIGH); //data
  digitalWrite(11, HIGH); //clock
  digitalWrite(11, LOW); //clock

  //latch high, low

  digitalWrite(12, HIGH);
  digitalWrite(12, LOW);

  delay(1000);
  
  

}
