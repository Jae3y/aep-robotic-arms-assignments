// AEP Week 2: repeating three-colour traffic light sequence.
const byte redPin = 13; // Red LED output pin.
const byte yellowPin = 12; // Yellow LED output pin.
const byte greenPin = 11; // Green LED output pin.
const unsigned long redDuration = 5000; // Red phase duration in milliseconds.
const unsigned long greenDuration = 5000; // Green phase duration in milliseconds.
const unsigned long yellowDuration = 2000; // Yellow phase duration in milliseconds.
void setup() { // Run once at startup.
  pinMode(redPin, OUTPUT); // Configure red LED pin as output.
  pinMode(yellowPin, OUTPUT); // Configure yellow LED pin as output.
  pinMode(greenPin, OUTPUT); // Configure green LED pin as output.
} // End setup.
void loop() { // Repeat the traffic light sequence forever.
  digitalWrite(redPin, HIGH); // Turn red on.
  delay(redDuration); // Keep red on for its set duration.
  digitalWrite(redPin, LOW); // Turn red off.
  digitalWrite(greenPin, HIGH); // Turn green on.
  delay(greenDuration); // Keep green on for its set duration.
  digitalWrite(greenPin, LOW); // Turn green off.
  digitalWrite(yellowPin, HIGH); // Turn yellow on.
  delay(yellowDuration); // Keep yellow on for its set duration.
  digitalWrite(yellowPin, LOW); // Turn yellow off before repeating.
} // End loop.
