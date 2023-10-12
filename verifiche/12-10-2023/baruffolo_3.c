#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "AmasonPraim.txt"
#define FILE_MEDIA "medie4BROB.TXT"

/*
Author: Noemi Baruffolo
date: 12/10/2023
es. es3
text:
LA SITUAZIONE FINALE PER REPARTO : stampare un report finale che riporti i
seguenti dati per ogni singolo reparto (crea la struttura con i campi necessari)
- REPARTO xxxxxx:
il numero dei prodotti scontati: xx (usare QUANTITA’ per fare il totale)
il totale in euro dello sconto applicato è yy euro su un totale di pp euro 
**** (suggerimento: il prezzo totale è dato dal prezzo singolo moltiplicato per la
quantità) ***
*/

typedef struct{
    char reparto[STRL];
    int quant;
    float prezzoSingolo;
    float euroSconto;

} Reparto;

//carica da file e restiuisce il numero di prodotti presenti in esso
void caricaDaFile(Reparto prodotto[], int dim, char nomeFile[]) {
    float prezzoFinale[DIM];
    char prodotto[STRL];
    float prezzoS[DIM];
    int k = 0;
    int cont = 0;
    float prezzoTot = 0;

    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(cont < dim && fscanf(fp, "%s", prodotto[k].reparto) != EOF){
            fscanf(fp, "%s %.2f %.2f %.2f", prodotto[cont], &prezzoS[cont], &prodotto[k].euroSconto, &prezzoFinale[cont]);
            prodotto[k].quant = cont;
            prezzoTot = prezzoS[cont] * prodotto[k].quant;
            cont++;
            k++;
        }
        fclose(fp);
    } else {
        printf("Il file non esiste(l'ho appena creato) o e' vuoto(riempilo prima)!\n");
    }
}

int main(){
    Reparto prodotti[DIM];

    caricaDaFile(prodotti, DIM, NOME_FILE);

    return 0;
}