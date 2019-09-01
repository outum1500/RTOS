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
   

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x28
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x28 (0 0 1 0 1 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, LOW);


   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////


   ////////////////////////////////4비트/////////////////////////////////

   ////////////////////////////// 0x28에 2
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x28에 2 (0 0 1 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro

   ////////////////////////////////////




   ////////////////////////////// 0x28에 8
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x28에 8 (1 0 0 0)
   digitalWrite(DB7, HIGH);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x06에 0
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x06에 0 (0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro

   ////////////////////////////////////




   ////////////////////////////// 0x06에 6
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x06에 6 (0 1 1 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, HIGH);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




         ////////////////////////////// 0x0C에 0
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x0C에 0 (0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro

   ////////////////////////////////////




      ////////////////////////////// 0x0C에 C
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x0C에 C (1 1 0 0)
   digitalWrite(DB7, HIGH);
   digitalWrite(DB6, HIGH);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




         ////////////////////////////// 0x80에 8
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x80에 8 (1 0 0 0)
   digitalWrite(DB7, HIGH);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro

   ////////////////////////////////////




         ////////////////////////////// 0x80에 0
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x80에 0 (0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro
   delayMicroseconds(100);
   ////////////////////////////////////




   ////////////////////////////// 0x01에 0
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x01에 0 (0 0 0 0)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, LOW);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 100micro

   ////////////////////////////////////




      ////////////////////////////// 0x01에 1
   digitalWrite(RS, LOW);
   digitalWrite(RW, LOW);
  //data : 0x01에 1 (0 0 0 1)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, HIGH);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, HIGH);
   digitalWrite(RW, HIGH);

   //delay 10ms
   delay(10);
   ////////////////////////////////////





   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ////////////////////////////// 0x31에 3
   digitalWrite(RS, HIGH);
   digitalWrite(RW, LOW);
  //data : 0x31에 3 (0 0 1 1)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, HIGH);
   digitalWrite(DB4, HIGH);

   //EN
   digitalWrite(EN, HIGH);
   digitalWrite(EN, LOW);

   //RW/RW
   digitalWrite(RS, LOW);
   digitalWrite(RW, HIGH);

   //delay 100micro
   ////////////////////////////////////




   ////////////////////////////// 0x31에 1
   digitalWrite(RS, HIGH);
   digitalWrite(RW, LOW);
  //data : 0x31에 1 (0 0 0 1)
   digitalWrite(DB7, LOW);
   digitalWrite(DB6, LOW);
   digitalWrite(DB5, LOW);
   digitalWrite(DB4, HIGH);

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
