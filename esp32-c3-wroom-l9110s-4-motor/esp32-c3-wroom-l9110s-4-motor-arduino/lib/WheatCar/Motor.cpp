#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int pin1, int pin2)
{
    pin1 = pin1;
    pin2 = pin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

// 向前移动
void Motor::moveForward()
{
    // 实现向前移动的代码
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

// 向后移动
void Motor::moveBackward()
{
    // 实现向后移动的代码
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

// 停车
void Motor::stop()
{
    // 实现停车的代码
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}
