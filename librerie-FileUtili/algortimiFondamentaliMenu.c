#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

/*
Author: Noemi Baruffolo
date: 24/07/2023
es. 3
text:
Caricare un vettore, quindi ordinarlo con gli algoritmi di ordinamento
studiati (chiedere all’utente quale vuole utilizzare) e quindi chiedere quale
elemento si vuole cercare e utilizzare l’algoritmo di ricerca opportuno.
*/

void menuO() {
    printf("Inserisci il numero corrispondente alla scelta desiderata:\n0: esci\n1: selection sort\n2: bubble sort1\n3: bubble sort 2\n4: bubble sort 3\n");
}

void menuR() {
    printf("Inserisci il numero corrispondente alla scelta desiderata:\n0: esci\n1: non ordinati disgiunti\n2: ordinati disgiunti\n3: non ordinati non disgiunti\n4: ordinati non disgiunti\n5: ricerca binaria non ricorsiva\n");
}

int chiediDim(int min, int max, char mess[]) {
    int n;

    do{
        printf(mess);
        scanf("%d", &n);
    } while(n < min || n > max);
    return n;
}

void caricaVett(int v[], int dim) {

	for(int k = 0; k < dim; k++){
		printf("Inserisci l'elemento [%d]: ", k + 1);
		scanf("%d", &v[k]);
	}
}

/////////// ALGORITMI DI ORDINAMENTO ///////////////

void scambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//1)
//SELECTION SORT
////Si cerca il minimo ad ogni ciclo e si fa al massimo un solo scambio a ciclo.
//Quando sistemo il penultimo elemento automaticamente è sistemato l’ultimo
void selectionSort(int v[],int n) {
    int k, kmin, j;
    for(k = 0;k < n - 1; k++) {
    kmin = k;
    for(j = k + 1; j < n; j++){
        if(v[kmin] > v[j]) // confronti
            kmin = j;
        }
        if(kmin != k)
            scambio(&v[k], &v[kmin]); //scambi
    }
return;
}
/*
COMPLESSITÀ
CONFRONTI
(n-1)+(n-2)+…+2+1=n(n-1)/2=O(n2
)
SCAMBI
Peggiore n-1=O(n)
Migliore 0
*/

//3)
//BUBBLE SORT 1,2,3

//2)
void bubbleSort1(int vett[], int n){
    int k, sup;
    for (sup = n - 1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (vett[k] > vett[k+1])
                scambio( &vett[k], &vett[k+1]);
            }
        }
    }
/*in alternativa i cicli for possono essere scritti così 
for (sup = n; sup > 1; sup--){
 for (k = 0; k < sup-1; k++){
    */

/*
COMPLESSITÀ
CONFRONTI:
n(n-1)/2=O(n2)
SCAMBI:
Peggiore n(n-1)/2=O(n2)
Migliore 0
*/

//3)
void bubbleSort2(int vett[], int n) {
//se non si fanno scambi in un giro il vettore è ordinato
    int k, sup;
    bool sca; 
    sup = n - 1;
    sca = true;
    while ((sup>0) && sca == true) {
        sca = false;
        for (k = 0; k < sup; k++) {
            if (vett[k] > vett[k + 1]){
                scambio( &vett[k], &vett[k + 1]);
                sca = true;
            }
        }
    sup--;
    }
}

//4)
void bubbleSort3(int vett[], int dim) {
    int k, sup, sca; 
    sup = dim - 1 ;
    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k + 1]){
                scambio(&vett[k], &vett[k + 1]);
                sca = k ;
            }
        }
        sup = sca ;
    }
}

/*
COMPLESSITÀ per tutti i tipi di bubble sort RAFFINATI
CONFRONTI:
Peggiore n(n-1)/2=O(n2)
Migliore n-1=O(n)
SCAMBI:
Peggiore n(n-1)/2=O(n2)
Migliore 0
*/

///////////////// ALGORITMI DI RICERCA /////////////////////////

//1)
//NON ordinati DISGIUNTI
int NonOrdDisg(int v[],int n, int x){
    int tro, k;
    tro = - 1;
    k = 0;
    while ((k < n) && (tro == -1)){
        if(x == v[k])
            tro = k;
        else {
            k++;
        }
    }
    return tro;
}
/*
COMPLESSITÀ per tutti i tipi di ricerca
CONFRONTI
Peggiore n
Migliore 1
Medio n/2

test con v[2 4 6 7]
*/

//2)
//ORDINATI DISGIUNTI
//vettore ordinato a elementi disgiunti
int OrdDisg2(int v[],int n, int x) {
    int tro, k;
    tro = - 1;
    k = 0 ;
    while((k < n) && (tro == - 1)){
        if(x == v[ k ])
            tro = k;
        else{
            if(v[ k ] > x ) 
                k = n ; //forza l’uscita dal ciclo
            else
                k++ ;}
    }
    return tro ;
}
/*
CONFRONTI
Peggiore n
Migliore 1

da testare v[0 5 7 3 5]
*/

//3)
//NON ordinati NON disgiunti
//vettore non ordinato a elementi non disgiunti restituisce le occorrenze
int NonOrdNonDisg(int v[],int n, int x) {
    int nx, k;
    nx = 0;
    for (k = 0; k < n; k++){
        if(x == v[k]){
            nx++;
        }
    }
    return nx; //numero di occorrenze
}
/*
CONFRONTI n (c’è il for)
per testare v[2 3 3 3 4 5 5]
*/

//4)
//ORDINATI NON disgiunti
//vettore ordinato a elementi non disgiunti
int OrdNonDisg2(int v[], int n, int x) {
    int nx, k;
    nx = 0;
    k = 0;
    while(k < n) {
        if(x == v[k]) {
            nx++;
            k++;
        }else
        if(v[k] > x) 
            k = n; //fa uscire dal ciclo
        else
            k++;
    }
    return nx; //numero di occorrenze
}
/*
CONFRONTI
Peggiore n
Migliore 1(non c’è e il primo è maggiore
*/

//5)
//RICRCA BINARIA ODICOTOMICA
//NON RICORSIVA
int ricercaBinariaNonRicorsiva(int v[], int n, int x) {
    int p, u, m, tro; // indice del… p= primo, u=ultimo, m=medio
    p = 0;
    u = n - 1;
    tro =- 1;
    while((p <= u) && tro == -1) {
        m = (p+u)/2;
        if(v[m] == x)
            tro = m; // valore x trovato alla posizione m
        else if(v[m] < x)
            p = m + 1;
        else // x < v[m]
            u = m - 1;
    }
    return tro;
}


int main() {
    int v[DIM];
    int dim, sceltaR, sceltaO;
    int x = 0;

    dim = chiediDim(1, DIM, "Inserisci la dimensione massima del vettore");

    if (dim != 0){
        caricaVett(v, dim);

        menuO();
        scanf("%d", &sceltaO);
        switch (sceltaO){
            case 0:
                break; //esce

            case 1:
                selectionSort(v, dim);               
                break;

            case 2:
                bubbleSort1(v, dim);
                break;

            case 3:
                bubbleSort2(v, dim);
                break;
            
            case 4:
                bubbleSort3(v, dim);
                break;

            default:
                printf("Inserisci un numero valido:\n");
                break;
            }
        if(sceltaO != 0){
            menuR();
            scanf("%d", &sceltaR);

            switch (sceltaR){
                case 0:
                    break; //esce

                case 1:
                    printf("Inserisci il numero da cercare: \n");
                    scanf("%d", &x);
                    printf("\nL'elemento trovato %d volte", NonOrdDisg(v, dim, x));
                    break;

                case 2:
                    printf("Inserisci il numero da cercare: \n");
                    scanf("%d", &x);
                    printf("\nL'elemento trovato in posizione %d", OrdDisg2(v, dim, x));
                    break;

                case 3:
                    printf("Inserisci il numero da cercare: \n");
                    scanf("%d", &x);
                    printf("\nL'elemento trovato %d volte", NonOrdNonDisg(v, dim, x));
                    break;

                case 4:
                    printf("Inserisci il numero da cercare: \n");
                    scanf("%d", &x);
                    printf("\nL'elemento trovato %d volte", OrdNonDisg2(v, dim, x));
                    break;

                case 5:
                    printf("Inserisci il numero da cercare: \n");
                    scanf("%d", &x);
                    printf("\nL'elemento trovato in posizione %d", ricercaBinariaNonRicorsiva(v, dim, x));
                    break;

                default:
                    printf("Inserisci un numero valido:\n");
                    break;
                }
        }

    } else {
        printf("Il vettore non ha dimensione ");
    }

    return 0;
}