#include "main.h"
#include "pros/misc.h"


bool status = false;
void setIntake(double power) {
    // intake.move(power);
    // intake_2.move(power);
}

void setIntakeMotors() {
    setIntake((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) * 127);
}

void fwM() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
    {
        if (status==false)
        {
            flywheel.setTargetRpm(2011);
            status = true;
        }

        else if (status==true) {
            flywheel.setTargetRpm(0);
            status = false;
        }
    }

    else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
    {
        if (status==false)
        {
            flywheel.setTargetRpm(-2011);
            status = true;
        }

        else if (status==true) {
            flywheel.setTargetRpm(0);
            status = false;
        }
    }
}