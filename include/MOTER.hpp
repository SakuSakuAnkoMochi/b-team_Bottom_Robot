#include "mbed.h"
#include <cmath>

typedef enum{
    CW = 0,
    CCW = 1,
}MotorDirection;

class MOTER
{
    private:
        PwmOut PWM;
        DigitalOut DIR;
        DigitalOut IsMove;

        float Speed;
        MotorDirection DIR_;
        bool IsMove_;
        double frequency;

    public:
        MOTER(PinName DIR_,PinName PWM_,DigitalOut IsMove_,double frequency_,float Speed_=0.0f,MotorDirection dir_= CW)
        :DIR(DIR_),PWM(PWM_),IsMove(IsMove_),frequency(frequency_),Speed(Speed_)
        {
            double period = 1.0 / frequency_;
            PWM.period(period);
            DIR=(int)dir_;
            PWM=0;
            IsMove=false;
        }
        MotorDirection GetDir();
        void SetDir(MotorDirection _dir);
        bool GetIsMove();
        void SetIsMove(bool _IsMove);
        float GetSpeed();
        void SetSpeed(float _Speed);
        double GetPwmFrequency();
        void SetPwmFrequency(double frequency);
        void Stop();
};

