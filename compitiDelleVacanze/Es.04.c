#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define DIM 100
#define LIM_MIN -20
#define LIM_MAX 20

/*
Author: Noemi Baruffolo
date: /07/2023
es. 4
text:
Creare un programma a menù con le seguenti funzioni:
 0 = esci
1 = carica il vettore con valori casuali da -20 a 20, dopo aver chiesto
quanti elementi si vogliono inserire
 2 = visualizza il vettore
 3 = somma di tutti gli elementi
 4 = media degli elementi
 5 = visualizza valore minimo e massimo
 6 = gli elementi sono tutti positivi?
 7 = somma degli elementi positivi
 somma degli elementi negativi
 quale somma è maggiore in valore assoluto?
ATTENZIONE! Controlla che sia stato caricato il vettore prima di poter
eseguire le varie opzioni
*/

void menu() {
    printf("Inserisci il numero corrispondente alla scelta: \n0 = esci\n1: carica vettore casuale (-20 - 20) e chiede quanti elementi inserire\n");
    printf("2: visualizza il vettore casuale\n3: somma tutti gli elementi\n4: media degli elementi\n5: visualizza il valore min e max\n");
    printf("6: dice se tutti gli elementi sono positivi o no\n7: somma gli elementi positivi, somma gli elementi negativi e dice quale somma e' maggiore (in valore assoluto)");
    printf("N^: ");
}

int chiediDim(int min, int max, char mess[]) {
    int n;

    do{
        printf(mess);
        scanf("%d", &n);
    } while(n < min || n > max);
    return n;
}

void caricaVett(int v[], int dim) {
    for(int k = 0; k < dim; k++) {
        v[k] = LIM_MIN + rand() % (LIM_MAX - LIM_MIN + 1);
    }
}

void visVett(int v[], int dim) {
    printf("Vettore ");
    for(int k = 0; k < dim; k++) {
        printf("[%d]: %d\n", k + 1, v[k]);
    }
}

int sommaVett(int v[], int dim) {
    int somma = 0;

    for(int k = 0; k < dim; k++) {
        somma += v[k];
    }

    return somma;
}

void valori(int v[], int dim, int *min, int *max) {
    int k;
    for (k = 0; k < dim; k++){
        if(k == 0){
            *max = v[k];
            *min = v[k];
        }
        if(v[k] > *max){
            *max = v[k];
        }
        if(v[k] < *min){
            *min = v[k];
        }
    }
}

bool sonoPos(int v[], int dim) {
    int k = 0;
    bool pos = true;
    while (k < dim && pos == true){
        if(v[k] < 0){
            pos = false;
        }
        k++;
    }
    return pos;
}

int somma(int v[], int dim, int *spos, int *sneg) {
    int som;
    *sneg = 0;
    *spos = 0;
    for (int k = 0; k < dim; k++){
        if(v[k] < 0){
            *sneg += (v[k]* -1); //somma positiva
        } else if(v[k] > 0) {
            *spos += v[k];
        }
    }
    if(*spos > *sneg) {
        som = 1;
    } else if(*sneg > *spos) {
        som = -1;
    } else { //sono uguali
        som = 0;
    }
    return som;
}

int main() {
    int v[DIM];
    int risp, dim, min, max, sp, sn, ris; //risposta, dimensione, minimo, massimo, somma positivi, somma negativi, risultato somma valore assoluto
    int som = 0;
    float media = 0;

    srand(time(NULL));

    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break;

        case 1:
            dim = chiediDim(1, DIM, "\nInserisci la dimensione del vettore: "); //dimensione da utilizzare del vettore in input
            caricaVett(v, dim); //caricamento con numeri casuali (-20 - 20) del vettore
            break;

        case 2:
            if(dim != 0) {
                visVett(v, dim); //visualizza il vettore
            } else{
                printf("\nCarica il vettore prima!");
            }
            break;
        
        case 3:
            if(dim != 0) {
                som = sommaVett(v, dim); //somma elementi del vettore
                printf("\nLa somma degli elementi del vettore e': %d", som);
            } else{
                printf("\nCarica il vettore prima!");
            }
            break;

        case 4:
            if(dim != 0 ) {
                media = som / dim; //media degli elementi del vettore 
                printf("\nLa media degli elementi del vettore e': %d", media);
            } else{
                printf("\nCarica il vettore prima!");
            }
            break;
        
        case 5:
            if(dim != 0) {
                valori(v, dim, &min, &max);
                printf("\nIl valore minimo e': %d\nIl valore massimo e': %d", min, max);
            } else{
                printf("\nCarica il vettore prima!");
            }
            break;

        case 6:
            if(dim != 0) {
                if(sonoPos(v, dim) == true) {
                    printf("\nGli elementi sono tutti positivi!");
                } else {
                    printf("\nNON tutti gli elementi sono positivi");
                }
            } else{
                printf("\nCarica il vettore prima!");
            }

            break;

        case 7:
            if(dim != 0) {
                ris = somma(v, dim, &sp, &sn);
                printf("\nLa somma dei numeri positivi e': %d", sp);
                printf("\nLa somma dei numeri negativi e': %d", sn);
                if(ris == 1){
                    printf("\nLa somma dei numeri positivi e' maggiore!\n");
                } else if(ris == -1) {
                    printf("\nLa somma dei numeri negativi e' maggiore!\n");
                } else {
                    printf("\nLe somme sono uguali!\n");
                }
                
            } else{
                printf("\nCarica il vettore prima!");
            }

            break;

        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);

    return 0;
}