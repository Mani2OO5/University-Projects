#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd_lib/lcd.h"
#include "rtc_lib/rtc.c"
#include "thermometer_lib/thermometer.c"

char* day_of_week( int year, int month, int day){

    if (month < 3){
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year /100;
    int h = (day + (13*(month + 1))/5 + k + (k/4) + (j/4) + (5*j)) % 7;
    switch (h){
        case 0:
            return "Saturday";
        case 1:
            return "Sunday";
        case 2:
            return "Monday";
        case 3:
            return "Tuesday";
        case 4:
            return "Wednesday";
        case 5:
            return "Thursday";
        case 6:
            return "Friday";
        default:
            return "unknown";
    }
}
int main(void) {

    DDRD = 0xFF;

    lcd_init(LCD_DISP_ON_CURSOR);
    TWI_Init();

    int hour   = 0;
    int minute = 0;
    int second = 0;

    int year  = 0;  
    int month = 0;
    int day   = 0;

    float temp;
    char temperature[16];

    


    while (1) {

        temp = ds18b20_get_temp();
        temperature[0] = 'T';
        temperature[1] = 'e';
        temperature[2] = 'm';
        temperature[3] = 'p';
        temperature[4] = ':';
        temperature[5] = ' ';  
        temperature[6] = (int)temp / 10 + '0';
        temperature[7] = (int)temp % 10 + '0';
        temperature[8] = '.';
        temperature[9] = (int)(temp * 10) % 10 + '0';
        temperature[10] = (int)(temp * 100) % 10 + '0';
        temperature[11] = 223;
        temperature[12] = 'C';
        temperature[13] = '\0';

        DS1307_ReadTime(&hour, &minute, &second);
        DS1307_ReadDate(&year, &month, &day);
        year += 2000;

        char time[9];
        time[0] = '0' + hour/10;
        time[1] = '0' + hour%10;
        time[2] = ':';
        time[3] = '0' + minute/10;
        time[4] = '0' + minute%10;
        time[5] = ':';
        time[6] = '0' + second/10;
        time[7] = '0' + second%10;
        time[8] = '\0';

        char date[11];
        date[0] = '0' + year/1000;
        date[1] = '0' + (year/100)%10;
        date[2] = '0' + (year/10)%10;
        date[3] = '0' + year%10;
        date[4] = '/';
        date[5] = '0' + month/10;
        date[6] = '0' + month%10;
        date[7] = '/';
        date[8] = '0' + day/10;
        date[9] = '0' + day%10;
        date[10] = '\0';


 
        lcd_gotoxy(0,0);
        lcd_puts(time);
        _delay_ms(50);
        lcd_gotoxy(0,1);
        lcd_puts(date);
        _delay_ms(50);
        lcd_gotoxy(0,2);
        lcd_puts(day_of_week(year, month, day));
        _delay_ms(50);
        lcd_gotoxy(0,3);
        lcd_puts(temperature);
        _delay_ms(100);


      
    }

    return 0;
}
