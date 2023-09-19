#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 09
text: Utilizzando la procedura POT2(x) e la funzione in C sqrt(x) crea la funzione IPOTENUSA() che
dati i due cateti restituisce l'ipotenusa. Creare un main che testi questa funzione.
*/

float nonNeg(float min){
	float n;
	printf("Inserisci un numero (n > 0): ");
	do{
		scanf("%f", &n);
		if(n <= min){
			printf("Inserisci un numero valido (n > 0): ");
		}
	} while(n < min);
	return n;
}

void POT2(float *x) {
    *x *= (*x);
}

float IPOTENUSA(float c1, float c2) {
    float i;

    POT2(&c1);
    POT2(&c2);

    i = sqrt(c1 + c2);

    return i;
}

int main() {
    float c1, c2;
    float i;

    c1 = nonNeg(0);
	c2 = nonNeg(0);

    i = IPOTENUSA(c1, c2);

    printf("L'ipotenusa del triangolo e': %.2f", i);

    return 0;
}