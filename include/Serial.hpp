#include "mbed.h"

class Serial
{
private:
    UnbufferedSerial Serial_Port;

public:
    Serial(PinName PIN1, PinName PIN2) : Serial_Port(PIN1, PIN2)
    {
        Serial_Port.baud(9600);
        Serial_Port.format(
            /* bits */ 8,
            /* parity */ SerialBase::None,
            /* stop bit */ 1);
            Serial_Port.attach(callback(this,&Receive));
    }
    void Send(char* str);
    void Receive();
};