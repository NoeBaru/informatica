#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: /07/2023
es. 11
text:
Verificare se una matrice quadrata è unaria (tutti 0 tranne la diagonale
principale di 1)
*/

int controlloInput(char mess[], int dim) {
    int n;

    do{
        printf(mess);
        scanf("%d", &n);
    } while(n < 0|| n > dim);
    return n;
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

bool unaria(int mat[][DIM], int dim) {
    int k = 0; //n.righe
    int j = 0; //n.colonne
    bool un = true; //unaria

    while(k < dim && un == true) { //righe
        while(j < dim && un == true) { //colonne
            if(k == j) { //se siamo sulla diagonale principale
                if(mat[k][j] != 1) {
                    un = false;
                }
            } else { //se siamo nel resto della matrice
                if(mat[k][j] != 0) {
                    un = false;
                }
            }

            j++;
        }

        k++;
    }

    return un;
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
    int mat[DIM][DIM];
    int dim = controlloInput("Inserire la dimensione della matrice: ", DIM);

    inizializzaMat(mat, dim, dim);

    if(unaria(mat, dim) == true) {
        printf("La matrice caricata e' unaria!\n\n");
    } else {
        printf("La matrice caricata NON e' unaria!\n\n");
    }

    stampaMat(mat, dim, dim);

    return 0;
}