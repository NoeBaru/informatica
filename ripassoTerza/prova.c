#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 26
#define DIM 100
#define NOME_FILE "dati_4BROB_informatica.txt"
#define FILE_MEDIA "medie4BROB.TXT"

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
    for (int k = 0; k < DIM; k++) {
        strcpy(classe[k].studente, ""); // Inizializza l'array studente
        classe[k].numVoti = 0;
        classe[k].sommaVoti = 0.0;
    }

    CalcolaMediaOgniStudenteCaricataDaFile(classe, DIM, NOME_FILE);
    SalvaMedieSuFile(classe, DIM);

    return 0;
}