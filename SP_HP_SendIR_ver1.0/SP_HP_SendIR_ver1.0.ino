#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <IRremoteESP8266.h>

IRsend irsend(D4);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "c7acaedd7d9e4acba38143c3d9663846";

void setup()
{
  irsend.begin();
  Serial.begin(9600);
  Blynk.begin(auth, "HP_ZMI", "khongpass");
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V2)
{
  int pinData = param.asInt();
  if (pinData == 1){
    //BLYNK_PRINT.println("Got triggered");
    irsend.sendNEC(0x00FFE000, 36);
  }
}
