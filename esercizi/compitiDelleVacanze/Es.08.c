#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REPARTI 3
#define MESI 6 

/*
Author: Noemi Baruffolo
date: /07/2023
es. 8
text:
I dati sugli incassi di 3 reparti di un magazzino nei primi 6 mesi sono
organizzati in una matrice, il numero di riga indica il numero del reparto,
il numero di colonna indica il mese. Calcolare l'incasso totale per ogni
mese, l'incasso totale per ogni reparto e l'incasso totale per tutti i
reparti nel periodo considerato. (programma a menù)
*/

void inizializzaMat(float mat[][MESI], int r, int c) {
    for(int k = 0; k < c; k++) {
        printf("Mese: %d\n", k + 1);
        for(int j = 0; j < r; j++) {
            printf("Reparto %d: ", j + 1);
            scanf("%f", &mat[j][k]);
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

float totM(float mat[][MESI], int r, int c) {
    int m;
    float tot = 0;

    m = controlloInput(1, c, "Inserisci il mese di cui vuoi il totale: ");

    for(int k = 0; k < r; k++) {
        tot += mat[k][m - 1];
    }

    return tot;
}

float totR(float mat[][MESI], int r, int c) {
    int rep;
    float tot = 0;

    rep =  controlloInput(1, r, "Inserisci il reparto di cui vuoi il totale: ");

    for(int k = 0; k < c; k++) {
        tot += mat[rep - 1][k];
    }

    return tot;
}

float tot(float mat[][MESI], int r, int c) {
    float totale = 0;

   for(int k = 0; k < c; k++) {
        for(int j = 0; j < r; j++) {
        totale += mat[j][k];
        }
    }

    return totale;
}

void menu() {
    printf("Digita il numero corrispondente alla tua scelta:\n");
    printf("0: esci\n1: totale incasso mensile\n2: incasso totale di un reparto\n3: incasso totale\n\n");
}

int main() {
    float mat[REPARTI][MESI] = {0}; //righe e colonne
    int risp;

    inizializzaMat(mat, REPARTI, MESI);

    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break;

        case 1:
            printf("Il totale del mese e': %.2f\n", totM(mat, REPARTI, MESI));
            break;

        case 2:
            printf("Il totale del reparto e': %.2f\n", totR(mat, REPARTI, MESI));
            break;
        
        case 3:
            printf("Il totale e': %.2f\n", tot(mat, REPARTI, MESI));
            break;
        
        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);

    return 0;
}