#include <Servo.h>
Servo servoHoriz;
Servo servoVert;
const int pinTL = A0; // LDR pins
const int pinBL = A1;
const int pinTR = A2;
const int pinServHoriz = 9; // servo pins
const int pinServVert = 8;  
 
// Servo limits are used to prevent the motors moving beyond their safe range. 
const int H_MIN = 5;
const int H_MAX = 175;
const int V_MIN = 5;
const int V_MAX = 100;
 
float posHoriz = 90;
float posVert = 90;
int deadband = 40;     // change if jittering
float Kp = 0.001;      //change if moving too fast
int updateDelay = 30;  
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  servoHoriz.attach(pinServHoriz, 500, 2400);
  servoVert.attach(pinServVert, 500, 2400);
  servoHoriz.write(posHoriz);
  servoVert.write(posVert);
  Serial.println("3-LDR Mode: Horizontal Direction Corrected");
}
void loop() {
  // Read sensors
  int tl = 4095 - analogRead(pinTL);
  int bl = 4095 - analogRead(pinBL);
  int tr = 4095 - analogRead(pinTR);
  // Error Calculation
  int errorHoriz = tl - tr;
  int errorVert = bl - tl;
  // Horizontal Movement
  if (abs(errorHoriz) > deadband) {
    posHoriz += (errorHoriz * Kp);
    posHoriz = constrain(posHoriz, 0, 180);
    servoHoriz.write(posHoriz);
  }
  // Vertical Movement
  if (abs(errorVert) > deadband) {
    posVert += (errorVert * Kp);
    posVert = constrain(posVert, 45, 135);
    servoVert.write(posVert);
  }
  // Testing/Debugging
  Serial.print("TL:"); Serial.print(tl);
  Serial.print(" BL:"); Serial.print(bl);
  Serial.print(" TR:"); Serial.print(tr);
  Serial.print(" | H_Pos:"); Serial.print(posHoriz);
  Serial.print(" V_Pos:"); Serial.println(posVert);
  delay(updateDelay);
}
