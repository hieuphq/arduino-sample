
const int g = 9;
const int b = 10;
const int r = 11;
void setup() {
  // put your setup code here, to run once:
  for(int i=9; i<12; i++){
      pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(r, 255);
  analogWrite(g, 123);
  analogWrite(b, 51);
  
}
