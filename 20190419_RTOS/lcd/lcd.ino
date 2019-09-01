#define RS 3
#define RW 4
#define EN 5
#define DB0 6
#define DB1 7
#define DB2 8
#define DB3 9
#define DB4 10
#define DB5 11
#define DB6 12
#define DB7 13

void setup() {
  // put your setup code here, to run once:
  //RS, RW는 HIGH로 시작
  //E, DB는 LOW로 시작
  
  int i;
  for(i=3; i<14; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);









  //RS, RW LOW로 바꿈
  //0x30을 DB0~DB7까지 넣기
  //E HIGH하고 다시 LOW로 바꿈
  //RS, RW HIGH로 바꿈
   //이거 3번 반복
   ////////////////////////////// 0x30
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x30 (0 0 1 1 0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x30
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x30 (0 0 1 1 0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x30
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x30 (0 0 1 1 0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x38
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x38 (0 0 1 1 1 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);
   digitalWrite(DB3, HIGH);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x06
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x06 (0 0 0 0 0 1 1 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, HIGH);
   digitalWrite(DB1, HIGH);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x0C / 12
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x0C (0 0 0 0 1 1 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);
   digitalWrite(DB3, HIGH);
   digitalWrite(DB2, HIGH);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x80
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x80 (1 0 0 0 0 0 0 0)
   digitalWrite(DB7, HIGH);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x01
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x01 (0 0 0 0 0 0 0 1)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, HIGH);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   delay(3);
   ////////////////////////////////////
    



   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ////////////////////////////// 0x31
   digitalWrite(RS, HIGH);
   digitalWrite(RW, LOW);
  //data : 0x31 (0 0 1 1 0 0 0 1)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);
   digitalWrite(DB3, LOW);
   digitalWrite(DB2, LOW);
   digitalWrite(DB1, LOW);
   digitalWrite(DB0, HIGH);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, LOW);
   digitalWrite(RW, HIGH);

   //delay 100micro
   ////////////////////////////////////

   delay(1000);



   
   
}
