// SCL pin 21 (Mega)
// SDA pin 20 (Mega)

#define SCL 21
#define SDA 20
#define DEV_ID_PCF8574 0x27

int i, j;
void I2C_PCF8574_set(char data);
void lcd_clear(void);
void graphicLCD_INST(char inst);
void graphicLCD_DATA(char lcd_data);
void I2C_data_8bit(char data);
void I2C_ack(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_PCF8574_set(char data);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);

  // standby
  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  // ------------------------------------------
  // graphicLCD 8bit mode
  graphicLCD_INST(0x30);
  graphicLCD_INST(0x30);
  graphicLCD_INST(0x30);
  graphicLCD_INST(0x28);

  // ------------------------------------------
  // graphicLCD 4bit mode
  graphicLCD_INST(0x20);
  graphicLCD_INST(0x80);

  graphicLCD_INST(0x00);
  graphicLCD_INST(0x60);

  graphicLCD_INST(0x00);
  graphicLCD_INST(0xc0);

  graphicLCD_INST(0x80);
  graphicLCD_INST(0x00);

  graphicLCD_INST(0x00);
  graphicLCD_INST(0x10);
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd_clear();

  graphicLCD_INST(0x20); // 0x36
  graphicLCD_INST(0x60);

  graphicLCD_INST(0x80); // y
  graphicLCD_INST(0x00);

  graphicLCD_INST(0x80); // x
  graphicLCD_INST(0x00);

  graphicLCD_INST(0x20);
  graphicLCD_INST(0x00);

  graphicLCD_DATA(0xf0);
  graphicLCD_DATA(0xf0);
  graphicLCD_DATA(0xf0);
  graphicLCD_DATA(0xf0);
  delay(1000);
}

void graphicLCD_data_4bit(int x, int y, unsigned short data) {
  graphicLCD_INST(0x20); // extended mode, graphic display on
  graphicLCD_INST(0x60);
  
  graphicLCD_INST((0x80 + (y % 32)) & 0xf0 ); 
  graphicLCD_INST(((0x80 + (y % 32)) & 0x0f) << 4 ); 
  graphicLCD_INST((0x80 + (y / 32) * 8 + x) & 0xf0);
  graphicLCD_INST(((0x80 + (y / 32) * 8 + x) & 0x0f) << 4);

  graphicLCD_INST(0x20); // basic mode
  graphicLCD_INST(0x00);
  
  graphicLCD_INST(((data & 0xff00) >> 8) & 0xf0); // y
  graphicLCD_INST((((data & 0xff00) >> 8) & 0x0f) << 4);
  graphicLCD_INST(((data & 0xff00) >> 8) & 0xf0); // y
  graphicLCD_INST((((data & 0xff00) >> 8) & 0x0f) << 4); 
}



void lcd_clear(void) {
  int i, j;

  for (j = 0; j < 8; j++) {
    for (i = 0; i < 64; i++) {
      graphicLCD_INST(0x20); // extended mode, graphic display on
      graphicLCD_INST(0x60);
      graphicLCD_INST( (0x80 + (i % 32)) & 0xf0 ); // y
      graphicLCD_INST( ((0x80 + (i % 32)) & 0x0f) << 4 ); // x
      graphicLCD_INST( (0x80 + (i / 32) * 8 + j) & 0xf0);
      graphicLCD_INST( ((0x80 + (i / 32) * 8 + j) & 0x0f) << 4);

      graphicLCD_INST(0x20); // basic mode
      graphicLCD_INST(0x00);

      graphicLCD_DATA(0x00);
      graphicLCD_DATA(0x00);
      graphicLCD_DATA(0x00);
      graphicLCD_DATA(0x00);
    }
  }
}

void graphicLCD_INST(char inst) {
  char data = 0x00;

  // -------------------------------------------
  // graphicLCD 8bit mode

  // RS Low
  I2C_PCF8574_set(data);

  // data 8bit
  data |= inst;
  I2C_PCF8574_set(data);

  // enable high
  data |= 0x04;
  I2C_PCF8574_set(data);
  // enable low
  data &= ~0x04;
  I2C_PCF8574_set(data);

  // RS High
  data |= 0x01;
  I2C_PCF8574_set(data);

  delayMicroseconds(100);
}

void graphicLCD_DATA(char lcd_data) {
  char data = 0x01;

  // -------------------------------------------
  // graphicLCD 8bit mode

  // data 8bit
  data |= lcd_data;
  I2C_PCF8574_set(data);

  // enable high
  data |= 0x04;
  I2C_PCF8574_set(data);
  // enable low
  data &= ~0x04;
  I2C_PCF8574_set(data);

  delayMicroseconds(100);
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

  delayMicroseconds(100);
}
