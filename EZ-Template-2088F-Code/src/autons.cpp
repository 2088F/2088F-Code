#include "main.h"
#include "extern.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}


void skills_auton() {
    // START tilt blue goal
  chassis.set_drive_pid(-7, 110);
  chassis.wait_drive();

  tilter.set_value(true);
  pros::delay(500);

  chassis.set_drive_pid(7, 110);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 103, 90);
  chassis.wait_drive();
  // END tilt blue goal


  // START clamp yellow goal
  chassis.set_drive_pid(42.0, 104);
  chassis.wait_drive();

  claw.set_value(true);
  pros::delay(150);

  chassis.set_drive_pid(49, 110);
  chassis.wait_drive();
  // END clamp yellow goal


  // START claw false yellow goal
  chassis.set_turn_pid(180, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(25, 110);
  chassis.wait_drive();

  claw.set_value(false);

  chassis.set_drive_pid(-15, 110);
  chassis.wait_drive();
  // END claw false yellow goal


  // START tilt false blue goal
  chassis.set_turn_pid(-180, 90);
  chassis.wait_drive();

  tilter.set_value(false);
  // // END tilt false blue goal


  // START tilt red goal
  chassis.set_drive_pid(30, 110);
  chassis.wait_drive();
}

void mGoal_auton() {
  chassis.set_drive_pid(10, 127);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 35, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(51, 127);
  chassis.wait_drive();

  claw.set_value(true);

  chassis.set_drive_pid(-57, 127);
  chassis.wait_drive();

  chassis.reset_gyro();

  chassis.set_turn_pid(-100, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-18, 110);
  chassis.wait_drive();
  
  tilter.set_value(true);
}

void 