#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 15/09/2023
es. 13
text: Calcolare la somma degli elementi di posizione pari e quelli di posizione dispari di un vettore
(procedura con 2 parametri per indirizzo) LO ZERO è CONSIDERATO PARI
*/

int chiediDim(int min, int max){
	int n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (1-%d): ", max);
		}
	} while(n < min || n > max);
	return n;
}

void caricaVett(int tab[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("\nInserisci il %d^ numero: ", k +1);
        scanf("%d", &tab[k]);
    }
}

void somma(int vett[], int *sommaP, int *sommaD, int dim) {
    for(int k = 0; k < dim; k++) {
        if(vett[k] % 2 == 0) {
            *sommaP += vett[k];
        } else {
            *sommaD += vett[k];
        }
    }
}

int main() {
    int vett[DIM];
    int dim;
    int sommaP = 0;
    int sommaD = 0;

    dim = chiediDim(0, DIM);

    caricaVett(vett, dim);

    somma(vett, &sommaP, &sommaD, dim);

    printf("La somma dei numeri pari: %d\n", sommaP);
    printf("La somma dei numeri dispari: %d\n", sommaD);

    return 0;
}