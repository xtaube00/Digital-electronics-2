
/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
//#include <util/delay.h> // Functions for busy-wait delay loops
#include <timer.h> 
//#include <uart.h>
#include <avr/interrupt.h>
 

// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#define OFFSET 32 // minimum for 0,9923ms PW
#define CONST 0.35f // constant 63/180=0,35
uint8_t duty = 128;
short degrees0 = 0;
short degrees1 = 0;

short i = 0;
short j = 0;

int main(void)
{
  SREG |= (1<<7);
  //set WGM to fast PWM (mode 7)
  TCCR1B |= (1<<CS12);
  //duty cycle
  //OCR1A = 0x3F; //48+15=63
  //OCR1B = 0x20; //32
  //set COM0A and COM0B to 1 for fast PWM output
  TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10) | (1<<WGM11)| (1<<WGM12); TCCR1A &=~((1<<COM1A0) | (1<<COM1B0) | (1<<WGM13));
  //OCR0B = 0x80;
  DDRB |= (1<<1)|(1<<2); 
  TIM0_overflow_interrupt_enable();
  TIM0_overflow_4s();
  sei();

  while (1)
  {

  }
  return 0;
}

ISR(TIMER0_OVF_vect)
{
  
  if (degrees0>=120)
  {
    i = 5;
  }
  else if (degrees0==0)
  {
    i = -5;
  }
   degrees0 = degrees0+i;
   duty = (uint8_t)((float)OFFSET+(CONST*((float)degrees0)));
  OCR1A = duty;

  if (degrees1>=120)
  {
    j = 3;
  }
  else if (degrees1==0)
  {
    j = -3;
  }

   degrees1 = degrees1+j; 
  duty = (uint8_t)((float)OFFSET+(CONST*((float)degrees1)));
  OCR1B = duty;
}
 