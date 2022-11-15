/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects chips and
 * modules that are connected to the SDA and SCL signals.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1, send one I2C (TWI) address every 33 ms,
 *           and test all combinations. Send information about scanning
 *           process to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize I2C (TWI)
    twi_init();

    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to test one I2C address
    // Set prescaler to 33 ms and enable interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("Scan I2C bus for devices:\r\n");

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Test one I2C Slave address from the range 8 to 119.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
   char uart_string[3];

    /* DSC3231 */

    /*twi_start((0x68<<1) + TWI_WRITE);
    twi_write(0x00);
    twi_stop();
    twi_start((0x68<<1) + TWI_READ);
    time_sec = twi_read_ack();
    time_min = twi_read_nack();
    twi_stop();
    itoa(time_min, uart_string, 10);
    uart_puts(uart_string);
    uart_putc(':');
    itoa(time_sec, uart_string, 10);
    uart_puts(uart_string);
    uart_puts("\r\n");
    */
    /* DHT12 */

    twi_start((0x5c<<1) + TWI_WRITE);
    twi_write(0x02);
    twi_stop();

    twi_start((0x5c<<1) + TWI_READ);
    temp = twi_read_ack();
    itoa(temp, uart_string, 10);
    uart_puts(uart_string);
    uart_putc('.');
    temp = twi_read_nack();
    twi_stop();
    itoa(temp, uart_string, 10);
    uart_puts(uart_string);
    uart_puts(" deg; ");

    twi_start((0x5c<<1) + TWI_WRITE);
    twi_write(0x00);
    twi_stop();

    twi_start((0x5c<<1) + TWI_READ);
    temp = twi_read_ack();
    itoa(temp, uart_string, 10);
    uart_puts(uart_string);
    uart_putc('.');
    temp = twi_read_nack();
    twi_stop();
    itoa(temp, uart_string, 10);
    uart_puts(uart_string);
    uart_puts(" percent");
    uart_puts("\r\n");

    
    
    
    /*
    if (ack==0)
    {
      itoa(sla,string, 10);
      uart_puts(string);
      uart_puts("\r\n");
    }

    twi_stop();

    if (sla >=119)
    {
      sla = 8;
      uart_puts("Repeating scan\r\n");
    }

    // Test ACK/NACK value obtained from I2C bus and send info to UART
    */
}