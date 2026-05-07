#include <Servo.h>
Servo servoHoriz;
Servo servoVert;
// Pin Definitions
const int pinTL = A0; // Top Left
const int pinBL = A1; // Bottom Left
const int pinTR = A2; // Top Right
const int pinBR = A3; // Bottom Right
 
// LDR pins are analogue inputs used to measure light intensity.
// Servo pins are outputs used to control the horizontal and vertical movement.
const int pinServHoriz = 9; // Horizontal (Yaw)
const int pinServVert = 8;  // Vertical (Pitch)
// Positions and Tuning
float posHoriz = 90;
float posVert = 90;
int deadband = 40;     // Sensitivity gap
float Kp = 0.005;      // Your preferred slow responsiveness
int updateDelay = 30;  
void setup() {
  Serial.begin(115200);
  // ESP32 Nano native resolution
  analogReadResolution(12); 
  // Attach servos
  servoHoriz.attach(pinServHoriz, 500, 2400);
  servoVert.attach(pinServVert, 500, 2400);
  // Start at centre
  servoHoriz.write(posHoriz);
  servoVert.write(posVert);
  Serial.println("4-LDR Smooth Mode Active");
}
void loop() {
  // 1. Read all four sensors (using the 4095 inversion for brightness)
  int tl = 4095 - analogRead(pinTL);
  int bl = 4095 - analogRead(pinBL);
  int tr = 4095 - analogRead(pinTR);
  int br = 4095 - analogRead(pinBR);
  // 2. Calculate Averages
  int avgTop = (tl + tr) / 2;
  int avgBot = (bl + br) / 2;
  int avgLeft = (tl + bl) / 2;
  int avgRight = (tr + br) / 2;
  // 3. Calculate Errors
  // Horizontal uses Left vs Right
  int errorHoriz = avgLeft - avgRight; 
  // Vertical uses Bottom vs Top (Based on your working 3-LDR logic)
  int errorVert = avgBot - avgTop;
  // 4. Horizontal Movement (Yaw)
  if (abs(errorHoriz) > deadband) {
    posHoriz += (errorHoriz * Kp);
    posHoriz = constrain(posHoriz, 0, 180);
    servoHoriz.write(posHoriz);
  }
  // 5. Vertical Movement (Pitch)
  if (abs(errorVert) > deadband) {
    posVert += (errorVert * Kp);
    posVert = constrain(posVert, 45, 135); 
    servoVert.write(posVert);
  }
  // Debugging Output - Monitor all 4 sensors
  Serial.print("TL:"); Serial.print(tl);
  Serial.print(" BL:"); Serial.print(bl);
  Serial.print(" TR:"); Serial.print(tr);
  Serial.print(" BR:"); Serial.print(br);
  Serial.print(" | H_Pos:"); Serial.print(posHoriz);
  Serial.print(" V_Pos:"); Serial.println(posVert);
  delay(updateDelay);
}
