#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define DIM_MAZZO 50
#define STRL 26
#define MIN_FORZA 5
#define MAX_FORZA 10
#define MIN_VITA 0
#define MIN_VITA_GEN 1
#define MAX_VITA 100
#define DADO_MIN 1
#define DADO_MAX 6

/*
Author: Noemi Baruffolo
date: 28/09/2023
es. 32
text:
Gioco carte Mostri caratterizzati da un nome, forza [5..10], vita [0..100]. Gestire il gioco con un 
menu:
● 0-esci
● 1- crea mostro
● 2- gioca (scegli mostro)
● 3- stampa mazzo
Si devono usare anche le seguenti funzioni:
● void setVita( Mostro *m, int vita); controlla correttezza vita
● void setForza( Mostro *m, int forza); controlla correttezza forza
● int getForza(Mostro m)
● int getVita(Mostro m)
● int getLancio(Mostro m) si lancia un dado con 6 facce e si moltiplica per la forza del mostro
● Mostro creaMostro(char nome[], int vita, int forza)
● Mostro creaMostroCasuale(char nome[])
*/

//set vs get, il set imposta mentre il get restituisce 

typedef struct{
    char nome[STRL];
    int forza;
    int vita;

} Mostro;

void menu() {
    printf("Inserisci il numero corrispondente alla scelta:\n0 = esci\n1: crea mostro\n2: gioca (sceglie il mostro)\n3: stampa mazzo\nN^: ");
}

int chiediDim(int min, int max, char messaggio[]){
	int n;
	printf(messaggio);
	do{
		scanf("%d", &n);
		if(n <= min || n > max){
			printf("Inserisci un numero valido (%d-%d): ", min, max);
		}
	} while(n < min || n > max);
	return n;
}

void setVita(Mostro *m, int vita){ //controlla correttezza vita
    vita = chiediProprieta(MIN_VITA, MAX_VITA, "Inserisci la vita: ");
    m->vita = vita;
}

void setForza(Mostro *m, int forza){ //controlla correttezza forza
    forza =  chiediProprieta(MIN_FORZA, MAX_FORZA, "Inserisci la forza: ");
    m->forza = forza;
}

Mostro creaMostro(char nome[], int vita, int forza){
    Mostro m;
    
    strcpy(m.nome, nome);
    setiVita(&m, vita);
    setForza(&m, forza);
    
    return m;
}

Mostro creaMostroCasuale(char nome[]){
    int vita = rand() % (MAX_VITA - MIN_VITA_GEN + 1) + MIN_VITA_GEN;
    int forza = rand() % (MAX_FORZA - MIN_FORZA + 1) + MIN_FORZA;

    return creaMostro(nome, vita, forza);
}

void creaMostroMenu(Mostro *mazzo, int dim){
    char nome[STRL];
    int  k= 0;
    bool inserito;

    while(k < dim){
        for(int k = 0; k < dim; k++){
        printf("Inserisci il nome del mostro [%d]: ", k + 1);
        fflush(stdin);
        scanf("%s", nome);

        convertiInMaiusc(nome);

        j = 0;

        inserito = false;
        while(j < k && inserito == false){
            if(strcmp(mazzo[j].nome, nome) == 0) {
                printf("Hai già inserito il nome del mostro!");
                inserito = true; //esce dal ciclo
            }

            j++;
        }

        if(inserito == false) {
            mazzo[k] = creaMostroCasuale(nome);
            k++;
        }
        
        
        }
    }
    
}

int getForza(Mostro m){

    return m.forza
}

int getVita(Mostro m){
    
    return m.vita
}

int getLancio(Mostro m){ //si lancia un dado con 6 facce e si moltiplica per la forza del mostro
    int dado;

    dado = DADO_MIN + rand() % (DADO_MAX + 1 - DADO_MIN);

    return dado * getForza(m);
}

void convertiInMaiusc(char stringa[]) {
    for(int k ; stringa[k] != '\0'; k++){
        if(stringa[k] >= 'a' && stringa[k] <= 'z')
            stringa[k] -= ('a' - 'A');
    }
}

void gioca(Mostro *mazzo, int dim) {
    char nomeGiocatore[STRL], nomeAvversario[STRL];
    int posGiocatore = -1;
    int posAvversario = -1;
    int k = 0;

    printf("Inserire il nome del giocatore: ");
    scanf("%d", nomeGiocatore);

    convertiInMaiusc(nomeGiocatore);

    printf("Inserire il nome dell'avversario: ");
    scanf("%d", nomeAvversario);

    convertiInMaiusc(nomeAvversario);

    //cercare se i nomi non sono uguali fatto in una fuznione da mettere a parte
   if(posGiocatore != -1 && posAvversario != -1) {
    combattimento(&mazzo[posGiocatore], &mazzo[posAvversario]);
   } else{

   }

    k = 0;

    while(k < dim && (posGiocatore == -1 || posAvversario == -1)){
        if(strcmp(mazzo[k].nome, nomeAvversario) == 0) {
            posGiocatore = k;
        }

        if(strcmp(mazzo[k].nome, nomeGiocatore) == 0) {
            posAvversario = k;
        }
    }
}

void stampaMazzo(Mostro *mazzo, int dim){
    for(int k = 0; k < dim; k++){
        printf("mostro[%d]: %s (V: %3d, F: %3d)", mazzo[k].nome, getVita(mazzo[k]), getForza(mazzo[k]));
    }
}

int main() {
    Mostro mazzo[DIM_MAZZO];
    int risp;
    int vita;
    int forza;
    int dim;
    char nome[STRL];

    srand(time(NULL));

    dim = chiediDim(0, DIM_MAZZO, "Inserisci il numero dei mostri nel mazzo: ");

    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break;

        case 1:

            creaMostroMenu(mazzo, dim);

            break;

        case 2:
            gioca(mazzo, dim);           
            break;
        
        case 3:
            stampaMazzo(mazzo, dim);
            break;

        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);
    



    return 0;
}