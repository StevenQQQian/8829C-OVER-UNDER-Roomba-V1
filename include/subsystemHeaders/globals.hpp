#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "flywheel.hpp"



extern pros::Motor lB;
extern pros::Motor lF;
extern pros::Motor rB;
extern pros::Motor rF;

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;


extern pros::Motor intake;

extern pros::Motor fw;

extern Flywheel_Controller flywheel;

extern pros::Controller master;

extern lemlib::Drivetrain_t drivetrain;

extern lemlib::ChassisController_t lateralController;

extern lemlib::ChassisController_t angularController;

extern lemlib::OdomSensors_t sensors;

extern pros::Imu imu;

extern lemlib::Chassis eason;