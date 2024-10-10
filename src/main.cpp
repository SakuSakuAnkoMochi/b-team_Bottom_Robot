#include "main.h"

void setup()
{
    for (unsigned int i = 0; i < sizeof(motorUnits) / sizeof(MotorUnit); i++)
    {
        motorUnits[i].Init();
    }
}
int t=0;
void loop()
{
    // t++;
    // RED = (t%30>=0&&t%30<10)?1:0;
    // BLUE = (t%30>=10&&t%30<20)?1:0;
    // GREEN = (t%30>=20&&t%30<30)?1:0;

    // if (Controller.getButtonState(PS3::Button_type::sikaku))
    // {
    //     motor.Move(0.8 * Controller.getButtonState(PS3::Button_type::sikaku));
    // }
    // else
    // {
    //     motor.Move(-0.8 * Controller.getButtonState(PS3::Button_type::maru));
    // }

    // if (Controller.getButtonState(PS3::Button_type::L1))//stop
    // {

    // }
    // else if(Controller.getButtonState(PS3::Button_type::R1))//restart
    // {

    // }
    // else if(abs(Controller.getRightJoystickXaxis() / 64.0)>0.1)//rotate
    // {
    //     float X = Controller.getRightJoystickXaxis() / 64.0;
    // }
    // else//move
    // {
    //     float X = Controller.getLeftJoystickXaxis() / 64.0;
    //     float Y = Controller.getLeftJoystickYaxis() / 64.0;
    //     float length = sqrt(X * X + Y * Y);
    //     float angle = atan2(Y, X);
    //     // float speed = Controller.getLeftJoystickYaxis() / 64.0;
    //     for (unsigned int i = 0; i < sizeof(motorUnits) / sizeof(MotorUnit); i++)
    //     {
    //         // motorUnits[i].Update(speed);
    //     }
    //     motorUnits[0].Update(length/2*sin(angle+PI/4)*128);
    // }
    // motors[0].Move(0.5);
    //motorUnits[0].Update(0.5);
    // motorUnits[1].Update(0);
    // motorUnits[2].Update(0);
    // motorUnits[3].Update(0);
    printf("%d",(int)(qeis[0].getSpeed()*100));
}

// DigitalOut SLP(PA_4);
// PwmOut PWM(PC_6);
// DigitalOut DIREC(PA_6);
int main()
{
    setup();
    while (1)
    {
        loop();
        // SLP=1;
        // PWM=0.5;
        // DIREC=1;
    }
}