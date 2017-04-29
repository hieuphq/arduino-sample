#include "DHT.h"

// Include for olded
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define Pin In and Out for output
#define DHTPIN 9     // what pin we're connected to
#define BTNIN 8
#define DETECT_LEFT 6
#define DETECT_RIGHT 7
#define SOUNDOUT 12

// Define oled constant
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int state = 0;
int numOfProgram = 3;

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

int numOfArr = 8;
bool leftArray[] = {0,0,0,0,0,0,0,0};
bool rightArray[] = {0,0,0,0,0,0,0,0};
int currLeftIdx = 0;
int currRightIdx = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Set up dht
  dht.begin();

  // Set up input 
  pinMode(BTNIN, INPUT);
  pinMode(DETECT_LEFT, INPUT);
  pinMode(DETECT_RIGHT, INPUT);
  pinMode(SOUNDOUT, OUTPUT);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(200);

  // Clear the buffer.
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,0);
  display.clearDisplay();
  display.println("Smart home");
  display.setCursor(30,10);
  display.println("Final Project");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int btnVal = digitalRead(BTNIN);

  if (btnVal) {
    state = (state + 1) % numOfProgram;
    delay(50);

    printCurrentProgramName(state);
  }
  runProgram(state);
}

void printCurrentProgramName(int program) {
  display.clearDisplay();
  display.setCursor(10,0);
  display.println("You choose program:");

  switch (program) {

    case 0:
      display.setCursor(10, 10);
      display.println("Detect motivation");
    break;

    case 1:
      display.setCursor(10, 10);
      display.println("Show temperature");
    break;

    case 2:
      display.setCursor(10, 10);
      display.println("Alarm");
    break;
  }
  display.display();
  delay(1000);
}
void runProgram(int currProgram) {
  switch (currProgram) {
    case 0:
      detectMotivation(DETECT_LEFT, DETECT_RIGHT);
    break;

    case 1:
      printTemp();
    break;

    case 2:
      detectHaveMotivation(DETECT_RIGHT, SOUNDOUT);
    break;
  }
}

void printTemp() {
	// put your main code here, to run repeatedly:

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {

    display.clearDisplay();
    display.setCursor(10, 10);
    String humidityPrefix = "Humidity: ";
    String humidityStr = humidityPrefix + h;
	  display.println(humidityStr);

    display.setCursor(10, 20);
    String temperaturePrefix = "Temp: ";
    String temperatureStr = temperaturePrefix + t;
	  display.println(temperatureStr);

    display.display();
    delay(100);
  }
}

void detectHaveMotivation(int inputPin, int outputPin) {
  int inputVal = digitalRead(inputPin);

  display.clearDisplay();
  display.setCursor(10, 10);

  if (inputVal == true) {
    digitalWrite(outputPin, HIGH);
    display.println("Alarm");
  } else {
    digitalWrite(outputPin, LOW);
    display.println("None");
  }
  display.display();
}

void disableControls() {
  digitalWrite(SOUNDOUT, LOW);
}

int detectMotivation(int leftSensorPin, int rightSensorPin) {

  int leftVal = digitalRead(leftSensorPin);
  int rightVal = digitalRead(rightSensorPin);

  if (leftVal != true && rightVal != true) {


    return -1;
  }



  Serial.println(leftVal);

  delay(800);

  // Serial.print("Left: " + leftVal);
  // Serial.print(" Right: " + rightVal);
  // Serial.print("\n");

  if (leftVal == true) {

    int otherRightVal = digitalRead(rightVal);

    if(otherRightVal == true){
        
        display.setCursor(10, 10);
        display.println("Left to Right");
        Serial.println("Left to Right");
    }
  }

  if (rightVal = true) {

    int otherLeftVal = digitalRead(leftVal);

    if(otherLeftVal == true){
        
        display.setCursor(10, 10);
        display.println("Right to Left");
        Serial.println("Right to Left");
    }
  }

  return 1;
}
