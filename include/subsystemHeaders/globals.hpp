#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "flywheel.hpp"
#include "pros/rotation.hpp"


// Drivetrain Motors
extern pros::Motor lB;
// extern pros::Motor lMb;
extern pros::Motor lM;
extern pros::Motor lF;
extern pros::Motor rB;
extern pros::Motor rM;
// extern pros::Motor rMb;
extern pros::Motor rF;

// MotorGroups
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

// Subsystem Motors
// extern pros::Motor intake;
// extern pros::Motor intake_2;

extern pros::Motor catapult;

extern pros::Motor fw;

extern Flywheel_Controller flywheel;

extern pros::Motor arm;



extern pros::Controller master;

extern lemlib::Drivetrain_t drivetrain;

// PID
extern lemlib::ChassisController_t lateralController;

extern lemlib::ChassisController_t angularController;

// Sensors
extern lemlib::OdomSensors_t sensors;

extern pros::Imu inertial_sensor;

extern pros::ADIDigitalIn limit;

extern pros::Rotation arm_rot;

// Drivetrain
extern lemlib::Chassis eason;




// Pneumatics
extern pros::ADIDigitalOut hook;
extern pros::ADIDigitalOut wings_L;
extern pros::ADIDigitalOut wings_R;

extern pros::ADIDigitalOut clamp;