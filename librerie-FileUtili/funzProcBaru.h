/*
Baruffolo Noemi 4^AROB A.S 2023-2024

                        Libreria di funzioni e procedure utili per lo svoglimento degli esercizi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

srand(time(NULL)) //per impostare il tempo diverso sempre, sennò stessa combinazione ogni volta e non va bene

rn = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN); //crea un numero random

fflush(stdin) //per pulire il buffer prima che venga inserito un carattere da tastiera

fopen(nomeFile, "r") // r: read, w: write, a: append

fclose(fp) //chiusura del file

strlen()// restituisce la lunghezza di una stringa.

strcpy()// copia una stringa in un'altra.

strcat()// concatena due stringhe.

strcmp()// confronta due stringhe e restituisce un valore intero che indica se le due stringhe sono uguali o quale delle due è più grande o più piccola dell'altra.

strchr()// cerca la prima occorrenza di un carattere all'interno di una stringa e restituisce un puntatore a quella posizione.

strstr()// cerca la prima occorrenza di una sottostringa all'interno di una stringa e restituisce un puntatore alla posizione di inizio della sottostringa.

/*Queste funzioni sono fondamentali per la manipolazione delle stringhe in C. Ad esempio, la funzione strlen() può essere utilizzata per verificare se una stringa è vuota
o meno, mentre la funzione strcpy() può essere utilizzata per copiare una stringa in un'altra variabile. La funzione strcmp() può essere utilizzata per ordinare le
stringhe o per confrontarle. La funzione strchr() e la funzione strstr() sono utilizzate per trovare una particolare parte di una stringa.
*/

//main
int main(){

    return 0;
}

//struttura con nome di tipologia
typedef struct{
    int numero;
    char nome[STRL];
    char carattere;
    bool risposta;
} Contenitore;

                                                                        //CONTROLLI


//controlla l'input con un minimo, un massimo e un messaggio da mettere divero ogni volta nella chiamata nel main
int chiediDim(int min, int max, char mess[]) {
    int n;

    do{
        printf(mess);
        scanf("%d", &n);
    } while(n < min || n > max);
    return n;
}

//controlla che non venga inserito un numero negativo
int nonNeg(int min){
	int n;
	printf("Inserisci un numero (n > 0): ");
	do{
		scanf("%d", &n);
		if(n <= min){
			printf("Inserisci un numero valido (n > 0): ");
		}
	} while(n < min);
	return n;
}

void esisteFile(char nomeFile[]){
    int numI;
    float numF;
    char c;
    char str[STRL];
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp == NULL){
        fp = fopen(nomeFile, "w");
        printf("Il file non esiste e l'ho appena creato");}
    else{
        /*printf("Ho trovato il file e lo apro in append");
        fp = fopen("prova.txt", "a");*/

        fscanf(fp,"%s %d %c %f", str, &numI, &c, &numF);
        printf("Il file contiene:\n%s %d %c %.2f", str, numI, c, numF);

        fclose(fp);
    }  
}

                                                                        //CARICA


//carica un vettore chiedendolo in input
void caricaVett(int v[], int dim) {

	for(int k = 0; k < dim; k++){
		printf("Inserisci l'elemento [%d]: ", k + 1);
		scanf("%d", &v[k]);
	}
}

//carica una matrice chiedendola in input
void caricaMat(int mat[][NC], int dim){
    for(int k = 0; k < dim; k++){
        for(int j = 0; j < dim; j++){
            printf("Inserisci un numero [%d][%d]", k, j);
            scanf("%d", &mat[k][j]);
        }
    }
}

//carica una matrice da file
void caricaMatDaFile(float mat[][NC], int nr, int nc, char nomeFile[]) {
    FILE *fp;

    fp = fopen(nomeFile, "r");

    if(fp != NULL){
        for(int k = 0; k < nr; k++) {
        //while(fscanf(fp, "%f", &mat[k][j]) != EOF && k < nr){
            for(int j = 0; j < nc; j++) {
                fscanf(fp, "%f", &mat[k][j]);
            }
        }
        fclose(fp);
    } else {
        printf("Il file della matrice non esiste o e' vuoto!\n");
    }
}


                                                                        //STAMPA


//stampa caratteri
void stampaC(int n, char c) {
    for(int k = 0; k < n; k++){
        printf("%c", c);
    }
}

//stampa quadrato di caratteri
void stampaQuad(int n, char c) {
    for(int k = 0; k < n; k++){
        stampaC(n, c);
        printf("\n");
    }   
}

//stampa rettangolo di caratteri
void stampaRett(int r, int c, char ca) {
    for(int k = 0; k < r; k++){
        stampaC(c, ca);
        printf("\n");
    }   
}

//stampa triangolo di caratteri
void stampaTr(int n, char c) {
    for(int k = 1; k < n + 1; k++){
        stampaC(k, c);
        printf("\n");
    }   
}

//stampa strisce tipo quelle dei passaggi pedonali con caratteri
void stampaStr(int n) {
    char nere = 'x';
    char bianche = 'O';
    int nStr = 2;

    for(int k = 0; k < n; k ++){
        if(k % 2 == 0){
            stampaRett(nStr, n, nere);
        } else {
            stampaRett(nStr, n, bianche);
        }
    }
}

//stampa di un vettore
void stampaVett(int vett[], int dim) {
    for (int k = 0; k < dim; k++) {
        printf("[%d]:%d ", k, vett[k]);
        printf("\n");
    }
    printf("\n");
}


//stampa una stringa
void stampaStr(char str[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("%c", str[k]);
    }
}

//stampa di una matrice
void stampaMat(int mat[][NC], int nr, int nc){
    
    for(int k = 0; k < nr; k++){
        for(int j = 0; j < nc; j++){
            printf("%d ", mat[k][j]);
        }
        printf("\n");
    }
}

                                                                //UTILITA'


//dice se può essere un triangolo o no
bool isTriangolo(float n1, float n2, float n3) {
	bool eTriangolo;
    
	//controllo che la lunghezza di ciascuna misura sia minore della somma delle altre due
    if ((n1 < n2 + n3) && (n2 < n1 + n3) && (n3 < n1 + n2)) { 
        eTriangolo = true;
    } else {
        eTriangolo = false;
    }
    return eTriangolo;
}

//dice se un triangolo e' isoscele o no e controlla che sia un triangolo
bool isIsoscele(float n1, float n2, float n3) {
    bool eIsoscele;

	if(isTriangolo(n1, n2, n3) == true) {
		if(n1 == n2 || n2 == n3 || n1 == n3) { //verifico se due lati sono uguali
        eIsoscele = true;
    } else{
        eIsoscele = false;
    }
	} else{
		printf("Le misure NON possono essere misure di un triangolo");
	}
    
    return eIsoscele;
}

//eleva alla potenza 
void pot2(float *x) {
    *x *= (*x);
}

//trova l'ipotenusa di un triangolo
float ipotenusa(float c1, float c2) {
    float i;

    pot2(&c1);
    pot2(&c2);

    i = sqrt(c1 + c2);

    return i;
}

//inverte le cifre di un numero
void inverti(int *x) {
	int tot = 0;
	int nuovoN;

	while(*x > 0){
		nuovoN = (*x) % 10;
		tot = tot * 10 + nuovoN;
		*x = (*x) /10;
	}

	*x = tot;
}

//fa in modo che in x finisca il minore dei 3 numeri, in z il maggiore e in y il numero rimanente. 
void crescenti(float *x, float *y, float *z) {
    float temp;

    //ricerca del valore massimo da assegnare
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }

    //ricerca del valore minimo da assegnare
    if (*y > *z) {
        temp = *y;
        *y = *z;
        *z = temp;
    }

    //ricerca del valore rimanente da assegnare
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

//calcola la tabellina di un numero
void creaTabellina(int tab[], int num, int dim) {
    for(int k = 0; k < dim; k++) {
        tab[k] = num * k;
    }
}

//stampa la tabellina
void stampaTabellina(int tab[], int num, int dim) {
    printf("La tabellina del numero %d e': ", num);
    for(int k = 0; k < dim; k++) {
        printf("%d ", tab[k]);
    }
}

//Calcola la somma degli elementi di posizione pari e quelli di posizione dispari di un vettore
void somma(int vett[], int *sommaP, int *sommaD, int dim) {
    for(int k = 0; k < dim; k++) {
        if(vett[k] % 2 == 0) {
            *sommaP += vett[k];
        } else {
            *sommaD += vett[k];
        }
    }
}

//calcola la somma della diagonale principale e secondaria di una matrice quadrata
void sommaDiagonali(int mat[][DIM], int dim, int *sommaDP, int *sommaDS){
    int j = dim - 1;
    *sommaDP = 0;
    *sommaDS = 0;

    for(int k = 0; k < dim; k++) {
        *sommaDP += mat[k][k];
        *sommaDS += mat[k][j];
        j --;
    }
}

//calcola la somma delle colonne di un matrice
void sommaColonneMat(float mat[][NC], float sommaC[], int nr, int nc) {

    for(int k = 0; k < nc; k++){ //colonne
        for(int j = 0; j < nr; j++){ //righe
            sommaC[k] += mat[j][k];
        }
        printf("\n");
    }        
}

//somma dagli elementi pari in posizione dispari e somma degli elementi dispari in posizione pari
void pariODispari(int vett[], int P[], int D[], int dim, int *np, int *nd) {
    *np = 0;
    *nd = 0;

    for(int k = 0; k < dim; k++) {
        if((vett[k] % 2 == 0) && (k % 2 != 0)) { //se il numero e' pari e se il numero pari e' in posizione dispari
                P[*np] = vett[k];
                *np += 1;
        } else { 
            if((vett[k] % 2 != 0) && (k % 2 == 0)) { //se il numero e' dispari e se il numero e' in posizione pari
                D[*nd] = vett[k];
                *nd += 1;
            }
        }
    }
}

//trova il minimo e il massimo
void minMax(float vett[], int dim) {
    float min = vett[0];
    float max = vett[0];

    for (int k = 0; k < dim; k++){
        if(vett[k] > max){
            max = vett[k];
        }
        if(vett[k] < min){
            min = vett[k];
        }
    }
}

//calcola il massimo
float calcolaMax(float vett[], int dim){
    float max = vett[0];

    for (int k = 0; k < dim; k++){
        if(vett[k] > max){
            max = vett[k];
        }
    }
    return max;
}

//calcola il minimo
float calcolaMin(float vett[], int dim){
    float min = vett[0];

    for (int k = 0; k < dim; k++){
        if(vett[k] < min){
            min = vett[k];
        }
    }
    return min;
}

//calcola la media
float calcolaMedia(float vett[], int dim) {

}


//genera una stringa con caratteri casuali
void randomStr(char str[], int dim) {
    for(int k = 0; k < dim; k++) {
        str[k] = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN);
    }
}

//controlla se il carattere e' una vocale o no
bool isVocale(char c){
    bool tro = false;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        tro = true;
    }
    return tro;
}

//cancella le vocali presenti in una stringa 
void cancellaV(char s[]) {
    int k, j = 0;
    for (k = 0; s[k] != '\0'; k++) {
        if (!isVocale(s[k])) {
            s[j] = s[k];
            j++;
        }
    }
    s[j] = '\0';
}

//controlla se un carattere e' minuscolo o no
bool isMinuscolo(char c){
    bool tro = false;

    if(c >= 'a' && c <= 'z'){
        tro = true;
    }
    return tro;
}

//trasforma il carattere minuscolo in maiuscolo
void upper(char str[]) {
	for(int k = 0; str[k] != '\0'; k++) {
		if(isMinuscolo(str[k])){
            str[k] -= 32; //con numeri codice ASCII
        }
	}
}

//dice se il numero di vocali in una stringa e' dispari
bool vocaliDispari(char str[]) {
    int nv = 0;
    bool dispari = false;
    int k, j = 0;
    for (k = 0; str[k] != '\0'; k++) {
        if (isVocale(str[k])) {
            nv += 1;
            j++;
        }
    }

    if(nv % 2 != 0) {
        dispari = true;
        }
    str[j] = '\0';

    return dispari;
}

//legge, scrive, cancella e rinomina un file
void fileRWDR(){
    FILE *fp, *ft; //puntatori al file da modificare e temporaneo
    char ch;
    if ((fp = fopen("dati.txt","r"))!= NULL) {
        if ((ft = fopen("temp.txt","w"))!= NULL) {
            while(fscanf(fp,"%c",&ch)!= EOF){
                //operazioni di modifica
                fprintf(ft,"%c",ch);
            }
            fclose(ft); // chiusura del file temporaneo
            fclose(fp); // chiusura del file da modificare
            remove("dati.txt"); //cancella vecchio file
            rename("temp.txt","dati.txt"); //rinomina
        }
        else {
            printf("Errore apertura file temporaneo");
            fclose(fp); //chiusura del file da modificare
        }
    }   
    else{
        printf("Errore apertura file da modificare"); 
    }
}

//legge un file e lo sovrascrive senza vocali
void fileNoVocali(){
    FILE *fp,*ft; //puntatori al file da modificare e temporaneo
    char ch;
    if ((fp = fopen("noVocali.txt","r"))!= NULL) {
        if ((ft = fopen("temp.txt","w"))!= NULL) {
            while(fscanf(fp,"%c",&ch)!= EOF){
                //operazioni di modifica
                if(ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
                    fprintf(ft,"%c",ch);
                }
            }
            printf("Il file ora non contiene vocali");

            fclose(ft); // chiusura del file temporaneo
            fclose(fp); // chiusura del file da modificare

            remove("noVocali.txt"); //cancella vecchio file
            rename("temp.txt","noVocali.txt"); //rinomina
        }
        else {
            printf("Errore apertura file temporaneo");
            fclose(fp); //chiusura del file da modificare
        }
    }   
    else{
        printf("Errore apertura file da modificare"); 
    }
}

//verifica se un vettore e' speculare o meno
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

                                                                    //ALGORITMI FONDAMENTALI:


void scambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//1)
//NON ordinati DISGIUNTI
int NonOrdDisg(int v[],int n, int x){
    int tro, k;
    tro = -1;
    k = 0;
    while ((k < n) && (tro == - 1)){
        if(x == v[k])
            tro = k;
        else
    k++;
    }
return tro;
}
/*
COMPLESSITÀ per tutti i tipi di ricerca
CONFRONTI
Peggiore n
Migliore 1
Medio n/2
*/

//versione con variabile booleana che restituisce solo la presenza o l’assenza dell’elemento cercato
bool NonOrdDisg (int v[], int n, int x) {
    int k = 0;
    bool tro = false;
    while (k < n && !tro){ //tro == false
        if (x == v[k])
            tro = true;
        else
            k++;
    }
return tro; //restituisce true se l’ha trovato, false altrimenti
}
// test con v[2 4 6 7]

//2)
//ORDINATI DISGIUNTI
//vettore ordinato a elementi disgiunti con una variabile in più per codice più comprensibile
int OrdDisg1(int v[],int n, int x) {
    int tro, k;
    bool continua;
    tro = -1;
    k = 0 ;
    continua = true;
    while((k < n) && (tro == - 1) && (continua == true)){
        if(x == v[ k ])
    tro = k;
    else{
        if(v[ k ] > x ) 
            continua = false ; //forza l’uscita dal ciclo
        else
            k++ ;}
    }
return tro ;
}

//vettore ordinato a elementi disgiunti
int OrdDisg2(int v[],int n, int x) {
    int tro, k;
    tro = -1;
    k = 0 ;
    while((k < n) && (tro == -1)){
        if(x == v[ k ])
            tro = k;
        else{
            if(v[k] > x ) 
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
            printf("\nL'elemento trovato in posizione %d", k);
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
//vettore ordinato a elementi non disgiunti con una variabile in più per codice più comprensibile
int OrdNonDisg1(int v[], int n, int x) {
    int nx, k; //n^ occorrenze, contatore
    bool continua;
    nx = 0;
    k = 0;
    continua = true;
    while(k < n && continua) {
        if(x == v[k]) {
        printf("\nL'elemento trovato in posizione %d", k);
        nx++;
        k++;
        }else
        if(v[k] > x) 
            continua = false; //fa uscire dal ciclo
        else
            k++;
    }
return nx; //numero di occorrenze
}

//vettore ordinato a elementi non disgiunti
int OrdNonDisg2(int v[], int n, int x) {
    int nx, k;
    nx = 0;
    k = 0;
    while(k<n) {
        if(x == v[k]) {
            printf("\nL'elemento trovato in posizione %d", k);
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

/////////// ALGORITMI DI ORDINAMENTO ///////////////

//5)
//RICRCA BINARIA ODICOTOMICA
//NON RICORSIVA
int ricercaBinariaNonRicorsiva(int v[], int n, int x) {
    int p,u,m,tro; // indice del… p= primo, u=ultimo, m=medio
    p = 0;
    u = n - 1;
    tro = - 1;
    while((p <= u)&& tro == - 1) {
        m = (p + u)/2;
        if(v[m] == x)
            tro = m; // valore x trovato alla posizione m
        else if(v[m] < x)
            p = m + 1;
        else // x < v[m]
            u = m - 1;
    }
return tro;
}

//6)
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
        if(kmin != k){
            scambio(&v[k], &v[kmin]); //scambi
        }
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

//7)
//BUBBLE SORT 1,2,3

//1)
void bubbleSort1(int vett[], int n){
    int k, sup;

    for (sup = n - 1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (vett[k] > vett[k + 1])
                scambio( &vett[k], &vett[k + 1]);
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

//2)
void bubbleSort2(int vett[], int n) {
//se non si fanno scambi in un giro il vettore è ordinato
    int k,sup;
    bool sca; 
    sup = n - 1;
    sca = true;
    while ((sup > 0) && sca == true) {
        sca = false;
        for (k = 0; k < sup; k++) {
            if (vett[k] > vett[k + 1]){
                scambio(&vett[k], &vett[k + 1]);
                sca = true;
            }
        }
    sup--;
    }
}

//3)
void bubbleSort3(int vett[], int n) {
    int k, sup, sca; 
    sup = n - 1;
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