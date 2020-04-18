#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include "minuterie.h"
#include <stdio.h>
#include <stdlib.h>

void determinerCategorie(int distance, char* outStr);
void emmettreTrigger();
void affichageSensorDetection(int ones_num, int tenth_num, LCM &displ, int deplacement);
void obtenirDelaiEcho(uint8_t numeroBroche);
int determinerManoeuvre(int distG, int distDe, int distDr);
double calculerDistance(int comp);