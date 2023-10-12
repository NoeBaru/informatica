/*
author:
date:
es:
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 30
#define NMAX 40

typedef struct {
    char nomeStudente[LUNG];
    float voto_media;
} Studente;

void mediaCont(char nomeFile[LUNG], Studente stud[NMAX]) {
    FILE *fp;
    FILE *fp2;
    fp = fopen(nomeFile, "r");
    int nVoti = 0;
    int k;
    float media = 0;
    float voto;
    char data[LUNG], prof[LUNG], materia[LUNG], nome[LUNG];
    char memData[LUNG]; //variabile per controllare il valore delle date
    if(fp == NULL) {
        printf("c'e' stato un problema con il file");
    } else {
        fp2 = fopen("medie4BROB.txt", "w");
        if(fp2 == NULL) {
            printf("c'e' stato un problema con il secondo file");
        } else {
            while(fscanf(fp, "%s %s %s %s %f", data, prof, materia, nome, &voto) != EOF) {
                if(strcmp(data, memData) != 0) {
                    strcpy(memData, data);
                    nVoti ++;
                    k = 0;
                }
                if(nVoti==1) {
                    strcpy(stud[k].nomeStudente, nome);
                    stud[k].voto_media = voto;
                } else {
                    stud[k].voto_media = stud[k].voto_media + voto;
                }
                k ++;
            }
            for (int c = 0; c < k; c++) {
                stud[c].voto_media = stud[c].voto_media/nVoti;
                fprintf(fp2, "studente: %s   media: %.2f \n", stud[c].nomeStudente, stud[c].voto_media);
            }
            printf("il caricamento e' avvenuto con successo");
            fclose(fp2);
        }
        fclose(fp);
    }
}



int main () {
    char nomeFile[LUNG] = "dati_4BROB_informatica.txt";
    Studente s[NMAX];
    mediaCont(nomeFile, s);

    return 0;
}