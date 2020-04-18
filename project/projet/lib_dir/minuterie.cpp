#include "minuterie.h"

void fermerMinuterie()
{
	// mode CTC du timer 1 avec horloge divisée par 1024
	// interruption après la durée spécifiée

	TCNT1 = 0;
	OCR1A = 0;
	TCCR1A = 0;
	TCCR1B = 0;  
	TCCR1C = 0;
	TIMSK1 = 0; 
}

void partirMinuterie(uint16_t duree) {

	// mode CTC du timer 1
        // interruption après la durée spécifiée
        TCNT1 = 0;
        OCR1A = duree;
        TCCR1A |= (1 << COM1A1) | (1 << COM1A0) ;
        TCCR1B |= (1 << WGM12)  | (1 << CS10);   //no prescaling
        TCCR1C = 0;
        TIMSK1 |= (1 << OCIE1A); 
}