#define F_CPU 8000000UL
#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h>
#include "sensor.h"
#include "minuterie.h"
#include "LCM.h"
#include "bouton.h"
#include "delai.h"
#include "Afficheur7segments.h"
#include "manoeuvre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum Mode {DETECT, MANVRE};
volatile Mode mode = DETECT;
volatile uint16_t compteur = 0;

ISR(TIMER1_COMPA_vect) {
    compteur++;
}

ISR(INT1_vect) {

    mode = MANVRE;
}

void initialisationPorts() {

    cli();
    DDRA = 0b11111000; 
    DDRB = 0xff; 
    DDRC = 0xff; 
    DDRD = 0b11110111;
    sei(); 
}

int modeDetection() {

    //fermer DEL, oscilloscopes et afficheur7-5.
    PORTD = 0x00;
    PORTC=0x00;
    
    //sensor gauche
    compteur = 0;
    obtenirDelaiEcho(0x01);
    double distanceG = calculerDistance(compteur);                    //calcul de distnace a partiedu temps en microsecondes.
    int onesNumG = ((int)distanceG);
    int tenthNumG = ((int)round(distanceG*10))%10;
    if (int(distanceG*10)%10 == 9) {
        onesNumG++;
        tenthNumG = 0;
    }
    
    //sensor devant 
    compteur = 0;
    obtenirDelaiEcho(0x02);
    double distanceDe = calculerDistance(compteur);                   //calcul de distnace a partiedu temps en microsecondes.
    int onesNumDe = ((int)distanceDe);
    int tenthNumDe = ((int)round(distanceDe*10))%10;
    if (int(distanceDe*10)%10 == 9) {
        onesNumDe++;
        tenthNumDe = 0;
    }

    //sensor droit 
    compteur = 0;
    obtenirDelaiEcho(0x04);
    double distanceDr = calculerDistance(compteur);                   //calcul de distnace a partie du temps en microsecondes.
    int onesNumDr = ((int)distanceDr);
    int tenthNumDr = ((int)round(distanceDr*10))%10;
    if (int(distanceDr*10)%10 == 9) {
        onesNumDr++;
        tenthNumDr = 0;
    }

    //affichage : 
    LCM disp(&DDRB, &PORTB);

    affichageSensorDetection(onesNumG, tenthNumG, disp, 0);    //afficher sensor gauche 
    affichageSensorDetection(onesNumDe, tenthNumDe, disp, 6);  //afficher sensor devant
    affichageSensorDetection(onesNumDr, tenthNumDr, disp, 12); //afficher sensor droit

    int manoeuvre = determinerManoeuvre(onesNumG, onesNumDe, onesNumDr);
    return manoeuvre;

}

void modeManoeuvre(int numeroManoe) {

    afficherManoeuvre(numeroManoe);

    switch (numeroManoe) {

        case 1 : 
            manoeuvre1();
            break;
            

        case 2 : 
            manoeuvre2();
            break; 
    

        case 3 : 
            manoeuvre3();
            break;
        

        case 4: 
            manoeuvre4();
            break;

        case 5 : 
            manoeuvre5();
            break;
        
        case 6 : 
            manoeuvre6();
            break;
            
        case 0 : 
            //attendre deux secondes.
            _delay_ms(2000);        
            break;
    }
    
}

int main() {

    initialisationPorts();
    initialisationBoutonPoussoir();
    int numeroMan = 0; 

    while(true) {
        
        switch (mode) {

            case DETECT: 
                numeroMan = modeDetection();
                break;

            case MANVRE:
                modeManoeuvre(numeroMan);
                mode = DETECT;
                break;

        }
        
  
    }
    
    return 0; 
}
    

 