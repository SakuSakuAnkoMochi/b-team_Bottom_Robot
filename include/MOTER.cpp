#include "MOTER.hpp"

MotorDirection MOTER::GetDir()
{
    return DIR_;
}
void MOTER::SetDir(MotorDirection dir)
{
    DIR_ = dir;
    DIR = (int)dir;
}
bool MOTER::GetIsMove()
{
    return IsMove_;
}
void MOTER::SetIsMove(bool isMove)
{
    IsMove_ = isMove;
    IsMove = isMove;
}
float MOTER::GetSpeed()
{
    return Speed;
}
void MOTER::SetSpeed(float _Speed)
{
    auto tmp = max(min(_Speed, 1.0f), -1.0f);
    Speed = tmp;
    auto dir_ = tmp >= 0 ? CW : CCW;
    if (GetDir() != dir_)
        SetDir(dir_);
    PWM = abs(tmp);
}
double MOTER::GetPwmFrequency()
{
    return frequency;
}
void MOTER::SetPwmFrequency(double frequency)
{
    double period = 1.0 / frequency;
    PWM.period(period);
}
void MOTER::Stop()
{
    Speed=0.0f;
    PWM=0;
}