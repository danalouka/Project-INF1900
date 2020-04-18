#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 


void fermerMinuterie ();
void partirMinuterie (uint16_t duree);
