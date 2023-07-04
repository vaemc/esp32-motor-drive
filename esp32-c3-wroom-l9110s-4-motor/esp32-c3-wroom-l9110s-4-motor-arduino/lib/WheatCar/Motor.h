#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
public:
    int pin1;
    int pin2;

    Motor(int pin1, int pin2);

    Motor()
    {
    }

    void moveForward();
    void moveBackward();
    void stop();
};

#endif // MOTOR_H
