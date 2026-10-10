// Generate Setup and Loop functions for Arduino
#include <Arduino.h>

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Setup digital pin modes
  pinMode(13, OUTPUT); // Pump control pin
  pinMode(12, OUTPUT); // Humidifier control pin
  pinMode(A0, INPUT);  // Soil moisture sensor pin
  pinMode(A1, INPUT);  // Humidity sensor pin

}

void loop() {
  // Call the function to read soil moisture:
  int moistureLevel;
  int humidityLevel;

  moistureLevel = moisture_api();
  // Call the function to control the pump based on moisture level:
    PumpControl_api(moistureLevel);
  // Read Humidity level
  humidityLevel = humidity_read_api();
  // Call the function to control the humidifier based on humidity level:
    HumidifierControl_api(humidityLevel);
  // Wait for a 10minutes:
  delay(600);
}