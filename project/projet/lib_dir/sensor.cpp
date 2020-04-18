#include "sensor.h"

void determinerCategorie(int distance, char* outStr) {

    if (distance < 1){
        outStr[0] = 'D';
        outStr[1] = 'N';
        outStr[2] = 'G';
        outStr[3] = 'R';
    }
    else if (distance < 3 && distance >= 1) {
        outStr[0] = 'A';
        outStr[1] = 'T';
        outStr[2] = 'T';
        outStr[3] = 'N';
    }
    else if (distance >= 3) {
        outStr[0] = ' ';
        outStr[1] = 'O';
        outStr[2] = 'K';
        outStr[3] = ' ';
    }

}

void emmettreTrigger() {

    // trigger : Ecrire 1 sur B0
    PORTB = 0xff;                          
    _delay_us(10); 
    PORTB = 0x00;
}

void obtenirDelaiEcho(uint8_t numeroBroche){

    _delay_us(100);
    emmettreTrigger();
    while (!(PINA & numeroBroche)) {}              //attendre alors que sensor A0 gauche est a 0.
    partirMinuterie(37);                           //compteur++ chaque 1 microseconde.
    while (PINA & numeroBroche) {}                 //echo : attendre alors que sensor (A0) est a 1.
    fermerMinuterie();
}

int determinerManoeuvre(int distG, int distDe, int distDr) {

    if (distG >= 3 &&  distDe >= 3 && (distDr < 3 && distDr >= 1))
        return 1;
    else if ((distG < 3 && distG >= 1) && distDe >= 3 &&  distDr >= 3 )
        return 2;
    else if (distG >= 3 && distDe < 1 && distDr < 1)
        return 3;
    else if (distG < 1 && distDe < 1 && distDr >= 3)
        return 4;
    else if (distG < 1  && distDe < 1 && distDr < 1)
        return 5;
    else if ((distG <= 3 && distG >1 ) && distDe >= 3 && (distDr < 3 && distDr >= 1))
        return 6; 
    else
        return 0; //combinaison non evaluee.
    

}

double calculerDistance(int comp){
    return ((double)comp*(0.340/2)/208);
}


void affichageSensorDetection(int ones_num, int tenth_num, LCM &displ, int deplacement) {


    char buffer[3];
    itoa(ones_num, buffer, 10);
    char buffer2[3];
    itoa(tenth_num, buffer2, 10);
    displ[0+deplacement] = buffer;
    cp_wait_ms(1);
    displ[1+deplacement] = ".";
    cp_wait_ms(1);
    displ[2+deplacement] = buffer2;
    cp_wait_ms(1);
    displ[3+deplacement] = "m";
    cp_wait_ms(1);
    
    char categorie[3];
    determinerCategorie(ones_num, categorie);
    displ.write(categorie, LCM_FW_HALF_CH + deplacement, false);
    cp_wait_ms(1);

}