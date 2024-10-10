#ifndef Motor_HPP
#define Motor_HPP
#include "mbed.h"

enum Direction
{
    CW=1,
    CCW=-1,
};

class Motor
{
    private:
        bool Slp;
        Direction BaseDir;
        Direction NowDir;
        float Pwm;

        DigitalOut _SLP;
        DigitalOut _DIR;
        PwmOut _PWM;

    public:
        Motor(PinName A,PinName B,PinName C,Direction Dire= Direction::CW):_SLP(A),_DIR(B),_PWM(C)
        {
            Motor::BaseDir = Dire;
            Motor::NowDir = Dire;
        }
        void Move(float r);
        void Start();
        void Stop();
        void Restart();
        void ChangeBaseDirection(Direction BaseDir);

        float GetPWM();
        Direction GetNowDir();
        Direction GetBaseDir();
        bool GetSlp();

};
#endif
