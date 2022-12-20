#include <avr/io.h>    
#include <timer.h> 
#include <avr/interrupt.h>
//load needed libraries

//------------ASYNCHRONOUS PWM CONTROL FOR 4 SERVOS----------------//
//-----------------------By Benjamin Nimmerrichter and Jakub Tauber//
//macros and variable declarations
#define OFFSET 63 // minimum for PW ~ 1ms , max for a PW ~ 2ms => 125
#define OFFSET2 16 // approx. quarter of ofset for timer 2
#define CONST 0.34444f // constant used to calculate 0-180 degrees of servo rotation (125-62)/180=0,34444 optimising division
#define CONST2 0.086111f // constant/4 for timer 2
uint8_t duty = 128; //duty cycle 0-255
uint8_t degrees0 = 0;
uint8_t degrees1 = 0;
uint8_t degrees2 = 0;
uint8_t degrees3 = 0;

uint8_t i = 0;
uint8_t j = 0;
uint8_t k = 0;
uint8_t l = 0;


int main(void)
{
  //enable interrupts on timer 0 and set the interrupt time
  TIM0_overflow_interrupt_enable();
  TIM0_overflow_16ms();


  //prescaler of timer 1 to clk(I/O)/256
  TCCR1B |= (1<<CS12) | (1<<WGM12);
  //prescaler of timer 2 to clk(T2S)/1024
  TCCR2B |= (1<<CS22) | (1<<CS21) | (1<<CS20);

  //set COM1A and COM1B to 1 for fast PWM output and WGM to FAST PWM mode
  TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10) | (1<<WGM11);
  //set COM2A and COM2B to 1 for fast PWM output and WGM to FAST PWM mode 
  TCCR2A |= (1<<COM2A1) | (1<<COM2B1) | (1<<WGM20) | (1<<WGM21);
  //set PB1, PB2 and PB3 as outputs
  DDRB |= (1<<1)|(1<<2)|(1<<3); 
  //set PD3 as output
  DDRD |= (1<<3);

  sei();
  OCR2A = 125;
  OCR2B = 63;
  while (1)
  {

  }
  return 0;
}

ISR(TIMER0_OVF_vect)
{
  //---timer 1 PWM---
  if (degrees0>=180)//setting direction and speed of rotation for servo on PB1
  {
    i = -5;
  }
  else if (degrees0==0)//setting direction and speed of rotation for servo on PB1
  {
    i = 5;
  }
  degrees0 = degrees0+i;
  duty = (uint8_t)((float)OFFSET+(CONST*((float)degrees0))); //calculates the value for the OCR1A register to be betweeen the specified 1 ms and 2 ms
  OCR1A = duty;

  if (degrees1>=180)//setting direction and speed of rotation for servo on PB2
  {
    j = -3;
  }
  else if (degrees1==0)//setting direction and speed of rotation for servo on PB2
  {
    j = 3;
  }

  degrees1 = degrees1+j; 
  duty = (uint8_t)((float)OFFSET+(CONST*((float)degrees1)));
  OCR1B = duty;

  //---timer 2 PWM---
  if (degrees2>=180)//setting direction and speed of rotation for servo on PB3
  {
    k = -1;
  }
  else if (degrees2==0)//setting direction and speed of rotation for servo on PB3
  {
    k = 1;
  }
  degrees2 = degrees2+k;
  duty = (uint8_t)((float)OFFSET2+(CONST2*((float)degrees2))); //calculates the value for the OCR2A register to be betweeen the specified 1 ms and 2 ms
  OCR2A = duty;

  if (degrees3>=180)//setting direction and speed of rotation for servo on PD3
  {
    l = -2;
  }
  else if (degrees3==0)//setting direction and speed of rotation for servo on PD3
  {
    l = 10;
  }

  degrees3 = degrees3+l; 
  duty = (uint8_t)((float)OFFSET2+(CONST2*((float)degrees3)));
  OCR2B = duty;
}