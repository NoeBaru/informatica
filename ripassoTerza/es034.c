#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 20
#define DIM 100
#define NOME_FILE "risultati.dat"

/*
Author: Noemi Baruffolo
date: 3/10/2023
es. 34
text: Aggiungere al file precedente "risultati.dat" il valore massimo tra i numeri
*/

void readWrite(int dim, char nomeFile[]) {
    FILE *fp; //puntatori al file da modificare e temporaneo
    int cont = 0;
    float num;
    float valoreMax;
    if ((fp = fopen(nomeFile,"a"))!= NULL) {
        while(cont < dim && fscanf(fp,"%f",&num)!= EOF){
            if(cont == 0){
                valoreMax = num;
            } else if (num > valoreMax){
                valoreMax = num;
            }
            cont ++;
        }
        fprintf(fp,"\nValore massimo: %.2f", valoreMax);
        printf("Il valore massimo e' stato stampato nel file correttamente");
        fclose(fp); // chiusura del file da modificare
    }else{
        printf("Errore apertura file da modificare, file non esistente o erroato");
    }
}

int main() {
    readWrite(DIM, NOME_FILE);
    return 0;
}