#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 21
#define DIM 100
#define AZIONI 7

/*
Author: Noemi Baruffolo
date: 26/09/2023
es. 29
text:
Un array di strutture contiene l'andamento delle quotazioni di alcune azioni in borsa nell'ultima 
settimana. La struttura è definita in questo modo:
● nome: stringa al massimo di 20 caratteri, senza spazi;
● valori: una sequenza di 7 float (uno per ogni giorno della settimana).
Il programma deve visualizzare sullo schermo quante azioni hanno avuto un calo superiore al 10% 
in una sola giornata.
Ad esempio:
● KettImport 100 98 97 96 110 109 105
● ACME 100 95 100 88 81 105 107
Il programma dovrà fornire come risultato 1, in quanto la ACME ha avuto un calo superiore al 10% 
fra il terzo e il quarto giorno.
*/

//azioniEs29.txt

typedef struct{
    char nome[STRL];
    float valori[DIM];
} Azioni;

int caricaDati(Azioni tab[], int dim, int numAz, char nomeFile[]){
    int k = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(fscanf(fp, "%s", tab[k].nome) != EOF && k < dim){
            for(int j = 0; j < numAz; j++) {   
                fscanf(fp, "%d", &tab[k].valori[j]);
                j++;
            }
            k++;
        }
    } else {
        printf("Il file della squadra non esiste o e' vuoto!\n");
    }

    return k;
}

int caloAzioni(Azioni tab[], int dim) {
    int cont = 0;
    for(int k = 0; k < dim; k++) {
        if() {
            cont++;
        }
    }
    return cont;
}

int main() {
    Azioni andamento[DIM];
    char nomeFile[STRL];
    int num;
    int numAzioni;

    printf("Inserisci il nome del file: ");
    fflush(stdin);
    scanf("%s", nomeFile);

    num = caricaDati(andamento, DIM, AZIONI, nomeFile);
    numAzioni = caloAzioni(andamento, num);

    return 0;
}