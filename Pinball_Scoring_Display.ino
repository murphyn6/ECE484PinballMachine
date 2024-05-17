/****************************************************************

  This code is for visual display and scoring, as score increments, it is stored here
  When the score is equal to that of a homerun, the matrix display will increment accordingly
  Uses Adafruit 2050 TFTLCD for color display


****************************************************************/

// Neccesary libraries for everything, uses SPI library for communication to screen

#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

// "Flexible" pins for SPI communcation to TFTLCD
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8


// Pins for communication to playfield
#define pinone 2
#define pintwo 3
#define pinthree 4

//Hex background color for screen, Ivy Green
#define background 0x0280


//Counter variable for scoring
int lastScore = 0;
int trueScore = 0;
int secLeft = 60;
int i = 0;

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  tft.begin();
  
  pinMode(pinone, INPUT);
  pinMode(pintwo, INPUT);
  pinMode(pinthree, INPUT);
  pinMode(lifePin, INPUT);

  
  // Forcing lastScore to 0 one last time
  lastScore = 0;

  //Set initial screen state
  tft.fillScreen(background);
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("Score");
  tft.setCursor(15, 20);
  tft.print(trueScore);
  tft.setCursor(405, 0);
  tft.setTextSize(2);
 // tft.println("Time");
  tft.setCursor(150,160);
  tft.setTextSize(3);
  tft.println("START");

}

void loop() {
  delay(500); // Needed delay on my end to keep transmissions from playfield from bogging arduino down
  secLeft = (60000 - millis()) / 1000; //Check how many seconds are left in the game, playtime is one minute
  
  while(i<1){
    screenUpdate();
    i++;
  }
  // Game over state, freezes program, must manually reset arduino to play again
  if(secLeft <= 0){
    tft.setCursor(150,160);
    tft.println("GAME OVER");
    return 0;
  }
 
  checkScore();
  
}



// Function to check scoring, updates screen after a state on the playfield is tripped
// This function reads from the playfield as a binary state, pins correspond to bits
// Scoring works as follows: a single is worth one point, double is worth two, triple is worth three, homerun is worth 4
// If the score is equal to three points, then a variable called trueScore  increments up by one, that is the score seen on the screen.
int checkScore() {
  int oneread = digitalRead(pinone);
  int tworead = digitalRead(pintwo);
  int threeread = digitalRead(pinthree);
  delay(10);

  if (oneread == HIGH && tworead == LOW && threeread == LOW) {
    Serial.println("Single");
    tft.setCursor(150, 160);
    tft.setTextSize(3);
    tft.println("Single!");
    delay(1000);
    lastScore += 1;
    screenUpdate();
  } else if (oneread == LOW && tworead == HIGH && threeread == LOW) {
    Serial.println("Double");
    tft.setCursor(150, 160);
    tft.setTextSize(3);
    tft.println("Double");
    delay(1000);
    lastScore += 2;
    screenUpdate();
  } else if (oneread == LOW && tworead == LOW && threeread == HIGH) {
    Serial.println("Triple");
    tft.setCursor(150, 160);
    tft.setTextSize(3);
    tft.println("Triple");
    delay(1000);
    lastScore += 3;
    screenUpdate();
  }
  else if (oneread == LOW && tworead == HIGH && threeread == HIGH) {
    Serial.println("Home Run");
    tft.setCursor(150, 160);
    tft.setTextSize(3);
    tft.println("Home Run!");
    delay(1000);
    lastScore += 5;
    screenUpdate();
  }
  if (lastScore >= 4) {
    trueScore += 1;
    lastScore = 0;
  }
  
  return trueScore;
  
}




// This is just an easy way to update the screen, cuts down on redundancies
void screenUpdate() {

  tft.fillScreen(background);
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("Score");
  tft.setCursor(15, 25);
  tft.print(trueScore);
  tft.setCursor(200,200);
  tft.println(secLeft);
  

}
