#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "AmasonPraim.txt"

/*
Author: Noemi Baruffolo
date: 12/10/2023
es. es1
text:
IL PRODOTTO IN EVIDENZA: scegliere e stampare a video il prodotto con lo sconto piu alto
in euro (non il valore piu alto della PERCENTUALE DI SCONTO, dovrete trovare il valore di
sconto piu alto in euro. Basta un prodotto, non c’è il caso di gestire il parimerito);
AMASONPRAIM
AMASON CONSIGLIA:
- prodotto xx
solo oggi e domani scontato di kk euro
*/

float calcolaScontoNegativo(float prezzo, float percentuale) {
    return prezzo - (prezzo * (percentuale / 100));
}

//carica da file e restiuisce il numero di prodotti presenti in esso
int caricaDaFile(float prezzoFinale[], char prodotto[], int dim, char nomeFile[]) {
    char reparto[STRL];
    float prezzoS[DIM];
    int quant[DIM];
    int percSconto[DIM];
    int cont = 0;

    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(cont < dim && fscanf(fp, "%s", reparto) != EOF){
            fscanf(fp, "%s %f %d %d", prodotto[cont], &prezzoS[cont], &quant[cont], &percSconto[cont]);
            prezzoFinale[cont] = calcolaScontoNegativo(prezzoS[cont], percSconto[cont]);
            cont++;
        }
        fclose(fp);
    } else {
        printf("Il file non esiste(l'ho appena creato) o e' vuoto(riempilo prima)!\n");
    }
    return cont;
}

//stampa a video tutti i prodotti(per controllare)
/*
void stampa(char prodotto[], float prezzoFinale[], int dim){
    for(int cont = 0; cont < dim; cont++){
        printf("%s: %.2f euro", prodotto, prezzoFinale[cont]);
    }
}
*/

float calcolaMax(float vett[], int dim){
    float max = vett[0];

    for (int cont = 0; cont < dim; cont++){
        if(vett[cont] > max){
            max = vett[cont];
        }
    }
    return max;
}

int main(){
    char prodotto[STRL];
    float prezzoFinale[DIM];
    float max = 0.0;
    int dim;
    dim = caricaDaFile(prezzoFinale, prodotto, DIM, NOME_FILE);

    //stampa(prodotto, prezzoFinale, dim);

    max = calcolaMax(prezzoFinale, dim);

    printf(
        "AMASONPRAIM"
        "AMASON CONSIGLIA:"
        "- prodotto %s"
        "solo oggi e domani scontato di %.2f euro", prodotto, max);

    return 0;
}