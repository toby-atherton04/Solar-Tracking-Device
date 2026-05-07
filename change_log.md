## Change 1 — Improved deadband and Kp

**Script changed:** basic_ldr_tracking.ino  
**Branch used:** improve-script-1-ldr-reading  
**Reason for change:**  
the control was too sensitive and it was moving too slowly so would never settle

**Change made:**  
increced deadband and Kp value

**Impact of change:**  
The test ran smoother and found a stopping place 

**How it was tracked:**  
The change was committed in GitHub

## Change 2 — Added servo safety limits

**Script changed:** dual_axis_tracking.ino  
**Branch used:** improve-script-2-servo-limits  

**Reason for change:**  
The original script did not clearly define safe movement limits for the horizontal and vertical servos. This could allow the servos to attempt to rotate beyond their useful range.

**Change made:**  
Minimum and maximum servo angles were added for both axes.

**How it was tracked:**  
The change was developed in a separate GitHub branch and committed with the message: "Add safe servo limits to dual-axis tracking script".

## Change 3 — Updated Arduino Nano ESP32 pin assignments and comments

**Script changed:** final_nano_esp32_solar_tracker.ino  
**Branch used:** improve-script-3-pin-comments  

**Reason for change:**  
The code needed to be adapted for the Arduino Nano ESP32 board, as the input and output pins had to be clearly assigned for the LDR sensors and servo motors.

**Change made:**  
The pin definitions were updated and comments were added to explain the purpose of the LDR inputs, servo outputs, tuning values, and movement limits.

**Impact of change:**  
The final script became easier to understand, test, and debug. The comments also made it clearer how the hardware connections relate to the software.

**How it was tracked:**  
The update was committed in GitHub with the message: "Update Nano ESP32 pin assignments and code comments".

**Impact of change:**  
The code became safer and more reliable because the servo movement was constrained within a defined range.


