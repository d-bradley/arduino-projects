/*
 * @author Daniel Bradley
 * CSI454 Lab 2
 * 
 * Code allows for LEDs to be turned on and off with 
 * pushbuttons.
*/
#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{
  PORTD |= (1 << PD2);
  PORTD |= (1 << PD3);
  PORTD |= (1 << PD4);
  DDRB = 0xff;
  
  while (1) 
  {
    if (bit_is_clear(PIND, PD4)) 
    {
      PORTB = 0b00000100;
    }
    else if (bit_is_clear(PIND, PD3)) 
    {
      PORTB = 0b00001000;
    }
    if (bit_is_clear(PIND, PD2)) 
    {
      PORTB = 0b00010000;                                 
    }
    else {                                             
      PORTB = 0b11100011;
    }
  }                                                 
  return 0;
}
