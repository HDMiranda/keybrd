/* simulate one scan of a key martix, on source active-low I/O expander

BREADBOARD SETUP *******************************
    Teensy LC connected to MCP23017 I/O expander via I2C
    4.7k Ohm pullup resistors on SDA and SCL
    use volt meter to measure pin voltages

MCP23017 PIN DIAGRAM ***************************
      write port B          read port A
    jumper0 GPB0 1          26 GPA7
            GPB1 2          25 GPA6
            GPB2 3          24 GPA5
            GPB3 4          23 GPA4  jumper4
    jumper4 GPB4 5          22 GPA3
            GPB5 6          21 GPA2
            GPB6 7          20 GPA1
            GPB7 8          19 GPA0  jumper0
    power    VDD 9          18 INTA
    GND      VSS 10         28 INTB
              NC 11         27 RESET power
    SCL      SCL 12         17 A2    gnd
    SDA      SDA 13         16 A1    gnd
              NC 14         15 A0    gnd
*/
#include "Wire.h"

const uint8_t ADDR  = 0x20;                     //MCP23017 I2C address with all ADDR pins grounded

void setup()
{
    delay(1000);                                //time for Serial print to work

// ================= configure ================
    Serial.print("config ");
    Wire.begin();

    Wire.beginTransmission(ADDR);
    Wire.write(0x01);                           //IODIRB Configure
    Wire.write(0);                              //as output
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x00);                           //IODIRA Configuration
    Wire.write(~0);                             //as input
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x0C);                           //GPPUA pull-up
    Wire.write(~0);                             //pull-up enabled
    Wire.endTransmission();

// =================== scan ===================
    Serial.println("scan");

    Wire.beginTransmission(ADDR);
    Wire.write(0x13);                           //GPIOB output
    Wire.write(B00001111);                      //pins 0-3 power (strobe, LED on), pins 4-7 ground
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x12);                           //GPIOA (immediately before requestFrom)
    Wire.endTransmission();

    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from GPIOA read
    Serial.print("portA=");
    Serial.println(Wire.read(), BIN);           //prints portA=11101111
}
void loop() { }