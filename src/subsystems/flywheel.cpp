// Deprecated

#include "main.h"
#include "pros/llemu.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include "subsystemHeaders/flywheel.hpp"
#include <string>


Flywheel_Controller::Flywheel_Controller(double kP, double kI, double kD, double ff) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->ff = ff;
    this->initialize();
}


void Flywheel_Controller::initialize() {
    this->error = 0;
    this->integral = 0;
    this->derivative = 0;
    this->prev_error = 0;
    this->current_voltage = 0;
    this->current_rpm = 0;
}


void update() {
    while (true) {
        flywheel.current_rpm = fw.get_actual_velocity() * 6;
        pros::delay(10);
    }
}




double Flywheel_Controller::calculate(double target_rpm) {
    this->error = target_rpm - this->current_rpm; // Calculates the current error from the current rpm to the target. 
    this->integral += this->error; // Calculates the integrations according to the errors. 
    this->derivative = this->error - this->prev_error; // Calculates the derivatives according to the current error and previous error. 

    double rpm = (ff * this->target_rpm) + (error * this->kP) + (integral * this->kI) + (derivative * this->kD);

    double velocity = rpm / (3600.0 / 127.0);

    this->prev_error = this->error;
    return velocity;
}


void give_power() {
    while (true) {

        if (flywheel.target_rpm == 0) {
            fw.move(0);
        }

        else {
            fw.move(flywheel.calculate(flywheel.target_rpm));
        }
        if (flywheel.current_voltage > 127) {
            flywheel.current_voltage = 127;
        }

        if (flywheel.current_voltage < 0) {
            flywheel.current_voltage = 0;
        }


        pros::delay(10);
    }
}

void Flywheel_Controller::setTargetRpm(double rpm) {
    this->target_rpm = rpm;
}

void print() {
    while (true) {
        pros::lcd::set_text(5, "Flywhale power: " + std::to_string(flywheel.current_rpm));
        pros::lcd::set_text(7, "Port 12: " + std::to_string(lB.get_voltage()));
        pros::delay(100);
    }
}

void bang_bang() {
    while (true) {
        if ((fw.get_actual_velocity() * 5) < ((flywheel.target_rpm)-200)) { // Condition when flywheel speed is more than 300 rpm slower than the target
            fw.move(127); // Set flywheel motor to max acceleration
        }
        else { // Condition when flywheel speed is close to or faster than the target speed
            fw.move((flywheel.target_rpm / (3600.0 / 127.0))); // Set flywheel motor to the target rpm voltage. 
        }
    }
}