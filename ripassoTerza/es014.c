#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 14
text: Dato un vettore A di interi creare i vettori PARI e DISPARI formati rispettivamente dagli
elementi pari in posizione dispari e dispari in posizione pari presenti in
A [10, 12, 13, 1] PARI[12] DISPARI[13]
*/

int chiediDim(int min, int max){
	int n;
	printf("\nInserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("\nInserisci un numero valido (1-%d): ", max);
		}
	} while(n < min || n > max);
	return n;
}

void caricaVett(int vett[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("\nInserisci il numero [%d]: ", k);
        scanf("%d", &vett[k]);
    }
}


void pariODispari(int vett[], int P[], int D[], int dim, int *np, int *nd) {
    *np = 0;
    *nd = 0;

    for(int k = 0; k < dim; k++) {
        if((vett[k] % 2 == 0) && (k % 2 != 0)) { //se il numero e' pari e se il numero pari e' in posizione dispari
                P[*np] = vett[k];
                *np += 1;
        } else { 
            if((vett[k] % 2 != 0) && (k % 2 == 0)) { //se il numero e' dispari e se il numero e' in posizione pari
                D[*nd] = vett[k];
                *nd += 1;
            }
        }
    }
}

void stampaVett(int vett[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("%d ", vett[k]);
    }
}

int main() {
    int A[DIM];
    int PARI[DIM];
    int DISPARI[DIM];
    int dimA = 0;
    int dimP = 0;
    int dimD = 0;


    dimA = chiediDim(0, DIM);

    caricaVett(A, dimA);

    pariODispari(A, PARI, DISPARI, dimA, &dimP, &dimD);

    printf("\nI numeri pari in posizione dispari sono:\n");
    stampaVett(PARI, dimP);

    printf("\nI numeri dispari in posizione pari sono:\n");
    stampaVett(DISPARI, dimD);

    return 0;
}