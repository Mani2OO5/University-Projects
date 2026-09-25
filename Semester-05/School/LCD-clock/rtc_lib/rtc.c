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