#include "main.h"
#include "pros/llemu.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "subsystemHeaders/flywheel.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


void screen() {
    // loop forever
    while (true) {
        lemlib::Pose pose = eason.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// pros::lcd::register_btn1_cb(on_center_button);
	eason.calibrate();
	flywheel.initialize();
	flywheel.enable = true;
	arm_rot.reset();
	arm_rot.reset_position();
	// arm_status = false;

	

	pros::Task screenTask(screen);
	pros::Task print_fw(print);
	pros::Task fwUpdate(update);
	pros::Task fwPower(bang_bang);
	pros::Task arm_aut(armAuton);
	lB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lM.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	// lMb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rM.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	// rMb.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	pros::lcd::clear();
	pros::lcd::initialize();
	// pros::lcd::set_text(1, "Eason is L");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// arm_status = true;
	// test();
	// nonMatchLoad();
	// matchLoad();
	nonMatchLoad_ELIM();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	arm_status = false;
	// eason.calibrate();
	// eason.setPose(0, 0, 0);
	enable = false;
	// setCatapult(80);

	while (true) {
		// if (limit.get_value() == 1) {
		// 	setCatapult(0);
			// hold = true;
		// }
		fwM();
		setDriveMotors();
		// setIntakeMotors();
		// setCatapultMotor();
		matchLoadBar();
		wingExpansion();
		LWing();
		// setClampPistons();
		armAngle();


		pros::delay(10);
	}
}