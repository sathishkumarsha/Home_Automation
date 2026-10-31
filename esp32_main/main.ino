// Generate Setup and Loop functions for Arduino
#include <Arduino.h>
const uint8_t SOIL_MOISTURE_PIN = 34;  // ESP32 GPIO34 (ADC1_CH6, input-only)
void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  analogReadResolution(12);
  analogSetPinAttenuation(SOIL_MOISTURE_PIN, ADC_11db);

  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void loop() {
  // Call the function to read soil moisture:
  int moistureLevel;
  int humidityLevel;

  moistureLevel = moisture_api();
  // Call the function to control the pump based on moisture level:
  PumpControl_api(moistureLevel);
  delay(600);
}