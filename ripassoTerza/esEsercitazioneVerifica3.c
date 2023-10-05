#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "dati_4BROB_informatica.txt"
#define FILE_MEDIA "medie4BROB.TXT"

/*
Author: Noemi Baruffolo
date: 5/10/2023
es. esEsercitazioneVerifica3
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

typedef struct {
    char studente[STRL];
    int numVoti;
    float sommaVoti;
} Studente;

void CalcolaMediaOgniStudenteCaricataDaFile(Studente classe[], int dim, char nomeFile[]) {
    int cont = 0;
    char data[STRL];
    char prof[STRL];
    char tipo[STRL];
    float voto;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if (fp != NULL) {
        while (cont < dim && fscanf(fp, "%s", data) != EOF) {
            fscanf(fp, "%s %s %s %f", prof, tipo, classe[cont].studente, &voto);
            classe[cont].sommaVoti += voto;
            classe[cont].numVoti++;
            cont++;
        }
        fclose(fp);
    } else {
        printf("Il file della classe non esiste o è vuoto!\n");
    }
}

void SalvaMedieSuFile(Studente classe[], int dim) {
    FILE *fp = fopen(FILE_MEDIA, "w");
    if (fp != NULL) {
        for (int k = 0; k < dim; k++) {
            if (classe[k].numVoti > 0) {
                float media = classe[k].sommaVoti / classe[k].numVoti;
                fprintf(fp, "%s %d %.2f\n", classe[k].studente, classe[k].numVoti, media);
            }
        }
        fclose(fp);
    } else {
        printf("Impossibile aprire il file per salvare le medie.\n");
    }
}

int main() {
    Studente classe[DIM];

    CalcolaMediaOgniStudenteCaricataDaFile(classe, DIM, NOME_FILE);
    SalvaMedieSuFile(classe, DIM);

    return 0;
}