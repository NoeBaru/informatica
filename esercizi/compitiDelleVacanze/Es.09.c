#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTI 3
#define PROVE 20

/*
Author: Noemi Baruffolo
date: /07/2023
es. 9
text:
 I dati sulle votazioni di 10 studenti in prove sono organizzati in una
matrice, il numero di riga indica il numero dello studente, il numero di
colonna indica il numero della prova. Calcolare la media dei voti di ciascun
studente, la media di ciascuna prova e la media generale della classe in
tutte le prove. (programma a menù)
*/

void inizializzaMat(float mat[][PROVE], int r, int c) {
    for(int k = 0; k < r; k++) {
        printf("Studente: %d\n", k + 1);
        for(int j = 0; j < c; j++) {
            printf("Prova %d: ", j + 1);
            scanf("%f", &mat[k][j]);
        }
    }
}

int controlloInput(int min, int max, char mess[]) {
    int m;

    do{
        printf(mess);
        scanf("%d", &m);
    } while(m < min || m > max);
    return m;
}

void mediaS(float mat[][PROVE], int r, int c) {
    float somma = 0;
    float media = 0;

    for(int k = 0; k < r; k++) { //studenti
        somma = 0;
        for(int j = 0; j < c; j++) { //prove
        somma += mat[k][j];
        }
        media = somma/c;
        printf("La media dei voti del %d studente e': %.2f\n", k + 1, media);
    }
}

void mediaP(float mat[][PROVE], int r, int c) {
    float somma, media;

    for(int k = 0; k < c; k++) { //prove
        somma = 0;
        for(int j = 0; j < r; j++) { //studenti
        somma += mat[j][k];
        }
        media = somma/r;
        printf("La media dei voti della %d prova e': %.2f\n", k + 1, media);
    }
}

float mediaTot(float mat[][PROVE], int r, int c) {
    float sommas, sommatot = 0, medias, mediatot;

    for(int k = 0; k < r; k++) {
        sommas = 0;
        for(int j = 0; j < c; j++) {
            sommas += mat[k][j];
        }
        medias = sommas / c;
        sommatot += medias;
    }
    mediatot = sommatot / r;

    return mediatot;
}

void menu() {
    printf("Digita il numero corrispondente alla tua scelta:\n");
    printf("0: esci\n1: media dei voti di ciascuno studente\n2: media di ciascuna prova\n3: media generale della classe in tutte le prove\n\n");
}

int main() {
    float mat[STUDENTI][PROVE] = {0};
    int risp, prove, media;

    prove = controlloInput(1, PROVE, "Inserisci il numero di prove: ");
    inizializzaMat(mat, STUDENTI, prove);

    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break; //esce

        case 1:
            mediaS(mat, STUDENTI, prove);
            break;

        case 2:
            mediaP(mat, STUDENTI, prove);
            break;
        
        case 3:
            printf("La media totale e': %.2f\n", mediaTot(mat, STUDENTI, prove));
            break;
        
        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);

    return 0;
}