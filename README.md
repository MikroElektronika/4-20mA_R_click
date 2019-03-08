![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# 4-20mA_R Click

---

- **CIC Prefix**  : C420MAR
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Sep 2018.

---

### Software Support

We provide a library for the 4-20mA_R Click on our [LibStock](https://libstock.mikroe.com/projects/view/564/4-20ma-r-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control 4-20mA R Click board. 
Library performs the communication with the device via SPI driver by writting to registers and by reading from registers.
Library get ADC value from MCP3201 chip and 
convert 12-bit ADC value to input ADC value range from 4 mA to 20 mA.

Key functions :

- ``` uint16_t c420mar_readData() ``` - Generic read 12-bit data function
- ``` uint16_t c420mar_getADCvalue() ``` - Function get ADC value from MCP3201 chip
- ``` float c420mar_convertADC( uint16_t inputADC ) ``` - Convert ADC value function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI and LOG structures,
     set CS (chip select) and INT ( enable ) pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of 4-20mA R Click board.
     Read input 12-bit ADC value from the MCP3201 chip.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the ADC value changes.


```.c

void applicationTask()
{
    valueADC = c420mar_getADCvalue();
    
    inputADC = c420mar_convertADC( valueADC );

    if ( ( ( valueADC - valueADCOld ) > sensitivity ) && ( ( valueADCOld - valueADC ) > sensitivity ) )
    {
        mikrobus_logWrite( " Input ADC: ", _LOG_TEXT );
        FloatToStr( inputADC, logText );
        mikrobus_logWrite( logText, _LOG_TEXT );
        mikrobus_logWrite( " mA", _LOG_LINE );
        mikrobus_logWrite("------------------------", _LOG_LINE);

        valueADCOld = valueADC;
        Delay_100ms();
     }

    Delay_1sec();
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/564/4-20ma-r-click-example) page.

Other mikroE Libraries used in the example:



**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
