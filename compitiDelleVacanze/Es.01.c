#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 28/06/2023
es. 01
text: Verificare se un vettore è speculare (per es. è formato dagli elementi 1,2,3,2,1)
*/

int chiediDim(int max){
	int n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (1-%d): ", max);
		}
	} while(n < 1 || n > max);
	return n;
}

void caricaVett(int v[], int dim) {

	for(int k = 0; k < dim; k++){
		printf("Inserisci l'elemento [%d]: ", k + 1);
		scanf("%d", &v[k]);
	}
}

bool speculare(int v[], int dim) {
	int k = 0;
	bool spec = true;

	while(k < dim/2 && spec == true ){
		if(v[k] != v[dim - 1 - k]) {
			spec = false;
		}
		k++;
	}
	return spec;
}

int main() {
	int vett[DIM]; //vettore contenete gli elementi interi da controllare
	
	int dim =  chiediDim(DIM);

	caricaVett(vett, dim);

	if(speculare(vett, dim) != true){ //scrivo se e' speculare o meno all'utente
		printf("\nIl vettore non e' speculare");
	} else {
		printf("\nIl vettore e' speculare");
	}

	return 0;
}