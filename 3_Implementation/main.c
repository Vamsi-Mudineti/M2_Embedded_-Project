#ifndef __AVR_ATmega328__
	#define __AVR_ATmega328__
#endif

#include <avr/io.h>

//header to enable data flow control over pins

#define F_CPU 1000000UL

//telling controller crystal frequency attached

#include <util/delay.h>
//#include <util/setbaud.h>

//header to enable delay function in program

int main(void)

{

                DDRD |= 1 << PIND1;//pin1 of portD as OUTPUT

                DDRD &= ~(1 << PIND0);//pin0 of portD as INPUT

                PORTD |= 1 << PIND0;

                int UBBRValue = 25;//AS described before setting baud rate

                //Put the upper part of the baud number here (bits 8 to 11)


                UBRR0H = (unsigned char) (UBBRValue >> 8);

                //Put the remaining part of the baud number here

                UBRR0L = (unsigned char) UBBRValue;

                //Enable the receiver and transmitter

                UCSR0B = (1 << RXEN0) | (1 << TXEN0);

                //Set 2 stop bits and data bit length is 8-bit

                UCSR0C = (1 << USBS0) | (3 << UCSZ00);

                while (1)

                {

                                if (bit_is_clear(PINC,0))//once button is pressed

                                {

                                                while (! (UCSR0A & (1 << UDRE0)) );

                                                {

                                                                UDR0 = 0b11110000;//once transmitter is ready sent eight bit data

                                                }

                                                // Get that data outa here!

                                                _delay_ms(220);

                                }
                }
}