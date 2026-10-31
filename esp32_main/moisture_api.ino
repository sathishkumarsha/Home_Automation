// Define the pin for the soil moisture sensor
//const uint8_t SOIL_MOISTURE_PIN = 34;  // ESP32 GPIO34 (ADC1_CH6, input-only)

/**
 * @brief Samples the soil moisture sensor and returns a value derived from the averaged ADC reading.
 *
 * This function performs the following steps:
 * - Takes 10 analog readings from SOIL_MOISTURE_PIN, waiting 5 ms between readings.
 * - Averages the readings, multiplies the average by 100, and divides by 4095.
 * - Returns the result as an 8-bit integer; it does not print or apply a dry/wet calibration.
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
  rawMoisture = (uint32_t)((total / sampleCount)*100);
  moisturePercent = (uint8_t)(rawMoisture/4095);

  return (100-moisturePercent);

}