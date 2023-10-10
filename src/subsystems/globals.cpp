#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "subsystemHeaders/flywheel.hpp"
#include <cstddef>

pros::Motor lB(5, pros::E_MOTOR_GEARSET_06, true);
pros::Motor lM(4, pros::E_MOTOR_GEARSET_06, true);
// pros::Motor lMb(16, pros::E_MOTOR_GEARSET_18, false);
pros::Motor lF(6, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rB(15, pros::E_MOTOR_GEARSET_06, false);
pros::Motor rM(14, pros::E_MOTOR_GEARSET_06, false);
// pros::Motor rMb(14, pros::E_MOTOR_GEARSET_18, true);
pros::Motor rF(16, pros::E_MOTOR_GEARSET_06, false);

pros::MotorGroup left_motors({lF, lM, lB});
pros::MotorGroup right_motors({rF, rM, rB});

// pros::Motor intake(1, pros::E_MOTOR_GEARSET_18, true);
// pros::Motor intake_2(3, pros::E_MOTOR_GEARSET_18, false);

pros::Motor catapult(0, pros::E_MOTOR_GEARSET_36, false);

pros::Motor fw(17, pros::E_MOTOR_GEARSET_06, true);

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Imu inertial_sensor(18);

pros::Rotation arm_rot(20);

pros::ADIDigitalIn limit('O');

pros::Motor arm(9, pros::E_MOTOR_GEARSET_36, true);


lemlib::Drivetrain_t drivetrain {
    &left_motors,
    &right_motors,
    15, // tracking width
    3.25,  // wheel diameter
    360 // wheel rpm
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

Flywheel_Controller flywheel(2.3, 0.023,0, 0.95);

lemlib::Chassis eason(drivetrain, lateralController, angularController, sensors);

pros::ADIDigitalOut hook('O', LOW);
pros::ADIDigitalOut wings_L('H', LOW);
pros::ADIDigitalOut wings_R('C', LOW);
pros::ADIDigitalOut clamp('O', LOW);

