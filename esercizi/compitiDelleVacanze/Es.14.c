#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P 10 //numero di punteggi e prove
#define DIM 100 //dimensione massima
#define STRL 20 //lunhezza stringhe
#define NOME_FILE "concorso.txt" //nome file

/*
Author: Noemi Baruffolo
date: /08/2023
es. 14
text:
In un concorso, i partecipanti sono sottoposti a 10 prove. I risultati del
concorso sono memorizzati in un array di strutture, che contiene, per ogni
concorrente, i seguenti dati:
• nome: stringa contenente al massimo 20 caratteri, compreso il
terminatore;
• punteggi: una sequenza di 10 interi.
• Totale: totale punteggi
Si scriva un programma che stampi, per ciascuna prova, chi è il vincitore e
con quale punteggio (ci sono pari merito). Inoltre si visualizzi la
classifica finale.
Ad esempio:
Rossi 4 6 1 ...
Bianchi 12 0 9 ...
Verdi 2 3 7 ...
Il programma dovrà visualizzare:
prova 1: Bianchi 12
prova 2: Rossi 6
prova 3: Bianchi 9
Esempio di contenuto dell'array di struct:
{"Rossi", {4,6,1,2,0,11,0,2,3,3},32},
{"Bianchi", {12,0,9,4,5,2,1,1,0,5},39},
{"Verdi", {2,3,7,9,10,4,5,9,7,2},58},
{"Astolfi", {0,2,6,1,8,5,9,10,6,8},55},
{"Lorenzi", {6,9,7,1,0,0,4,5,5,1},38},
{"Franchi", {1,10,11,19,4,7,2,0,4,7},65}
*/

typedef struct {
    char nome[STRL];
    int punt[P];
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
            }
            fscanf(fp, "%d", &conc[k].tot);
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

    int num = caricaDati(concorrenti, DIM, P, NOME_FILE); //numero di partecipanti e caricamento dei dati da file

    winner(concorrenti, num, P); //vincitore per ogni prova

    stampaClassifica(concorrenti, num); //stampa classifica

    return 0;
}