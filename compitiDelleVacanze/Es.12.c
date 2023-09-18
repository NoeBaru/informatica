#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME_FILE "STATI.txt"
#define NAZ 193
#define STRL 26

/*
Author: Noemi Baruffolo
date: /08/2023
es. 12
text:
In un file STATI.txt sono memorizzati per ogni nazione il nome, la
capitale, la superficie in kmq, il numero di abitanti. Ordinare il file in
ordine alfabetico rispetto alla nazione e quindi dato il nome di uno stato
visualizzare tutti suoi dati compresa la densità.
*/

typedef struct {
    char nome[STRL];
    char cap[STRL];
    float kmq;
    int numA;
} Naz;

int contaNaz(char nomeF[]) {
    int c;
    int cont = 0;

    FILE *fp;
    fp = fopen(nomeF,"r");

    if(fp != NULL) {
        while ((c = fgetc(fp)) != EOF) {
            if(c =='\n') {
                cont++;
            }
        }
        fclose(fp); //chiude il file
    }
    return cont;
}

void caricaNaz(Naz tab[], int dim, char nomeF[]) {
    FILE *fp;
    fp = fopen(nomeF,"r");

    if(fp != NULL) {
        for(int k = 0; k < dim; k++) {
            fscanf(fp, "%s %s %f %d", tab[k].nome, tab[k].cap, &tab[k].kmq, &tab[k].numA);
        }
        fclose(fp); //chiude il file
    }
}

void scambio(Naz *a, Naz *b) {
    Naz temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(Naz tab[], int n) {
    int k, sup, sca;
    int ris;
    sup = n - 1 ;
    while ( sup > 0 ) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            ris = strcmp(tab[k].nome, tab[k + 1].nome);
            if (ris > 0){ //se la prima e' sup alla seconda
                scambio(&tab[k], &tab[ k + 1 ]);
                sca = k ;
            }
        }
        sup = sca ;
    }
}

void scriviNaz(Naz tab[], int dim, char nomeF[]) {
    FILE *fp;
    fp = fopen(nomeF,"w");

    if(fp != NULL) {
        for(int k = 0; k< dim; k++) {
            fprintf(fp, "%s %s %f %d\n", tab[k].nome, tab[k].cap, tab[k].kmq, tab[k].numA);
        }
        fclose(fp); //chiude il file
    }
}

void convertiMaiusc(char s[STRL]) {
    int k = 0;
    
    while(s[k] != '\0') {
        if(s[k] >= 'a' && s[k] <= 'z') {
            s[k] -= ('a' - 'A'); //32 in tabella ascii
        }
        k++;
    }
}

int OrdDisg2(Naz tab[],int n, char x[]) {
    int tro, k, ris;
    tro = - 1;
    k = 0 ;
    while((k < n) && (tro == - 1)){
        ris = strcmp(x, tab[k].nome);
        if(ris == 0)
            tro = k;
        else{
            if(ris < 0 ) 
                k = n ; //forza l’uscita dal ciclo
            else
                k++ ;}
    }
return tro ;
}

int main() {
    Naz tab[NAZ];

    FILE *fp;
    char n[STRL];
    int dim = 0;
    float dens = 0;
    int indice;

    dim = contaNaz(NOME_FILE);

    if( dim != 0) {
        caricaNaz(tab, dim, NOME_FILE);
        bubbleSort3(tab, dim);
        scriviNaz(tab, dim, NOME_FILE);

        printf("Inserisci il nome della nazione di cui vuoi i dati: ");
        scanf("%s", n);
        convertiMaiusc(n);
        indice = OrdDisg2(tab, dim, n);

        if(indice == -1) {
            printf("La nazione %s non e' stata trovata!", n);
        } else {
            dens = tab[indice].numA /tab[indice].kmq;
            printf("%s:\nCapitale: %s\nSuperficie kmq: %.3f\nNumero abitanti: %d\nDenista' di popolazione: %.2f", tab[indice].nome, tab[indice].cap, tab[indice].kmq, tab[indice].numA, dens);
        }
    } else {
        printf("\nIl file non esiste o e' vuoto, crealo e compilalo!");
    }

    return 0;
}