#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 11
text: . Crea la procedura CRESCENTI(x,y,z) che fa in modo che in x finisca il minore dei 3 numeri, in z
il maggiore e in y il numero rimanente. 
*/

float nonNeg(float min){
	float n;
	
	do{
		scanf("%f", &n);
		if(n <= min){
			printf("Inserisci un numero valido (n > 0): ");
		}
	} while(n < min);
	return n;
}

void CRESCENTI(float *x, float *y, float *z) {
    float temp;

    //ricerca del valore massimo da assegnare
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }

    //ricerca del valore minimo da assegnare
    if (*y > *z) {
        temp = *y;
        *y = *z;
        *z = temp;
    }

    //ricerca del valore rimanente da assegnare
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

int main() {
    float x, y, z;

    printf("Inserisci il primo numero (n > 0): ");
    x = nonNeg(0);
	printf("Inserisci il secondo numero (n > 0): ");
	y = nonNeg(0);
	printf("Inserisci il terzo numero (n > 0): ");
	z = nonNeg(0);

    CRESCENTI(&x, &y, &z);

    printf("x = %.2f y = %.2f z = %.2f", x, y, z);

    return 0;
}