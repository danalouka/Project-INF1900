#define F_CPU 8000000
#define VERT (0x02)
#define ROUGE (0x01)
#define ETEINT (0x00)
#define DEL (PORTB)
#include <avr/io.h>
#include <util/delay.h>

void emettreAmbre();