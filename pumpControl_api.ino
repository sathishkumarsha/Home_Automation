// Activate the pump control pin DIO pin 7, if moisture level is less than 20%
// Deactivate the pump control pin , if moisture level is more than 70%
// Generate the pump control in a function PumpControl_api()

void PumpControl_api(int moistureLevel) {
  const int PUMP_PIN = 7;  // Define the pump control pin
  pinMode(PUMP_PIN, OUTPUT);  // Set the pump pin as an output

  if (moistureLevel < 20) {
    // Activate the pump
    digitalWrite(PUMP_PIN, HIGH);
  } else if (moistureLevel > 70) {
    // Deactivate the pump
    digitalWrite(PUMP_PIN, LOW);
  }
}