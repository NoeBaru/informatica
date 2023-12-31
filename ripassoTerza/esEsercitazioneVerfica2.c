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
es. esEsercitazioneVerifica2
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

void CalcolaMediaSingolaCaricataDaFile(Studente classe[], int dim, char nomeFile[]) {
    int cont = 0;
    int j = 0;
    int contV = 0;
    char data[STRL];
    char prof[STRL];
    char tipo[STRL];
    char studenteN[STRL] = "Bagnis";
    float voto;
    float somma = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if (fp != NULL) {
        while (cont < dim && fscanf(fp, "%s", data) != EOF) {
            fscanf(fp, "%s %s %s %f", prof, tipo, classe[cont].studente, &voto);
            if (strcmp(studenteN, classe[cont].studente) == 0) {
                somma += voto;
                contV++;
            }
            cont++;
        }
        fclose(fp);

        for (int k = 0; k < cont; k++) {
            classe[k].voto_media = somma / contV; // Calcolo la media corretta
            if (strcmp(studenteN, classe[k].studente) == 0) {
                if(j == 0){
                    printf("%s %.2f\n", classe[k].studente, classe[k].voto_media);
                    j++;
                }
            }
        }
    } else {
        printf("Il file della classe non esiste o è vuoto!\n");
    }
}

int main() {
    Studente classe[DIM];

    CalcolaMediaSingolaCaricataDaFile(classe, DIM, NOME_FILE);

    return  0;
}