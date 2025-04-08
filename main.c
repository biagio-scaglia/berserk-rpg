#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "personaggi.h"
#include "combattimento.h"
#include "colors.h"
int main() {
    srand(time(NULL));

    char username[50];
    printf("Inserisci il tuo username: ");
    scanf("%s", username);

    int player_index = trova_player(username);
    if (player_index == -1) {
        aggiungi_player(username);
        player_index = player_count - 1;
    }

    int continua = 1;
    while (continua) {
        int difficolta;
        printf("\nScegli la difficoltà:\n");
        printf("1. Facile\n");
        printf("2. Normale\n");
        printf("3. Difficile\n");
        printf("> ");
        scanf("%d", &difficolta);

        int score = 0;
        int nemici_extra = 0;
        int potenziato = 0;

        if (difficolta == 2) {
            nemici_extra = 1;
            score += 200;
        } else if (difficolta == 3) {
            nemici_extra = rand() % 3 + 1;
            potenziato = rand() % 3;
            score += 500;
        }

        introduzione();

        Personaggio guts = {"Guts", 100, 45, 15};

        for (int i = 0; i < nemici_extra; i++) {
            Personaggio nemico_extra = crea_apostolo(potenziato);
            printf(YELLOW "\n👹 Un nuovo nemico appare: %s!\n" RESET, nemico_extra.nome);
            guts = combattimento(guts, nemico_extra, &score);
            if (guts.hp <= 0) break;
        }

        if (guts.hp > 0) {
            Personaggio apostolo = crea_apostolo(potenziato);
            printf(YELLOW "\n👹 Un nuovo nemico appare: %s!\n" RESET, apostolo.nome);
            guts = combattimento(guts, apostolo, &score);
        }

        if (guts.hp > 0) {
            printf("\n🌑 La notte cala, ma un'altra ombra emerge dall'oscurità...\n");
            delay(2000);
            Personaggio demone = crea_demone(potenziato);
            printf(YELLOW "\n🔥 Un nuovo nemico appare: %s!\n" RESET, demone.nome);
            guts = combattimento(guts, demone, &score);
        }

        if (guts.hp > 0) {
            dialogo_pre_boss();
            Personaggio boss_finale = crea_boss_finale(potenziato);
            printf(YELLOW "\n👹 L'ultimo nemico appare: %s!\n" RESET, boss_finale.nome);
            guts.attacco *= 2;
            guts.difesa /= 2;
            guts = combattimento(guts, boss_finale, &score);
        }

        if (guts.hp > 0) {
            printf(GREEN "\n🎉 Guts ha annientato ogni creatura oscura.\n" RESET);
            printf("La battaglia è finita. L'oscurità può aspettare... per ora.\n");
            printf("\nYOU WIN\n");
            score += 1000;
        } else {
            printf("\nHai sconfitto %d nemici!\n", score / 100);
        }

        players[player_index].score += score;
        players[player_index].games_played++;
        printf("\n%s, il tuo punteggio in questa partita: %d\n", username, score);
        printf("Punteggio totale: %d\n", players[player_index].score);

        printf("\nVuoi giocare ancora? (1=Si, 0=No): ");
        scanf("%d", &continua);
    }

    mostra_classifica();

    return 0;
}
