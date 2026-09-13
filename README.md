<!-- DON'T MODIFY ANYTHING ABOVE -->

<!-- Modify from here -->
<!-- ### EDL 2025 Project Submission Repository.

Change this file to include the relevant information of your project. Refer to SUBMISSION_INSTRUCTIONS.md file and follow it for your final submission. Make sure to pass the GitHub Actions. (The Docs Added should turn green and it should say "passing") -->





https://github.com/user-attachments/assets/5dc95bf6-1b18-49de-8811-edd3fce2244d




# S.N.A.S.H. - Your Friendly Neighbourhood MorphoBot
## MON-10
## Team Members:
- Sthiti Padhi
- Neel Bhavesh Rambhia
- Arin Prashant Weling
- Saumya Dharmesh Shah
- Harshil Singla

## Problem Statement and Solution:
### Problem Statement
Robots designed exclusively for ground travel or aerial operation often encounter significant challenges when faced with unpredictable or mixed environments. Ground-based robots may be unable to overcome obstacles or reach elevated areas, while aerial robots are limited by battery constraints and inefficiency during extended ground operations.

The problem is to create a robotic platform that can seamlessly transition between driving and flying, allowing it to navigate a wide range of terrains and obstacles efficiently. The system should provide the user with the ability to switch modes as needed to maximize energy efficiency and reach locations that would be inaccessible to single-mode robots.

### Solution
We developed **S.N.A.S.H.**, a multi-modal robotic system capable of:

- **Driving**: Increasing battery life and locomotive abilities for ground traversal.
- **Flying**: Quadcopter mode helps navigate over obstacles or difficult terrain.
- **Morphing**: A custom servo setup to switch between drive and drone configurations.

The system is controlled by a single flight controller that dynamically switches outputs to:
- 1 motor driver (controlling two motors via IN1 and two motors via IN2) (drive mode)  
- 4-in-1 ESC on SpeedyBee (flight mode)
- 4 Servo motors from their dedicated PCBs
based on mode-switch commands from the user through the RC transmitter.

### Folder Structure:
```plaintext
/Project-Root
├── /others
    ├── future_work.md/
    ├── learnings_takeaways.md/
    ├── user_manual.md/
    ├── README.md/
 
├── /3d_models               # laser cuts and 3d prints
    ├── Chassis/
    ├── Wheel_Assembly/
    ├── README.md/          
 
├── /pcb                    # pcb design files
    ├── PCB1/
    ├── Resources/
    ├── README.md/

├── /milestone reports

├── /inav

├── /Ardupilot                    # source folder
    ├── ArduCopter/         # we used ArduCopter and added files here
        ├── Copter.cpp
        ├── mode.cpp
        ├── mode_drive.cpp
        ├── mode_morph.cpp
        ├── mode_stabilize.cpp
        ├── README.md/      # describes the changes made, marked as 'EDL-MON10'
        └── ...
    
    ├── ArduPlane/  
    
    ├── ArduRover/
    
    ├── libraries/          # modified hwdef for gpio, default params
        ├── AP_HAL/
        ├── AP_HAL_ChibiOS/
        ├── AP_Motors/      # To use extra motor output or change motor functions - to be done here
        └── ...
    
    ├── modules/            
    
    ├── Tools/              # Developer tools, test scripts, MAVProxy, etc.
    
    ├── build/              # Build scripts and configuration
    
    ├── docs/               # Documentation
    
    ├── wscript             # Waf build system entry point
    └── README.md           # Project overview and setup instructions

```
