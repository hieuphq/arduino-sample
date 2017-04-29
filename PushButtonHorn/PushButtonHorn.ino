
const int pin0 = 8;
const int pin13 = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin13, OUTPUT);
  pinMode(pin0, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(pin0);
  Serial.println(val);

  switch (val) {
  	case 0:
  		digitalWrite(pin13, LOW);
  	break;

  	case 1:
  		digitalWrite(pin13, HIGH);
  	break;
  }
  delay(300);
}
