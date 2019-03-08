/*
Example for 4-20mA_R Click

    Date          : Sep 2018.
    Author        : Nenad Filipovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI and LOG structures,
     set CS (chip select) and INT ( enable ) pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of 4-20mA R Click board.
     Read input 12-bit ADC value from the MCP3201 chip.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the ADC value changes.


*/

#include "Click_4-20mA_R_types.h"
#include "Click_4-20mA_R_config.h"


char logText[50];
uint16_t valueADC;
float inputADC;
uint16_t valueADCOld = 0;
uint16_t sensitivity = 10;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_C420MAR_SPI_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    c420mar_spiDriverInit( (T_C420MAR_P)&_MIKROBUS1_GPIO, (T_C420MAR_P)&_MIKROBUS1_SPI );
    
    mikrobus_logWrite("     4-20mA R Click",_LOG_LINE);
    mikrobus_logWrite("------------------------", _LOG_LINE);
    Delay_100ms();
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}