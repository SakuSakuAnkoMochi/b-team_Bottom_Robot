#include "QEI.h"

const int8_t encodeTable[] = {0, -1,  1,  0, 1,  0,  0, -1, -1,  0,  0,  1, 0,  1, -1,  0 };


QEI::QEI(PinName A, PinName B, int ppr, Timer *timer) /*: channelA(A), channelB(B)*/
{

    channelA = new InterruptIn(A);
    channelB = new InterruptIn(B);

    _timer = timer; //_timerアドレス timerアドレス
    last_degree = 0;
    last_time = 0;
    _ppr = ppr; //_ppr実体ppr実体

    init();
}


//大事な中身
void QEI::init()
{
    channelA->rise(callback(this,&QEI::encode)); //立ち上がり割り込み(thisアドレス)
    channelB->rise(callback(this,&QEI::encode));
    channelA->fall(callback(this,&QEI::encode)); //立ち下がり割り込み
    channelB->fall(callback(this,&QEI::encode));
    
    currState = 0;
    prevState = 0;
    position = 0;

    _timer -> start();
}

double QEI::getSpeed() //回転角度 / s (つまり角速度)(By K)
{
    //static double last_time = 0;
    //static double last_degree = 0;
    double current_time =_timer -> read(); //秒単位(by K)
    double dt = current_time - last_time;
    double current_degree = double(position) * 360.0/(_ppr*4.0); // position[] * 360[deg / 回転] / ( ppr[パルス / 回転] * 4.0[逓倍※単位なし])By K
    double speed = (current_degree - last_degree) / dt;
    last_degree = current_degree;
    last_time = current_time;
    return speed;
}

void QEI::encode(void)
{
    int8_t chanA  = channelA->read();//ノイズで負の値来たらやばいかも？
    int8_t chanB  = channelB->read();
    currState = chanA | (chanB << 1);//|はOR演算//シフトしないとかぶる

    if (prevState != currState) {
        position += encodeTable[ currState | (prevState<<2) ];//状態なのでABの2つ分ずらす
        prevState = currState;
    }
}



//2024/3/25 rise関数の引数を変更 by K
//参考：https://os.mbed.com/docs/mbed-os/v6.16/apis/interruptin.html