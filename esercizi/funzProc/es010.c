#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 10
text: Crea la procedura INVERTI(x) che inverte le cifre del suo parametro che deve essere un
intero positivo. Per esempio se x = 12 alla fine x=21. Creare un main che testi questa
funzione.
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

void INVERTI(int *x) {
	int n = *x;
	int tot = 0;
	int nuovoN;

	while(n > 0){
		nuovoN = n % 10;
		tot = tot * 10 + nuovoN;
		n = n /10;
	}

	*x = tot;
}

int main() {
    int x;

    x = nonNeg(0);

	INVERTI(&x);

	printf("Il numero invertito e': %d", x);

    return 0;
}