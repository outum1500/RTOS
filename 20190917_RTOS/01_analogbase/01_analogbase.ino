void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_data_x;
  analog_data_x = analogRead(A0);
  Serial.println(analog_data_x);
  delay(10);
}
