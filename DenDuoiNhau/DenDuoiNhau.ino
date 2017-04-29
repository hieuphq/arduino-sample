int nextPin = 0;
bool verse = true;

void setup() {
  // put your setup code here, to run once:
  for(int i = 11; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 11; i < 14; i++) {
    digitalWrite(i, LOW); 
  }
  nextPin = (nextPin + 1) % 3;
  if (nextPin == 0) {
    verse = !verse;
  }

  if (verse) {
    digitalWrite(13 - nextPin, HIGH);
  } else {
    digitalWrite(11 + nextPin, HIGH);
  }
   
  delay(150);
}
