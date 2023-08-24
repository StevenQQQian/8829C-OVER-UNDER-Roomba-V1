#include "main.h"
#include "pros/misc.h"

bool hook_status = false;
bool wings_status = false;

void matchLoadBar() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        if (hook_status == false) {
            hook.set_value(true);
            hook_status = true;
        }

        else if (hook_status == true) {
            hook.set_value(false);
            hook_status = false;
        }
    }
}

void wingExpansion() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
        if (wings_status == false) {
            wings.set_value(true);
            wings_status = true;
        }

        else if (wings_status == true) {
            wings.set_value(false);
            wings_status = false;
        }
    }
}