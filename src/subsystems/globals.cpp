#include "main.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Motor lB(1, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lF(2, pros::E_MOTOR_GEARSET_06, false);
pros::Motor rB(3, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rF(4, pros::E_MOTOR_GEARSET_06, true);

pros::MotorGroup left_motors({lF, lB});
pros::MotorGroup right_motors({rF, rB});

pros::Motor fw(5, pros::E_MOTOR_GEARSET_06, false);