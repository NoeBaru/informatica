#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "testo.txt"
#define FILE_TEMP "temp.txt"

/*
Author: Noemi Baruffolo
date: 3/10/2023
es. 36
text: Leggere un file di testo "testo.txt" carattere per carattere, modificarlo in modo che le parole dopo i 
caratteri . ! ? siano in maiuscolo e quelli dopo i caratteri , ; : ( ) in minuscolo
*/

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
char minuscMaiusc(char ch) {
    ch -= 32; //con numeri codice ASCII
    return ch;
}

//trasforma il carattere maiuscolo in minuscolo
char maiuscMinusc(char ch) {
    ch += 32; //con numeri codice ASCII
    return ch;
}

void caricaDaFileModificaCaratteri(char nomeFile[], char nomeFileTemp[]) {
    char ch;

    FILE *fp;
    FILE *ft;

    fp = fopen(nomeFile, "r");
    ft = fopen(nomeFileTemp, "w");

    bool u = false;
    bool l = false;

    if(fp != NULL){
        while((ch = fgetc(fp)) != EOF){
            if(ch == '.' || ch == '!' || ch == '?' ){
                u = true;
                
            } else if(ch == ',' || ch == ';' || ch == ':' || ch == '(' || ch == ')'){
                l = true;
            }

            if (isMaiuscolo(ch) && l == true){
                l = false;
                ch = maiuscMinusc(ch);
            }

            if (isMinuscolo(ch) && u == true){
                u = false;
                ch = minuscMaiusc(ch);
            }
            fputc(ch, ft);
        }
        fclose(ft);
        fclose(fp);
    } else {
        printf("Il file della matrice non esiste o e' vuoto!\n");
    }
}

int main() {
    caricaDaFileModificaCaratteri(NOME_FILE, FILE_TEMP);

    return 0;
}