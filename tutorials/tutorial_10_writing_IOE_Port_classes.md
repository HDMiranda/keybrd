Tutorial 10 - writing new IOE Port classes
==========================================
Port classes are the keybrd library's interface to I/O expander ports.

To write a new Port class:

1. Get a copy of the I/O expander's datasheet.
2. An I/O expander will use one of two communication protocols: [http://www.byteparadigm.com/applications/introduction-to-i2c-and-spi-protocols/](SPI or I2C).
   Refer to the [Arduino SPI](https://www.arduino.cc/en/Reference/SPI)
   or [Arduino Wire (I2C)](https://www.arduino.cc/en/Reference/Wire) library
3. Get familiar with your I/O expander.
   Different I/O expanders use different commands (a.k.a. operation codes).
   Refer to your I/O expander's datasheet for read and write commands.
   Search for Arduino sketch examples containing your I/O expander
   ([sumotoy](https://github.com/sumotoy/gpio_expander) has a large gpio expander library).
   Write very simple read and write examples for your I/O expander.
   Simple SPI I/O expander examples:
    todo link, pictures
    /home/wolfv/Documents/Arduino/demo/IOE_MCP23S17_read/ todo internal pull-up resistors
    /home/wolfv/Documents/Arduino/demo/IOE_MCP23S17_write/
   Simple I2C I/O expander examples:
    todo link, pictures
    read
    write
4. Study other keybrd Port classes.
   Port classes for SPI MCP23S17 I/O expander:
   *todo
   *
   *
   Port classes for I2C PCA9655E I/O expander:
   * PortWrite_PCA9655E todo link
   * PortRead_PCA9655E
   * LED_PCA9655E
5. Write similar Port classes for your I/O expander.
   Debugging I/O expander code is hard because SPI or I2C protocol adds a level of indirection.

<br>
<a rel="license" href="https://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://licensebuttons.net/l/by/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">keybrd tutorial</span> by <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd" property="cc:attributionName" rel="cc:attributionURL">Wolfram Volpi</a> is licensed under a <a rel="license" href="https://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd/issues/new" rel="cc:morePermissions">https://github.com/wolfv6/keybrd/issues/new</a>.