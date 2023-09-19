#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 01
text: Fare un programma che letto un numero non negativo N e un carattere C, stampi a video N
volte C Per esempio se N=4 e C= 'A' a schermo compare
AAAA
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

void stampa(int n, char c) {
    printf("\n");
    for(int k = 0; k < n; k++){
        printf("%c", c);
    }
}

int main() {
    int n;
    char c;

    n = nonNeg(0);

    printf("Inserisci un carattere: ");
    fflush(stdin);
    scanf("%c", &c);

    stampa(n, c);

    return 0;
}