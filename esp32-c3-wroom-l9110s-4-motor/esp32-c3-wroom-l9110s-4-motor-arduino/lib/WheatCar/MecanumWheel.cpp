#include <Arduino.h>
#include "MecanumWheel.h"

MecanumWheel::MecanumWheel(Motor motor1, Motor motor2, Motor motor3, Motor motor4)
{
    motor1 = motor1;
    motor2 = motor2;
    motor3 = motor3;
    motor4 = motor4;
}

// 向前移动
void MecanumWheel::moveForward()
{
    // 实现向前移动的代码
    motor1.moveForward();
    motor2.moveForward();
    motor3.moveForward();
    motor4.moveForward();
}

// 向后移动
void MecanumWheel::moveBackward()
{
    // 实现向后移动的代码
    motor1.moveBackward();
    motor2.moveBackward();
    motor3.moveBackward();
    motor4.moveBackward();
}

// 向左移动
void MecanumWheel::moveLeft()
{
    // 实现向左移动的代码
}

// 向右移动
void MecanumWheel::moveRight()
{
    // 实现向右移动的代码
}

// 左上角移动
void MecanumWheel::moveTopLeft()
{
    // 实现左上角移动的代码
}

// 左下角移动
void MecanumWheel::moveBottomLeft()
{
    // 实现左下角移动的代码
}

// 右上角移动
void MecanumWheel::moveTopRight()
{
    // 实现右上角移动的代码
}

// 右下角移动
void MecanumWheel::moveBottomRight()
{
    // 实现右下角移动的代码
}

// 顺时针旋转
void MecanumWheel::rotateClockwise()
{
    // 实现顺时针旋转的代码
}

// 逆时针旋转
void MecanumWheel::rotateCounterClockwise()
{
    // 实现逆时针旋转的代码
}

// 停车
void MecanumWheel::stop()
{
    // 实现停车的代码
    motor1.stop();
    motor2.stop();
    motor3.stop();
    motor4.stop();
}
