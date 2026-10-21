# Assignment A — 6-DOF arm

## Parts

Arduino Uno, six servo motors, six potentiometers, breadboard and jumper wires.

## Wiring

| Component | Pin/terminal | Connect to |
|---|---|---|
| Base servo | Signal | D3 |
| Shoulder servo | Signal | D5 |
| Elbow servo | Signal | D6 |
| Wrist pitch servo | Signal | D9 |
| Wrist roll servo | Signal | D10 |
| Gripper servo | Signal | D11 |
| Each servo | V+ / GND | 5V / GND |
| Pots 1–6 | Outer terminals | 5V and GND (either orientation; it changes direction) |
| Pots 1–6 | Wiper/middle terminal | A0, A1, A2, A3, A4, A5 respectively |

## How it works

Each analogue input ranges from 0–1023 and `map()` converts it to 0–180. Each servo receives the paired angle. This is a six-input/six-actuator position controller; the simulated servos are independent. On physical hardware, six servos should use a separate supply sized for stall current and share ground with the Uno.

## Line-by-line code guide

Inline comments annotate every source line. The arrays pair servo pins, pot pins, and readable joint names by the same index. The loop reads each pot, maps its range, writes the angle and reports it over serial.

## TinkerCAD evidence

Not built or simulated here. In TinkerCAD choose the Servo component and connect all three leads for every servo. See the root screenshot checklist.
