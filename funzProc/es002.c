#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 02
text: Usando le funz/proc create nell'esercizio precedente fare un programma che letto un
numero non negativo N e un carattere C, stampi a video un quadrato NxN di caratteri C (a
video NON sembrerà un quadrato, ma fa lo stesso, l'importante è che ci siano N caratteri in
N righe). Per esempio se N=3 e C= 'A' a schermo compare
AAA
AAA
AAA
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

void stampaTab(int n, char c) {
    for(int k = 0; k < n; k++){
        stampaC(n, c);
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

    stampaTab(n, c);
    

    return 0;
}