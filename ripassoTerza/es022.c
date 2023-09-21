#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100
#define MAX 10

/*
Author: Noemi Baruffolo
date: 21/09/2023
es. 22
text: Dopo aver caricato in memoria una matrice di interi quadrata di ordine N (con N inserito da tastiera
non superiore a 10), sommare gli elementi della diagonale principale e quelli della diagonale
secondaria
*/

int chiediDim(int min, int max){
	int n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= min || n > max){
			printf("Inserisci un numero valido (%d-%d): ", min + 1, max);
		}
	} while(n < min || n > max);
	return n;
}

void caricaMat(int mat[][DIM], int dim){
    for(int k = 0; k < dim; k++){
        for(int j = 0; j < dim; j++){
            printf("Inserisci un numero [%d][%d]", k, j);
            scanf("%d", &mat[k][j]);
        }
    }
}

void sommaDiagonali(int mat[][DIM], int dim, int *sommaDP, int *sommaDS){
    int j = dim - 1;
    *sommaDP = 0;
    *sommaDS = 0;

    for(int k = 0; k < dim; k++) {
        *sommaDP += mat[k][k];
        *sommaDS += mat[k][j];
        j --;
    }
}

void stampaMat(int mat[][DIM], int dim){
    
    for(int k = 0; k < dim; k++){
        for(int j = 0; j < dim; j++){
            printf("%3d", mat[j][k]);
        }
        printf("\n");
    }
}

int main() {
    int mat[DIM][DIM];
    int N;
    int sommaDP = 0;
    int sommaDS = 0;

    N = chiediDim(0, MAX); //numero di righe e colonne

    caricaMat(mat, N);

    sommaDiagonali(mat, N, &sommaDP, &sommaDS);

    printf("La somma della diagonale principale e': %d\nLa somma della diagonale secondaria e': %d\n", sommaDP, sommaDS);
    
    printf("La matrice e':\n");

    stampaMat(mat, N);

    return 0;
}