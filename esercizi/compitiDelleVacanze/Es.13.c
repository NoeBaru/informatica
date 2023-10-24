#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100
#define STRL 26

#define NOME_FILE "rubrica.txt"

/*
Author: Noemi Baruffolo
date: /08/2023
es. 13
text:
Utilizzando le tabelle creare una RUBRICA con la seguente struttura
"Contatto":
• Cognome
• Nome
• Sesso (M o F)
• Indirizzo
• Telefono
• Età
 Applicare il seguente menù:
 0 - esci
 1 - Inserisci nuovo elemento con caricamento ordinato per cognome (ricerca
posizione)
 2 - Cerca elemento X per nome
 3 - Visualizza tutto
 4 - Statistiche: età media dei maschi e delle femmine
 5 - Modifica dati elemento X
 6 - Incrementa l'età d’ogni elemento di 1 (nuovo anno)
*/

typedef struct{
    char cognome[STRL];
    char nome[STRL];
    char sesso;
    char indirizzo[STRL];
    int tel;
    int eta;
} Contatto;

void scriviCont(Contatto tab[], int dim, char nomeF[]) {
    FILE *fp;

    fp = fopen(nomeF,"w");

    if(fp != NULL) { //se esiste
        for(int k = 0; k < dim; k++) {
            fprintf(fp, "%s %s %c %s %d %d\n", tab[k].cognome, tab[k].nome, tab[k].sesso, tab[k].indirizzo, tab[k].tel, tab[k].eta);
        }
        fclose(fp); //chiude il file
    }
}

int caricaCont(Contatto tab[], int dim, char nomeF[]) {
    int c;
    int cont = 0;

    FILE *fp;
    fp = fopen(nomeF,"r");

    if(fp != NULL) { //se esiste
        while (fscanf(fp, "%s", tab[cont].cognome) != EOF && cont < dim) {
            fscanf(fp, "%s %c %s %d %d", tab[cont].nome, &tab[cont].sesso, tab[cont].indirizzo, &tab[cont].tel, &tab[cont].eta);
            cont ++;
        }
        fclose(fp); //chiude il file
    }
    return cont; 
}

void convertiMaiusc(char *c) {
 
    if(*c >= 'a' && *c <= 'z') {
        *c -= ('a' - 'A'); //32 in tabella ascii
    }
}

Contatto inputCont(){
    Contatto c;
    printf("Inserisci il cognome: ");
    scanf("%s", c.cognome);
    printf("Inserisci il nome: ");
    scanf("%s", c.nome);

    do{
        printf("Inserisci il sesso (F o M): ");
        fflush(stdin);
        scanf("%c", &c.sesso);
        convertiMaiusc(&c.sesso);
    } while (c.sesso != 'M' && c.sesso != 'F');

    printf("Inserisci l'indirizzo: ");
    scanf("%s", c.indirizzo);
    printf("Inserisci il numero di telefono: ");
    scanf("%d", &c.tel);
    printf("Inserisci l'eta': ");
    scanf("%d", &c.eta);

    return c;
}

void nuovoCont(Contatto tab[], int *dim) {
    int k = 0;
    
    Contatto c = inputCont();

    while(k < *dim && strcmp(c.cognome, tab[k].cognome) > 0) {
        k++;
    }

    for(int j = *dim; j > k; j--) {
        tab[j] = tab[j - 1];
    }

    tab[k] = c;

    *dim += 1;
}

void stampaContatto(Contatto c) {
    printf(
        "Cognome: %s\n"
        "Nome: %s\n"
        "Sesso: %c\n"
        "Indirizzo: %s\n"
        "Telefono: %d\n"
        "Eta': %d\n\n",
        c.cognome, c.nome, c.sesso, c.indirizzo, c.tel, c.eta
    );
}

int cercaCont(Contatto tab[], int dim) {
    char nomeN[STRL];
    int cont = 0;

    printf("Inserisci il nome: ");
    scanf("%s", nomeN);

    for(int k = 0; k < dim; k++) {
        if(strcmp(nomeN, tab[k].nome) == 0){
            stampaContatto(tab[k]);
            cont++;
        }
    }
    return cont;
}

void visualizza(Contatto tab[], int dim) {
    for(int k = 0; k < dim; k++) {
        stampaContatto(tab[k]);
    }
}

void statistiche(Contatto tab[], int dim) {
    int sm = 0, sf = 0; //somma m e somma f
    int cm = 0, cf = 0; //contatori m e f

    for(int k = 0; k < dim; k++) {
        if(tab[k].sesso == 'M') {
            sm += tab[k].eta;
            cm++;
        } else{
            sf += tab[k].eta;
            cf++;
        }
    }
    if(dim == 0){
        printf("Rubrica vuota, impossibile fare la statistica\n\n");
    } else{
        printf("Eta' media dei maschi: %d\nEta' media delle femmine: %d\n\n", sm/cm, sf/cf);
    }
}


int NonOrdDisg(Contatto tab[],int dim, int x){
    int tro, k;
    tro = - 1;
    k = 0;
    while ((k < dim) && (tro == -1)){
        if(x == tab[k].tel){
            tro = k;
        }
        else {
            k++;
        }
    }
    return tro;
}

void modificaCont(Contatto tab[], int dim) {
    Contatto c;
    int cont = cercaCont(tab, dim);
    int indice;
    int tel;

    if(cont != 0){
        printf("Scegliere quale contatto modificare (inserire il numero di telefono): ");
        scanf("%d", &tel); //metti controllo !!
        indice = NonOrdDisg(tab, dim, tel);
        if(indice == -1) {
            printf("Hai inserito un numero sbagliato!\n\n");
        } else{
            c = inputCont();
            tab[indice] = c;
        }
    } else{
        printf("Non ho trovato contatti con il nome cercato!\n\n");
    }
}

void incrementaEta(Contatto tab[], int dim) {
    for(int k = 0; k < dim; k++) {
        tab[k].eta += 1;
    }
}

void menu() {
    printf(
        "Digita il numero corrispondente alla tua scelta tra le seguenti:\n"
        "0: esci\n"
        "1: Inserisci nuovo elemento con caricamento ordinato per cognome (ricerca posizione)\n"
        "2: Cerca elemento X per nome\n"
        "3: Visualizza tutto\n"
        "4: Statistiche: età media dei maschi e delle femmine\n"
        "5: Modifica dati elemento X\n"
        "6: Incrementa l'età d’ogni elemento di 1 (nuovo anno)\n"
        "N^: "
    );
}

int main() {
    Contatto rubrica[DIM];

    int risp;

    int dim = caricaCont(rubrica, DIM, NOME_FILE);

    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break; //esce

        case 1:
            nuovoCont(rubrica, &dim);
            break;

        case 2:
            if(cercaCont(rubrica, dim) == 0){
                printf("Rubrica vuota, impossibile trovare il contatto\n\n");
            }
            break;
        
        case 3:
            visualizza(rubrica, dim);
            break;
        
        case 4:
            statistiche(rubrica, dim);
            break;
        
        case 5:
            modificaCont(rubrica, dim);
            break;

        case 6:
            incrementaEta(rubrica, dim);
            break;
        
        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);

    scriviCont(rubrica, dim, NOME_FILE);

    return 0;
}