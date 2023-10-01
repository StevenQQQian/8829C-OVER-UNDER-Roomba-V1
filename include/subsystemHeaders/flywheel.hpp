#pragma once

class Flywheel_Controller {
    public: 
    bool enable;
    double target_rpm;
    double current_rpm;
    double current_voltage;
    /**
    @brief Construct a new Flywheel Controller
    @param kP proportional gain, multiplied by error and being added to the output
    @param kI integral gain, multiplied by total error and added to output
    @param kD derivative gain, multiplied by change in error and added to output
    @param ff A voltage ratio that adjusts the flywheel power if the acceleration of flywheel is too slow
    */
        Flywheel_Controller(double kP, double kI, double kD, double ff);


    /**
    @brief Calculate the power to the flywheel motor
    @param target_rpm the rpm that is desired for the flywheel
    */
        double calculate(double target_rpm);


    /**
    @brief Initialize all the values in the PID Controller
    */

        void initialize();

    /**
    @brief Task, give the flywheel power continuously 
    */

    /**
    @brief Function, sets the target rpm of the flywheel
    */
        void setTargetRpm(double rpm);



        

    private: 
        
        double kP;
        double kI;
        double kD;
        double ff;
        double error;
        double integral;
        double derivative;
        double prev_error;
};

extern void update();

void flywheelMotors();

void print();

void give_power();

extern bool status;

void bang_bang();