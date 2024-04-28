#ifndef stepper_h
#define stepper_h

#include <Arduino.h>

#define STEPS_PER_REV 200
#define MICROSTEPS_PER_STEP 2

class Stepper{
public:

    /// Constructor. Creates stepper object.
    ///default speed is 1 RPM
    /// \param[in] DIR: motor driver direction pin
    /// \param[in] STEP: motor driver step pin
    /// \param[in] enableUsed: boolean to use enable feature [default is disabled]
    ///(i.e. always enabled)
    Stepper(uint8_t DIR, uint8_t STEP);

    ///sets the enable pin for the motor driver
    ///enable pin is set to output
    void setEnablePin(uint8_t enablePin);

    ///enables the motor driver
    void enable();

    ///disables the motor driver
    void disable();

    ///gets the enable state of the driver
    /// \return the state of the driver
    bool isEnabled();

    ///attaches limit switch for position control
    void attachLimitSW(uint8_t switch_pin);

    ///moves the motor one step in the specified direction by setDirection
    void step();

    ///sets the direction of the motor
    /// \param[in] direction: -->bool
    ///false is CW, true is CCW
    ///default is CW.
    void setDirection(bool direction);


    ///gets the current set direction of the motor
    /// \return the motor direction, false is CW, true is CCW
    bool direction();

    /// Sets the desired constant speed for use with step().
    /// \param[in] speed The desired constant speed in RPM
    /// second. 
    void setSpeed(uint8_t speed);

    /// The most recently set speed.
    /// \return the most recent speed in steps per second
    uint8_t speed();


    ///runs the motor for the specified number of steps
    ///in the specified direction
    void run(long steps, bool dir);

private:
    uint8_t _speed;
    uint8_t _dir_pin;
    uint8_t _step_pin;
    bool _direction;
    bool _enableUsed;
    uint8_t _enable_pin;
    bool _isEnabled;
    long _MICROSECONDS_PER_MICROSTEP;
};

#endif
