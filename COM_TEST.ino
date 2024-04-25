#include <Wire.h>
int lastScore = 0;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(2, 1);    // request 6 bytes from peripheral device #8

  while (Wire.available()) { // peripheral may send less than requested
    int c = Wire.read(); // receive a byte as character
    Serial.println(c);
    return 0;
  }

  delay(500);
}
int checkScore(int score){
  int newScore = lastScore - score;
  lastScore = newScore;
    

    switch(newScore){
      case 1:
        Serial.println("SINGLE");
        break;
      case 2:
        Serial.println("DOUBLE");
        break;
      case 3:
        Serial.println("TRIPLE");
        break;
       case 4:
        Serial.println("HOME RUN");
        break;
        
    }
    return newScore;
}
