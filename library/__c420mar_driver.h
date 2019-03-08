/*
    __c420mar_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __c420mar_driver.h
@brief    4-20mA_R Driver
@mainpage 4-20mA_R Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   C420MAR
@brief      4-20mA_R Click Driver
@{

| Global Library Prefix | **C420MAR** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Sep 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _C420MAR_H_
#define _C420MAR_H_

/** 
 * @macro T_C420MAR_P
 * @brief Driver Abstract type 
 */
#define T_C420MAR_P    const uint8_t*

/** @defgroup C420MAR_COMPILE Compilation Config */              /** @{ */

   #define   __C420MAR_DRV_SPI__                            /**<     @macro __C420MAR_DRV_SPI__  @brief SPI driver selector */
//  #define   __C420MAR_DRV_I2C__                            /**<     @macro __C420MAR_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __C420MAR_DRV_UART__                           /**<     @macro __C420MAR_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup C420MAR_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup C420MAR_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup C420MAR_INIT Driver Initialization */              /** @{ */

#ifdef   __C420MAR_DRV_SPI__
void c420mar_spiDriverInit(T_C420MAR_P gpioObj, T_C420MAR_P spiObj);
#endif
#ifdef   __C420MAR_DRV_I2C__
void c420mar_i2cDriverInit(T_C420MAR_P gpioObj, T_C420MAR_P i2cObj, uint8_t slave);
#endif
#ifdef   __C420MAR_DRV_UART__
void c420mar_uartDriverInit(T_C420MAR_P gpioObj, T_C420MAR_P uartObj);
#endif


/** @defgroup C420MAR_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 12-bit data function
 *
 * @param[in] writeCommand    12-bit data command to write
 *
 * Function write 12-bit data via SPI
 * on the MCP3201 chip.
 */
void c420mar_writeData( uint16_t writeData );

/**
 * @brief Generic read 12-bit data function
 *
 * @return
 * 12-bit data ( 0 - 4095 ) from MCP3201 chip
 *
 * Function read 12-bit ADC value from
 * the MCP3201 chip.
 */
uint16_t c420mar_readData();

/**
 * @brief Get 12- bit ADC value function
 *
 * @return
 * 12-bit data ( 0 - 4095 ) from MCP3201 chip
 *
 * Function read 12-bit ADC value from
 * the MCP3201 chip.
 */
uint16_t c420mar_getADCvalue();

/**
 * @brief Convert ADC value function
 *
 * @param[in] inputADC    12- bit ADC value
 *
 * Function convert 12-bit ADC value to
 * input ADC value range from 4 mA to 20 mA.
 */
float c420mar_convertADC( uint16_t inputADC );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_4-20mA_R_STM.c
    @example Click_4-20mA_R_TIVA.c
    @example Click_4-20mA_R_CEC.c
    @example Click_4-20mA_R_KINETIS.c
    @example Click_4-20mA_R_MSP.c
    @example Click_4-20mA_R_PIC.c
    @example Click_4-20mA_R_PIC32.c
    @example Click_4-20mA_R_DSPIC.c
    @example Click_4-20mA_R_AVR.c
    @example Click_4-20mA_R_FT90x.c
    @example Click_4-20mA_R_STM.mbas
    @example Click_4-20mA_R_TIVA.mbas
    @example Click_4-20mA_R_CEC.mbas
    @example Click_4-20mA_R_KINETIS.mbas
    @example Click_4-20mA_R_MSP.mbas
    @example Click_4-20mA_R_PIC.mbas
    @example Click_4-20mA_R_PIC32.mbas
    @example Click_4-20mA_R_DSPIC.mbas
    @example Click_4-20mA_R_AVR.mbas
    @example Click_4-20mA_R_FT90x.mbas
    @example Click_4-20mA_R_STM.mpas
    @example Click_4-20mA_R_TIVA.mpas
    @example Click_4-20mA_R_CEC.mpas
    @example Click_4-20mA_R_KINETIS.mpas
    @example Click_4-20mA_R_MSP.mpas
    @example Click_4-20mA_R_PIC.mpas
    @example Click_4-20mA_R_PIC32.mpas
    @example Click_4-20mA_R_DSPIC.mpas
    @example Click_4-20mA_R_AVR.mpas
    @example Click_4-20mA_R_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __c420mar_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */