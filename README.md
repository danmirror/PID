# PID MOTOR AND ROTARY
> PID basic and rotary metode change interupt for arduino uno

### Contact Me
> <a href="https://me-danuandrean.github.io/">Danu Andrean</a>

## ATMEGA 328  

Description                                    | code
---------------------------------------------- | -------------
Reset                                          |
External Interrupt Request 0  (pin D2)         |  (INT0_vect)
External Interrupt Request 1  (pin D3)         |  (INT1_vect)
Pin Change Interrupt Request 0 (pins D8 to D13)|  (PCINT0_vect)
Pin Change Interrupt Request 1 (pins A0 to A5) |  (PCINT1_vect)
Pin Change Interrupt Request 2 (pins D0 to D7) |  (PCINT2_vect)
Watchdog Time-out Interrupt                    |  (WDT_vect)
Timer/Counter2 Compare Match A                 |  (TIMER2_COMPA_vect)
Timer/Counter2 Compare Match B                 |  (TIMER2_COMPB_vect)
Timer/Counter2 Overflow                        |  (TIMER2_OVF_vect)
Timer/Counter1 Capture Event                   |  (TIMER1_CAPT_vect)
Timer/Counter1 Compare Match A                 |  (TIMER1_COMPA_vect)
Timer/Counter1 Compare Match B                 |  (TIMER1_COMPB_vect)
Timer/Counter1 Overflow                        |  (TIMER1_OVF_vect)
Timer/Counter0 Compare Match A                 |  (TIMER0_COMPA_vect)
Timer/Counter0 Compare Match B                 |  (TIMER0_COMPB_vect)
Timer/Counter0 Overflow                        |  (TIMER0_OVF_vect)
SPI Serial Transfer Complete                   |  (SPI_STC_vect)
USART Rx Complete                              |  (USART_RX_vect)
USART, Data Register Empty                     |  (USART_UDRE_vect)
USART, Tx Complete                             |  (USART_TX_vect)
ADC Conversion Complete                        |  (ADC_vect)
EEPROM Ready                                   |  (EE_READY_vect)
Analog Comparator                              |  (ANALOG_COMP_vect)
2-wire Serial Interface  (I2C)                 |  (TWI_vect)
Store Program Memory Ready                     |  (SPM_READY_vect)
