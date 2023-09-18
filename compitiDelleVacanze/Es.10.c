#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: /07/2023
es. 10
text:
Data la matrice A NRxNC creare la sua trasposta B NCxNR
1 2 3 diventa   1 4
4 5 6           2 5
                3 6
*/

int controlloInput(char mess[], int dim) {
    int m;

    do{
        printf(mess);
        scanf("%d", &m);
    } while(m < 0|| m > dim);
    return m;
}

void inizializzaMat(int mat[][DIM], int r, int c) {
    for(int k = 0; k < r; k++) {
        for(int j = 0; j < c; j++) {
            printf("%d %d: ", k, j);
            scanf("%d", &mat[k][j]);
        }
    }
    printf("\n\n");
}

void trasposta(int mat1[][DIM], int mat2[][DIM], int r, int c) {
    for(int k = 0; k < r; k++) {
        for(int j = 0; j < c; j++) {
            mat2[j][k] = mat1[k][j];
        }
    }
}

void stampaMat(int mat[][DIM], int r, int c) {
    for(int k = 0; k < r; k++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", mat[k][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c; //righe e colonne
    int a[DIM][DIM]; //matrice input normale
    int b[DIM][DIM]; //matrice output trasposta

    r = controlloInput("Inserisci il  numero di righe della matrice 1: ", DIM);
    c = controlloInput("Inserisci il  numero di colonne della matrice 1: ", DIM);
    
    inizializzaMat(a, r, c);
    trasposta(a, b, r, c);
    stampaMat(a, r, c);
    stampaMat(b, c, r);

    return 0;
}