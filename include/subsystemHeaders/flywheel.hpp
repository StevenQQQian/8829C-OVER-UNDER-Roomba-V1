#pragma once

class Flywheel_Controller {
    public: 
    bool enable;
    double target_rpm;
    double current_rpm;
    /**
    @brief Construct a new Flywheel Controller
    @param kP proportional gain, multiplied by error and being added to the output. 
    @param kI integral gain, multiplied by total error and added to output
    @param kD derivative gain, multiplied by change in error and added to output
    */
        Flywheel_Controller(double kP, double kI, double kD);


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
        void give_power();

    private: 
        
        double kP;
        double kI;
        double kD;
        double error;
        double integral;
        double derivative;
        double prev_error;
};

extern void update();