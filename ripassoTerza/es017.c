#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 256

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 17
text: Cancellare le vocali presenti in una stringa (ciao -> c), usare la funzione isVocale(car)
*/

bool isVocale(char c){
    bool tro = false;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        tro = true;
    }
    return tro;
}

void cancellaV(char s[]) {
    int k, j = 0;
    for (k = 0; s[k] != '\0'; k++) {
        if (!isVocale(s[k])) {
            s[j] = s[k];
            j++;
        }
    }
    s[j] = '\0';
}

int main() {
	char str[STRL]; //stringa input
	
	printf("Inserisci una frase: ");
	fgets(str, STRL, stdin);
	
	cancellaV(str);
	
	printf("%s", str);	

	return 0;
}
