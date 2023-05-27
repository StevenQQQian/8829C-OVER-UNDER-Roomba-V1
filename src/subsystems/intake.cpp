#include "main.h"
#include "pros/misc.h"

void setIntake(double power) {
    intake.move(power);
}

void setIntakeMotors() {
    setIntake((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) * 127);
}
