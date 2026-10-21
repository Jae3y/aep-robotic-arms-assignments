# Week 2 — Traffic light

Build in TinkerCAD Circuits with an Arduino Uno, red, yellow and green LEDs, and one 220 Ω resistor per LED.

## Wiring

- Red LED anode to D13 through a 220 Ω resistor.
- Yellow LED anode to D12 through a 220 Ω resistor.
- Green LED anode to D11 through a 220 Ω resistor.
- Connect every LED cathode to GND.

## Code walkthrough

- `RED`, `YELLOW`, and `GREEN` assign the required pins.
- `setup()` configures all three pins as outputs.
- `loop()` turns on red for 5 seconds, green for 5 seconds, then yellow for 2 seconds.
- Each LED is turned off before the next phase, and the loop repeats continuously.
- `delay()` provides the requested timed sequence while the sketch waits.

Capture a TinkerCAD simulator screenshot after confirming the sequence changes in order.
