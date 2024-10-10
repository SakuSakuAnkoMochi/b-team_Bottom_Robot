#include "Motor.hpp"

void Motor::Move(float r)
{
    Pwm = r;
    _PWM = abs(r);
    if (r * BaseDir >= 0)
    {
        NowDir = Direction::CW;
        _DIR = 0;
    }
    else
    {
        NowDir = Direction::CCW;
        _DIR = 1;
    }
}
void Motor::Start()
{
    Motor::_DIR = 0;
    Motor::_SLP = 0;
    Motor::_PWM = 0;
    Motor::Slp = 1;
    Motor::_SLP = 1;
}
void Motor::Stop()
{
    Motor::Slp = false;
    Motor::Pwm = 0;
    Motor::_SLP = 0;
    Motor::_PWM = 0;
}
void Motor::Restart()
{
    Motor::Slp = 1;
    Motor::_SLP = 1;
}

void Motor::ChangeBaseDirection(Direction BaseDir)
{
    Motor::BaseDir = BaseDir;
}

float Motor::GetPWM()
{
    return Motor::Pwm;
}
Direction Motor::GetNowDir()
{
    return Motor::NowDir;
}
Direction Motor::GetBaseDir()
{
    return Motor::BaseDir;
}
bool Motor::GetSlp()
{
    return Motor::Slp;
}