#include "PWM.h"

void PWM(int tempsVoulu, float pourcentage, int frequence) //tempsVoulu en secondes et frequence en HZ
{
	int b = (int)((pow(10,3) / ((float)frequence))); //b est la periode en us
	int a = b * (pourcentage / 100); //a : periode quand PWM est a 1, en us

	for (int i = 0; i < ((tempsVoulu*pow(10,3))/b); i++)
	{
		PORTB = 0xff;
		delai_ms(a);
		PORTB = 0x00;
		delai_ms(b - a);
	}
}


void ajustementPWM(int pourcentageRoueDroite, int pourcentageRoueGauche) //tempsVoulu en secondes et frequence en HZ
{
	 const uint8_t TOP = 0xFF;
	OCR1A = TOP * (100 - pourcentageRoueDroite)/100;

	OCR1B = TOP * (100 - pourcentageRoueGauche)/100;

	// division d'horloge par 8 - implique une frequence de PWM fixe

	TCCR1A = (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0) | (1 << WGM10);

	TCCR1B = (1 << CS11);

	TCCR1C = 0;
}