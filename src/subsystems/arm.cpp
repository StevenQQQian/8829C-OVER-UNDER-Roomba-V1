#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

bool arm_status = false;
int arm_dir = 0;
void armAngle() {
    // if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    //     if (arm_status == false) {
    //         arm.move(120);
    //         arm_status = true;
    //     }

    //     else if (arm_status == true) {
    //         arm.move(0);
    //         arm_status = false;
    //     }
    // }

    // else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
    //     if (arm_status == false) {
    //         arm.move(-120);
    //         arm_status = true;
    //     }

    //     else if (arm_status == true) {
    //         arm.move(0);
    //         arm_status = false;
    //     }
    // }
    arm.move(120 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)));
}

void armAuton() {
    while (arm_status == true) {
        if (arm_dir == 0) {
            arm.move(0);
        }

        else if (arm_dir == 1) {
            arm.move(90);
        }

        else if (arm_dir == -1) {
            arm.move(-90);
        }

        pros::delay(10);

    }
}