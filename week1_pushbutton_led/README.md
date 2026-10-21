# Week 1 — Pushbutton LED

Build in TinkerCAD Circuits with an Arduino Uno, one LED, a 220 Ω resistor, a momentary pushbutton, and jumper wires.

## Wiring

- LED anode to D13 through the 220 Ω resistor; LED cathode to GND.
- Pushbutton between D2 and GND. The sketch uses `INPUT_PULLUP`, so no external pull-down resistor is needed.

## Code walkthrough

- `ledPin` and `buttonPin` name the two digital pins.
- `buttonState` and `lastButtonState` hold the current and previous active-low button values.
- `setup()` sets D13 as output, D2 as `INPUT_PULLUP`, and starts serial output at 9600 baud.
- `loop()` reads D2. LOW means pressed; HIGH means released.
- `digitalWrite()` turns the LED on only while the button is pressed.
- The state-change check prints one message per press or release instead of flooding the monitor.
- The 20 ms delay provides simple debounce.

The sketch starts with the LED off and should print a press/release transition when the button state changes. Capture a TinkerCAD simulator screenshot only after checking that response.
