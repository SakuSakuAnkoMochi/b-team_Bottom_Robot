#include "PID.hpp"

void PID::Init()
{
    Kp = 20;  // Pゲイン
    Kd = 5;   // Dゲイン
    Ki = 1;   // Iゲイン
    T=1;
}
void PID::Reset()
{
    e_pre = 0; // 微分の近似計算のための初期値
    prop_pre=0;
    row_pass_deriv=0;
    output=0;
    //ie = 0;    // 積分の近似計算のための初期値
}
float PID::Calc(float _r/*目標値*/ ,float _y/*現在値*/)
{
    T=gettime();
    //deltaTimeを求める
    // PID制御の式より、制御入力uを計算
    y=_y;
    r=_r;
    e = r - y;                // 誤差を計算
    prop=(e-e_pre)/T;
    deriv=(prop-prop_pre)/T;
    row_pass_deriv+=(deriv-row_pass_deriv)/8;
    du=Kp*prop+Ki*e+Kd*row_pass_deriv;
    output+=du;

    e_pre=e;
    prop_pre=prop;
    return output;
}