#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "personaggi.h"

void delay(int ms);
void introduzione();
void dialogo_pre_boss();
Personaggio combattimento(Personaggio guts, Personaggio nemico, int *score);

#endif