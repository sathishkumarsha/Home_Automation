// Define the pin for the soil moisture sensor
#define SOIL_MOISTURE_PIN A0  // Analog pin A0 is used for the sensor

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
  int sensorValue = analogRead(SOIL_MOISTURE_PIN);  // Read the analog value from the sensor

  // Map the sensor value to a percentage (0% = dry, 100% = wet)
  int moisturePercentage = map(sensorValue, 0, 1023, 0, 100);

  // Print the sensor value and percentage to the Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  return moisturePercentage;
}