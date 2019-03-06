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

L9110MotorController::L9110MotorController(byte motorA_pwm, byte motorA_dir,byte motorB_pwm, byte motorB_dir, int speed)
{
   motorA.dir = motorA_dir;  
   motorA.pwm = motorA_pwm; //1A
    
   motorB.dir = motorB_dir; //1B
   motorB.pwm = motorB_pwm; //1A

   pinMode(motorA.pwm, OUTPUT);     
   pinMode(motorA.dir, OUTPUT);
   digitalWrite(motorA.pwm, LOW);
   digitalWrite(motorA.dir, LOW);

   pinMode(motorB.pwm, OUTPUT);     
   pinMode(motorB.dir, OUTPUT);
   digitalWrite(motorB.pwm, LOW);
   digitalWrite(motorB.dir, LOW);

   this->speed = speed;
}

void L9110MotorController::Stop()
{
   digitalWrite(motorA.dir, LOW);
   analogWrite( motorA.pwm, LOW);

   digitalWrite(motorB.dir, LOW);
   analogWrite( motorB.pwm, LOW);
}

void L9110MotorController::MotorATurn()
{
   byte rspeed = 255-speed;
  
   digitalWrite(motorA.dir, DIR_FORWARD);
   analogWrite(motorA.pwm, rspeed);

   digitalWrite(motorB.dir, DIR_BACKWARD);
   analogWrite(motorB.pwm, rspeed);
}
void L9110MotorController::MotorBTurn()
{
   byte rspeed = 255-speed;
   digitalWrite(motorB.dir, DIR_FORWARD);
   analogWrite(motorB.pwm, rspeed);

   digitalWrite(motorA.dir, DIR_BACKWARD);
   analogWrite(motorA.pwm, rspeed);
}

void L9110MotorController::SetDir(L9110_MOTOR_DIRECTION dir)
{
   byte rspeed = ( (dir == DIR_FORWARD) ? 255-speed : speed);
  
   digitalWrite(motorA.dir, dir);
   analogWrite(motorA.pwm, rspeed);

   digitalWrite(motorB.dir, dir);
   analogWrite(motorB.pwm, rspeed);
}