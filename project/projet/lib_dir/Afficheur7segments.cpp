#include "Afficheur7segments.h"


void affichageChiffreSurLapseTemps(unsigned int position, uint8_t chiffre,uint8_t temps){

    PORTC=chiffre;
    PORTA=position;
    delai_ms(temps);
}

void afficherSequenceChiffres(uint8_t temps, uint8_t chiffre1, uint8_t chiffre2, uint8_t chiffre3, uint8_t chiffre4)
{   

    for(unsigned int i=0; i<temps;i++){
    affichageChiffreSurLapseTemps(UN, chiffre1,1);
    affichageChiffreSurLapseTemps(DEUX, chiffre2,1);
    affichageChiffreSurLapseTemps(TROIS, Moins,1);
    affichageChiffreSurLapseTemps(QUATRE, chiffre3,1);
    affichageChiffreSurLapseTemps(CINQ, chiffre4,1);
    }

}

int determinerChiffre(uint8_t chiffre){

    switch (chiffre){
        case 1: return 0x60;
        case 2: return 0xda;
        case 3: return 0xf2;
        case 4: return 0x66;
        case 5: return 0xb6;
        case 6: return 0xbe;
        case 7: return 0xe0;
        case 8: return 0xfe;
        case 9: return 0xf6;
        case 0: return 0xfc;

    }

}

void passageVitesse(double ratio, uint8_t premierNombre, uint8_t deuxiemeNombre, uint8_t troisiemeNombre, uint8_t quatriemeNombre){
//premier nombre est le nombre que nous sommes présentement, alors que le deuxième est celui que nous voulons afficher (same pour trois et quatre)
//ratio est le nombre de ms que l'on delay pour chaque bond

    uint8_t differencePremier;
    int additionPremier;
    int additionDeuxieme;

    //déterminer le plus grand nombre et savoir si l'on doit soustraire ou additionner
    //pour que le premier nombre rejoingne le deuxieme
    if (premierNombre<deuxiemeNombre){
        differencePremier=deuxiemeNombre-premierNombre;
        additionPremier=1;
    }else{
        differencePremier=premierNombre-deuxiemeNombre;
        additionPremier=0;
    }

    uint8_t differenceDeuxieme;

    //meme principe mais pour le deuxieme nombre de l'afficheur
    if (troisiemeNombre<quatriemeNombre){
        differenceDeuxieme=quatriemeNombre-troisiemeNombre;
        additionDeuxieme=1;
    }else{
        differenceDeuxieme=troisiemeNombre-quatriemeNombre;
        additionDeuxieme=0;
    }

    //déterminer quelle différence est la plus grande pour la boucle for
    uint8_t difference;
    if(differenceDeuxieme>=differencePremier){
        difference=differenceDeuxieme;
    }else{
        difference=differencePremier;
    }


    uint8_t dizainePremier= premierNombre/10;
    uint8_t unitePremier= premierNombre%10;

    uint8_t dizaineDeuxieme= troisiemeNombre/10;
    uint8_t uniteDeuxieme= troisiemeNombre%10;



    if(additionPremier==1|additionDeuxieme==1){
        for(unsigned int i=0; i<difference;i++){
            if(premierNombre!=deuxiemeNombre){
            ++unitePremier;

            //ajout d'une dizaine si l'on passe à 10
            if(unitePremier==10){
                unitePremier=0;
                ++dizainePremier;
            }
            }

            if(troisiemeNombre!=quatriemeNombre){
            ++uniteDeuxieme;
            
            if(uniteDeuxieme==10){
                uniteDeuxieme=0;
                ++dizaineDeuxieme;
            }
            }

            affichageChiffreSurLapseTemps(UN, determinerChiffre(dizainePremier),ratio/5);
            affichageChiffreSurLapseTemps(DEUX, determinerChiffre(unitePremier), ratio/5);
            affichageChiffreSurLapseTemps(TROIS, Moins,ratio/5);
            affichageChiffreSurLapseTemps(QUATRE, determinerChiffre(dizaineDeuxieme),ratio/5);
            affichageChiffreSurLapseTemps(CINQ, determinerChiffre(uniteDeuxieme),ratio/5);
            
        }


    //cas ou le deuxieme nombre est plus petit donc on soustrait au nombre
    }else{
        for(unsigned int i=0; i<difference;i++){

            if(premierNombre!=deuxiemeNombre){
            if(unitePremier==0){
                unitePremier=9;
                --dizainePremier;
            }else{
                --unitePremier;
            }
            }

            if(troisiemeNombre!=quatriemeNombre){
            if(uniteDeuxieme==0){
                uniteDeuxieme=9;
                --dizaineDeuxieme;
            }else{
                --uniteDeuxieme;
            }
            }
             
            affichageChiffreSurLapseTemps(UN, determinerChiffre(dizainePremier),ratio/5);
            affichageChiffreSurLapseTemps(DEUX, determinerChiffre(unitePremier),ratio/5);
            affichageChiffreSurLapseTemps(TROIS, Moins,ratio/5);
            affichageChiffreSurLapseTemps(QUATRE, determinerChiffre(dizaineDeuxieme),ratio/5);
            affichageChiffreSurLapseTemps(CINQ, determinerChiffre(uniteDeuxieme),ratio/5);
            

        }

    }

}
