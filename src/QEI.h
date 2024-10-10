#ifndef QEI_H
#define QEI_H

#include "mbed.h"

class QEI {

public:

    QEI(PinName A, PinName B, int ppr, Timer *timer);//コンストラクタ
    
    //double getDegree(); //メンバ関数
    double getSpeed();  //この関数は複数回呼んではいけない。割り込みのタイミングがずれて別物となるため。

private:

    void init(); //メンバ関数
    void encode(void);
    
    InterruptIn* channelA; //InterruptInインスタンス//main文にないのでコンストラクタは自分で用意してやる必要がある（このままでは初期化されない）
    InterruptIn* channelB;
    Timer *_timer; //Timerクラスのポインタ変数_timerを宣言
    
    int currState;
    int prevState;
    long long int position; //このカウンタがオーバーフローしたら死ぬ
    double _ppr;
    double last_degree;
    double last_time;
};

#endif