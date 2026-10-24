// Activate pump control pin 2 when moisture is below 40%.
// Deactivate pump control pin 2 when moisture is above 80%.
// PumpControl_api() controls the active-low pump output.
#define PUMP_PIN 2

/**
 * @brief Controls the pump using the soil-moisture reading.
 *
 * Turns the pump on when moisture is below 40% and off when it is above 80%.
 * Readings from 40% through 80% leave the pump output unchanged. The output
 * is active-low: LOW turns the pump on and HIGH turns it off. Prints a status
 * message when either threshold condition is met.
 *
 * @param moistureLevel Soil-moisture level as an integer percentage.
 */
void PumpControl_api(int moistureLevel) {
  if (moistureLevel < 40) {
    Serial.print("PumpON\n");
    // Activate the pump
    digitalWrite(PUMP_PIN, LOW);
  } else if (moistureLevel > 80) {
    Serial.print("PumpOFF\n");
    // Deactivate the pump
    digitalWrite(PUMP_PIN, HIGH);
  }
}