#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 20
#define DIM 100
#define NOME_FILE "numeri.dat"
#define NOME_NEW_FILE "risultati.dat"

/*
Author: Noemi Baruffolo
date: 3/10/2023
es. 33
text: Dato un file di testo "numeri.dat" contenente dei numeri reali, leggerli e infine salvare nel file 
"risultati.dat" il valore medio. Attenzione il file può non esistere o essere vuoto
*/

void readWrite(int dim, char nomeFile[], char newNameFile[]) {
    FILE *fp,*ft; //puntatori al file da modificare e temporaneo
    int cont = 0;
    float num;
    float somma = 0;
    float media = 0;
    if ((fp = fopen(nomeFile,"r"))!= NULL) {
        if ((ft = fopen(newNameFile,"w"))!= NULL) {
            while(cont < dim && fscanf(fp,"%f",&num)!= EOF){
                cont++;//operazioni di modifica
                somma += num;
            }
            if(somma != 0){
                media = somma / cont;
            }
            fprintf(ft,"%.2f",media);
            printf("La media e' stata stampata nel file correttamente");

            fclose(ft); // chiusura del file temporaneo
            fclose(fp); // chiusura del file da modificare
        }
        else {
            printf("Errore apertura file temporaneo");
            fclose(fp); //chiusura del file da modificare
        }
    }   
    else{
        printf("Errore apertura file da modificare, file non esistente o erroato");

    }
}

int main() {
    readWrite(DIM, NOME_FILE, NOME_NEW_FILE);
    return 0;
}