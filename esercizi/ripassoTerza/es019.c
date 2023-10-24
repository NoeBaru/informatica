#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 256

/*
Author: Noemi Baruffolo
date: 19/09/2023
es. 19
text: Scrivere una funzione con la seguente interfaccia bool VocaliDispari(char str[]) che
restituisca TRUE se il numero di vocali presenti nella stringa è dispari, FALSE altrimenti. Si
utilizzi la funzione isVocale(c) per fare il confronto corretto.
*/

bool isVocale(char c){
    bool tro = false;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        tro = true;
    }
    return tro;
}

bool vocaliDispari(char str[]) {
    int nv = 0;
    bool dispari = false;
    int k, j = 0;
    for (k = 0; str[k] != '\0'; k++) {
        if (isVocale(str[k])) {
            nv += 1;
            j++;
        }
    }

    if(nv % 2 != 0) {
        dispari = true;
        }
    str[j] = '\0';

    return dispari;
}

int main() {
    char str[STRL];

    printf("Inserisci una frase: ");
	fgets(str, STRL, stdin);

    if(vocaliDispari(str) == true) {
        printf("Il numero di vocali inserite nella frase e' dispari");
    } else {
        printf("Il numero di vocali inserite nella frase e' pari");
    }

    return 0;
}