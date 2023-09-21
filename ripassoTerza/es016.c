#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define STRL 31
#define LIM_MIN 32
#define LIM_MAX 126

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 16
text: Creare una stringa random 32-126 lunga n caratteri
*/

int chiediDim(int min, int max){
	int n;
	printf("Inserisci il numero di numeri: ");
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (1-%d): ", max);
		}
	} while(n < min || n > max);
	return n;
}

void randomStr(char str[], int dim) {
    for(int k = 0; k < dim; k++) {
        str[k] = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN);
    }
}

void stampaStr(char str[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("%c", str[k]);
    }
}

int main() {
    char str[STRL];

    int n;

    n = chiediDim(0, STRL);

    srand(time(NULL));

    randomStr(str, n);

    stampaStr(str, n);

    return 0;
}
