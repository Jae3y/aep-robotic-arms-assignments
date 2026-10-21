// Assignment A: six potentiometers directly command six servo joints.
#include <Servo.h> // Include Arduino's built-in Servo library.
const byte jointCount = 6; // Number of controlled joints.
Servo joints[jointCount]; // Create one Servo object for each joint.
const byte servoPins[jointCount] = {3, 5, 6, 9, 10, 11}; // Servo signal pins in joint order.
const byte potPins[jointCount] = {A0, A1, A2, A3, A4, A5}; // Potentiometer wiper pins in joint order.
const char *jointNames[jointCount] = {"base", "shoulder", "elbow", "wrist_pitch", "wrist_roll", "gripper"}; // Labels for serial output.
void setup() { // Run once at startup.
  Serial.begin(9600); // Start the serial monitor output.
  for (byte i = 0; i < jointCount; i++) { // Visit each joint index.
    joints[i].attach(servoPins[i]); // Connect that servo object to its signal pin.
  } // End servo attachment loop.
} // End setup.
void loop() { // Continuously read all six controls.
  for (byte i = 0; i < jointCount; i++) { // Visit each potentiometer and servo pair.
    int rawValue = analogRead(potPins[i]); // Read the potentiometer from 0 through 1023.
    int angle = map(rawValue, 0, 1023, 0, 180); // Convert the reading to a 0 through 180 degree command.
    joints[i].write(angle); // Command the matching servo to the mapped angle.
    Serial.print(jointNames[i]); // Print the joint label.
    Serial.print('='); // Separate the label from its angle.
    Serial.print(angle); // Print the commanded angle in degrees.
    Serial.print(i == jointCount - 1 ? '\n' : ','); // End the row or separate it from the next joint.
  } // End joint-reading loop.
  delay(15); // Allow servo commands time to update before the next pass.
} // End loop.
