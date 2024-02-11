//shared with Mr Hansen successfully :)
#include <SServo.h>


Servo leftEar;
Servo rightEar;

byte LEDPIN = 13;

const byte PAW1 = 1;
const byte PAW2 = 2;
const byte PAW3 = 3;
const byte PAW4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;
//this code above this is setting the pins
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAW1, INPUT);
  pinMode(PAW2, INPUT);
  pinMode(PAW3, INPUT);
  pinMode(PAW4, INPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
  //this code is setting the variables as inputs and outputs
}

void loop() {
  // If paw 1 is pressed, then do the following
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);

    // If paw 2 is pressed, then do the following
    if (digitalRead(PAWPIN2) == HIGH) {
      digitalWrite(LEDPIN, LOW);

      // If paw 3 is pressed, then do the following
      if (digitalRead(PAWPIN3) == HIGH) {
        playMusic();

        // If paw 4 is pressed, then do the following
        if (digitalRead(PAWPIN4) == HIGH) {
          int score = playGame();
        }
      }

      void wagEars() {
        leftEar.write(0);
        rightEar.write(0);
        leftEar.write(90);
        rightEar.write(90);
        leftEar.write(0);
        rightEar.write(0);
      }

      void blinkingLed() {
        byte randNumber = random(1, 3);

        for (int i = 0; i <= randNumber; i++) {}
        digitalWrite(LEDPIN, HIGH)
          delay(500);
        digitalWrite(LEDPIN, LOW);
        delay(500);
      }
    }