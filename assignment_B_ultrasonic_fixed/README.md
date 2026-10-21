# Assignment B — Fix the Class 4 ultrasonic sketch

## Parts and wiring

| Component | Pin/terminal | Connect to |
|---|---|---|
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| HC-SR04 | TRIG | D9 |
| HC-SR04 | ECHO | D10 |

Parts: Arduino Uno and HC-SR04 ultrasonic distance sensor.

## Bug and fix

The original class sketch called `NewPing` and `sonar.ping_cm()`. The handoff reports that TinkerCAD does not provide NewPing, so that sketch cannot compile there. This version removes the dependency, triggers the sensor directly, and measures the echo with Arduino's `pulseIn()`. It also handles `pulseIn()` returning zero on timeout explicitly; displaying zero centimetres would falsely imply an object touching the sensor.

## How it works

The Uno sends a 10 μs pulse on TRIG. The sensor raises ECHO for the sound's round-trip time. At roughly 0.0343 cm/μs, distance is `time × 0.0343 ÷ 2`. The timeout is approximately the round-trip time at 200 cm (200 × 58 μs). The result is an estimate, not a calibrated measurement.

## Line-by-line code guide

Every source line has an inline comment. Pin constants identify the sensor connections; `setup()` starts serial and configures pin directions; `loop()` generates the trigger pulse, performs the bounded echo read, reports timeout or converts and prints a valid distance, then waits 250 ms.

## TinkerCAD evidence

Not simulated here. A screenshot should show the sensor wiring and serial output including a changed target distance. See the root checklist.
