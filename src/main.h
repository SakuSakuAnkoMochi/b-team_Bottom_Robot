#include "mbed.h"
#include "PS3.h"
#include "Motor.hpp"
#include "QEI.h"
#include "MotorUnit.hpp"

PS3 Controller(PA_0, PA_1);

//(0番,左上),(1番,左下),(2番,右下),(3番,右上)とする
const int PPR = 250; // 一回転したときに何回パルスが来るかの値
Timer timer;
QEI qeis[] = {
    //QEI(PC_1, PC_0, PPR, &timer), // ゼロ番目はA層とB層が逆らしい
    QEI(PB_0, PB_6, PPR, &timer),
    QEI(PC_3, PC_4, PPR, &timer),
    QEI(PC_6, PC_7, PPR, &timer),
    QEI(PC_8, PC_9, PPR, &timer),
};
Motor motors[] = {
    //Motor(PA_4, PB_1, PB_4,Direction::CCW),
    // Motor(PA_4, PB_2, PB_5),
    // Motor(PA_4, PB_9, PB_6),
    // Motor(PA_4, PA_15, PB_7,Direction::CCW),
    Motor(PA_4, PA_6, PC_6,Direction::CCW),
    Motor(PA_4, PA_7, PC_7),
    Motor(PA_4, PA_15, PC_8),
    Motor(PA_4, PB_8, PA_8,Direction::CCW),
};
PID pids[]={
    PID(&timer),
    PID(&timer),
    PID(&timer),
    PID(&timer),
};

MotorUnit motorUnits[]=
{
    MotorUnit(&qeis[0],&motors[0],&pids[0]),
    MotorUnit(&qeis[1],&motors[1],&pids[1]),
    MotorUnit(&qeis[2],&motors[2],&pids[2]),
    MotorUnit(&qeis[3],&motors[3],&pids[3]),
};


DigitalOut RED(PA_6);
DigitalOut BLUE(PA_7);
DigitalOut GREEN(PA_8);