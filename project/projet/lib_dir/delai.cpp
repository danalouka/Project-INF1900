#include "delai.h"

void delai_us(int delai)
{
    for(int i =0; i < delai; i++)
        _delay_us(1);
}

void delai_ms(int delai) 
{
    for(int i =0; i < delai; i++)
        _delay_ms(1);
}