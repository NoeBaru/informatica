#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 06
text: Creare la funzione isTriangolo() che, dati 3 numeri, restituisce true/1 se possono essere le
misure di un triangolo, false/0 altrimenti. Creare un main che testi questa funzione.
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

bool isTriangolo(float n1, float n2, float n3) {
	bool eTriangolo;
    
	//controllo che la lunghezza di ciascuna misura sia minore della somma delle altre due
    if ((n1 < n2 + n3) && (n2 < n1 + n3) && (n3 < n1 + n2)) { 
        eTriangolo = true;
    } else {
        eTriangolo = false;
    }
    return eTriangolo;
}

int main() {
    float n1, n2, n3;

	printf("Inserisci il primo numero (n > 0): ");
    n1 = nonNeg(0);
	printf("Inserisci il secondo numero (n > 0): ");
	n2 = nonNeg(0);
	printf("Inserisci il terzo numero (n > 0): ");
	n3 = nonNeg(0);

	if(isTriangolo(n1, n2, n3) == true) {
		printf("Le misure possono essere misure di un triangolo");
	} else{
		printf("Le misure NON possono essere misure di un triangolo");
	}

    return 0;
}