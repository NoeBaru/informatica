/*
Baruffolo Noemi 4^AROB A.S 2023-2024

                    Libreria di funzioni e procedure in linguaggio C utili per lo svoglimento degli esercizi e velocizzare la scrittura del codice nelle verifiche
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define DIM 1004
#define NR 2
#define NC 2
#define STRL 26

#define LIM_MIN 0
#define LIM_MAX 100

#define NOME_FILE "prova.txt"


srand(time(NULL)); //per impostare il tempo diverso sempre, sennò stessa combinazione ogni volta e non va bene

rn = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN); //crea un numero random

fflush(stdin); //per pulire il buffer prima che venga inserito un carattere da tastiera

fopen(nomeFile, "r"); // r: read, w: write, a: append

fclose(fp); //chiusura del file

strlen();// restituisce la lunghezza di una stringa.

strcpy();// copia una stringa in un'altra.

strcat();// concatena due stringhe.

strcmp();// confronta due stringhe e restituisce un valore intero che indica se le due stringhe sono uguali o quale delle due è più grande o più piccola dell'altra.

strchr();// cerca la prima occorrenza di un carattere all'interno di una stringa e restituisce un puntatore a quella posizione.

strstr();// cerca la prima occorrenza di una sottostringa all'interno di una stringa e restituisce un puntatore alla posizione di inizio della sottostringa.

/*Queste funzioni sono fondamentali per la manipolazione delle stringhe in C.
Ad esempio, la funzione strlen() può essere utilizzata per verificare se una stringa è vuota o meno,
mentre la funzione strcpy() può essere utilizzata per copiare una stringa in un'altra variabile.
La funzione strcmp() può essere utilizzata per ordinare le stringhe o per confrontarle.
La funzione strchr() e la funzione strstr() sono utilizzate per trovare una particolare parte di una stringa.
*/

/*                                               DEFINIZIONI MATEMATICHE E CULTURA GENERALE
NUMERI PRIMI: numeri interi positivi che possono essere divisi soltanto per sé stessi e per 1
IVA: Moltiplica il prezzo netto per 0,22 e ottieni l'importo dell'IVA. Un'altra opzione è dividere il prezzo netto per 100 e poi moltiplicarlo per 22. L'importo dell'IVA è di 136,40 euro.
FATTORIALE DI UN NUMERO: moltiplicare tutti i numeri naturali che lo precedono (escluso lo zero), con esso incluso. Es: il 4! darà come risultato 4 x 3 x 2 x 1 = 24
STAGIONI:
- primavera: 20/04
- estate 21/06
- autunno 22/09
- inverno 21/12
GIORNI MESI: "TRENTA GIORNI HA NOVEMBRE CON APRIL, GIUGNO E SETTEMBRE. DI VENTOTTO CE N'È UNO, TUTTI GLI ALTRI NE HAN TRENTUNO."
*30gg:
 - novembre
 - aprile
 - giugno
 - settembre
*28gg:
 - febbraio
*31gg:
 tutti gli altri
AREA POLIGONI:
- rettangolo/parallelogramma: A=b⋅h  inversa b = A/h     h = A/b
- quadrato: A = l^2      A = d^2/2   inverse: l = sqrt(A)    d = sqrt(2A)
- rombi/quadrilateri con le diagonali perpendicolari: A = D*d/2 inverse: D = 2A/d   d = 2A/D
- triangolo: A = b*h/2  inverse: b = 2A/h   h = 2A/b
- trapezio: A = (B + b)*h/2 inverse: B = 2A/h-b     b = 2A/h-B
- poligoni regolari: A = perimetro*apotema/2 = p*a/2 (un apotema = raggio della circonferenza inscritta del poligono)
- cerchio: A = pi*r^2
PERIMETRO POLIGONI:
rettangolo/parallelogramma: P = (b + h)*2 oppure P = (b + l)*2
- quadrato: P = l*4
- rombi/quadrilateri con le diagonali perpendicolari: P = (L +l)*2
- triangolo: P = a + b +c
- trapezio: P = B + b +l1 +l2
- poligoni regolari: P = l*6
- cerchio: P = 2pi * r
DIAGONALE PRINCIPALE E SECONDARIA:
- Sommap=Sommap+mat [ i ][ i ]
- Sommad=Sommad+mat [ i ][ N – i -1 ]
NUEMERO DI FIBONACCI: I termini della successione sono detti numeri di Fibonacci e i primi 25 di essi sono: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,144, 233, 377, 610, 987,1597, 2584, 4181, 6765,10946, 17711, 28657, 46368, 75025.
FATTORI PRIMI: sono i numeri primi che lo dividono esattamente, cioè senza resto 
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

                                                                    //FUNZ_PROC STRING.H

int length = strlen(string1); // Calcola la lunghezza della stringa string1
strcpy(destination, string1);  // Copia la stringa string1 in destination
strcat(destination, string2);  // Concatena string2 alla fine di destination
int compare = strcmp(string1, string2); // Confronta due stringhe (restituisce 0 se sono uguali)
char *ptr = strchr(string1, 'o'); // Cerca il primo carattere 'o' nella stringa string1
char *substring = strstr(string1, "ell"); // Cerca la sottostringa "ell" in string1

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
//converte i gradi fahrenheit in celsius
float fahrenheit = (celsius * 9 / 5) + 32;

// Funzione per calcolare la lunghezza di una stringa
int lunghezzaStringa(const char* stringa) {
    int lunghezza = 0;
    while (stringa[lunghezza] != '\0') {
        lunghezza++;
    }
    return lunghezza;
}

// Funzione per copiare una stringa in un'altra
void copiaStringa(char* destinazione, const char* sorgente) {
    int i = 0;
    while (sorgente[i] != '\0') {
        destinazione[i] = sorgente[i];
        i++;
    }
    destinazione[i] = '\0';
}

//calcola il numero di Fibonacci
int calcolaFibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

//calcola massimo comun divisore
int calcolaMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//calcola il minimo comune multiplo
int calcolaLCM(int a, int b) {
    return (a * b) / calcolaMCD(a, b);
}

//verifica se un anno e' bisestile
bool isBisestile(int anno) {
    bool bisestile = false;
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        bisestile = true; // È bisestile
    }
    return bisestile; // Non è bisestile
}

//verifica se un numero e' primo o no
bool isPrimo(int numero) {
    bool primo = true;
    if (numero <= 1){
        primo = false; // I numeri minori o uguali a 1 non sono primi
    } 
    for (int cont = 2; cont * cont <= numero; cont++) {
        if (numero % cont == 0) {
            primo = false; // È divisibile, quindi non è primo
        }
    }
    return primo; // È primo
}

//verifica se la stringa data è un palindromo o no
bool isPalindromo(const char *stringa) {
    bool palindromo = true;
    int lung = strlen(stringa);
    for (int cont = 0; cont < lung / 2; cont++) {
        if (stringa[cont] != stringa[lung - 1 - cont]) {
            palindromo = false; // Non è un palindromo
        }
    }
    return palindromo; // È un palindromo
}

int main() {
    char stringa[100];

    printf("Inserisci una parola: ");
    scanf("%s", stringa);

    if (isPalindromo(stringa)) {
        printf("%s è un palindromo!\n", stringa);
    } else {
        printf("%s non è un palindromo!\n", stringa);
    }
    return 0;
}


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
    float somma = 0.0;
    float media;
    for(int cont = 0; cont < dim; cont++){
        somma += vett[cont];
        cont++;
    }
    media = somma / (float)dim;
    printf("La media di tutti i voti(%d) della classe e': %.2f", dim, media);
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

//calcola l'Interesse composto
int main() {
    float capitaleIniziale, tassoInteresse, importoFinale;
    int anni;

    printf("Inserisci il capitale iniziale: ");
    scanf("%f", &capitaleIniziale);
    printf("Inserisci il tasso di interesse annuale (in percentuale): ");
    scanf("%f", &tassoInteresse);
    printf("Inserisci il numero di anni: ");
    scanf("%d", &anni);

    tassoInteresse = tassoInteresse / 100; // Converte il tasso in decimale

    importoFinale = capitaleIniziale * pow(1 + tassoInteresse, anni);

    printf("L'importo finale dopo %d anni è %.2f\n", anni, importoFinale);

    return 0;
}

//cerca una parola in una frase
int cercaParola(const char *parola, const char *array[], int dim) {
    for (int cont = 0; cont < dim; cont++) {
        if (strcmp(parola, array[cont]) == 0) {
            return cont; // Parola trovata
        }
    }
    return -1; // Parola non trovata
}

//conta il numero di parole in una frase
int contaParole(const char *frase) {
    int parole = 0;
    bool inParola = false;

    for (int cont = 0; frase[cont] != '\0'; cont++) {
        if (frase[cont] == ' ' || frase[cont] == '\n' || frase[cont] == '\t') {
            inParola = false;
        } else if (!inParola) {
            inParola = true;
            parole++;
        }
    }

    return parole;
}

//scomposizione in fattori primi
void scomposizioneFattoriPrimi(int numero) {
    for (int cont = 2; cont <= numero; cont++) {
        while (numero % cont == 0) {
            printf("%d ", cont);
            numero /= cont;
        }
    }
}

//calcolo valore assoluto
int valoreAssoluto(int numero) {
    return (numero < 0) ? -numero : numero;
}

//calcola il numero di divisori
int contaDivisori(int numero) {
    int divisori = 0;

    for (int cont = 1; cont <= numero; cont++) {
        if (numero % cont == 0) {
            divisori++;
        }
    }

    return divisori;
}

//calcola la media ponderata
int main() {
    int numMaterie;
    float voti[10], pesi[10], sommaPonderata = 0, sommaPesi = 0;

    printf("Inserisci il numero di materie: ");
    scanf("%d", &numMaterie);

    for (int i = 0; i < numMaterie; i++) {
        printf("Inserisci il voto per la materia %d: ", i + 1);
        scanf("%f", &voti[i]);
        printf("Inserisci il peso per la materia %d: ", i + 1);
        scanf("%f", &pesi[i]);

        sommaPonderata += voti[i] * pesi[i];
        sommaPesi += pesi[i];
    }

    float mediaPonderata = sommaPonderata / sommaPesi;
    printf("La media ponderata è %.2f\n", mediaPonderata);

    return 0;
}

//verifica la corretteza delle parentesi di un esercizio
bool verificaParentesi(const char *sequenza) {
    int aperte = 0;

    for (int i = 0; sequenza[i] != '\0'; i++) {
        if (sequenza[i] == '(') {
            aperte++;
        } else if (sequenza[i] == ')') {
            aperte--;
        }

        if (aperte < 0) {
            return false; // Trovata una parentesi chiusa prima di una aperta
        }
    }

    return aperte == 0; // Deve esserci lo stesso numero di parentesi aperte e chiuse
}

int main() {
    char sequenza[1000];

    printf("Inserisci una sequenza di parentesi: ");
    gets(sequenza);

    if (verificaParentesi(sequenza)) {
        printf("Le parentesi sono bilanciate.\n");
    } else {
        printf("Le parentesi non sono bilanciate.\n");
    }

    return 0;
}

//conta i giorni di un mese inserito in input
#include <stdio.h>

int main() {
    int mese, anno;

    printf("Inserisci un mese (1-12): ");
    scanf("%d", &mese);
    printf("Inserisci un anno: ");
    scanf("%d", &anno);

    int giorniInMese;

    if (mese < 1 || mese > 12) {
        printf("Mese non valido.\n");
    } else if (mese == 2) {
        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
            giorniInMese = 29;
        } else {
            giorniInMese = 28;
        }
    } else if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
        giorniInMese = 30;
    } else {
        giorniInMese = 31;
    }

    if (giorniInMese > 0) {
        printf("Il mese %d dell'anno %d ha %d giorni.\n", mese, anno, giorniInMese);
    }

    return 0;
}

//calcolo intersezioni tra due insiemi
void calcolaIntersezione(int insieme1[], int dimensione1, int insieme2[], int dimensione2) {
    printf("Insieme intersezione: { ");
    for (int cont = 0; cont < dimensione1; cont++) {
        for (int k = 0; k < dimensione2; k++) {
            if (insieme1[cont] == insieme2[k]) {
                printf("%d ", insieme1[cont]);
                break;
            }
        }
    }
    printf("}\n");
}

//Verifica se la matrice è un quadrato magico (la somma di ogni riga, colonna e diagonale è uguale)
int main() {
    int n;

    printf("Inserisci la dimensione del quadrato magico (n x n): ");
    scanf("%d", &n);

    int quadratoMagico[15][15];

    printf("Inserisci gli elementi del quadrato magico:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &quadratoMagico[i][j]);
        }
    }

    int sommaRiga, sommaColonna, sommaDiagonalePrincipale = 0, sommaDiagonaleSecondaria = 0;

    // Calcola la somma della diagonale principale e della diagonale secondaria
    for (int i = 0; i < n; i++) {
        sommaDiagonalePrincipale += quadratoMagico[i][i];
        sommaDiagonaleSecondaria += quadratoMagico[i][n - 1 - i];
    }

    // Verifica se la somma delle diagonali è uguale
    if (sommaDiagonalePrincipale != sommaDiagonaleSecondaria) {
        printf("Non è un quadrato magico.\n");
        return 0;
    }

    // Verifica se la somma di ogni riga e colonna è uguale alla somma delle diagonali
    for (int i = 0; i < n; i++) {
        sommaRiga = 0;
        sommaColonna = 0;
        for (int j = 0; j < n; j++) {
            sommaRiga += quadratoMagico[i][j];
            sommaColonna += quadratoMagico[j][i];
        }
        if (sommaRiga != sommaDiagonalePrincipale || sommaColonna != sommaDiagonalePrincipale) {
            printf("Non è un quadrato magico.\n");
            return 0;
        }
    }

    printf("È un quadrato magico.\n");

    return 0;
}

//calcola sconti
float calcolaScontoNegativo(float prezzo, float percentuale) {
    return prezzo - (prezzo * (percentuale / 100));
}

float calcolaScontoPositivo(float prezzo, float percentuale) {
    return prezzo + (prezzo * (percentuale / 100));
}

//sconti e IVA
int main() {
    float prezzo_base, tot, sconto_negativo, sconto_positivo, iva;

    // Input del prezzo di base e la percentuale totale
    printf("Inserisci il prezzo di base: ");
    scanf("%f", &prezzo_base);
    printf("Inserisci la percentuale totale: ");
    scanf("%f", &tot);

    // Calcolo dello sconto negativo e positivo
    sconto_negativo = prezzo_base * (tot / 100);
    sconto_positivo = prezzo_base * (tot / 100);
    
    // Calcolo dell'IVA
    iva = prezzo_base * 0.22;  // Esempio: IVA al 22%

    // Calcolo del prezzo finale
    float prezzo_scontato = prezzo_base - sconto_negativo + sconto_positivo + iva;

    // Output dei risultati
    printf("Sconto negativo: %.2f\n", sconto_negativo);
    printf("Sconto positivo: %.2f\n", sconto_positivo);
    printf("IVA: %.2f\n", iva);
    printf("Prezzo finale: %.2f\n", prezzo_scontato);

    return 0;
}


                                                                    //ALGORITMI FONDAMENTALI:


void scambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//1)
//NON ordinati DISGIUNTI
int nonOrdDisg(int v[],int n, int x){
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
bool nonOrdDisg (int v[], int n, int x) {
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
int ordDisg1(int v[],int n, int x) {
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
int ordDisg2(int v[],int n, int x) {
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
int nonOrdNonDisg(int vett[],int dim, int x) {
    int pos = 0;
    for (int k = 0; k < dim; k++){
        if(x == vett[k]){
            printf("\nL'elemento trovato in posizione %d", k);
            pos++;
        }
    }
return pos; //numero di occorrenze
}
/*
CONFRONTI n (c’è il for)
per testare v[2 3 3 3 4 5 5]
*/

//4)
//ORDINATI NON disgiunti
//vettore ordinato a elementi non disgiunti con una variabile in più per codice più comprensibile
int ordNonDisg1(int v[], int n, int x) {
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
int ordNonDisg2(int v[], int n, int x) {
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