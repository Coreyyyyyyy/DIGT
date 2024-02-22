//add the Servo to library of functions
#include <Servo.h>

//set up of constants and pins
const byte LEDPIN = 13;
const byte BUTTONPIN = 1;
const byte MICROPHONEPIN = 2;
const byte SERVOPIN = 3;
//set up servo the servo positions and the trigger volume
const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512; //0-1023

//create a servo called opener
Servo opener;

//setup which of the pins are input/output, and attach the opener servo to its pin
void setup() {
  pinmode(LEDPIN, OUTPUT);
  pinmode(BUTTONPIN, INPUT);
  pinmode(MICROPHONEPIN, INPUT);
  opener.attach(SERVOPIN);

  Serial.begin(9600);
}

//continuously check if the two statements are true with a loop
void loop() {
  //check if the microphone value is bigger than the trigger's volume
  if (analogRead(MICROPHONEPIN) > LOUDENOUGH) {
    Serial.print("Knock heard, unlocking the box");
    digitalWrite(LEDPIN, HIGH);
    opener.write(UNLOCK);
  }
  //check if the button has been pressed
  //if pressed, move the servo to locked position
  if (digitalRead(BUTTONPIN) == HIGH) {
    Serial.print("Button has been pressed, locking the box");
    opener.write(LOCK);
  }
}