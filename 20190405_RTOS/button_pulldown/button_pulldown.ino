void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  unsigned long currentMillis=0;
  unsigned long previousMillis=0;
  int button=LOW;
  int previousbutton=LOW;
  currentMillis=millis();

  if(button!=previousbutton){
    previousbutton=button;
    printf("%d", currentMillis-previousMillis);
    previousMillis=currentMillis;
  }
}
