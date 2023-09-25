#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 11

/*
Author: Noemi Baruffolo
date: 15/09/2023
es. 12
text: Caricare un vettore con la tabellina del numero x letto da tastiera (se x è 3 il vettore conterrà 0,3,6,9,…,30) 
*/

int nonNeg(int min){
	int n;
	printf("Inserisci un numero (n > 0): ");
	do{
		scanf("%d", &n);
		if(n <= min){
			printf("Inserisci un numero valido (n > 0): ");
		}
	} while(n < min);
	return n;
}

void creaTabellina(int tab[], int num, int dim) {
    for(int k = 0; k < dim; k++) {
        tab[k] = num * k;
    }
}

void stampaTabellina(int tab[], int num, int dim) {
    printf("La tabellina del numero %d e': ", num);
    for(int k = 0; k < dim; k++) {
        printf("%d ", tab[k]);
    }
}

int main() {
    int tabellina[DIM];

    int x; //numero in input

    x = nonNeg(0);

    creaTabellina(tabellina, x, DIM);

    stampaTabellina(tabellina, x, DIM);

    return 0;
}