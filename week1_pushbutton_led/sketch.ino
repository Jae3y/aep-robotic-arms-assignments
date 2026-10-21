// AEP Week 1: Pushbutton controls an external LED on Arduino Uno.
const byte ledPin = 13; // The external LED is connected through a 220 ohm resistor.
const byte buttonPin = 2; // The button connects D2 to GND when pressed.
int buttonState = HIGH; // Store the current input state; HIGH means released.
int lastButtonState = HIGH; // Store the prior state to print only on changes.
void setup() { // Run once when the Arduino starts.
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output.
  pinMode(buttonPin, INPUT_PULLUP); // Enable the internal pullup for a stable released state.
  Serial.begin(9600); // Start serial output at 9600 baud.
} // End setup.
void loop() { // Repeat the input check.
  buttonState = digitalRead(buttonPin); // Read LOW when pressed and HIGH when released.
  bool pressed = (buttonState == LOW); // Convert the active-low input to a pressed flag.
  digitalWrite(ledPin, pressed ? HIGH : LOW); // Turn the LED on only while pressed.
  if (buttonState != lastButtonState) { // Check for a press or release transition.
    if (pressed) { // Handle the pressed transition.
      Serial.println("Button Pressed! LED turned ON."); // Report the pressed state.
    } else { // Handle the released transition.
      Serial.println("Button Released! LED turned OFF."); // Report the released state.
    } // End state message selection.
    lastButtonState = buttonState; // Save the state for the next loop.
  } // End change check.
  delay(20); // Debounce the button and limit repeated reads.
} // End loop.
