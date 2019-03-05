/*
L9110MotorController.cpp - A library for motor control with a L9110 H Bridge Module
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

#include "Arduino.h"
#include "L9110MotorController.h"

void L9110MotorController::Stop()
{
   digitalWrite(motorA.lB_dir, LOW);
   analogWrite( motorA.lA_pwm, LOW);

   digitalWrite(motorB.lB_dir, LOW);
   analogWrite( motorB.lA_pwm, LOW);
}


void L9110MotorController::SetDir(L9110_MOTOR_DIRECTION dir)
{
   byte rspeed = ( (dir == DIR_FORWARD) ? 255-speed : speed);
  
   digitalWrite(motorA. lB_dir, dir);
   analogWrite(motorA.lA_pwm, rspeed);

   digitalWrite(motorB.lB_dir, dir);
   analogWrite(motorB.lA_pwm, rspeed);
}