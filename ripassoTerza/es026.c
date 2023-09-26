#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 26
#define M 100
#define N 7

/*
Author: Noemi Baruffolo
date: 25/09/2023
es. 26
text: Dire se una matrice è speculare rispetto all'asse verticale
*/

//File: matEs26.txt

int caricaMatDaFile(int matrice[][N], char nomeFile[], int nRighe, int nColonne) {
    int r = 0, c;

    FILE *fp;
    fp = fopen(nomeFile, "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
    } else {
        r = 0;
        while (r < nRighe && fscanf(fp, "%d", &matrice[r][0]) != EOF) {
            for (int c = 1; c < nColonne; c++)
                fscanf(fp, "%d", &matrice[r][c]);
            r++;
        }
        fclose(fp);
    }
    return r;
}

bool isSpeculare(int mat[][N], int nr, int nc) {
	int r = 0, c = 0;
	bool spec = true;

	while(r < nr / 2 && spec == true ){
        c = 0;
        while(c < nc / 2 && spec == true){
		    if(mat[r][c] != mat[r][nc - 1 - c]) {
		    	spec = false;
		    }
		    c++;
        }
        r++;
	}
	return spec;
}

void stampaMatrice(int matrice[][N], int nr, int nc) {
    for (int x = 0; x < nr; x++) {
        for (int y = 0; y < nc; y++) {
            printf("%3d  ", matrice[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int MAT[M][N];
    char nomeFile[STRL];
    int nr = 0;
    int numSpec = 0;

    printf("Inserisci il nome del file: ");
    scanf("%s", nomeFile);

    nr = caricaMatDaFile(MAT, nomeFile, M, N);
    
    if(isSpeculare(MAT, nr, N) == true){
        printf("La matrice e' speculare!\n");
    } else{
        printf("La matrice NON e' speculare!\n");
    }

    stampaMatrice(MAT, nr, N);

    return 0;
}