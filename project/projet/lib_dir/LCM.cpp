#include "LCM.h"

void afficherManoeuvre(int numeroManoe){

    LCM displ(&DDRB, &PORTB);

    if (numeroManoe == 0) {

        displ.write("Combinaison", 0 , false);
        cp_wait_ms(1);
        displ.write("non evaluee", LCM_FW_HALF_CH, false);
        cp_wait_ms(1);
    }
    else {

        displ.write("Manoeuvre ",0 , false);
        cp_wait_ms(1);
        displ << numeroManoe;
    }
}