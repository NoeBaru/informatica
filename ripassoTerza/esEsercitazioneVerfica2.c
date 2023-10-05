#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "dati_4BROB_informatica.txt"

/*
Author: Noemi Baruffolo
date: 5/10/2023
es. esEsercitazioneVerifica
text:
La 4B ROB affronta le prime 2 verifiche di informatica con la prof.ssa Cerutti (teoria) e il prof.
Ferrua. Dal nuovo registro viene estratto il file “dati_4BROB_informatica.txt”
Si vuole sapere:

1) ANDAMENTO DELLA CLASSE: stampare il numero totale di voti raccolti nelle due verifiche e
la media dei voti globali di entrambe le verifiche (preciso: la media di tutti i voti di tutti gli alunni di
tutte le verifiche presenti sul file)
La stampa sarà “Nella classe 4B ROB sono stati raccolti X voti con voto medio Y”.

2) LA TUA MEDIA: cerca il tuo cognome e popola una struct STUDENTE di tipo:
• studente (stringa lunghezza 20)
• voto_media (reale)
La struct popolata come descritto sopra, deve essere salvata su un file avente nome:
“TuoCognome”.TXT (preciso: “TuoCognome” va sostituito con il tuo cognome!)

3) LA MEDIA DI OGNI SINGOLO ALUNNO: popolare un array di struct STUDENTI di
tipo:
• studente (stringa lunghezza 20)
• numVoti (int)
• sommaVoti (reale)
L’array di struct popolato come descritto sopra, dovrà essere salvato su un file avente nome:
MEDIE4BROB.TXT
*/

typedef struct{
    char studente[STRL];
    float voto_media;
} Studente;


//carica una matrice da file
void CalcolaMediaSingolaCaricataDaFile(Studente classe[], int dim, char nomeFile[]) {
    int cont = 0;
    int contV = 0;
    char data[STRL];
    char prof[STRL];
    char tipo[STRL];
    char cognome[STRL];
    char studenteN[STRL] = "Bagnis";
    float voto;
    float somma = 0;
    float media;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        while(cont < dim && fscanf(fp, "%s", data) != EOF){ //carico i dati della classe
            fscanf(fp, "%s %s %s %f", prof, tipo, classe[cont].studente, &voto);
            if(strcmp(studenteN, classe[cont].studente) == 0){
                somma += voto;
                contV++;
            }
            cont++;
        }
        fclose(fp);

        for(int k = 0; k < cont; k++){ //calcolo la media di tutti gli studenti e stampo il mio cognome  ela mia media
            classe[k].voto_media = somma / cont;
            if(strcmp(studenteN, classe[k].studente) == 0){
                printf("%s %.2f", classe[k].studente, classe[k].voto_media);
                contV++;
            }
        }

    } else {
        printf("Il file della classe non esiste o e' vuoto!\n");
    }
}
/*
int cercaStudente(Studente classe[], int dim) {
    char studenteN[STRL] = "Baruffolo";
    int somma = 0;
    int cont = 0;

    for(int k = 0; k < dim; k++) {
        if(strcmp(studenteN, classe[k].studente) == 0){
            somma += 
            classe[k].voto_media = somma / cont;
            printf("%s %.2f", classe[k].studente, classe[k].voto_media);
            cont++;
        }
    }
    return cont;
}
*/

int main() {
    Studente classe[DIM];

    CalcolaMediaSingolaCaricataDaFile(classe, DIM, NOME_FILE);

    return  0;
}