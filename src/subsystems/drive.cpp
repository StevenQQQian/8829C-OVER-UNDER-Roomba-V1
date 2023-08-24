#include "main.h"


void setDrive(double left, double right) {
    lF.move(left);
    lMb.move(left);
    lMf.move(left);
    lB.move(left);
    rF.move(right);
    rMf.move(right);
    rMb.move(right);
    rB.move(right);
}

void setDriveMotors() {
    // Deadband for controller analog
    const int deadband = 5;
    int x = abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
    int y = abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
    // FORWARD/BACKWARD POWER
    double LjoyY = y/10.0;
    // TURNING POWER
    double RjoyX = x/10.0;
    double power = 0;
    double turn = 0;

    if (y > deadband || x > deadband) {
        if (y > 85) {
            power = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyY - 6.0)))) * 10.0 - 3.0;
        }
        else if (y > 55 && y <= 85) {
            power = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyY - 6.0)))) * 10.0 - 10.0;
        }
        else {
            power = 5*pow((1.0/5.5)*(LjoyY), 3.0) * 12.7;
        }

        if (x > 95) {
            turn = 0.8*(12.7 / (1.0 + exp(-(3.0/4.0)*(RjoyX - 6.0)))) * 10.0 - 3.0;
        }
        else if (x > 55 && x <= 85) {
            turn = 0.35*(12.7 / (1.0 + exp(-(3.0/4.0)*(RjoyX - 6.0)))) * 10.0 - 10.0;
        }
        else {
            turn = 0.6*5*pow((1.0/5.5)*(RjoyX), 3.0) * 12.7;
        }
    }
    // Direction Settings
    if (master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) < 0) {
        power = -power;
    }
    if (master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) < 0) {
        turn = -turn;
    }
    double leftPower = power + turn;
    double rightPower = power - turn;
    
    // Power Setting
    setDrive(leftPower, rightPower);
}