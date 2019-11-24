void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int leftflag = 0;
int rightflag = 0;
int upflag = 0;
int downflag = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int analog_x = 0, analog_y = 0;
  
  analog_x = analogRead(A0); // data read
  analog_y = analogRead(A1);
  
  if(analog_x >= 400 && analog_x <= 700 && analog_y >= 400 && analog_y <= 700){ // center
    if(leftflag == 1 || rightflag == 1 || upflag == 1 || downflag == 1){
      Serial.println("center");
      leftflag = 0;
      rightflag = 0;
      upflag = 0;
      downflag = 0;
    }
  }
  else if(analog_x < 400){ // left
    if(leftflag == 0){
      Serial.println("left");
      leftflag = 1;
    }
  }
  else if(analog_x > 700){ // right
    if(rightflag == 0){
      Serial.println("right");
      rightflag = 1;
    }
  }
  else if(analog_y < 400){ // up
    if(upflag == 0){
      Serial.println("up");
      upflag = 1;
    }
  }
  else if(analog_y > 700){ // down
    if(downflag == 0){
      Serial.println("down");
      downflag = 1;
    }
  }
  

  delay(10);
}
