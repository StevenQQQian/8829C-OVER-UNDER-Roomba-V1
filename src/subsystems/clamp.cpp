#include "main.h"
#include "pros/misc.h"

bool clamp_status = false;

void setClampPistons() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        if (clamp_status == false) {
            clamp.set_value(true);
            clamp_status = true;
        }

        else if (clamp_status == true) {
            clamp.set_value(false);
            clamp_status = false;
        }
    }
}