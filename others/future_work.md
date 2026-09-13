## Improvements to the Morphobot
1. The flange bearing is the ‘weakest link’ in the morphobot. The bearing rotates smoothly in the direction it is supposed to but slightly moves in the perpendicular direction as well, causing the wheel to move sideways and potential out of the small gear. Any improvements in this aspect would be very impactful to the overall mechanical stability.
2. Currently we are using only SpeedyBee pins M6 and M8 and pairing up the servo motors. We can independently control all the servo motors using pins M6, M7, M8, S9. This way the alignment of the legs will become more accurate.
.3 All the servo motors currently use their own Buck IC for power but after doing current consumption analysis in normal and stall conditions, a single IC may be used to power multiple servos. It is also possible that the servo doesn't enter stall mode during any mode and thus required current will be very less so we can directly power all servos using a single IC but give different PWM for control.
4. Add servo plates or latching mechanisms as a safety feature to the morphobot to prevent the legs from deviating from the required 90 degree position.
5. Taking left and right turns in the drive mode can be smoothened out further by giving different speeds to the two sides. This can be done by using another PWM output.
6. The flight time can be increased by using a battery with higher mAh, keeping the weight constraints in mind.
7. The entire MorphoBot can potentially be scaled down if someone wants to create an even miniature version. Our weight estimate was 3kg but it turned out to be only around 2kg. So, there is scope to scale down the size to around half of what it is right now.

## Optional Nice to have features
1. Addition of FPV camera or GPS module
2. Making the morphobot completely autonomous by integration of RaspberryPi or Jetson Nano
3. Further modes could be added to the bot such as crawling, standing/ walking on two wheels, etc.
4. A standard electrical and mechanical interface can be added to make it like Boston Dynamic's Spot. Spot is a robot dog with an interface on top where one can easily attach any payload for their specific application.
