#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "GARE.txt"

/*
Author: Noemi Baruffolo
date: 4/10/2023
es. 37
text: Sia dato il file GARE.TXT così costituito (da creare e riempire):
mario rossi 25 (minuti impiegati a portare a termine la gara) INVIO
luca verdi 17 INVIO
loris bianchi 32 INVIO
Produrre in output l’atleta (cognome, nome) che ha impiegato meno tempo a portare a termine la
gara.
*/

typedef struct{
    char nome[STRL];
    char cognome[STRL];
    int minTermineGara;
} Partecipanti;

int chiediDim(int min, int max, char messaggio[]){
	int n;
	printf(messaggio);
	do{
		scanf("%d", &n);
		if(n <= 0 || n > max){
			printf("Inserisci un numero valido (1-%d): ", max);
		}
	} while(n < min || n > max);
	return n;
}

void caricaDaFile(Partecipanti gara[], int dim, char nomeFile[]) {
    int k = 0;

    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(k < dim && fscanf(fp, "%s", gara[k].nome) != EOF){
            fscanf(fp, "%s %d", gara[k].cognome, &gara[k].minTermineGara);
            k++;
        }
        fclose(fp);
    } else {
        printf("Il file della matrice non esiste o e' vuoto!\n");
    }
}

int calcolaMin(Partecipanti gara[], int dim){
    int min = gara[0].minTermineGara;

    for (int k = 1; k < dim; k++){
        if(gara[k].minTermineGara < min){
            min = gara[k].minTermineGara;
        }
    }

    return min;
}

int cercaPosMin(Partecipanti gara[],int dim, int min) {
    int k = 0;
    while (k < dim && gara[k].minTermineGara == min){
        k++;
    }
return k;
}

void stampaPartecipanti(Partecipanti gara[], int dim) {
    for (int k = 0; k < dim; k++) {
        printf("%s %s %d\n", gara[k].cognome, gara[k].nome, gara[k].minTermineGara);
    }
    printf("\n");
}

int main() {
    Partecipanti gara[DIM];
    int dim = chiediDim(0, DIM, "Inserisci il numero di partecipanti di alla gara: ");
    int min; 
    int posMin;

    caricaDaFile(gara, dim, NOME_FILE);

    min = calcolaMin(gara, dim);
    posMin = cercaPosMin(gara, dim, min);

    stampaPartecipanti(gara, dim); //prova

    printf("L'atleta %s %s ha impiegato il tempo minore (%d)",  gara[posMin].cognome, gara[posMin].nome, gara[posMin].minTermineGara);
    
    return 0;
}