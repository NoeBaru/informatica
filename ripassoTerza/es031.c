#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 20
#define DIM 100
#define FILE_PROD_DA_CANCELLARE "SCADUTI.DAT"
#define NOME_FILE "NEGOZIO.DAT"

/*
Author: Noemi Baruffolo
date: 26/09/2023
es. 31
text:
Un negozio di alimentari ha un archivio in cui vengono memorizzati i prodotti presenti in 
magazzino. Per ogni prodotto in magazzino, si dispone dei seguenti dati:
● la descrizione (stringa di al massimo 20 caratteri, incluso il terminatore);
● la quantità disponibile in magazzino (int);
● data di scadenza (tipo struttura).
Il programma deve memorizzare in un altro SCADUTI.DAT tutti i prodotti che sono da cancellare 
dall'archivio perché scaduti rispetto alla data letta da tastiera.
I dati vengono letti da un file NEGOZIO.DAT e la tabella deve poi essere ordinata rispetto la 
descrizione
Esempio di contenuto del file e dell'array di struct dopo l'ordinamento:
melanzane 85 2019/7/3
olio 60 2025/5/28
pere 150 2026/11/3
arance 210 2020/4/12
tonno 48 2027/10/4
pasta 75 2021/4/12
pomodoro 61 2015/7/31
aceto 49 2022/4/30
{"aceto",49,2022,4,30},
{"arance",210, 2020,4,12},
{"melanzane",85, 2019,7,3},
{"olio",60,2025,5,28},
{"pasta",75, 2021,4,12},
{"pere",150,2026,11,3},
{"pomodoro",61,2015,7,31},
{"tonno",48, 2027,10,4}
*/

typedef struct{
    int anno;
    int mese;
    int giorno;
} Data;

typedef struct{
    char descrizione[STRL];
    int quant;
    Data sadenza;
} Alimento;

int caricaDati(Alimento archivio[], int dim, char nomeFile[]){
    int k = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(k < dim && fscanf(fp, "%s", archivio[k].descrizione) != EOF){
            fscanf(fp, "%d", &archivio[k].quant);
            fscanf(fp, "%d", &archivio[k].sadenza.anno);
            fscanf(fp, "%d", &archivio[k].sadenza.mese);
            fscanf(fp, "%d", &archivio[k].sadenza.giorno);
            k++;
        }
    } else {
        printf("Il file del concorso non esiste o e' vuoto!\n");
    }

    return k;
}

void scambio(Alimento *a, Alimento *b){
    Alimento temp = *a;
    *a = *b;
    *b = temp;
}

void ordinaProdotti(Alimento archivio[], int dim){
    int k, sup, sca, risult;
    sup = dim - 1 ;
    while ( sup > 0 ) {
        sca=  0;
        for (k = 0; k < sup; k++) {
            risult = strcmp(archivio[k].descrizione, archivio[k + 1].descrizione);
            if (risult > 0){
                scambio(&archivio[k], &archivio[k + 1]);
                sca = k;
            }
            //per verificare che abbiaordinato e funzioni
            printf("%s ", archivio[k].descrizione);
            printf("%d ", &archivio[k].quant);
            printf("%d/", &archivio[k].sadenza.anno);
            printf("/%d", &archivio[k].sadenza.mese);
            printf("%d\n", &archivio[k].sadenza.giorno);
        }
    sup = sca;
    }
}

void convertiData(Data data) {
    
}

int prodottiScaduti(Alimento archivio[], int dim, char nomeFile[], Data dataOggi){
    int cont = 0;

    FILE *fp;

    fp = fopen(nomeFile, "w");

    if(fp != NULL){
        for(int k = 0; k < dim; k++){
            if(convertiData(dataOggi) >= convertiData(dataOggi)){
                fprintf(fp, "%s ", archivio[k].descrizione);
                fprintf(fp, "%d ", &archivio[k].quant);
                fprintf(fp, "%d/", &archivio[k].sadenza.anno);
                fprintf(fp, "/%d", &archivio[k].sadenza.mese);
                fprintf(fp, "%d\n", &archivio[k].sadenza.giorno);
                cont++;
            }
        }
    } else {
        printf("Il file del concorso non esiste o e' vuoto!\n");
    }
    return cont;
}


int main() {
    Alimento archivio[DIM];
    Data dataOggi;
    int annoAttuale, meseAttuale, giornoAttuale;

    int dim = caricaDati(archivio, DIM, NOME_FILE); //numero di prodotti e caricamento dei dati da file

    printf("Inserisci la data attuale: %d/%d/%d", &dataOggi.anno, &dataOggi.mese, &dataOggi.giorno);

    ordinaProdotti(archivio, dim);

    prodottiScaduti(archivio, dim, FILE_PROD_DA_CANCELLARE, annoAttuale, meseAttuale, giornoAttuale);

    return 0;
}