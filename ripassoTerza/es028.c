#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 21
#define DIM 100

/*
Author: Noemi Baruffolo
date: 26/09/2023
es. 28
text:
Si scriva un programma che definisca una struttura che permetta di contenere una serie di dati 
Squadra (struct Squadra) del tipo:
● nome squadra (stringa di lunghezza 20) ;
● goal fatti (intero) ;
● goal subiti (intero).
Il programma deve permettere nell'ordine le seguenti operazioni:
A. Memorizzare i dati in un vettore di strutture "campionato";
B. Stampare a terminale tutti i nomi delle squadre che hanno fatto un numero di goal 
maggiore del numero dei goal subiti.
C. Letto a terminale il nome di una squadra stampare a video i goal fatti e i goal subiti o dire 
che non è presente nell'elenco
Esempio di contenuto dell'array di struct:
{"juventus", 1, 10, 12},
{"milan", 8, 7, 6},
{"inter", 10, 13, 11},
{"palermo", 2, 9, 10},
{"lazio", 5, 8, 4},
{"udinese", 14, 5, 7}
*/

//File: squadraEs28.txt

typedef struct{
    char nome[STRL];
    int goalFatti;
    int goalSubiti;
} Squadra;

int caricaDati(Squadra tab[], int dim, char nomeFile[]){
    int k = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(fscanf(fp, "%s", tab[k].nome) != EOF && k < dim){
            fscanf(fp, "%d", &tab[k].goalFatti);
            fscanf(fp, "%d", &tab[k].goalSubiti);
            k++;
        }
    } else {
        printf("Il file della squadra non esiste o e' vuoto!\n");
    }

    return k;
}

void stampaSqudreGoalMagg(Squadra tab[], int dim) {
    for(int k = 0; k< dim; k++){
        if(tab[k].goalFatti > tab[k].goalSubiti){
            printf("%s %d %d\n", tab[k].nome, tab[k].goalFatti, tab[k].goalSubiti);
        }
    }
}

void stampaContatto(Squadra tab) {
    printf(
        "Squadra: %s\n"
        "goal fatti: %d\n"
        "goal subiti': %d\n\n",
        tab.nome, tab.goalFatti, tab.goalSubiti
    );
}

void cercaSquadra(Squadra tab[], int dim) {
    char nomeN[STRL];
    int cont = 0;

    printf("Inserisci il nome: ");
    fflush(stdin);
    scanf("%s", nomeN);

    for(int k = 0; k < dim; k++) {
        if(strcmp(nomeN, tab[k].nome) == 0){
            stampaContatto(tab[k]);
            cont++;
        }
    }

    if(cont == 0){
        printf("Non esiste la squadra cercata");
    }
}

int main() {
    Squadra campionato[DIM];
    int numS = 0;
    char nomeFile[STRL];

    printf("Inserisci il nome del file: ");
    fflush(stdin);
    scanf("%s", nomeFile);

    numS = caricaDati(campionato, DIM, nomeFile); //A

    stampaSqudreGoalMagg(campionato, numS); //B

    cercaSquadra(campionato, numS); //C

    return 0;
}