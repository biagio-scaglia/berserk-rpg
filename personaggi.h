#ifndef PERSONAGGI_H
#define PERSONAGGI_H

typedef struct {
    char nome[50];
    int hp;
    int attacco;
    int difesa;
} Personaggio;

Personaggio crea_apostolo(int potenziato);
Personaggio crea_demone(int potenziato);
Personaggio crea_boss_finale(int potenziato);

#endif