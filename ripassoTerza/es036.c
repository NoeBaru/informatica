#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "testo.txt"

/*
Author: Noemi Baruffolo
date: 3/10/2023
es. 36
text: Leggere un file di testo "testo.txt" carattere per carattere, modificarlo in modo che le parole dopo i 
caratteri . ! ? siano in maiuscolo e quelli dopo i caratteri , ; : ( ) in minuscolo
*/

void caricaDaFile(char str[], char nomeFile[]) {
    int k = 0;

    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(fgets(str, STRL, fp) != '\0' && fgets(str, STRL, fp) != EOF){
            k++;
        }
        fclose(fp);
    } else {
        printf("Il file della matrice non esiste o e' vuoto!\n");
    }
}

//controlla se un carattere e' minuscolo o no
bool isMinuscolo(char c){
    bool tro = false;

    if(c >= 'a' && c <= 'z'){
        tro = true;
    }
    return tro;
}

//controlla se un carattere e' maiuscolo o no
bool isMaiuscolo(char c){
    bool tro = false;

    if(c >= 'A' && c <= 'Z'){
        tro = true;
    }
    return tro;
}

//trasforma il carattere minuscolo in maiuscolo
void minuscMaiusc(char str[]) {
	for(int k = 0; str[k] != '\0'; k++) {
		if(isMinuscolo(str[k])){
            str[k] -= 32; //con numeri codice ASCII
        }
	}
}

//trasforma il carattere maiuscolo in minuscolo
void maiuscMinusc(char str[]) {
	for(int k = 0; str[k] != '\0'; k++) {
		if(isMinuscolo(str[k])){
            str[k] += 32; //con numeri codice ASCII
        }
	}
}

void modificaCaratteri(char str[]){
    int k = 0;
    //int lung = strlen(str);
    while(k != '\0'){ // lung = strlen(str)
        if(str[k] == ',' || str[k] == ';' || str[k] == ':' || str[k] =='(' || str[k] == ')'){
            if (isMaiuscolo(str)){
                maiuscMinusc(str);
            }
        } else if(str[k] == '.' || str[k] == '!' || str[k] == '?'){
            if (isMinuscolo(str)){
                minuscMaiusc(str);
            }
        }

        k++;
    }
}

int main() {
    char str[STRL];
    caricaDaFile(str, NOME_FILE);
    modificaCaratteri(str);

    printf("%s", str);

    return 0;
}