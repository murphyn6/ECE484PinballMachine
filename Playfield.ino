// Frederick Levins ECE 484 Embedded Systems
// Final Pinball Project
// Playfield: This is the main code for driving the functionality of an interactive pinball playfield.
// The playfield intends to update scoring based on the ideas of baseball at each base (single, double, triple) and 
// outfield (homerun). The functionality updates pins HIGH/LOW to launch the ball back after the photoresistor 
// inside each hole detects the ball.

#include <Servo.h>

#define thermPinS A1  // Single
#define thermPinD A0 // Double
#define thermPinT A2  // Triple
#define thermPinH A3  // Homerun

// read pins
#define sPinO 2
#define sPinT 3
#define sPinTH 4



int pos = 0; // servo postion

// set of servos
Servo myServoO;
Servo myServoT;
Servo myServoTH;
Servo myServoF;


void setup() {
  
  Serial.begin(9600);
  pinMode(thermPinS, INPUT);
  pinMode(thermPinD, INPUT);
  pinMode(thermPinT, INPUT);
  pinMode(thermPinH, INPUT);

  pinMode(sPinO, OUTPUT);
  pinMode(sPinT, OUTPUT);
  pinMode(sPinTH, OUTPUT);
 
  myServoO.attach(7);
  myServoT.attach(8);
  myServoTH.attach(9);
  myServoF.attach(10);
  myServoO.write(0);
  myServoT.write(0);
  myServoTH.write(0);
  myServoF.write(0);
 

}

void loop() {

 digitalWrite(sPinO,LOW); // 001
 digitalWrite(sPinT, LOW);
 digitalWrite(sPinTH, LOW);

 /* check values of photoresistors
 int thermValS = analogRead(thermPinS);
 int thermValD = analogRead(thermPinD);
 int thermValT = analogRead(thermPinT);
 int thermValH = analogRead(thermPinH); */

 Serial.println(thermValS);
 Serial.println(thermValD);
 Serial.println(thermValT);
 Serial.println(thermValH);
 
  delay(500);
 
  // Single
  if (thermValS < 500) { // dark factor
    myServoO.write(180);
    delay(1000);
    myServoO.write(0);
    digitalWrite(sPinO, HIGH);
    digitalWrite(sPinT, LOW);
    digitalWrite(sPinTH, LOW);
    Serial.println("1");
    delay(500);

  }

 
   // Double
  if (thermValD < 80) { // dark factor
    myServoT.write(60);
    delay(1000);
    myServoT.write(0);
    digitalWrite(sPinO, LOW); // 010
    digitalWrite(sPinT, HIGH);
    digitalWrite(sPinTH, LOW);
    Serial.println("2");
    delay(500);
  }

   // Triple
  if (thermValT < 100) { // dark factor
    myServoTH.write(180);
    delay(1000);
    myServoTH.write(0);
    digitalWrite(sPinO, LOW);
    digitalWrite(sPinT, LOW);
    digitalWrite(sPinTH, HIGH);
    Serial.println("3");
    delay(500);
  }

   // Homerun
  if (thermValH < 100) { // dark factor
    myServoF.write(180);
    delay(1000);
    myServoF.write(0);
    digitalWrite(sPinO, LOW); 
    digitalWrite(sPinT, HIGH);
    digitalWrite(sPinTH, HIGH);
    Serial.println("4");
    delay(500);
  }
}
