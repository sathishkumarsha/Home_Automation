// Generate Setup and Loop functions for Arduino
#include <Arduino.h>

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Call the function to read soil moisture:
  int moistureLevel = moisture_api();
  // Call the function to control the pump based on moisture level:
    PumpControl_api(moistureLevel);
  // Read Humidity level
  int humidityLevel = humidity_read_api();
  // Call the function to control the humidifier based on humidity level:
    HumidifierControl_api(humidityLevel);
  // Wait for a 10minutes:
  delay(600000);
}