#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "subsystemHeaders/flywheel.hpp"
#include <cstddef>

pros::Motor lB(0, pros::E_MOTOR_GEARSET_18, true);
pros::Motor lMf(0, pros::E_MOTOR_GEARSET_18, true);
pros::Motor lMb(0, pros::E_MOTOR_GEARSET_18, true);
pros::Motor lF(0, pros::E_MOTOR_GEARSET_18, true);
pros::Motor rB(0, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rMf(0, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rMb(0, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rF(0, pros::E_MOTOR_GEARSET_18, false);

pros::MotorGroup left_motors({lF, lMf, lMb, lB});
pros::MotorGroup right_motors({rF, rMf, rMb, rB});

// pros::Motor intake(1, pros::E_MOTOR_GEARSET_18, true);
// pros::Motor intake_2(3, pros::E_MOTOR_GEARSET_18, false);

pros::Motor catapult(2, pros::E_MOTOR_GEARSET_36, false);

pros::Motor fw(18, pros::E_MOTOR_GEARSET_06, true);

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Imu inertial_sensor(5);

pros::ADIDigitalIn limit('D');


lemlib::Drivetrain_t drivetrain {
    &left_motors,
    &right_motors,
    15, // tracking width
    3.25,  // wheel diameter
    333 // wheel rpm
};

lemlib::OdomSensors_t sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &inertial_sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    3, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

// turning PID
lemlib::ChassisController_t angularController {
    3.3, // kP
    23, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

Flywheel_Controller flywheel(4, 0.4,19291, 0);

lemlib::Chassis eason(drivetrain, lateralController, angularController, sensors);

pros::ADIDigitalOut hook('A', LOW);
pros::ADIDigitalOut wings('B', LOW);
pros::ADIDigitalOut clamp('C', LOW);

