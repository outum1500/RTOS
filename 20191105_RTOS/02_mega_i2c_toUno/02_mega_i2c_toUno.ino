// SCL pin 21 (Mega)
// SDA pin 20 (Mega)

#define SCL 21
#define SDA 20
#define DEV_ID_PCF8574 0x27

int i, j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  // standby
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  // start
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);

  // device ID
  for (i = 0; i < 8; i++) {
    if ((DEV_ID_PCF8574 << 1) & (0x80 >> i))
      digitalWrite(SDA, HIGH);
    else
      digitalWrite(SDA, LOW);

    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }

  // ack
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);

  // data 8 bit
  for (i = 0; i < 8; i++) {
    if (0x08 & (0x80 >> i))
      digitalWrite(SDA, HIGH);
    else
      digitalWrite(SDA, LOW);

    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }

  // ack
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);

  // stop
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  delay(1000);

  // standby
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  // start
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);

  // device ID
  for (i = 0; i < 8; i++) {
    if ((DEV_ID_PCF8574 << 1) & (0x80 >> i))
      digitalWrite(SDA, HIGH);
    else
      digitalWrite(SDA, LOW);

    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }

  // ack
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);

  // data 8 bit
  for (i = 0; i < 8; i++) {
    if (0x00 & (0x80 >> i))
      digitalWrite(SDA, HIGH);
    else
      digitalWrite(SDA, LOW);

    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }

  // ack
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);

  // stop
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  delay(1000);
}
