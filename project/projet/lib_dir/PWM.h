#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "delai.h"

void PWM(int tempsVoulu, float pourcentage, int frequence);
void ajustementPWM(int pourcentageRoueDroite, int pourcentageRoueGauche);