#ifndef __AVR_ATmega328__
	#define __AVR_ATmega328__
#endif

#include <avr/io.h>

#define F_CPU 1000000UL

#include <util/delay.h>

int main(void)

{

                DDRD |= (1 << PIND0);//PORTD pin0 as INPUT

                DDRC=0xFF;//PORTC as OUTPUT

                int UBRR_Value = 25; // 2400 baud rate

                UBRR0H = (unsigned char) (UBRR_Value >> 8);

                UBRR0L = (unsigned char) UBRR_Value;

                UCSR0B = (1 << RXEN0) | (1 << TXEN0);

                UCSR0C = (1 << USBS0) | (3 << UCSZ00);

                unsigned char receiveData;

                while (1)

                {

                                while (! (UCSR0A & (1 << RXC0)) );

                                receiveData = UDR0;

                                if (receiveData == 0b11110000)

                                {

                                          PORTC ^= (1 << PINC0);

                                           _delay_ms(220);

                                }

                }

}              
