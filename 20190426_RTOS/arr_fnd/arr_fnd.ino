void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  /////////////////////////////////////
  pinMode(10, OUTPUT);   
  pinMode(11, OUTPUT);   
  pinMode(12, OUTPUT);   
  pinMode(14, OUTPUT);   
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);   // Power 5
  pinMode(19, OUTPUT);   // Power 10
}

int fnd_char[9][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1},
  {1, 1, 0, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 1, 1}
};

int i, j;

void loop() {
  // put your main code here, to run repeatedly:
  
  for(i=0;i<8;i++){
    digitalWrite(18, HIGH);
    digitalWrite(19, LOW);
    digitalWrite(i+10, !(fnd_char[1][i]));
  }
  delay(10);
  for(i=0;i<8;i++){
    digitalWrite(18, LOW);
    digitalWrite(19, HIGH);
    digitalWrite(i+10, !(fnd_char[3][i]));
  }
  delay(10);
}
