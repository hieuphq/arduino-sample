#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "c7acaedd7d9e4acba38143c3d9663846";
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "HP_ZMI", "khongpass");
}
void loop()
{
  Blynk.run();
}
