#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include <cstddef>

pros::Motor lB(1, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lF(2, pros::E_MOTOR_GEARSET_06, false);
pros::Motor rB(3, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rF(4, pros::E_MOTOR_GEARSET_06, true);

pros::MotorGroup left_motors({lF, lB});
pros::MotorGroup right_motors({rF, rB});

pros::Motor intake(6, pros::E_MOTOR_GEARSET_06, false);

pros::Motor fw(5, pros::E_MOTOR_GEARSET_06, false);

Flywheel_Controller flywheel(0, 0, 0);

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Imu imu(9);


lemlib::Drivetrain_t drivetrain {
    &left_motors,
    &right_motors,
    10, // tracking width
    4,  // wheel diameter
    360 // wheel rpm
};

lemlib::OdomSensors_t sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis eason(drivetrain, lateralController, angularController, sensors);