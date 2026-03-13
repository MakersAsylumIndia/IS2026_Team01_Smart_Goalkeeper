#include <Servo.h>

Servo myServo;

int joystickX = A0;   // VRx pin of joystick
int servoPin = 9;

int joyValue;
int servoAngle;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  joyValue = analogRead(joystickX);      // Read joystick value (0-1023)

  servoAngle = map(joyValue, 0, 1023, 0, 180);   // Convert to servo angle

  myServo.write(servoAngle);             // Move servo

  delay(10); // small delay for stability
}