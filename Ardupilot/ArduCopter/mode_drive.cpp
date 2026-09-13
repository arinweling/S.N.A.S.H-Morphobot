#include "Copter.h"

//#include "AP_Math.h"  // Ensure you include this

/*
 * Init and run calls drive mode
 */
bool ModeDrive::init(bool ignore_checks) 
{
    // motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
        motors->rc_write(1, 0);
        motors->rc_write(2, 0);
        motors->rc_write(3, 0);
        motors->rc_write(4, 0);
        // Print debug information to SITL 
    return true;
}

// stabilize_run - runs the main stabilize controller
// should be called at 100hz or more
void ModeDrive::run()
{
    // apply simple mode transform to pilot inputs
    update_simple_mode();
        motors->rc_write(1, 0);
        motors->rc_write(2, 0);
        motors->rc_write(3, 0);
        motors->rc_write(4, 0);

        // Define PWM thresholds (these depend on RC calibration)
    // constexpr int16_t YAW_CENTER = 1500;  // Neutral position
    // constexpr int16_t DEADZONE = 50;      // Small buffer to avoid unintended movement
    // constexpr int16_t YAW_LEFT = 1300;    // Example left turn threshold
    // constexpr int16_t YAW_RIGHT = 1700;   // Example right turn threshold

    //uint16_t speed_min = 0000;  // Get servo_min (PWM min)
    //uint16_t speed_max = 2000;  // Get servo_max (PWM max)

    // convert pilot input to lean angles
    // float target_roll, target_pitch;
    // get_pilot_desired_lean_angles(target_roll, target_pitch, copter.aparm.angle_max, copter.aparm.angle_max);

    // get pilot's desired yaw rate
    //hal.console->printf("ModeDrive Running...\n");
    float target_left_right = channel_yaw->get_radio_in();
    float rover_forward = channel_throttle->get_radio_in(); 

    rover_forward = constrain_int16(rover_forward,0,2000);
    target_left_right = constrain_int16(target_left_right, 0, 2000);
    // int calc_final_pwm = rover_forward;
    // // calc_final_pwm = AP_Math::constrain(rover_forward, 1000, 2000);
    // calc_final_pwm = (rover_forward<2000? (rover_forward>1000? rover_forward: 1000) : 2000);
    // int pwm = AP_Math::constrain(target_left_right, 1000, 2000);


    // if (rover_forward > 1500) {
    //     motors->rc_write(4, calc_final_pwm);
    //     motors->rc_write(5, 0);
    //     motors->rc_write(6, calc_final_pwm);
    //     motors->rc_write(7, 0);
    //     hal.console->printf("Target Left/Right: %.2f, Rover Forward: %.2f, PWM: %d\n", 
    //                     target_left_right, rover_forward, calc_final_pwm);
    // } 

    // else
    // {
    //     motors->rc_write(4, 0);
    //     motors->rc_write(5, 0);
    //     motors->rc_write(6, 0);
    //     motors->rc_write(7, 0);
    // }
    // }
    // int pwm = target_left_right; // multipled by const. factor
    // pwm = (target_left_right<2000? (target_left_right>1000? target_left_right: 1000) : 2000);
    //float left_speed = rover_forward -target_left_right;
    //float right_speed = rover_forward + target_left_right;

    if(950<target_left_right && target_left_right<1050)
    {
        u_int16_t a = (rover_forward>1000? 2*(rover_forward-1000) : 0);
        u_int16_t b = (rover_forward>1000? 0 : 2*(1000-rover_forward));

        motors->rc_write(4, a);
        motors->rc_write(5, b);
        motors->rc_write(6, a);
        motors->rc_write(7, b);
    }

    if(950>=target_left_right) //left
    {
        u_int16_t val1 = rover_forward-1000;
        u_int16_t val2 = 1000 - rover_forward ;
        u_int16_t a = (rover_forward>1000? val1*2 : 0);
        u_int16_t b = (rover_forward>1000? 0 : val2*2);

        motors->rc_write(4, a);
        motors->rc_write(5, b);
        motors->rc_write(6, b);
        motors->rc_write(7, a);
    }

    if(target_left_right>=1050) //right
    {
        u_int16_t a = (rover_forward>1000? (rover_forward-1000)*2 : 0);
        u_int16_t b = (rover_forward>1000? 0 : (1000-rover_forward)*2);

        motors->rc_write(4, b);
        motors->rc_write(5, a);
        motors->rc_write(6, a);
        motors->rc_write(7, b);
    }
        // Print debug information to SITL console
        //hal.console->printf("Target Left/Right: %.2f, Rover Forward: %.2f, Left PWM: %.2f Right PWM: %.2f\n", target_left_right, rover_forward, left_speed, right_speed);
    // }

    // else if (target_left_right < (YAW_CENTER + DEADZONE)){

    //     //int pwm = target_left_right; // multipled by const. factor
    //     motors->rc_write(4, pwm);
    //     motors->rc_write(5, 0);
    //     motors->rc_write(7, pwm);
    //     motors->rc_write(6, 0);

    //         }
    // else{
    //     if (rover_forward > 500){
    //                 motors->rc_write(4, calc_final_pwm);
    //         motors->rc_write(5, 0);
    //         motors->rc_write(6, calc_final_pwm);
    //         motors->rc_write(7, 0);
    //         hal.console->printf("Target Left/Right: %.2f, Rover Forward: %.2f, PWM: %d\n", 
    //                         target_left_right, rover_forward, calc_final_pwm);

    //     }
    //         else
    //     {
    //         motors->rc_write(4, 0);
    //         motors->rc_write(5, 0);
    //         motors->rc_write(6, 0);
    //         motors->rc_write(7, 0);
    //     }
    // }
    
    // can I use this for speed? Is pwm single going to be according to the throttle set? - Sthiti


}
