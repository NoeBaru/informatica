#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 26
#define NR 100
#define NC 100
#define MAX 10

//matEs24.txt

/*
Author: Noemi Baruffolo
date: 21/09/2023
es. 24
text: Data una matrice NRxNC caricata da file, creare il vettore riga di lunghezza NC contenente la
somma delle colonne della matrice
*/

float chiediDim(char mess[], int min, int max){
	float n;
	printf(mess);
	do{
		scanf("%f", &n);
		if(n <= min || n > max){
			printf(mess);
		}
	} while(n < min || n > max);
	return n;
}

void caricaMatDaFile(float mat[][NC], int nr, int nc, char nomeFile[]) {
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        for(int k = 0; k < nr; k++) {
        //while(fscanf(fp, "%f", &mat[k][j]) != EOF && k < nr){
            for(int j = 0; j < nc; j++) {
                fscanf(fp, "%f", &mat[k][j]);
            }
        }
        fclose(fp);
    } else {
        printf("Il file della matrice non esiste o e' vuoto!\n");
    }
}

void sommaColonneMat(float mat[][NC], float sommaC[], int nr, int nc) {

    for(int k = 0; k < nc; k++){ //colonne
        for(int j = 0; j < nr; j++){ //righe
            sommaC[k] += mat[j][k];
        }
        printf("\n");
    }        
}

void stampaVett(float vett[], int dim) {
    for (int k = 0; k < dim; k++) {
        printf("[%d]:%.2f ", k, vett[k]);
        printf("\n");
    }
    printf("\n");
}

void stampaMat(float mat[][NC], int nr, int nc){
    
    for(int k = 0; k < nr; k++){
        for(int j = 0; j < nc; j++){
            printf("%.2f ", mat[k][j]);
        }
        printf("\n");
    }
}

int main() {
    float mat[NR][NC];
    float sommaC[NC] = {0};
    int nr, nc;
    char nomeFile[STRL];

    nr = chiediDim("Inserisci il numero di righe :", 0, NR);
    nc = chiediDim("Inserisci il numero di colonne :", 0, NC);
    printf("Inserisci il nome del file: ");
    scanf("%s", nomeFile);

    caricaMatDaFile(mat, nr, nc, nomeFile);

    sommaColonneMat(mat, sommaC, nr, nc);

    printf("la somma delle colonne e':\n");
    stampaVett(sommaC, nc);

    printf("La matrice e':\n");
    stampaMat(mat, nr, nc);

    return 0;
}