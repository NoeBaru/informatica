#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 15
text: Dato un vettore di reali trovare il minimo e il massimo, quindi ordinarlo in ordine
decrescente usando un algoritmo studiato e verificare che il primo e l'ultimo elemento
coincidono con i valori di minimo e massimo trovati
*/

float chiediDim(int min, int max){
	float n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%f", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (1-%d): ", max);
		}
	} while(n < min || n > max);
	return n;
}

void caricaVett(float vett[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("\nInserisci il %d^ numero: ", k +1);
        scanf("%f", &vett[k]);
    }
}

void scambio(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(float vett[], int dim) {
    int k, sup, sca; 
    sup = dim - 1 ;
    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k + 1]){
                scambio(&vett[k], &vett[k + 1]);
                sca = k ;
            }
        }
        sup = sca ;
    }
}

void minMax(float vett[], int dim) {
    float min = vett[0];
    float max = vett[0];

    for (int k = 0; k < dim; k++){
        if(vett[k] > max){
            max = vett[k];
        }
        if(vett[k] < min){
            min = vett[k];
        }
    }

    bubbleSort3(vett, dim);

    if(vett[0] == min){
        printf("\nIl minimo corrisponde (%.2f)", min);
    }
    if(vett[dim - 1] == max){
        printf("\nIl massimo corrisponde (%.2f)", max);
    }
}

void stampaVett(float vett[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("%.2f ", vett[k]);
    }
}


int main() {
    float vett[DIM];
    int dim;

    dim = chiediDim(0, DIM);

    caricaVett(vett, dim);

    minMax(vett, dim);

    printf("\nIl vettore ordinato e':\n");
    stampaVett(vett, dim);

    return 0;
}