// Activate the pump control pin DIO pin 7, if moisture level is less than 20%
// Deactivate the pump control pin , if moisture level is more than 70%
// Generate the pump control in a function PumpControl_api()
#define PUMP_PIN 12

/**
 * @brief Controls the water pump based on the soil moisture level.
 *
 * This function activates or deactivates the pump depending on the provided
 * moisture level. If the moisture level is below 20, the pump is turned ON.
 * If the moisture level is above 50, the pump is turned OFF.
 * The function also prints the pump status ("PumpON" or "PumpOFF") to the Serial monitor.
 *
 * @param moistureLevel The current soil moisture level (integer value).
 */
void PumpControl_api(int moistureLevel) {
  if (moistureLevel < 20) {
    Serial.print("PumpON");
    // Activate the pump
    digitalWrite(PUMP_PIN, LOW);
  } else if (moistureLevel > 50) {
    Serial.print("PumpOFF");
    // Deactivate the pump
    digitalWrite(PUMP_PIN, HIGH);
  }
}