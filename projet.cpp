//les definitions:
#define DELGauche PORT??
#define DELDroite PORT??

//les inclusions:
...

//les enumeration globales:
enum CategorieDistance {OK, ATTN, DNGR};
enum Mode {DETECT, MANVRE};
enum Manoeuvre {MAN1, MAN2, MAN3, MAN4, MAN5, MAN6}

//les variables globales:
LSD lsd;
CategorieDistance categorieGauche = OK;
CategorieDistance categorieDevant = OK;
CategorieDistance categorieDroite = OK;
Mode mode = DETECT;
Manoeuvre manoeuvre // = ?? 

//les fonctions:
//permet l'initialisation des portes de la carte.
void initialisationDirection(){}:

//permet de changer le mode du robot.
void changerMode(Etat modeDonne){

    if (modeDonne == MANVRE) {

        //verification a cause du mecanisme du rebond de la souris
        if (/*buttonPresse*/) {
            _delay_ms(10); 
            if(/*buttonPresse*/){
                while (buttonPresse){}
                mode = modeDonne;
            }
        }
    }
    else if (modeDonne == DETECT) {
        
        mode = modeDonne;
    }
}

//permet d'executer le mode de detection du robot.
void modeDetection() {
    
}

//permet d'executer le mode de manouvre du robot. Elle gere tous les possiblites de manoeuvres possibles.
void modeManoeuvre() {

    switch (manoeuvre){

        case MAN1: 

            break;

        case MAN2: 

            break;

        case MAN3: 

            break;

        case MAN4: 

            break;

        case MAN5: 

            break;

        case MAN6: 

            break;

        default: 
            
            break;
    }
}

//a mettre dans la librairie:
//allumerEnRouge(DEL){}
void allumerEnRouge(DEL del){;}

//alomuer En Vert(DEL){}
void allumuerEnVert(DEL del){;}

int main () {

    initialisationDirection():

    while (true) {

        switch (mode) {

            case DETECT:

                //met le robot en mode de detection
                modeDetection();

                //if bouton appuiee (only scrut. no need if ISR : on change de mode en ISR))
                changerMode(MAUVRE);
                break;

            case MANVRE:

                //liste des ifs pour detrminer le manoeuvre
                //manoeuvre = 

                //met le robot en mode de manoeuvre
                modeManoeuvre();
        
                //if fin de manoeuvre
                changerMode(DETECT);
                break;

        }

    }

    return 0;
}