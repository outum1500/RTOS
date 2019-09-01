#define DATA 10
#define CLOCK 11
#define LATCH 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DATA, OUTPUT); //Data 핀
  pinMode(CLOCK, OUTPUT); //Shift Clock 핀
  pinMode(LATCH, OUTPUT); //Latch 핀
  pinMode(7, OUTPUT);
  // Reset 핀은 5V에 꽂아놓고 항상 HIGH로 유지
  // Output Enable 핀은 GND에 꽂아놓고 항상 LOW로 유지하여 값 자동 전송
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);

  
  

  
}
