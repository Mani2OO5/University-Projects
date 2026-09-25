#define DS18B20_PIN PC2
#define DS18B20_DDR DDRC
#define DS18B20_PORT PORTC
#define DS18B20_PIN_READ PINC

void ds18b20_reset() {
    DS18B20_DDR |= (1<<DS18B20_PIN);
    DS18B20_PORT &= ~(1<<DS18B20_PIN);
    _delay_us(480);
    DS18B20_DDR &= ~(1<<DS18B20_PIN);
    DS18B20_PORT |= (1<<DS18B20_PIN);
    _delay_us(70);
    _delay_us(410);
}

void ds18b20_write_bit(unsigned char bit) {
    if(bit) {
        DS18B20_DDR |= (1<<DS18B20_PIN);
        DS18B20_PORT &= ~(1<<DS18B20_PIN);
        _delay_us(10);
        DS18B20_DDR &= ~(1<<DS18B20_PIN);
        DS18B20_PORT |= (1<<DS18B20_PIN);
        _delay_us(55);
    } else {
        DS18B20_DDR |= (1<<DS18B20_PIN);
        DS18B20_PORT &= ~(1<<DS18B20_PIN);
        _delay_us(65);
        DS18B20_DDR &= ~(1<<DS18B20_PIN);
        DS18B20_PORT |= (1<<DS18B20_PIN);
    }
}

unsigned char ds18b20_read_bit() {
    unsigned char bit;
    DS18B20_DDR |= (1<<DS18B20_PIN);
    DS18B20_PORT &= ~(1<<DS18B20_PIN);
    DS18B20_DDR &= ~(1<<DS18B20_PIN);
    DS18B20_PORT |= (1<<DS18B20_PIN);
    _delay_us(10);
    bit = (DS18B20_PIN_READ & (1<<DS18B20_PIN)) ? 1 : 0;
    _delay_us(55);
    return bit;
}

void ds18b20_write_byte(unsigned char byte) {
    for(int i=0;i<8;i++) {
        ds18b20_write_bit(byte & 0x01);
        byte >>= 1;
    }
}

unsigned char ds18b20_read_byte() {
    unsigned char byte = 0;
    for(int i=0;i<8;i++) {
        if(ds18b20_read_bit()) byte |= (1<<i);
    }
    return byte;
}

float ds18b20_get_temp() {
    unsigned char temp_l, temp_h;
    int temp;
    float celsius;
    ds18b20_reset();
    ds18b20_write_byte(0xCC);
    ds18b20_write_byte(0x44);
    _delay_ms(750);   // انتظار برای تبدیل دما
    ds18b20_reset();
    ds18b20_write_byte(0xCC);
    ds18b20_write_byte(0xBE);
    temp_l = ds18b20_read_byte();
    temp_h = ds18b20_read_byte();
    temp = (temp_h << 8) | temp_l;
    celsius = temp * 0.0625;
    return celsius;
}