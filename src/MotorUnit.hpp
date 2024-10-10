#ifndef MotorUnit_HPP
#define MoterUnit_HPP
#include "QEI.h"
#include "Motor.hpp"
#include "PID.hpp"
class MotorUnit
{
private:
    QEI* qei;
    Motor* motor;
    PID* pid;
    float r;//目標値

public:
    MotorUnit(QEI* _qei,Motor* _motor,PID* _pid)
    {
        qei=_qei;
        motor=_motor;
        pid=_pid;
        r=0;
    };
    void Init();
    void Reset();
    void Update(float r);
};
#endif