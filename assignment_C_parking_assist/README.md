# Assignment C — Smart parking gate and proximity alert

## Parts

Arduino Uno, HC-SR04, servo motor, buzzer, breadboard and jumper wires.

## Wiring

| Component | Pin/terminal | Connect to |
|---|---|---|
| HC-SR04 | VCC / GND | 5V / GND |
| HC-SR04 | TRIG / ECHO | D9 / D10 |
| Buzzer | + / − | D4 / GND |
| Gate servo | Signal | D6 |
| Gate servo | V+ / GND | 5V / GND |

## Problem and operation

The design models a vehicle approaching a parking gate. A valid target below 30 cm opens the gate. From 8 cm up to 30 cm the buzzer gives short proximity beeps; below 8 cm it sounds continuously. At 30 cm or farther, the gate closes and the buzzer is silent. If the sensor times out, the gate stays closed and the serial monitor reports that the reading is unknown. The threshold behaviour is the intended logic; it has not been measured in TinkerCAD here.

## Line-by-line code guide

Every line in `sketch.ino` has an inline comment. The helper returns `-1` on timeout. `setup()` configures the sensor, buzzer and servo. `loop()` handles unknown readings first, then selects the critical alarm, proximity alert, or closed-gate state.

## TinkerCAD evidence

Not simulated here. Use the HC-SR04 component's distance control during simulation to capture one above 30 cm, one between 8 and 30 cm, and one below 8 cm if the simulator supports those cases.
