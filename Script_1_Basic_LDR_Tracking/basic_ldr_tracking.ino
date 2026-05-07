#include <Servo.h>
 
Servo myServo;
 
 
 
int leftPin = A1;
 
int rightPin = A2;
 
int servoPos = 90;
 
 
 
// TUNING PARAMETERS
 
int deadband = 5;    // Lowered for higher sensitivity
 
float Kp = 0.05;      // Increased for more decisive movement
 
 
 
void setup() {
 
  Serial.begin(115200);
 
  analogReadResolution(10); // Standardises sensor range to 0-1023
 
  myServo.attach(9);
 
  myServo.write(servoPos);
 
}
 
 
 
void loop() {
 
  int leftVal = analogRead(leftPin);
 
  int rightVal = analogRead(rightPin);
 
  int error = leftVal - rightVal;
 
 
 
  if (abs(error) > deadband) {
 
    servoPos += Kp * error;
 
    servoPos = constrain(servoPos, 0, 180);
 
    myServo.write(servoPos);
 
  }
 
 
 
  // Monitor these numbers!
 
  // If the Diff is smaller than your deadband, it won't move.
 
  Serial.print("L:"); Serial.print(leftVal);
 
  Serial.print(" R:"); Serial.print(rightVal);
 
  Serial.print(" Diff:"); Serial.print(error);
 
  Serial.print(" Pos:"); Serial.println(servoPos);
 
 
 
  delay(50); // Faster updates for better sensitivity
 
}
