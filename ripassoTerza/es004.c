#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 04
text: Usando le funz/proc create degli esercizi precedenti stampare triangolo fare un programma
che letto un numero non negativo H e un carattere C, stampare a video un triangolo
rettangolo isoscele di altezza H. Per esempio se H = 3

X
XX
XXX
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

void stampaC(int n, char c) {
    for(int k = 0; k < n; k++){
        printf("%c", c);
    }
}

void stampaTr(int n, char c) {
    for(int k = 1; k < n + 1; k++){
        stampaC(k, c);
        printf("\n");
    }   
}

int main() {
    int n;
    char c;

    n = nonNeg(0);

    printf("Inserisci un carattere: ");
    fflush(stdin);
    scanf("%c", &c);

    stampaTr(n, c);
    

    return 0;
}