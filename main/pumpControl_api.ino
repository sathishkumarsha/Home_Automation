// Activate the pump control pin DIO pin 7, if moisture level is less than 20%
// Deactivate the pump control pin , if moisture level is more than 70%
// Generate the pump control in a function PumpControl_api()
#define PUMP_PIN 12

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