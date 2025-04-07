#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char username[50];
    int score;
    int games_played;
} Player;

extern Player players[100];
extern int player_count;

int trova_player(char username[]);
void aggiungi_player(char username[]);
void mostra_classifica();

#endif