#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG 256
/*
Author: Noemi Baruffolo
date: 28/06/2023
es. 6
text: Cancellare le vocali presenti in una stringa (ciao→c)
*/

bool eVocale(char c){
    bool tro=false;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        tro=true;
    }
    return tro;
}

void cancellaV(char s[]) {
    int k, j = 0;
    for (k = 0; s[k] != '\0'; k++) {
        if (!eVocale(s[k])) {
            s[j] = s[k];
            j++;
        }
    }
    s[j] = '\0';
}

int main() {
	char str[LUNG]; //stringa input
	
	printf("Inserisci una frase: ");
	fgets(str, LUNG, stdin);
	
	cancellaV(str);
	
	printf("%s", str);	

	return 0;
}