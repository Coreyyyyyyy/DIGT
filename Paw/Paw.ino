//shared with Mr Hansen successfully :)



void setup() {
  pinMode(PAWPIN
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

      void playMusic(){
        //play an MP3 file here
      }

      int playGame(){
        byte score = 99;
        //play simon says game
        return score;
      }
