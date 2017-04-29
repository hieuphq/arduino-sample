/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int i;
bool showTime = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for(i = 11; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  i = 11;
  while( i < 14) {
    if (showTime) {
      digitalWrite(i, HIGH);
      delay(500);
    } else {
      digitalWrite(i, LOW);
      delay(500);
    }
    i ++;
  }
  /*
  for(i = 11; i < 14; i++) {
    if (showTime) {
      digitalWrite(i, HIGH);
      delay(500);
    } else {
      digitalWrite(i, LOW);
      delay(500);
    }
  }*/
  showTime = !showTime;
}
