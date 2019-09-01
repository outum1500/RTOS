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

int data[8]={0, 0, 1, 0, 0, 0, 0, 0}; //Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7 순임
int data1[8]={0, 0, 0, 0, 0, 0, 0, 0};
int i=0;

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<8;i++){
    if(data[7-i]==0){  //배열 마지막부터 차례대로 넣음
      digitalWrite(DATA, LOW);
    }
    else if(data[7-i]==1){
      digitalWrite(DATA, HIGH);
    }

    digitalWrite(CLOCK, HIGH); //Shift Register에 한비트 전달
    digitalWrite(CLOCK, LOW);
  }

  digitalWrite(LATCH, HIGH);  //Storage Register에 8비트 한꺼번에 전달
  digitalWrite(LATCH, LOW);

  delay(1000);



  //-------------------------------------------------------


  for(i=0;i<8;i++){
    if(data1[i]==0){
      digitalWrite(DATA, LOW);
    }
    else if(data1[i]==1){
      digitalWrite(DATA, HIGH);
    }

    digitalWrite(CLOCK, HIGH); //Shift Register에 한비트 전달
    digitalWrite(CLOCK, LOW);
  }

  digitalWrite(LATCH, HIGH);  //Storage Register에 8비트 한꺼번에 전달
  digitalWrite(LATCH, LOW);

  delay(1000);
}
