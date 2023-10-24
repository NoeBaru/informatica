#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG 20
#define DIM 100
#define GIORNI 30
#define NOME_FILE "appDent.txt"

/*
Author: Noemi Baruffolo
date: /08/2023
es. 15
text:
Un ambulatorio dentistico utilizza un array di strutture per memorizzare
tutte le prenotazioni effettuate per il mese di Luglio. Le prenotazioni hanno
la seguente struttura:
• cognome: stringa di 20 caratteri, compreso il terminatore;
• data: intero da 1 a 30.
Si scriva un programma che stampi quali giorni sono liberi e dato un giorno
del mese gli appuntamenti del giorno.
Esempio di contenuto dell'array di struct:
{"Astolfi", 27},
{"Bianchi", 3},
{"Carli", 15},
{"Conti", 3},
{"Diaz", 2},
{"Ferro", 22},
{"Finotti", 21},
{"Marangoni", 13},
{"Montale", 28},
{"Nardo", 1},
{"Natale", 30},
{"Pasquali", 3},
{"Ranieri", 10},
{"Salvi", 20},
{"Tommasi", 27},
*/

typedef struct{
    char cognome[LUNG];
    int data;

} Prenotazione;

int chiediDim(int dim){
    int n;
    do{
        scanf("%d", &n);
        if(n < 0 || n > dim){
            printf("Inserisci un valore valido (superiore a 1 e minore di %d)", dim);
        }
    } while(n < 0 || n > dim);
}

int caricaVett(Prenotazione v[], int max, char nomeFile[]) {
    int dim = 0;
    int k = 0;
    FILE *fp;
    fp = fopen(nomeFile, "r");

    if(fp != NULL) {
        while(fscanf(fp, "%s %d", v[k].cognome, &v[k].data) != EOF && k < max) {
            k++;
            dim++;
        } 
        fclose(fp);
    }
    return dim;
}

void scambio(Prenotazione *a, Prenotazione *b) {
    Prenotazione temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(Prenotazione vett[], int n) {
    int k, sup, sca; 
    sup= n - 1 ;
    while ( sup > 0 ) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (vett[ k ].data > vett[k + 1].data){
                scambio(&vett[k], &vett[k + 1]);
                sca = k ;
            }
        }
        sup = sca ;
    }
}

bool cercaGiorno(Prenotazione v[], int dim, int x) {
    int k = 0;
    bool res = false;

    while(k < dim && res == false) {
        if(v[k].data == x) {
            res = true;
        }
        k++;
    }
    return res;
}

void contL(Prenotazione appuntamenti[], int dim, int giorni) {
    for(int k = 1; k <= giorni; k++) {
        if(cercaGiorno(appuntamenti, dim, k) == false) {
            printf("Il giorno %d e' libero!\n", k);
        }
    }
}

void appPerGiorno(Prenotazione app[],int dim, int giorni) {
    int x;
    int cont = 0;
    printf("Inserisci una data (1 - %d): ", giorni);
    x = chiediDim(giorni);

    printf("Appuntamenti per il giorno %d luglio:\n", x);

    for(int k = 0; k < dim; k++){
        if(x == app[k].data){
            printf("%s\n", app[k].cognome);
            cont++;
        }
    }

    if(cont == 0) {
        printf("Non sono stati trovati appuntamenti per il giorno %d luglio!\n", x);
    }
}

int main(){
    Prenotazione appuntamenti[DIM];

    int dim = caricaVett(appuntamenti, DIM, NOME_FILE);

    if(dim != 0)  {
        contL(appuntamenti, dim, GIORNI);

        appPerGiorno(appuntamenti, dim, GIORNI);
    } else {
        printf("Il file e' vuot o non esiste!");
    }

return 0;
}