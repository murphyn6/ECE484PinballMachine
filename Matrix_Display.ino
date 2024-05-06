/****************************************************************

This code is for visual display and scoring, as score increments, it is stored here
When the score is equal to that of a homerun, the matrix display will increment accordingly
Uses Adafruit 2050 TFTLCD for color display


****************************************************************/

// Neccesary libraries for everythin
//#include <LedControl.h>
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


/*Pins for matrix display
int DIN = 11;
int CS = 7;
int CLK = 13;
*/
//Counter variable for scoring
int lastScore = 0;

/*
//Matrix display set up and bytes for displaying numbers to display
LedControl lc = LedControl(DIN,CLK,CS,0);

byte zero[8] = {0x00,0x3c,0x24,0x24,0x24,0x24,0x24,0x3c};
byte one[8] = {0x00,0x38,0x78,0x18,0x18,0x18,0x7e,0x7e};
byte two[8] = {0x7c,0x7c,0x0c,0x7c,0x7c,0x60,0x7c,0x7c};
byte three[8] = {0x7c,0x7c,0x0c,0x3c,0x3c,0x0c,0x7c,0x7c};
byte four[8] = {0x6c,0x6c,0x6c,0x7c,0x7c,0x0c,0x0c,0x0c};
byte five[8] = {0x7c,0x7c,0x60,0x7c,0x7c,0x0c,0x7c,0x7c};
byte six[8] = {0x00,0x3c,0x20,0x20,0x3c,0x24,0x24,0x3c};
byte seven[8] = {0x00,0x7c,0x7c,0x6c,0x0c,0x0c,0x0c,0x0c};
byte eight[8] = {0x00,0x3c,0x24,0x24,0x3c,0x24,0x24,0x3c};
byte nine[8] = {0x00,0x3c,0x24,0x24,0x3c,0x04,0x04,0x3c};
*/
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tft.begin();
  //lc.shutdown(0,false);
  //lc.setIntensity(0,15);
  //lc.clearDisplay(0);
  pinMode(pinone,INPUT);
  pinMode(pintwo,INPUT);
  pinMode(pinthree,INPUT);
  lastScore = 0;
 // printByte(zero);
  tft.fillScreen(HX8357_BLACK);
  
}

void loop() {
  
  tft.setCursor(150,160);
  tft.setTextSize(3); tft.setRotation(3);
  tft.setTextColor(HX8357_RED);
  tft.println("Home Run!");
  tft.setCursor(0,0);
  tft.setTextSize(2); 
  tft.println("Home");
  tft.setCursor(15,20);
  tft.println("1");

  tft.setCursor(430,0);
  tft.setTextSize(2); 
  tft.println("Away");
 
  checkScore();
  
  
  

}

/*void printByte(byte character []){
  int i=0;
  for(i=0;i<8;i++){
    lc.setRow(0,i,character[i]);
  }

  
}*/

// Function to check scoring and keep update
int checkScore(){
  int oneread = digitalRead(pinone);
  int tworead = digitalRead(pintwo);
  int threeread = digitalRead(pinthree);
  delay(100);
  if(oneread == HIGH && tworead == LOW && threeread == LOW){
    Serial.println("Single");
    lastScore += 1;
  }else if(oneread == LOW && tworead == HIGH && threeread == LOW){
    Serial.println("Double");
    lastScore += 2;
  }else if(oneread == LOW && tworead == LOW && threeread == HIGH){
    Serial.println("Triple");
    lastScore += 3;
  }
  else if(oneread == LOW && tworead == HIGH && threeread == HIGH){
    Serial.println("Home Run");
    lastScore += 4;
  }
  return lastScore;
  
}





    
  

















  
