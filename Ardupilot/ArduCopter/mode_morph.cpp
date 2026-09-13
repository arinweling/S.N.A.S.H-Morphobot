#include "Copter.h"

//#include "AP_Math.h"  // Ensure you include this

/*
 * Init and run calls for stabilize flight mode
 */

// stabilize_run - runs the main stabilize controller
// should be called at 100hz or more
void ModeMorph::run()
{
    // apply simple mode transform to pilot inputs
    static uint32_t start_time ;
    
    //SRV_Channels::set_aux_channel_default(SRV_Channel::k_none, 5);
      // Use the getter
    /*
    // Disable all motors
    SRV_Channels::enable_by_mask(0b00000000);
    gcs_send_text(MAV_SEVERITY_INFO, "Diasable M1-M8");

    // Set PWM to 1000µs (OFF) for all motors
    for (uint8_t chan = 0; chan < 8; chan++) {
        SRV_Channels::set_output_pwm_chan(chan, 1000);
    }
    gcs_send_text(MAV_SEVERITY_INFO, "Stopped all motors");
    */
    // Determine Servo Rotation Based on Previous Mode
    for (int i = 0; i<9; i++) 
        motors->rc_write(i,0);

//   start_time = AP_HAL::millis(); // Record start time
// if (AP_HAL::millis() - start_time < 2000) {
//     // Wait for 2 seconds before executing the next step
//     return;
// }


    if(copter.was_drive_mode) {
        SRV_Channels::set_output_pwm_chan(9, 1500);  // Rotate +90°
       // sleep(2);
       start_time = AP_HAL::millis(); 
       if (AP_HAL::millis() - start_time < 2000) {
    // Wait for 2 seconds before executing the next step
        return;}
        for (int i = 4; i<9; i++) {
        motors->rc_write(i,0);
        motors->rc_write(8-i,1000);
        }
        //gcs_send_text(MAV_SEVERITY_INFO, "Morph Mode: Rotating +90°");
    }
    
    else{
        SRV_Channels::set_output_pwm_chan(9, 500);  // Rotate -90°
        //gcs_send_text(MAV_SEVERITY_INFO, "Morph Mode: Rotating -90°");
       start_time = AP_HAL::millis(); 
       if (AP_HAL::millis() - start_time < 2000) {
    // Wait for 2 seconds before executing the next step
        return;}
         for (int i = 4; i<9; i++) {
        motors->rc_write(8-i,0);
        motors->rc_write(i,1000);
        }
    }
}
