#include "mbed.h"
#ifndef PID_HPP
#define PID_HPP

class PID
{
private:
    float Kp; // Pゲイン
    float Ki; // Iゲイン
    float Kd; // Dゲイン
    float T;  // 制御周期[秒]
    Timer *timer;

    float y; // 現在値
    float r; // 目標
    float e;
    float e_pre;
    float prop;
    float deriv;
    float prop_pre;
    float row_pass_deriv;
    float du;
    float output;

    float gettime()
    {
        timer->start();
        static float prev_time;
        float a = timer->read() - prev_time;
        prev_time = timer->read();
        return a;
    }

public:
    PID(Timer *_timer)
    {
        timer = _timer;
    };
    void Init();
    void Reset();
    float Calc(float r, float y);
};
#endif