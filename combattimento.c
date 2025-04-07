#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "colors.h"
#include "combattimento.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

void delay(int ms) {
    usleep(ms * 1000);
}

void introduzione() {
    printf(CYAN "\n--- BERSERK: L'OSCURITÀ AVANZA ---\n" RESET);
    delay(1500);
    printf("\nGuts avanza nel buio, la Spada Ammazza Draghi ricoperta di sangue secco.\n");
    delay(2000);
    printf("L'aria è densa di cenere e morte...\n");
    delay(2000);
    printf(YELLOW "\nUn ruggito infernale squarcia il silenzio.\n" RESET);
    delay(1500);
    printf(RED "Dall'ombra emerge un Apostolo... assetato di carne umana.\n" RESET);
    delay(2000);
    printf("\nGuts stringe i denti e solleva la sua spada...\n");
    delay(1500);
    printf(BLUE "\nLa battaglia ha inizio.\n" RESET);
    delay(2000);
}

void dialogo_pre_boss() {
    printf(RED "\n『HAH... HAH... HAH...』\n" RESET);
    delay(2000);
    printf(YELLOW "\n🔥 Guts si rialza, gli occhi rossi come il fuoco dell'inferno.\n" RESET);
    delay(2000);
    printf("『Non importa quanti siete... non importa quanto siete forti...』\n");
    delay(2000);
    printf("『Finché riesco a muovere un dito... IO VI SPAZZERÒ VIA!』\n");
    delay(2000);
    printf(RED "\n『RRRRAAAAAAAAAHHH!!!』\n" RESET);
    delay(2000);
}

Personaggio combattimento(Personaggio guts, Personaggio nemico, int *score) {
    printf(YELLOW "\n🔪 Guts si prepara a combattere...\n" RESET);
    delay(1000);

    while (guts.hp > 0 && nemico.hp > 0) {
        int scelta;
        printf("\n⚔️  Cosa vuoi fare?\n");
        printf("1. Attacca con tutta la tua forza\n");
        printf("2. Difenditi\n");
        printf("3. Schiva e contrattacca\n");
        printf("> ");
        scanf("%d", &scelta);

        if (scelta == 1) {
            int danno_guts = guts.attacco - nemico.difesa + (rand() % 5);
            danno_guts = (danno_guts < 0) ? 0 : danno_guts;
            printf(GREEN "\n💥 Guts colpisce con violenza! Infligge %d danni!\n" RESET, danno_guts);
            nemico.hp -= danno_guts;
        } else if (scelta == 2) {
            printf(BLUE "\n🛡️ Guts si difende, riducendo il danno nemico.\n" RESET);
            guts.difesa *= 2;
        } else if (scelta == 3) {
            printf(CYAN "\n⚡ Guts tenta di schivare!\n" RESET);
            if (rand() % 2 == 0) {
                printf(GREEN "✨ Schivata perfetta! Il nemico perde l'attacco!\n" RESET);
                continue;
            } else {
                printf(RED "💀 Fallisce la schivata! Subisce un colpo in pieno!\n" RESET);
            }
        }

        if (nemico.hp <= 0) {
            printf(GREEN "\n💀 %s è stato sconfitto!\n" RESET, nemico.nome);
            *score += 100;
            break;
        }

        printf(RED "\n☠️  %s attacca con ferocia!\n" RESET, nemico.nome);
        int danno_nemico = nemico.attacco - guts.difesa + (rand() % 5);
        danno_nemico = (danno_nemico < 0) ? 0 : danno_nemico;
        printf(RED "🔥 Guts subisce %d danni!\n" RESET, danno_nemico);
        guts.hp -= danno_nemico;
        delay(1000);

        if (scelta == 2) {
            guts.difesa /= 2;
        }

        if (guts.hp <= 20) {
            printf(YELLOW "\n⚡ Guts si abbandona alla furia... qualcosa cambia nei suoi occhi.\n" RESET);
            delay(1000);
            printf("🔴 Le vene si gonfiano, il respiro si fa irregolare...\n");
            delay(2000);
            printf(RED "\n『RRRRAAAAAAAAAHHH!!!』\n" RESET);
            delay(2000);
            printf(YELLOW "\n🔥 Guts entra nella Berserker Mode!\n" RESET);
            guts.attacco *= 2;
            guts.difesa /= 2;
        }

        if (guts.hp <= 0) {
            printf(RED "\n💀 Guts cade a terra, il sangue si mescola alla polvere...\n" RESET);
            printf("\nGAME OVER\n");
            break;
        }
    }

    return guts;
}