#include "main.h"
#include "pros/misc.h"


bool status = false;
void setIntake(double power) {
    // intake.move(power);
    // intake_2.move(power);
}

// void setIntakeMotors() {
//     setIntake((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) * 127); // Calculate power. If the intake button is pressed, it give positive power while it gives negative when outtake button is pressed. 
// }

void fwM() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
    {
        if (status==false)
        {
            flywheel.setTargetRpm(2500); // Give the flywheel motor a consistent speed of 100V. 
            status = true;
        }

        else if (status==true) {
            flywheel.setTargetRpm(0); // Stop the flywheel motor by coasting. 
            status = false;
        }
    }
}