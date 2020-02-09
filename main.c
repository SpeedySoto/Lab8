
/*	Partner(s) Name & E-mail: David Wilson
 *	Lab Section: 023
 *	Assignment: Lab #8  Exercise #1 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template 
 * 	or example code, is my own original work.
 */


#include <avr/io.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);

}

int main(void)
{

	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	ADC_init();
	
	unsigned short A2D = ADC;
	//unsigned char my_char = (char)my_short; // my_char = 0xCD
	//my_char = (char)(my_short >> 4); // my_char = 0xBC
	
	while (1)
	{
		PORTB = (char) A2D;
		PORTD = (char) (A2D >> 4);
		A2D = ADC;
	}
}
