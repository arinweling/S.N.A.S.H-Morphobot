## Description

The PCB has two Buck regulator IC's (LMR14050) that step down the voltage from 14.8V-16.8V (4S LiPo Battery) to 7.4V in order to power the Servo Motors. Since there are 4 servo motors, two PCB's (and thus 4 IC's) are used for the same. The circuit is simply designed from the datasheet specifications given. 

The PCB was designed on KiCad 8.0 and maufactured from PCB Power (external vendor) since via size on IC footprint was quite small.


## How to use this directory

Download or clone this repository to get all the necessary files. Edit the "fp-lib-table" and "sym-lib-table" files to include _your_ path for the symbols and footprints required. All symbol and footprint files are within the "Resources" directory.


## Quick Verification of the PCB after Manufacturing

Testpoints are provided on the PCB for quick verification of the output voltage. LED's are also present and can be used as a visual indicator but not necessarily reliable (a range of voltage will turn it on, you can't assume it is 7.4V only). Also, the LED is optional and may be removed or not soldered and the PCB would work fine.


## Calculations for the circuit

#### LMR14050 Buck Switching Regulator IC  

Input Voltage - 14.8V 

Output Voltage - 7.4V 

Max Output Current - 3.8A 

Transient Response - 5% 

Soft-Start time - 5ms 

#### Output Voltage Setpoint: 

R_FBT = (14.8-0.75)/0.75 * R_FBB 

So, R_FBT = 160k & R_FBB = 18k 

#### Output Inductor Selection: 

L=4.7uH (available from WEL) 

Lmin =  [(14.8-7.4)/(3.8*0.4)] * [7.4/(14.8*f)] = 2.4342 / f 

For Lmin = 4.7uH => f = 517kHz 

Take Switching Frequency 750kHz => Lmin = 3.24uH 

#### Switching Frequency: 

f = 750kHz 

R_T = 32.4k 

Closest available R_T = 33k => f=732kHz 

#### Output Capacitor: 
100uF (25V) x2 in Parallel 

#### Schottky Diode: 
5-6A rated Schottky diode 

<https://www.googleadservices.com/pagead/aclk?sa=L&ai=DChcSEwi1pe33-riLAxV_p2YCHWZMDQwYABADGgJzbQ&ae=2&aspm=1&co=1&ase=5&gclid=CjwKCAiA5Ka9BhB5EiwA1ZVtvMta-bck2QZtikhFSwPQNB7W7tcWDABVQjyAaNMlUeXBK18xhEKkKRoCkBsQAvD_BwE&ohost=www.google.com&cid=CAESVeD2yFSM_nJpq_IPCykuUYeB5w_LyxcPm_9DhT0_zzm2AJfOdDbZZ1pPT8ZjT5nLCw1axiebZy9D2vHVyNDqCvjmDnesfMkeMb1UFT9ZSRDTL9Qf3vY&sig=AOD64_19A6xZXjguXm5rXCT6MYhL_5oAdA&ctype=5&q=&ved=2ahUKEwjA1Of3-riLAxWlRWwGHe09F8AQ9aACKAB6BAgCEA8&adurl=>

#### Input capacitor: 
10uF (35V) + 0.1uF for high frequency filtering 

#### Bootstrap: 
0.1uF (16V) 


## Testing Plan

1. Solder only one IC and test it before soldering the other one 
2. Use DC Power Supply and give 14.8V input voltage in CV mode by attaching to XT60 using alligator clips 
3. Attach a high resistance (10kOhm) to output and turn on the power supply (LED should light up) 
4. Check VIN and GND test points to confirm 14.8V and 0V 
5. Check VOUT test point to confirm 7.4V 
6. Decrease resistance to check performance when higher current is drawn 
7. Decrease resistance till 2.2 Ohm (use power resistor since current capacity is exceeded at such low resistance 
8. Apply a PWM signal to center jumper (J4) and check the signal using oscilloscope on Pin1 of J2 and J3 
9. Remove power supply and attach 4S LiPo battery. Check the output voltage again and performance with 2.2Ohm again 
10. Remove resistor and attach servo motor. Give a PWM using any simple microcontroller and check correct functioning. 
11. Attach the servo arm and apply heavy load to make the servo motor stall. Check that IC is working properly even when stalling. 
12. Repeat for 2nd IC. 
