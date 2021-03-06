#ifndef _VVC_MAIN_H
#define _VVC_MAIN_H

#include <stdint.h>
#include <string.h>

#if defined( VVC_F0 )
  #include "stm32f0xx.h"
#elif defined( VVC_F1 )
  #include "stm32f1xx.h"
#elif defined( VVC_L0 )
  #include "stm32l0xx.h"
#elif defined( VVC_G0 )
  #include "stm32g0xx.h"
#elif defined( VVC_L4 )
  #include "stm32l4xx.h"
#elif defined( VVC_WB )
  #include "stm32wbxx.h"
#endif

// Global defines.
// (LED pin depends on your board)
#if defined( STM32F030x6 ) || defined( STM32F031x6 )
  #define LEDEN   ( RCC_AHBENR_GPIOAEN )
  #define PoLED   ( GPIOA )
  #define PiLED   ( 1 )
#elif defined( STM32F103x8 ) || defined( STM32F103xB )
  #define LEDEN   ( RCC_APB2ENR_IOPBEN )
  #define PoLED   ( GPIOB )
  #define PiLED   ( 12 )
#elif defined( STM32L031x6 )
  #define LEDEN   ( RCC_IOPENR_GPIOBEN )
  #define PoLED   ( GPIOB )
  #define PiLED   ( 3 )
#elif defined( STM32G071xB )
  #define LEDEN   ( RCC_IOPENR_GPIOCEN )
  #define PoLED   ( GPIOC )
  #define PiLED   ( 6 )
#elif defined( STM32L496xG )
  #define LEDEN   ( RCC_AHB2ENR_GPIOAEN )
  #define PoLED   ( GPIOA )
  #define PiLED   ( 15 )
#elif defined( STM32WB55xE )
  #define LEDEN   ( RCC_AHB2ENR_GPIOEEN )
  #define PoLED   ( GPIOE )
  #define PiLED   ( 4 )
#endif

// Pre-defined memory locations for program initialization.
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;

uint32_t core_clock_hz;
volatile uint32_t systick;

#endif
