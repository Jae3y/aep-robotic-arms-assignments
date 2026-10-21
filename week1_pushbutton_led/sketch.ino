// AEP Week 1: Pushbutton controls an external LED on Arduino Uno.
const byte ledPin = 13; // External LED anode goes to D13 through a 220 ohm resistor.
const byte buttonPin = 2; // Button input is D2 with an external 10k pulldown.
int buttonState = LOW; // Store the most recently read button level.
int lastButtonState = LOW; // Store the previous level so messages print only on changes.
void setup() { // Run setup once after the board starts.
  pinMode(ledPin, OUTPUT); // Configure the LED pin as an output.
  pinMode(buttonPin, INPUT); // Configure the pulled-down button pin as an input.
  Serial.begin(9600); // Start serial output at 9600 baud.
} // End setup.
void loop() { // Repeat button monitoring continuously.
  buttonState = digitalRead(buttonPin); // Read HIGH when pressed and LOW when released.
  digitalWrite(ledPin, buttonState); // Match LED state to the button state.
  if (buttonState != lastButtonState) { // Print only when the button changes state.
    if (buttonState == HIGH) { // Check whether the button is now pressed.
      Serial.println("Button Pressed! LED turned ON."); // Report the pressed state.
    } else { // The changed state is released.
      Serial.println("Button Released! LED turned OFF."); // Report the released state.
    } // End pressed/released choice.
    lastButtonState = buttonState; // Save this state for the next loop pass.
  } // End state-change check.
  delay(20); // Debounce the mechanical button and reduce repeated reads.
} // End loop.
