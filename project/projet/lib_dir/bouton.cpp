#include "bouton.h"

void fermerBouton() {

	cli();

	EIMSK = 0;  // Le inturrupt du pin est desactivé.
	EICRA = 0;

}

void initialisationBoutonPoussoir(void)
{

    cli();

    EIMSK |= (1 << INT1);

    EICRA |= (1 << ISC11) ;

    sei();
}