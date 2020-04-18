#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include "minuterie.h"
#include <stdio.h>
#include <stdlib.h>

void afficherManoeuvre(int numeroManoe);