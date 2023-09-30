#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define DIM 50
#define STRL 26
#define MIN_F 5
#define MAX_F 10
#define MIN_VITA 0
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

Mostro creaMostro(char nome[], int vita, int forza){
    Mostro m;
    printf("Inserisci il nome del mostro: ");
    fflush(stdin);
    scanf("%s", nome);
    setiVita(?, vita);
    setForza(?, forza);
}

void setVita(Mostro *m, int vita){ //controlla correttezza vita
    vita = chiediProprieta(MIN_VITA, MAX_VITA, "Inserisci la vita: ");
    m->vita = vita;
}

void setForza(Mostro *m, int forza){ //controlla correttezza forza
    forza =  chiediProprieta(MIN_F, MAX_F, "Inserisci la forza: ");
    m->forza = forza;
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

}

Mostro creaMostroCasuale(char nome[]){

}



int main() {
    Mostro mazzo[DIM];
    int risp;
    int vita;
    int forza;

    srand(time(NULL));


    do{
        menu();
        scanf("%d", &risp);
        switch (risp) {
        case 0:
            break;

        case 1:
            creaMostro(mazzo->nome, mazzo->vita, mazzo->forza);
            break;

        case 2:
            
            break;
        
        case 3:
            
            break;

        default:
            printf("Inserisci un numero valido:\n");
            break;
        }
    } while(risp != 0);
    



    return 0;
}