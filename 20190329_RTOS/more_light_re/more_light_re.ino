void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

int i=0, j=0;

void loop() {
  // put your main code here, to run repeatedly:

  for(i=0; i<100; i++){         //1초 = 1000미리 = 1000000마이크로
    for(j=0; j<100; j++){
      digitalWrite(13, HIGH);     // x * 10000번 = 1000000마이크로    x= 100
      delayMicroseconds(i);
      digitalWrite(13, LOW);
      delayMicroseconds(100-i);
    }
  }

  for(i=0; i<100; i++){         //1초 = 1000미리 = 1000000마이크로
    for(j=0; j<100; j++){
      digitalWrite(13, HIGH);     // x * 10000번 = 1000000마이크로    x= 100
      delayMicroseconds(100-i);
      digitalWrite(13, LOW);
      delayMicroseconds(i);
    }
  }
}
