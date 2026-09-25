#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int i;

int main(void)
{
    i = 0;
    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;
    DDRD = 0xFF;
    int time = 0;
    while (1)
    {
        int time_digits[2];
        time_digits[0] = time / 10;
        time_digits[1] = time % 10;

        PORTC = (1 << i);

        PORTB = 0x04;
        _delay_ms(1200);
        PORTB = 0x02;
        _delay_ms(300);
        PORTB = 0x01;
        _delay_ms(1500);
        time += 15;

 
      
  


    i++;
    if  (i == 8) { i = 0; }
    }

}
