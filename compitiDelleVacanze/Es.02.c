#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 28/06/2023
es. 2
text:
Dato un vettore A di interi creare i vettori PARI e DISPARI formati
rispettivamente dagli elementi pari e dispari presenti in A
*/

int chiediDim(int max){
	int n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (0-%d): ", max);
		}
	} while(n <= 0 || n > max);
	return n;
}

void caricaVett(int v[], int dim) {

	for(int k = 0; k < dim; k++){
		printf("Inserisci l'elemento [%d]: ", k + 1);
		scanf("%d", &v[k]);
	}
}

void ePari(int v[], int pari[], int dispari[],int dim, int *np, int *nd) {
    int res = 0;
    *np = 0;
    *nd = 0;
    for(int k = 0; k < dim; k++){
        res = v[k] % 2;

        if(res == 0){
            pari[*np] = v[k];
            *np+= 1;
        } else {
            dispari[*nd] = v[k];
            *nd+= 1;
        }
    }
}

void stampaVett(int v[], int dim) {
    for(int k = 0; k < dim; k++){
		printf("%d ", v[k]);
	}
}

int main() {
    int a[DIM];

    int pari[DIM];
    int dispari[DIM];

    int np = 0; //numero di n pari
    int nd = 0; //numero di n dispari

    int dim =  chiediDim(DIM);

	caricaVett(a, dim);

    ePari(a, pari, dispari, dim, &np, &nd);

    printf("\nVettore numeri pari [%d]: ", np);
    stampaVett(pari, np);

    printf("\nVettore numeri dispari [%d]: ", nd);
    stampaVett(dispari, nd);

    return 0;
}