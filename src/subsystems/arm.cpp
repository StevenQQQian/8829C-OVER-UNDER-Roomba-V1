#include "main.h"
#include "pros/misc.h"

bool arm_status = false;
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