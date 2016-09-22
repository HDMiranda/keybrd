#ifndef LED_IOE_H
#define LED_IOE_H
#include <Arduino.h>
#include <inttypes.h>
#include <Wire.h>
#include <LED.h>
#include <PortWriteInterface.h>

/* A LED_IOE object is an I/O expander pin that is connected to an LED indicator light.
Input/Ouput Direction configuration are set to ouput in PortWrite_*.begin() and PortRead_*.begin(). todo PortRead_*??
*/
class LED_IOE: public LED
{
    private:
        PortWriteInterface& refPort;
        const uint8_t pin;                      //bit pattern, 1 is IOE pin to LED

    public:
        LED_IOE(PortWriteInterface& refPort, const uint8_t pin)
            : refPort(refPort), pin(pin) {}
        virtual void on();
        virtual void off();
};
#endif
