// Assignment B: HC-SR04 range measurement without the unsupported NewPing library.
const byte trigPin = 9; // HC-SR04 trigger connects to D9.
const byte echoPin = 10; // HC-SR04 echo connects to D10.
const unsigned long echoTimeoutUs = 200UL * 58UL; // Approximate timeout for a 200 cm round trip.
void setup() { // Run once at startup.
  Serial.begin(9600); // Start serial output at 9600 baud.
  pinMode(trigPin, OUTPUT); // Configure trigger as an output.
  pinMode(echoPin, INPUT); // Configure echo as an input.
  digitalWrite(trigPin, LOW); // Start with the trigger in its idle state.
} // End setup.
void loop() { // Take repeated distance measurements.
  digitalWrite(trigPin, LOW); // Ensure a clean low trigger level.
  delayMicroseconds(2); // Hold low briefly before the trigger pulse.
  digitalWrite(trigPin, HIGH); // Begin the ultrasonic trigger pulse.
  delayMicroseconds(10); // Hold high for the HC-SR04 trigger duration.
  digitalWrite(trigPin, LOW); // End the trigger pulse.
  unsigned long echoTimeUs = pulseIn(echoPin, HIGH, echoTimeoutUs); // Measure the echo pulse, with a bounded wait.
  if (echoTimeUs == 0) { // Check whether pulseIn timed out without an echo.
    Serial.println("No echo within 200 cm range."); // Report timeout instead of implying a real 0 cm reading.
  } else { // Convert a valid echo duration to distance.
    float distanceCm = echoTimeUs * 0.0343f / 2.0f; // Convert round-trip microseconds to one-way centimetres.
    Serial.print("Distance: "); // Print the measurement label.
    Serial.print(distanceCm, 1); // Print centimetres to one decimal place.
    Serial.println(" cm"); // Finish the measurement line.
  } // End echo-validity choice.
  delay(250); // Wait before the next reading.
} // End loop.
