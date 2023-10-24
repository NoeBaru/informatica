#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 256

/*
Author: Noemi Baruffolo
date: 28/06/2023
es. 7
text: Convertire in maiuscolo tutte le vocali
*/

//correggi com ees5

void maiuscV(char s[]) {
	for(int k = 0; sI[k] != '\0'; k++) {
	//al posto di if(s[k] == 'a' || s[k] == 'A' || s[k] == 'e' || s[k] == 'E' || s[k] == 'i' || s[k] == 'I' || s[k] == 'o' || s[k] == 'o' || s[k] == 'u' || s[k] == 'U') { }
		if(strchr("aeiou", sI[k]) != NULL) { //controlla la presenza dei caratteri contenuti nella stringa, restituisce NULL se non trova
			sO[k] = sI[k] - 32; //con numeri codice ASCII
		} else {
			sO[k] = sI[k];
		}
	}
}

int main() {
	char str[LUNG]; //stringa input
	
	printf("Inserisci una frase: ");
	fgets(str, LUNG, stdin);
	
	maiuscV(str);
	
	printf("%s", str);	

	return 0;
}