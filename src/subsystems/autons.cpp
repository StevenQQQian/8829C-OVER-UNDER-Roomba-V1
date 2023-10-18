#include "main.h"
#include "pros/rtos.hpp"

void test() {
    eason.setPose(0, 0, 0);
    // eason.turnTo(30, 30, 1000, false, 80);
    arm_dir = 1;

}

void nonMatchLoad() {
    eason.setPose(38, -70, 0);
    arm.move(60);
    eason.moveTo(61, -44, 2000, 40);
    arm.move(0);
    eason.turnTo(61, -20, 500, false, 90);
    eason.moveTo(61, -20, 1000, 100);

    pros::delay(500);
    eason.moveTo(51, -60, 1500, 90);

    eason.moveTo(21, -22, 1400, 90);

    eason.turnTo(5, -25, 1400, false, 100);
    
    eason.moveTo(5, -25, 1400, 90);

    arm.move(-100);
    pros::delay(1000);
    arm.move(0);

    eason.turnTo(47, -10, 1000, false, 100);

    arm.move(70);
    eason.moveTo(47, -10, 1000, 100);
    arm.move(0);
    eason.moveTo(49, -8, 500, 100);
    arm.move(60);
    eason.moveTo(-5, -49, 2000);
    arm.move(0);
    // eason.moveTo(3, -70, 1000, 90);
}

void matchLoad() {
    eason.setPose(-38, -70, 0);

    arm.move(60);
    eason.moveTo(-63, -44, 2000, 40);
    arm.move(0);

    eason.turnTo(-63, -20, 500, false, 90);
    eason.moveTo(-63, -20, 1000, 100);

    // arm.move(60);
    eason.moveTo(-53, -56, 1500, 100);

    eason.turnTo(0, 0, 1000, false, 100);

    eason.moveTo(-56.5, -60.5, 500, 100);
    arm.move(110);
    pros::delay(600);
    arm.move(0);

    eason.turnTo(0, -59, 1500, false, 50);

    eason.moveTo(-35, -60, 1000, 100);

    eason.turnTo(-2, -60, 1000, true, 100);

    eason.moveTo(-2, -60, 1500, 100);
    
}

void nonMatchLoad_ELIM() {
    eason.setPose(35, -59, 90);
    arm.move(32);
    eason.moveTo(67, -35, 1000, 100);
    arm.move(58);
    eason.moveTo(66.5, -9, 1500, 100);
    arm.move(0);

    eason.moveTo(51, -47, 1100, 100);

    eason.moveTo(21, -19, 1200, 100);

    arm.move(-60);

    eason.moveTo(6, -16, 1200, 100);

    arm.move(0);

    eason.turnTo(50, 0, 1000, false, 100);

    arm.move(60);

    eason.moveTo(53, 0, 1200, 100);

    arm.move(0);

    eason.moveTo(19, -15, 1000, 100);

    eason.turnTo(0, 0, 1000, false, 100);


    eason.moveTo(24, -5, 1000, 100);

    eason.moveTo(4, 6, 1000, 100);

    arm.move(-60);

    eason.moveTo(-3, 6, 1000, 100);

    arm.move(0);

    eason.turnTo(24, 6, 2000, false, 60);


    wings_L.set_value(true);
    wings_R.set_value(true);
    wings_status = true;
    wings_L_status = true;

    arm.move(60);
    eason.moveTo(50, 6, 1500, 100);
    arm.move(0);
}

void skills() {
    eason.setPose(-35, -60, 135);

    eason.moveTo(-62, -37, 1000, 100);

    eason.moveTo(-60, -24, 1000, 127);

    eason.moveTo(-55, -54, 1000, 100);

    flywheel.setTargetRpm(2100);

    eason.turnTo(47, -3, 1000, false, 100);


    setDrive(-30, -30);

    pros::delay(170);
    
    setDrive(0, 0);


    pros::delay(28000);

    flywheel.setTargetRpm(0);

    eason.turnTo(-21, -60, 1000, true, 100);

    eason.moveTo(-21, -64, 1000, 200);

    eason.moveTo(44, -65, 1000, 200);

    eason.moveTo(64, -40, 1000, 200);

    eason.turnTo(61, -28, 1000, true, 200);

    setDrive(-127, -127);

    pros::delay(250);

    setDrive(0, 0);

    pros::delay(1000);

    
    eason.moveTo(44, -65, 1000, 200);

    eason.moveTo(64, -40, 1000, 200);

    eason.turnTo(61, -28, 1000, true, 200);

    setDrive(-127, -127);

    pros::delay(250);

    setDrive(0, 0);

    pros::delay(500);

    eason.moveTo(44, -58, 1000, 200);

    eason.moveTo(15, -21, 1000, 200);
    

    eason.moveTo(14, 10, 1000, 200);

    eason.turnTo(60, -1, 1000, false, 200);

    wings_L.set_value(true);
    wings_R.set_value(true);

    eason.moveTo(60, -1, 1000, 200);

    wings_R.set_value(false);
    wings_L.set_value(false);

    pros::delay(500);

    eason.moveTo(20, -50, 1000, 200);

    eason.turnTo(60, -1, 1000, false, 200);

    // wings_L.set_value(true);
    

    eason.moveTo(60, -1, 1000, 200);

    // wings_L.set_value(false);

    pros::delay(500);

    eason.moveTo(20, 0, 1000, 200);


    eason.turnTo(60, -1, 1000, false, 200);

    wings_R.set_value(true);
    // wings_L.set_value(true);

    eason.moveTo(70, -1, 1000, 200);

    // wings_L.set_value(false);
    wings_R.set_value(false);

    // eason.moveTo(58, -23, 1000, 127);

    // eason.moveTo(40, -40, 1000, 100);

    // eason.moveTo(0, 0, 2000, 100);

    

    // flywheel.setTargetRpm(2023);

    // pros::delay(27000);

    // flywheel.setTargetRpm(0);


}