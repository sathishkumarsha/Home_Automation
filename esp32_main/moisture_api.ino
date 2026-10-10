// Define the pin for the soil moisture sensor
const uint8_t SOIL_MOISTURE_PIN = 34;  // Analog pin A0 is used for the sensor

/**
 * @brief Reads the soil moisture sensor value, maps it to a percentage, and prints the result to the Serial Monitor.
 *
 * This function performs the following steps:
 * - Reads the analog value from the soil moisture sensor connected to SOIL_MOISTURE_PIN.
 * - Maps the raw sensor value (0-1023) to a percentage (0% = dry, 100% = wet).
 * - Prints the moisture percentage to the Serial Monitor for monitoring purposes.
 * - Adds a 1-second delay for readability between measurements.
 */
int moisture_api() {
  const int sampleCount = 10;
  uint32_t total = 0;
  uint32_t rawMoisture = 0;
  uint8_t moisturePercent = 0;

  for (int i = 0; i < sampleCount; i++) {
    total += analogRead(SOIL_MOISTURE_PIN);
    delay(5);
  }
  // Raw ADC reading, typically 0-4095 
  rawMoisture = (uint32_t)((total / sampleCount)*100)
  moisturePercent = (uint8_t)(rawMoisture/4095);

  return moisturePercent;

}