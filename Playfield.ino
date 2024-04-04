// Frederick Levins
// ECE 484 Pinball Playfield

// Need to decide points multiplier
// how to pass points and symbolization of output aka "SINGLE!" to Jacob
// How to move/speed of servo, SPI needed?


//first base 
const int firstBaseT = 0;
const int firstBaseS = 1;

//second base 
const int secondBaseT = 2;
const int secondBaseS = 3;

//first base 
const int thirdBaseT = 4;
const int thirdBaseS = 5;

//first base 
const int fourthBaseT = 6;
const int fourthBaseS = 7;

int score = 0;

void setup()
{
  Serial.begin(9600);

  // first base
  pinMode(firstBaseT, INPUT);
  pinMode(firstBaseS, INPUT);

  // second base
  pinMode(firstBaseT, INPUT);
  pinMode(firstBaseS, INPUT);

  // third base
  pinMode(firstBaseT, INPUT);
  pinMode(firstBaseS, INPUT);

  // fourth base
  pinMode(firstBaseT, INPUT);
  pinMode(firstBaseS, INPUT);

}
// Read phototransistor light levels, display raw and converted analog values.
// Produce varying intensity LED levels
void loop()
{

  // First base --> dunno if needed for S
  int firstValT = analogRead(firstBaseT);
  int firstValS = analogRead(firstBaseS);

  // Second base
  int secondValT = analogRead(secondBaseT);
  int secondValS = analogRead(secondBaseS);

  // Third base
  int thirdValT = analogRead(thirdBaseT);
  int thirdValS = analogRead(thirdBaseS);


  // Fourth base
  int fourthValT = analogRead(fourthBaseT);
  int fourthValS = analogRead(fourthBaseS);

  // First Base
  if (firstValtT < 500 /*threshold determine*/) {
    delay(100);
    //set servo low
    delay(200);
    score += 1;
    // set servo high
    Serial.println("Single");
  }

  // Second Base
  if (secondValtT < 500 /*threshold determine*/) {
    delay(100);
    //set servo low
    delay(200);
    score += 2;
    // set servo high
    Serial.println("Double");
  }

  // Third Base
  if (thirdValtT < 500 /*threshold determine*/) {
    delay(100);
    //set servo low
    delay(200);
    score += 3;
    // set servo high
    Serial.println("Triple");
  }

  // Fourth Base
  if (fourthValtT < 500 /*threshold determine*/) {
    delay(100);
    //set servo low
    delay(2);
    score += 4;
    // set servo high
    Serial.println("HomeRun");
  }

  return score;
 
}
