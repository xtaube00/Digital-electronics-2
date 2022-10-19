# Lab 3: YOUR_FIRSTNAME LASTNAME

### Overflow times

1. Complete table with overflow times.

  | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16us | 128us | -- | 1024us | -- | 4096us | 16384us |
   | Timer/Counter1 | 16 | 4096us | 32768us | -- | 262144us | -- |1,049s | 4,194s |
   | Timer/Counter2 | 8  | 16us | 128us | 512us | 1024us | 2048us | 4096us | 16384us |


### Interrupts

2. In `timer.h` header file, define macros also for Timer/Counter2. Listing of part of the header file with settings for Timer/Counter2. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   /**
    * @name  Definitions for 8-bit Timer/Counter2
    * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
     #define TIM2_stop()             TCCR2B &= ~((1<<CS22) | (1<<CS21) | (1<<CS20));
   // #define TIM2_overflow_16us()     TCCR2B &= ~((1<<CS22) | (1<<CS21)); TCCR2B |= (1<<CS20);
   #define TIM2_overflow_128us()    TCCR2B &= ~((1<<CS22) | (1<<CS20)); TCCR2B |= (1<<CS21);
   #define TIM2_overflow_512us()	TCCR2B &= ~(1<<CS22); TCCR2B |= (1<<CS21) | (1<<CS20);
  #define TIM2_overflow_1ms()   TCCR2B &= ~((1<<CS21) | (1<<CS20)); TCCR2B |= (1<<CS22);
  #define TIM2_overflow_2ms()		TCCR2B &= ~(1<<CS21); TCCR2B |= (1<<CS22) | (1<<CS20);
  #define TIM2_overflow_4ms()      TCCR2B &= ~(1<<CS20); TCCR2B |= (1<<CS22) | (1<<CS21);
  #define TIM2_overflow_16ms()      TCCR2B |= ((1<<CS22) | (1<<CS21) | (1<<CS20));

  /**
  * @brief Defines interrupt enable/disable modes for Timer/Counter1.
  */
  // #define TIM2_overflow_interrupt_enable()    TIMSK2 |= (1<<TOIE2);
  // #define TIM2_overflow_interrupt_disable()   TIMSK2 &= ~(1<<TOIE2);
  /**
    */
   // WRITE YOUR CODE HERE
   
   ```