#ifndef STEPPER_H
#define STEPPER_H



class Stepper {
public:

    /// Constructor. Creates stepper object.
    /// \param[in] DIR: motor driver direction pin
    /// \param[in] STEP: motor driver step pin
    /// \param[in] enableUsed: boolean to use enable feature [default is disabled]
    ///(i.e. always enabled)
    Stepper(uint8_t DIR, uint8_t STEP, bool enabledUsed = false)

    ///sets the enable pin for the motor driver
    ///enable pin is set to output
    void setEnablePin(uint8_t enablePin);

    ///attaches limit switch for position control
    void attachLimitSW(uint8_t switch_pin);

    ///moves the motor one step in the specified direction by setDirection
    void step();

    ///sets the direction of the motor
    /// \param[in] direction: -->bool
    ///false is CW, true is CCW
    ///default is CW.
    void setDirection(bool direction)


    ///gets the current set direction of the motor
    /// \return the motor direction, false is CW, true is CCW
    bool direction();

    /// Sets the desired constant speed for use with runSpeed().
    /// \param[in] speed The desired constant speed in steps per
    /// second. Positive is clockwise. Speeds of more than 1000 steps per
    /// second are unreliable. Very slow speeds may be set (eg 0.00027777 for
    /// once per hour, approximately. 
    void    setSpeed(float speed);

    /// The most recently set speed.
    /// \return the most recent speed in steps per second
    float   speed();

private:
    float _speed;
    uint8_t _dir_pin;
    uint8_t _step_pin;
    bool _direction
    


#endif
