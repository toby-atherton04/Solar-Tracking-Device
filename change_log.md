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

**Impact of change:**  
The code became safer and more reliable because the servo movement was constrained within a defined range.

**How it was tracked:**  
The change was developed in a separate GitHub branch and committed with the message: "Add safe servo limits to dual-axis tracking script".
