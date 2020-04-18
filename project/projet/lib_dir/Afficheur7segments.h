#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#include "delai.h"
#define UN 0xf7
#define DEUX 0xef
#define TROIS 0xdf
#define QUATRE 0xbf
#define CINQ 0x7f
#define Zero 0xfc
#define Un 0x60
#define Deux 0xda
#define Trois 0xf2
#define Quatre 0x66
#define Cinq 0xb6
#define Six 0xbe
#define Sept 0xe0
#define Huit 0xfe
#define Neuf 0xf6
#define Moins 0x02


//enum positionSeptSegments{UN=0xf7,DEUX=0xef,TROIS=0xdf,QUATRE=0xbf,CINQ=0x7f};
//enum valeurChiffre{Zero=0xfc, Un=0x60, Deux=0xda, Trois=0xf2, Quatre=0x66, 
    //Cinq=0xb6, Six=0xbe, Sept=0xe0, Huit=0xfe, Neuf=0xf6, Moins=0x02};

void affichageChiffreSurLapseTemps(unsigned int position, uint8_t chiffre,uint8_t temps);
void afficherSequenceChiffres(uint8_t temps, uint8_t chiffre1, uint8_t chiffre2, uint8_t chiffre3, uint8_t chiffre4);
int determinerChiffre(uint8_t chiffre);
void passageVitesse(double ratio, uint8_t premierNombre, uint8_t deuxiemeNombre, uint8_t troisiemeNombre, uint8_t quatriemeNombre);