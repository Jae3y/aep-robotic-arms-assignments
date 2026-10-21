// Assignment C: ultrasonic parking gate with a servo actuator and warning buzzer.
#include <Servo.h> // Include Arduino's built-in Servo library.
Servo gateServo; // Create the gate servo controller.
const byte trigPin = 9; // HC-SR04 trigger pin.
const byte echoPin = 10; // HC-SR04 echo pin.
const byte buzzerPin = 4; // Buzzer output pin.
const byte gateServoPin = 6; // Gate servo signal pin.
const int openThresholdCm = 30; // Open the gate when a target is closer than this distance.
const int alarmThresholdCm = 8; // Use a continuous alarm below this distance.
long readDistanceCm() { // Measure and return distance in centimetres, or -1 on timeout.
  digitalWrite(trigPin, LOW); // Ensure a clean trigger start.
  delayMicroseconds(2); // Hold the trigger low briefly.
  digitalWrite(trigPin, HIGH); // Start the trigger pulse.
  delayMicroseconds(10); // Hold the trigger high for 10 microseconds.
  digitalWrite(trigPin, LOW); // End the trigger pulse.
  unsigned long echoTimeUs = pulseIn(echoPin, HIGH, 30000UL); // Measure the echo with a 30 ms timeout.
  if (echoTimeUs == 0) { // Check for missing echo.
    return -1; // Return an invalid-distance marker.
  } // End timeout check.
  return (long)(echoTimeUs * 0.0343f / 2.0f); // Convert round-trip duration to approximate centimetres.
} // End distance function.
void setup() { // Configure the circuit once.
  pinMode(trigPin, OUTPUT); // Configure sensor trigger output.
  pinMode(echoPin, INPUT); // Configure sensor echo input.
  pinMode(buzzerPin, OUTPUT); // Configure buzzer output.
  gateServo.attach(gateServoPin); // Attach the gate servo signal.
  gateServo.write(0); // Start with the gate closed.
  Serial.begin(9600); // Start serial status output.
} // End setup.
void loop() { // Repeatedly sense and control the gate.
  long distanceCm = readDistanceCm(); // Get the latest distance or timeout marker.
  if (distanceCm < 0) { // Treat a timeout as unknown, not a nearby obstacle.
    gateServo.write(0); // Keep the gate closed when distance is unknown.
    noTone(buzzerPin); // Silence the buzzer when there is no valid reading.
    Serial.println("No echo; gate held closed."); // Report sensor timeout clearly.
    delay(100); // Pause briefly before retrying.
    return; // Begin the next loop iteration.
  } // End timeout handling.
  Serial.print("distance_cm="); // Print a label for the range reading.
  Serial.println(distanceCm); // Print the measured distance.
  if (distanceCm < alarmThresholdCm) { // Check for the immediate hazard zone.
    gateServo.write(90); // Open the gate in response to an approaching vehicle.
    tone(buzzerPin, 1500); // Sound a continuous 1500 Hz warning.
    delay(50); // Keep the loop responsive while maintaining the alarm.
  } else if (distanceCm < openThresholdCm) { // Check for the gate-opening range.
    gateServo.write(90); // Open the gate.
    noTone(buzzerPin); // Silence the critical alarm outside its threshold.
    tone(buzzerPin, 1000, 80); // Give a short proximity beep.
    delay((unsigned long)map(distanceCm, alarmThresholdCm, openThresholdCm, 80, 500)); // Beep more slowly farther from the gate.
  } else { // The target is at least the opening threshold away.
    gateServo.write(0); // Close the gate.
    noTone(buzzerPin); // Turn off the warning buzzer.
    delay(100); // Limit sensor polling rate.
  } // End distance-range decision.
} // End loop.
