#ifndef MECANUMWHEEL_H
#define MECANUMWHEEL_H

#include "Motor.h"

class MecanumWheel
{
public:
    Motor motor1;
    Motor motor2;
    Motor motor3;
    Motor motor4;
    MecanumWheel(Motor motor1, Motor motor2, Motor motor3, Motor motor4);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveTopLeft();
    void moveBottomLeft();
    void moveTopRight();
    void moveBottomRight();
    void rotateClockwise();
    void rotateCounterClockwise();
    void stop();
};

#endif // MECANUMWHEEL_H
