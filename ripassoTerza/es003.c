#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 03
text: Usando le funz/proc create precedentemente fare un programma che letto larghezza L e
altezza H non negativi e un carattere C, stampi a video un rettangolo HxL di caratteri C. Per
esempio se H=2 e L=3 e C= 'A' a schermo compare
AAA
AAA
*/


int nonNeg(int min){
	int n;

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

void stampaRett(int r, int c, char ca) {
    for(int k = 0; k < r; k++){
        stampaC(c, ca);
        printf("\n");
    }   
}

int main() {
    int l;
    int h;
    char c;

    printf("Inserisci la larghezza (n > 0): ");
    l = nonNeg(0);
    printf("Inserisci l'altezza (n > 0): ");
    h = nonNeg(0);

    printf("Inserisci un carattere: ");
    fflush(stdin);
    scanf("%c", &c);

    stampaRett(h, l, c);
    

    return 0;
}