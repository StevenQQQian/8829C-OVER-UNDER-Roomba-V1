#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <string>

void setCatapult(int power) {
    catapult.move(power);
} 

bool hold = false;
bool enable = false;

void setCatapultMotor() {
    if (limit.get_value() == 1) {
        hold = true;
    }
    pros::lcd::set_text(6, "Limit Switch: " + std::to_string(limit.get_value()));
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
        hold = false;
        setCatapult(80);
        pros::delay(300);
        setCatapult(80);
        // Shoot Catapult
        // while (limit.get_value() != 1) {
        //     setCatapult(127);
        //     pros::delay(10);
        // }
        // hold = true;
    }
}

void cata_hold() {

	while (true) {
       
		if (hold) {
			int absPos = catapult.get_position();
        
            while (hold) {
                int power = (absPos - catapult.get_position())*1.25;
                setCatapult(power);
                pros::delay(10);
            }
        }
        pros::delay(10);
	}

}

void cata_initialize() {
    hold = false; 
    // Shoot Catapult
    while (limit.get_value() == 0) {
        setCatapult(90);
    } hold = true;
}

void cata_shoot() {
    hold = false;
    // Shoot Catapult
    setCatapult(110);
    pros::delay(750);

    cata_initialize();
}

void Cata_initialize() {
    hold = false; 
    // Shoot Catapult
    while (limit.get_value() == 0) {
        setCatapult(100);
    } hold = true;
}

void trackCata() {
    while (true) {
        if (enable) {
            if (limit.get_value() == 1) {
                setCatapult(0);
                hold = true;
            }
        }
        pros::delay(10);
    }
}