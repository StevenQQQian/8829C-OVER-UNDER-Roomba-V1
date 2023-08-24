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
        flywheel.current_rpm = fw.get_actual_velocity() * 5;
        pros::delay(10);
    }
}




double Flywheel_Controller::calculate(double target_rpm) {
    this->error = target_rpm - this->current_rpm;
    this->integral += this->error;
    this->derivative = this->error - this->prev_error;

    double rpm = (this->ff * target_rpm) + (error * this->kP) + (integral * this->kI); // + (derivative * this->kD);

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
            fw.move_velocity(flywheel.calculate(flywheel.target_rpm));
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
        pros::delay(100);
    }
}
