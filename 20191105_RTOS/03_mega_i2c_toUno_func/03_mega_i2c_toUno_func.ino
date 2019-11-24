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
  
  // standby
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  I2C_PCF8574_set(0x08);
  delay(500);

  I2C_PCF8574_set(0x00);
  delay(500);
}

void I2C_data_8bit(char data) {
  // data 8 bit
  for (i = 0; i < 8; i++) {
    if (data & (0x80 >> i))
      digitalWrite(SDA, HIGH);
    else
      digitalWrite(SDA, LOW);

    digitalWrite(SCL, HIGH);
    digitalWrite(SCL, LOW);
  }
}

void I2C_ack() {
  pinMode(SDA, INPUT);
  digitalWrite(SCL, HIGH);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);
}

void I2C_start() {
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);
}


void I2C_stop() {
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);
}

void I2C_PCF8574_set(char data) {
  // start
  I2C_start();

  // device ID
  I2C_data_8bit(DEV_ID_PCF8574 << 1);

  // ack
  I2C_ack();

  // Data 8bit
  I2C_data_8bit(data);

  // ack
  I2C_ack();

  // stop
  I2C_stop();
}
