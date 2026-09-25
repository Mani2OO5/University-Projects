#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


void TWI_Start(void) {
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
}

void TWI_Stop(void) {
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void TWI_Write(int data) {
    TWDR = data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
}

int TWI_Read_ACK(void) {
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}

int TWI_Read_NACK(void) {
    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}


int dec2bcd(int val) {
    return ((val / 10) << 4) | (val % 10);
}

int bcd2dec(int val) {
    return ((val >> 4) * 10) + (val & 0x0F);
}


void DS1307_ReadTime(int *h, int *m, int *s) {
    TWI_Start();
    TWI_Write(0xD0);     
    TWI_Write(0x00);     

    TWI_Start();
    TWI_Write(0xD1);     

    *s = bcd2dec(TWI_Read_ACK());
    *m = bcd2dec(TWI_Read_ACK());
    *h = bcd2dec(TWI_Read_NACK());

    TWI_Stop();
}
void DS1307_ReadDate(int *y, int *m, int *d) {
    TWI_Start();
    TWI_Write(0xD0);     
    TWI_Write(0x04);     

    TWI_Start();
    TWI_Write(0xD1);     

    *d = bcd2dec(TWI_Read_ACK());
    *m = bcd2dec(TWI_Read_ACK());
    *y = bcd2dec(TWI_Read_NACK());

    TWI_Stop();
}

void TWI_Init(void) {
    TWSR = 0x00;
    TWBR = 32;   
}
int day_of_week( int year, int month, int day){

    if (month < 3){
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year /100;
    int h = (day + (13*(month + 1))/5 + k + (k/4) + (j/4) + (5*j)) % 7;
    
    return h;
}
int main(void) {

    DDRA = 0xFF; // Set PORTA as output for segments
    DDRB = 0xFF;
    DDRC = 0xFF; // Set PORTD as output for 6 7-segment displays  

    TWI_Init();

    int hour   = 0;
    int minute = 0;
    int second = 0;

    int year  = 0;  
    int month = 0;
    int day   = 0;


    
    int segment[10] = {
        0xC0, 0xF9, 0xA4, 0xB0, 0x99,
        0x92, 0x82, 0xF8, 0x80, 0x90
    };

    while (1) {

        
        DS1307_ReadTime(&hour, &minute, &second);
        DS1307_ReadDate(&year, &month, &day);

        int calender_digits[6];

        calender_digits[0] = year / 10;
        calender_digits[1] = year % 10;
        calender_digits[2] = month / 10;
        calender_digits[3] = month % 10;
        calender_digits[4] = day / 10;
        calender_digits[5] = day % 10;

        int clock_digits[6];

        clock_digits[0] = hour / 10;
        clock_digits[1] = hour % 10;
        clock_digits[2] = minute / 10;
        clock_digits[3] = minute % 10;
        clock_digits[4] = second / 10;
        clock_digits[5] = second % 10;

        int i;  
        for (i = 0; i < 6; i++) {

            PORTA = segment[clock_digits[i]];

            if(i == 1 || i == 3)
            {
                PORTB = segment[calender_digits[i]] - 0x80 ;
            }
            else
            {
                PORTB = segment[calender_digits[i]];
            }

            PORTC = (1 << i + 2);
            _delay_ms(50);
        }
    }

    return 0;
}
