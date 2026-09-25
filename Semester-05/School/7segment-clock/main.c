#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
int main()
{
    DDRC = 0xFF; // Set PORTC as output for segments 
    DDRD = 0xFF; // Set PORTD as output for 6 7-segment displays
    uint8_t second  = 0;
    uint8_t minute  = 0;
    uint8_t hour    = 0;
    while (1)
    {

        _delay_ms(1000);
        second++;
        if(second>=60){ second=0; minute++; }
        if(minute>=60){ minute=0; hour++; }
        if(hour>=24){ hour=0; }

        uint8_t segment[10] = 
        {
            0xC0, 0xF9, 0xA4, 0xB0, 0x99,
            0x92, 0x82, 0xF8, 0x80, 0x90
        };

        int digits[6];

        digits[0] = hour / 10;
        digits[1] = hour % 10;
        digits[2] = minute / 10;
        digits[3] = minute % 10;
        digits[4] = second / 10;
        digits[5] = second % 10;
       

        uint8_t i;
        for (i = 0; i <= 6; i++)
        {
            PORTC = segment[digits[i]];
            PORTD =( 1 << i );
            _delay_ms(1000);
        }  
    }
    return 0;
}
