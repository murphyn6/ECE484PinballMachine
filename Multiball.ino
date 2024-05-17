
#include <Servo.h>

Servo myservo; 
Servo myservo2;
const int ir = 7;
int pos = 0;

void setup() {
  pinMode(ir, INPUT);
  digitalWrite(ir, LOW);
  myservo.attach(4); //Outer Servo
  myservo2.attach(5); //Inner Servo
  myservo.write(180); //Sets Outer Servo Open
  myservo2.write(0); //Sets Inner Servo Closed
}

void loop() {

  if(digitalRead(ir)==LOW) { //If ball is detected
    myservo.write(90); //Close Outer Servo
    delay(2000);
    myservo2.write(25); //Open Inner Servo to let Additional Ball out
    delay(2000);
    myservo.write(180); //Opens Outer Servo to release both balls onto playfield
    delay(5000);
    myservo.write(90); //Close Outer Servo
    myservo2.write(0); //Close Inner Servo
    while(true){ //Prevents System from triggering more than once per play
      
    }

  }
}
