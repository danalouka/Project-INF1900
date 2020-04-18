#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#define PORTENSORTIE (0xFF)
#define PORTENENTREE (0x00)


void fermerBouton();
void initialisationBoutonPoussoir();