#include "main.h"

pros::ADIDigitalOut claw ('H');
pros::ADIDigitalOut tilter ('G');
pros::ADIPotentiometer pot ('A');
pros::Motor lift(11, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);