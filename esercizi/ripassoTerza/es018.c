#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 256

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 18
text: Creare upper(s), funzione che converte in maiuscolo tutti i caratteri di s. Utilizzare la
funzione isMinuscolo(car) 
*/

bool isMinuscolo(char c){
    bool tro = false;

    if(c >= 'a' && c <= 'z'){
        tro = true;
    }
    return tro;
}

void upper(char str[]) {
	for(int k = 0; str[k] != '\0'; k++) {
		if(isMinuscolo(str[k])){
            str[k] -= 32; //con numeri codice ASCII
        }
	}
}

int main() {
	char str[STRL];
	
	printf("Inserisci una frase: ");
	fgets(str, STRL, stdin);
	
	upper(str);
	
	printf("%s", str);	

	return 0;
}