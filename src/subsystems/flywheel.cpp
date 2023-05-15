#include "main.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"



Flywheel_Controller::Flywheel_Controller(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->initialize();
}


void Flywheel_Controller::initialize() {
    this->error = 0;
    this->integral = 0;
    this->derivative = 0;
    this->prev_error = 0;
}


void Flywheel_Controller::update() {
    while (true) {
        this->current_rpm = fw.get_actual_velocity() * 5;
        pros::delay(10);
    }
}




double Flywheel_Controller::calculate(double target_rpm) {
    this->error = target_rpm - this->current_rpm;
    this->integral += error;
    this->derivative = error - prev_error;

    double power = (error * kP) + (integral * kI) + (derivative * kD);

    return power;   
}

void Flywheel_Controller::give_power(double rpm) {
    while (enable) {
        fw.move_velocity(this->calculate(rpm));
        pros::delay(10);
    }
}
