#ifndef ROWSCANNER_SHIFTREGSPISOSINGLEROW_H
#define ROWSCANNER_SHIFTREGSPISOSINGLEROW_H

#include <Arduino.h>
#include <inttypes.h>
#include <config_keybrd.h>
#include <SPI.h>
#include <ScannerInterface.h>

/* Scanner_ShiftRegsRead reads shift registers.
This was tested on 74HC165 shift registers, which are Parallel-In-Serial-Out (PISO).
Upto 4 shift registers can be in a daisy chained for a total of 32 read pins.

Example instantiation:
    Row row_R0(scanner_R, 0, ptrsKeys_R0, sizeof(ptrsKeys_R0)/sizeof(*ptrsKeys_R0));
    Scanner_ShiftRegsRead scanner_R(HIGH, SS, 4);

The Row "strobePin" parameter is ignored.
In the above example, the "strobePin" argument is 0, but it doesn't matter what value is given.

There are three Scanner_ShiftRegsRead parameters.
"strobeOn" paramter is ignored, but should be active state HIGH or LOW required by ScannerInterface.

"slaveSelect" paramter can be any controller pin connected to shift register's SHIFT-LOAD pin.

"byte_count" is the number of bytes to read from shift registers (1 to 4).
byte_count should cover all the row's keys:
    byte_count*8 >= row's keyCount

Hardware setup:
There is only one row, and it is permanently active.
Switches are connected to shift-register parallel-input pins and row.
Diodes are not needed because there is only one row.

For active low:
Shift-register parallel-input pins need 10k Ohm pull-up resistors powered.
Switches connect powered row to parallel-input pins.
Controller's MISO pin is connected to shift register's complementary serial output (/QH) pin

For active high:
Shift-register parallel-input pins need 10k pull-down resistors grounded.
Switches connect grouned row to parallel-input pins.
Controller's MISO pin is connected to shift register's serial output (QH) pin
*/
class Scanner_ShiftRegsRead : public ScannerInterface
{
    private:
        const uint8_t slaveSelect;//controller pin number connected to shift register SHIFT-LOAD pin
        const uint8_t byte_count;               //number of bytes to read from shift registers
    public:
        Scanner_ShiftRegsRead(const bool strobeOn,
                                       const uint8_t slaveSelect, const uint8_t byte_count);
        void init(const uint8_t strobePin);
        void begin();
        virtual read_pins_t scan(const uint8_t strobePin);
};
#endif