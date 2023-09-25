#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 26
#define M 100
#define N 4

/*
Author: Noemi Baruffolo
date: 25/09/2023
es. 27
text: Data una matrice rettangolare MAT (MxN), di interi, già carica, calcolare il minimo, il massimo e la
media dei valori contenuti.
*/

//File: matEs27.txt

int caricaMatDaFile(int matrice[][N], char nomeFile[], int nRighe, int nColonne) {
    int r = 0, c;

    FILE *fp;
    fp = fopen(nomeFile, "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
    } else {
        r = 0;
        while (r < nRighe && fscanf(fp, "%d", &matrice[r][0]) != EOF) {
            for (int c = 1; c < nColonne; c++)
                fscanf(fp, "%d", &matrice[r][c]);
            r++;
        }
        fclose(fp);
    }
    return r;
}


void minMax(int vett[], int *min, int *max, int dim, int *somma) {
    *min = vett[0];
    *max = vett[0];

    for (int k = 0; k < dim; k++){
        if(vett[k] > *max){
            *max = vett[k];
        }
        if(vett[k] < *min){
            *min = vett[k];
        }

        *somma += vett[k];
    }
}

void matMinMaxMedia(int mat[][N], int dim){
    int media = 0, somma = 0, n = 0;
    int min, max;

    for(int k = 0; k< dim; k++) {
        minMax(mat[k], dim, &min, &max, &somma);
    }

    media = somma / dim;

    printf("Il minimo e': %d\nIl massimo e': %d\nLa media e': %d", min, max, media);
}

void stampaMatrice(int matrice[][N], int nr, int nc) {
    for (int x = 0; x < nr; x++) {
        for (int y = 0; y < nc; y++) {
            printf("%3d  ", matrice[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int MAT[M][N];
    char nomeFile[STRL];
    int nr = 0;
    int numSpec = 0;

    printf("Inserisci il nome del file: ");
    scanf("%s", nomeFile);

    nr = caricaMatDaFile(MAT, nomeFile, M, N);

    matMinMaxMedia(MAT, nr);

    stampaMatrice(MAT, nr, N);

    return 0;
}