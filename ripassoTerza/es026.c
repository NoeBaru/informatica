#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 26
#define M 100
#define N 4

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

bool isSpeculare(int v[], int dim) {
	int k = 0;
	bool spec = true;

	while(k < dim/2 && spec == true ){
		if(v[k] != v[dim - 1 - k]) {
			spec = false;
		}
		k++;
	}
	return spec;
}

bool matSpec(int mat[][N], int numR) {
    int k = 0;
    bool spec = false;

    while(k < numR && (IsSpeculare(mat[k], numR) == true)){
        spec = true;
        k++;
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
    
    if(matSpec(MAT, nr) == true){
        printf("La matrice e' speculare!");
    } else{
        printf("La matrice NON e' speculare!");
    }

    stampaMatrice(MAT, nr, N);

    return 0;
}