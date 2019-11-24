#include <Wire.h>

#define DEV_ID  0x27

void setup() {
  Wire.begin(DEV_ID);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  pinMode(13,OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  if(Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character

    if(c & 0x08){
      digitalWrite(13, HIGH);
    }
    else{
      digitalWrite(13, LOW);
    }
   
  }
}
