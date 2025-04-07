#include <stdio.h>
#include <string.h>
#include "player.h"

Player players[100];
int player_count = 0;

int trova_player(char username[]) {
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void aggiungi_player(char username[]) {
    strcpy(players[player_count].username, username);
    players[player_count].score = 0;
    players[player_count].games_played = 0;
    player_count++;
}

void mostra_classifica() {
    printf("\n🏆 CLASSIFICA 🏆\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s - Punteggio: %d - Partite giocate: %d\n",
               i+1, players[i].username, players[i].score, players[i].games_played);
    }
}//
// Created by Biagio Scaglia on 07/04/2025.
//
