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

    eason.moveTo(-5, 6, 1000, 100);

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