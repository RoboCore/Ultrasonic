#include <Ultrasonic.h>

HC_SR04 sensor1(12,13); // (trigger, echo)

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensor1.distance());
  delay(100);
}
