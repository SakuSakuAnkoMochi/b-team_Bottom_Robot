#include "MotorUnit.hpp"

void MotorUnit::Init()
{
    motor->Start();
    pid->Init();
}

void MotorUnit::Reset()
{
    motor->Stop();
    motor->Restart();
    pid->Reset();
}

void MotorUnit::Update(float r)
{
    motor->Move(r);
}