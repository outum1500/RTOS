#define DATA 10
#define CLOCK 11
#define LATCH 12

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, OUTPUT); //Data 핀
  pinMode(CLOCK, OUTPUT); //Shift Clock 핀
  pinMode(LATCH, OUTPUT); //Latch 핀
  // Reset 핀은 5V에 꽂아놓고 항상 HIGH로 유지
  // Output Enable 핀은 GND에 꽂아놓고 항상 LOW로 유지하여 값 자동 전송
}

int data=0x40;
int data1=0x20;
int i=0;

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<8;i++){
    if(data&(0x01<<i))
      digitalWrite(DATA, HIGH);
    else
      digitalWrite(DATA, LOW);

    digitalWrite(CLOCK, HIGH); //Shift Register에 한비트 전달
    digitalWrite(CLOCK, LOW);
  }

  digitalWrite(LATCH, HIGH);  //Storage Register에 8비트 한꺼번에 전달
  digitalWrite(LATCH, LOW);

  delay(1000);


  //----------------------------------------------------------

  for(i=0;i<8;i++){
    if(data1&(0x01<<i))
      digitalWrite(DATA, HIGH);
    else
      digitalWrite(DATA, LOW);

    digitalWrite(CLOCK, HIGH); //Shift Register에 한비트 전달
    digitalWrite(CLOCK, LOW);
  }

  digitalWrite(LATCH, HIGH);  //Storage Register에 8비트 한꺼번에 전달
  digitalWrite(LATCH, LOW);

  delay(1000);
}
