#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NP 10 //numero di punteggi e prove
#define DIM 100 //dimensione massima
#define STRL 20 //lunghezza stringhe

/*
Author: Noemi Baruffolo
date: 26/09/2023
es. 30
text:
In un concorso, i partecipanti sono sottoposti a 10 prove. I risultati del concorso sono memorizzati 
in un array di strutture, che contiene, per ogni concorrente, i seguenti dati:
• nome: stringa contenente al massimo 20 caratteri, compreso il terminatore;
• punteggi: una sequenza di 10 interi.
• totale: calcola la somma dei punteggi durante il caricamento e verrà usato per la classifica
Caricare i dati da tastiera e visualizzare per ciascuna prova, chi è il vincitore e con quale punteggio 
e quindi la classifica finale.
Esempio di contenuto dell'array di struct:
{"Rossi", {4,6,1,2,0,4,0,1,2,2}},
{"Bianchi", {12,0,9,4,5,2,1,1,0,5}},
{"Verdi", {2,3,7,9,10,4,5,9,7,2}},
{"Astolfi", {0,2,6,1,8,5,9,10,7,8}},
{"Lorenzi", {6,9,7,1,0,0,4,5,2,1}},
{"Franchi", {1,10,11,19,4,7,2,0,2,7}}
*/

//vedi es14 compiti delle vacanze
//concorsoEs30.txt

typedef struct {
    char nome[STRL];
    int punt[NP];
    int tot;
} Concorso;

int caricaDati(Concorso conc[], int dim, int p, char nomeFile[]){
    int k = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(fscanf(fp, "%s", conc[k].nome) != EOF && k < dim){
            for(int j = 0; j < p; j++) {
                fscanf(fp, "%d", &conc[k].punt[j]);
                conc[k].tot += conc[k].punt[j];
            }
            k++;
        }
    } else {
        printf("Il file del concorso non esiste o e' vuoto!\n");
    }

    return k;
}

void winner(Concorso conc[], int dim, int np) {
    int max = 0;

    for(int k = 0; k < np; k++){ //prove
        printf("Il vincitore della prova n^%d e': ", k + 1);
        max = conc[0].punt[k];
        for(int j = 1; j < dim; j++){ //partecipanti
            if(conc[j].punt[k] > max){
                max = conc[j].punt[k];
            }
        }
        for(int j = 0; j < dim; j++) {
            if(conc[j].punt[k] == max) {
                printf("%s ", conc[j].nome);
                printf("%d\n", max);
            }
        }
    }
}

void scambio(Concorso *a, Concorso *b) {
    Concorso temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(Concorso conc[], int dim) {
    int k, sup, sca; 
    sup = dim - 1 ;
    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (conc[k].tot < conc[k + 1].tot){
                scambio(&conc[k], &conc[k + 1]);
                sca = k ;
            }
        }
        sup = sca ;
    }
}

void stampaClassifica(Concorso conc[], int dim) {

    bubbleSort3(conc, dim); //ordinamento classifica finale

    printf("\n\nLa classifica finale e':\n");

    for (int k = 0; k < dim; k++){
        printf("%s ", conc[k].nome);
        printf("%d\n", conc[k].tot);
    }
}

int main() {
    Concorso concorrenti[DIM];
    char nomeFile[STRL];

    printf("Inserisci il nome del file: ");
    fflush(stdin);
    scanf("%s", nomeFile);

    int num = caricaDati(concorrenti, DIM, NP, nomeFile); //numero di partecipanti e caricamento dei dati da file

    winner(concorrenti, num, NP); //vincitore per ogni prova

    stampaClassifica(concorrenti, num); //stampa classifica

    return 0;
}