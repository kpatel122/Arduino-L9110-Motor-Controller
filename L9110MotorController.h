/*
L9110MotorController.h - A library for motor control with a L9110 H Bridge Module
Copyright (c) 2019 Kunal Patel

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

This permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef L9110MotorController_H
#define L9110MotorController_H

#include "Arduino.h"
 


typedef struct MOTOR_PINS
{
  byte pwm; //1A
  byte dir; //1B
}MOTOR_PINS;

enum L9110_MOTOR_DIRECTION
{
    DIR_FORWARD = HIGH,
    DIR_BACKWARD = LOW
};

class L9110MotorController
{
  public:
    L9110MotorController(byte motorA_pwm, byte motorA_dir,byte motorB_pwm, byte motorB_dir, int speed);
    void Stop();
    void SetDir(L9110_MOTOR_DIRECTION dir);
    void MotorATurn();
    void MotorBTurn();
    void SetSpeed(int newSpeed){this->speed = newSpeed;}
    int GetSpeed(){return speed;}
  private:
    int speed;
    MOTOR_PINS motorA;
    MOTOR_PINS motorB;
};

#endif
