int i = 0;
const int photoSensor = A0;
const int numOfLed = 3;
const int maxPhotoSensor = 1023;
const int firstLedPin = 11;
int step = maxPhotoSensor / numOfLed;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = firstLedPin; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print("Hey, ");
  // Serial.println("BEAC is cool");
  // Serial.println("Agree");

  // for(int i = 5; i < 50; i += 5){
  //     Serial.println(i);
  //     delay(100);
  // }

  int photoValue = analogRead(photoSensor);
  Serial.println(photoValue);

  // for(int i = firstLedPin; i < 14; i++) {
  //   digitalWrite(i, LOW); 
  // }

  for(int i = 0; i < numOfLed; i++) {

  	if (i * step <= photoValue) {
  		digitalWrite(i+ firstLedPin, HIGH);
  	} else {
  		digitalWrite(i+ firstLedPin, LOW);
  	}
  }

  delay(500);
}


