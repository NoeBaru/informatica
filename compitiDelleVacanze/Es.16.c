#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_FILE "COORDINATE.txt"
#define NOME_FILE_O "output.txt"
#define STRL 256
#define MAXC 10 //non 9 perché da 0 a 9 sono 10
#define MAXR 10 
#define MIN 0
#define MAX 9

/*
Author: Noemi Baruffolo
date: /09/2023
es. 16
text:
Sia dato il file COORDINATE.TXT così costituito (da creare e riempire):
(0 , 7) (4 , 9) (1 , 5) INVIO
(8 , 2) (1 , 4) INVIO
I numeri tra parentesi, sempre tra lo 0 ed il 9, rappresentano il numero di
riga ed il numero di colonna riferiti ad una matrice quadrata 9 x 9.
In ogni riga del file vi sia un numero imprecisato di coordinate
(nell’esempio 3 nella prima riga e due nella seconda). Dopo una parentesi )
vi sia sempre uno spazio e ci sia una virgola tra spazi tra le due
coordinate.
Leggere dal file i numeri che si trovano dentro ogni singola parentesi e
scrivere nella corrispondente riga-colonna della matrice un * avendo cura
di controllare che i valori siano corretti e che tale scrittura non sia già
avvenuta.
Creare il file di output con la stampa della matrice e all’inizio l’eventuale
elenco degli errori con relative coordinate
*/

void caricaDati(int mat[][MAXC], char nomeFile[], char nomeFileO[]) {
    FILE *fp;
    FILE *out;
    
    fp = fopen(nomeFile, "r");
    out = fopen(nomeFileO, "w");

    int r, c;
    
    while(fscanf(fp, "(%d , %d) ", &r, &c) != EOF) {
        if((r < 0 || r > 9) || (c < 0 || c > 9)) {
            fprintf(out, "Errore: Coordinate inserite non comprese tra 0 e 9!\n");
        } else {
            if(mat[r][c] == '*') {
                fprintf(out, "Errore: Hai gia' inserito le coordinate (%d , %d)!\n", r, c);
            } else {
                mat[r][c] = '*';
            }
        }
    }

    fclose(out);
    fclose(fp);
}

void caricaMat(int mat[][MAXC], char nomeFile[], char nomeFileO[]) {
    FILE *fp;
    FILE *out;
    
    fp = fopen(nomeFile, "r");
    out = fopen(nomeFileO, "w");

    for(int r = 0; r < 10; r++) {
        for(int c = 0; c < 10; c++) {
            fprintf(out, "%c", mat[r][c]);
        }
        fprintf(out, "\n");
    }
    
    fclose(out);
    fclose(fp);
}

int main() {
    int mat[MAXR][MAXC] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };

    caricaDati(mat, NOME_FILE, NOME_FILE_O);
    caricaMat(mat, NOME_FILE, NOME_FILE_O);

    return 0;
}