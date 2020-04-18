#include "manoeuvre.h"


void manoeuvre1()
{
    ajustementPWM(VITESSE_INITIALE_MAN1, VITESSE_INITIALE_MAN1);
    PORTD = ROUES_AVANCENT;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN1;
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN1;

    for (uint8_t i = vitesseActuelleGauche; i > (VITESSE_IINTERMEDIAIRE_MAN1 - 1); i = i - SPEED_CHANGE_RATE_MAN1)
    {

        ajustementPWM(vitesseActuelleDroite, i);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN1, determinerChiffre(i / 10), determinerChiffre(i % 10), determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
        vitesseActuelleGauche = i;
    }

    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));

    for (uint8_t i = vitesseActuelleGauche; i < (VITESSE_FINALE_MAN1 + 1); i = i + SPEED_CHANGE_RATE_MAN1)
    {
        ajustementPWM(VITESSE_FINALE_MAN1, i);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN1, determinerChiffre(i / 10), determinerChiffre(i % 10), determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
        vitesseActuelleGauche = i;
    }
    afficherSequenceChiffres(2000, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}
void manoeuvre2()
{

    ajustementPWM(VITESSE_INITIALE_MAN2, VITESSE_INITIALE_MAN2);
    PORTD = ROUES_AVANCENT;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN2;
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN2;

    for (uint8_t i = vitesseActuelleDroite; i > (VITESSE_IINTERMEDIAIRE_MAN2 - 1); i = i - SPEED_CHANGE_RATE_MAN2)
    {

        ajustementPWM(i, vitesseActuelleGauche);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN2, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10), determinerChiffre(i / 10), determinerChiffre(i % 10));
        vitesseActuelleDroite = i;
    }

    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));

    for (uint8_t i = vitesseActuelleDroite; i < (VITESSE_FINALE_MAN2 + 1); i = i + SPEED_CHANGE_RATE_MAN2)
    {
        ajustementPWM(i, vitesseActuelleGauche);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN2, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10), determinerChiffre(i / 10), determinerChiffre(i % 10));
        vitesseActuelleDroite = i;
    }
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}
void manoeuvre3()
{
    ajustementPWM(VITESSE_INITIALE_MAN3, VITESSE_INITIALE_MAN3);
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN3;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN3;
    PORTD = ROUE_GAUCHE_RECULE;
    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    vitesseActuelleDroite = VITESSE_IINTERMEDIAIRE_MAN3;
    vitesseActuelleGauche= VITESSE_IINTERMEDIAIRE_MAN3;
    ajustementPWM(vitesseActuelleDroite, vitesseActuelleGauche);
    PORTD = ROUES_AVANCENT;
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    ajustementPWM(VITESSE_INITIALE_MAN3, VITESSE_INITIALE_MAN3);
    vitesseActuelleDroite = VITESSE_INITIALE_MAN3;
    vitesseActuelleGauche = VITESSE_INITIALE_MAN3;
    PORTD = ROUE_DROITE_RECULE;
    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    ajustementPWM(VITESSE_FINALE_MAN3, VITESSE_FINALE_MAN3);
    vitesseActuelleDroite = VITESSE_FINALE_MAN3;
    vitesseActuelleGauche = VITESSE_FINALE_MAN3;
    PORTD = ROUES_AVANCENT;
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}
void manoeuvre4()
{
    ajustementPWM(VITESSE_INITIALE_MAN4, VITESSE_INITIALE_MAN4);
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN4;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN4;
    PORTD = ROUE_DROITE_RECULE;
    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    vitesseActuelleDroite = VITESSE_IINTERMEDIAIRE_MAN4;
    vitesseActuelleGauche = VITESSE_IINTERMEDIAIRE_MAN4;
    ajustementPWM(vitesseActuelleDroite, vitesseActuelleGauche);
    PORTD = ROUES_AVANCENT;
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    ajustementPWM(VITESSE_INITIALE_MAN4, VITESSE_INITIALE_MAN4);
    vitesseActuelleDroite = VITESSE_INITIALE_MAN4;
    vitesseActuelleGauche = VITESSE_INITIALE_MAN4;
    PORTD = ROUE_GAUCHE_RECULE;
    afficherSequenceChiffres(DELAI_1000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    ajustementPWM(VITESSE_FINALE_MAN4, VITESSE_FINALE_MAN4);
    vitesseActuelleDroite = VITESSE_FINALE_MAN4;
    vitesseActuelleGauche = VITESSE_FINALE_MAN4;
    PORTD = ROUES_AVANCENT;
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}
void manoeuvre5()
{
    ajustementPWM(VITESSE_INITIALE_MAN5, VITESSE_INITIALE_MAN5);
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN5;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN5;
    PORTD = ROUE_DROITE_RECULE;
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
    ajustementPWM(VITESSE_IINTERMEDIAIRE_MAN5, VITESSE_IINTERMEDIAIRE_MAN5);
    vitesseActuelleDroite = VITESSE_IINTERMEDIAIRE_MAN5;
    vitesseActuelleGauche = VITESSE_IINTERMEDIAIRE_MAN5;
    PORTD = ROUES_AVANCENT;
    for (uint8_t i = vitesseActuelleGauche; i < (VITESSE_FINALE_MAN5+1); i = i + SPEED_CHANGE_RATE_MAN5)
    {
        ajustementPWM(i, i);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN5, determinerChiffre(i / 10), determinerChiffre(i % 10), determinerChiffre(i / 10), determinerChiffre(i % 10));

        vitesseActuelleGauche = i;
        vitesseActuelleDroite = i;
    }
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}
void manoeuvre6()
{
    ajustementPWM(VITESSE_INITIALE_MAN6, VITESSE_INITIALE_MAN6);
    uint8_t vitesseActuelleDroite = VITESSE_INITIALE_MAN6;
    uint8_t vitesseActuelleGauche = VITESSE_INITIALE_MAN6;
    PORTD = ROUES_AVANCENT;

    for (uint8_t i = vitesseActuelleGauche; i > (VITESSE_FINALE_MAN6-1); i = i - SPEED_CHANGE_RATE_MAN6)
    {
        ajustementPWM(i, i);

        afficherSequenceChiffres(DELAI_CHANGEMENT_VITESSE_MAN6, determinerChiffre(i / 10), determinerChiffre(i % 10), determinerChiffre(i / 10), determinerChiffre(i % 10));

        vitesseActuelleGauche = i;
        vitesseActuelleDroite = i;
    }
    afficherSequenceChiffres(DELAI_2000MS, determinerChiffre(vitesseActuelleGauche / 10), determinerChiffre(vitesseActuelleGauche % 10),
                             determinerChiffre(vitesseActuelleDroite / 10), determinerChiffre(vitesseActuelleDroite % 10));
}