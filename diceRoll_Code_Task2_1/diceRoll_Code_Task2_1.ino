//add a LCD library of functions
#include <LiquidCrystal.h>
//HAN COMMENT this looks great Corey! very pleased to see all the comments in your code as well
//setup all the pins as constants
const byte BUTTONPIN = 1;
const byte NOISEPIN = A0;
const byte POTENTPIN = A1;

//Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal screen(0);

//setup which of the pins are input/output
//and randomise where we start our random numbers from
void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(POTENTPIN, INPUT);

  randomSeed(analogRead(NOISEPIN));

  Serial.begin(9600);

  //set up the LCD's number of rows and columns:
  if (!screen.begin(16, 2)) {
    Serial.println("couldn't start the screen? check wiring");
    while (1);
  }
}

//continuously check if the "roll dice" button has been pressed with a loop
void loop() {
  //if the button has been pressed, read the potentiometer to check what the dice type is
  //then call the rollDice method with that sort of dice
  if (digitalRead(BUTTONPIN) == HIGH) {
    Serial.println("Rolling dice");
    //gives a value of 0-1023
    int diceType = analogRead(POTENTPIN);
    //use map to change the value
    //1 = 4-sided, 2 = 6-sided, 3 = 8-sided, 4 = 10-sided, 5 = 12-sided, 6 = 20-sided
    diceType = map(diceType, 0, 1023, 1, 6);
    //pass the new value to rollDice method
    rollDice(diceType);
  }
}

//takes a value from 1 to 6 as the type of dice and uses random to choose a value and prints it to the screen
void rollDice(byte numSides) {
  //create a variable with a default value
  byte diceRoll = 255;

  //check which sided dice is needed
  //make a random choice and then print the value
  switch (numSides) {
    case 1:
      Serial.print("A 4 sided dice rolls: ");
      diceRoll = random(1, 4);
      break;
    case 2:
      Serial.print("A 6 sided dice rolls: ");
      diceRoll = random(1, 6);
      break;
    case 3:
      Serial.print("A 8 sided dice rolls: ");
      diceRoll = random(1, 8);
      break;
    case 4:
      Serial.print("A 10 sided dice rolls: ");
      diceRoll = random(1, 10);
      break;
    case 5:
      Serial.print("A 12 sided dice rolls: ");
      diceRoll = random(1, 12);
      break;
    case 6:
      Serial.print("A 20 sided dice rolls: ");
      diceRoll = random(1, 20);
      break;
    default:
      Serial.println("Issue with mapping potentiometer values");
      break;
  }
  screen.println(diceRoll);
}
