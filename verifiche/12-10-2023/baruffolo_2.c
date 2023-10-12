#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "AmasonPraim.txt"
#define FILE_SCONTO "ProdottiScontati.txt"

/*
Author: Noemi Baruffolo
date: 12/10/2023
es. es2
text:
ELENCO DEI PRODOTTI SCONTATI: creare un file “ProdottiScontati.txt” (i prodotti non
scontati riportano il valore 0 “zero” nella colonna PERCENTUALE SCONTO) con il relativo
sconto in euro e il prezzo di vendita al netto dello sconto.
*/

float calcolaScontoNegativo(float sconto, float prezzo, float percentuale) {
    sconto = (prezzo * (percentuale / 100));
    return prezzo - sconto;
}

int caricaDaFile(float prezzoFinale[], char prodotto[], int dim, char nomeFile[], char nomeFileSconto[]) {
    char reparto[STRL];
    float prezzoS[DIM];
    float sconto [DIM];
    int quant[DIM];
    int percSconto[DIM];
    int cont = 0;

    FILE *fp;
    FILE *fs;

    fp = fopen(nomeFile, "r");
    fs = fopen(nomeFileSconto, "w");

    if(fp != NULL){
        while(cont < dim && fscanf(fp, "%s", reparto) != EOF){
            fscanf(fp, "%s %f %d %d", prodotto[cont], &prezzoS[cont], &quant[cont], &percSconto[cont]);
            prezzoFinale[cont] = calcolaScontoNegativo(sconto[cont], prezzoS[cont], percSconto[cont]);
            fprintf(fs, "Il prodotto %s %s %s sconto €:%.2f prezzo vendita netto: %.2f", reparto, prodotto[cont], prezzoS[cont], sconto[cont], prezzoFinale[cont]);
            cont++;
        }
        fclose(fs);
        fclose(fp);
    } else {
        printf("Il file non esiste(l'ho appena creato) o e' vuoto(riempilo prima)!\n");
    }
    return cont;
}

int main(){
    char prodotto[STRL];
    float prezzoFinale[DIM];
    int dim;

    dim = caricaDaFile(prezzoFinale, prodotto, DIM, NOME_FILE, FILE_SCONTO);

    return 0;
}