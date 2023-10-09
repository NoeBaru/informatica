#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 21
#define DIM 100
#define NOME_FILE "testo.txt"

/*
Author: Noemi Baruffolo
date: 3/10/2023
es. 35
text: Leggere un file di testo "testo.txt" carattere per carattere, contare le parole presenti caricando ogni 
parola in un vettore di stringhe (supporre che non ci siano più di 100 parole di lunghezza massima 
20)
*/

void readWrite(int dim, char nomeFile[]) {
    FILE *fp; //puntatori al file da modificare
    int cont = 0;
    char ch;
    char strVett[DIM][STRL];
    bool successivo = false;

    if ((fp = fopen(nomeFile,"r"))!= NULL) {
        while(cont < dim && fscanf(fp, "%20s", strVett[cont]) != EOF){
            printf("%s\n", strVett[cont]);
            cont++;
        }
        fclose(fp); // chiusura del file da modificare
    } else{
        printf("Errore apertura file da modificare"); 
    }
}

int main() {
    readWrite(DIM, NOME_FILE);

    return 0;
}