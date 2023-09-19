#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 05
text: Usando le funz/proc create degli esercizi precedenti stampare n strisce pedonali lunghe lung
se n=3 e lung = 5 saranno così
XXXXX
XXXXX
00000
00000
XXXXX
XXXXX
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

void stampaStr(int n) {
    char nere = 'x';
    char bianche = 'O';
    int nStr = 2;

    for(int k = 0; k < n; k ++){
        if(k % 2 == 0){
            stampaRett(nStr, n, nere);
        } else {
            stampaRett(nStr, n, bianche);
        }
    }
}

int main() {
    int n;
    int lung;
    
    printf("Inserisci il numero di strisce (n > 0): ");
    n = nonNeg(0); //numero strisce

    printf("Inserisci la larghezza delle strisce (n > 0): ");
    lung = nonNeg(0); //lunghezza caratteri strisce

    stampaStr(lung); //dimensione quadrato 

    return 0;
}