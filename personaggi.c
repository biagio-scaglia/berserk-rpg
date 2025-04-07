#include "personaggi.h"

Personaggio crea_apostolo(int potenziato) {
    return (Personaggio){"Apostolo della Mano di Dio", 60 + (potenziato * 20), 15 + (potenziato * 5), 3 + potenziato};
}

Personaggio crea_demone(int potenziato) {
    return (Personaggio){"Demone della Furia", 90 + (potenziato * 30), 20 + (potenziato * 7), 5 + potenziato};
}

Personaggio crea_boss_finale(int potenziato) {
    return (Personaggio){"Abominio dell'Abisso", 150 + (potenziato * 50), 25 + (potenziato * 10), 10 + potenziato};
}