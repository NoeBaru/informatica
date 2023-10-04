#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STRL 20

#define DIM_MAZZO 100

#define MIN_VITA 0
#define MIN_VITA_GEN 10
#define MAX_VITA 100

#define MIN_FORZA 5
#define MAX_FORZA 10

#define FACCE_DADO 6

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

typedef struct {
    char nome[STRL];
    int forza;
    int vita;

} Mostro;

void menu() {
    printf("\nInserisci il numero corrispondente alla scelta:\n0 = esci\n1: crea mostro\n2: gioca (sceglie il mostro)\n3: stampa mazzo\nN^: ");
}

Mostro creaMostro(char nome[], int vita, int forza) {
    Mostro m;
    
    strcpy(m.nome, nome);
    m.vita = vita;
    m.forza = forza;
    
    return m;
}

Mostro creaMostroCasuale(char nome[]) {
    return creaMostro(nome, rand() % (MAX_VITA - MIN_VITA_GEN + 1) + MIN_VITA_GEN, rand() % (MAX_FORZA - MIN_FORZA + 1) + MIN_FORZA);
}

void setVita(Mostro *m, int vita) {
    if(vita >= MIN_VITA && vita <= MAX_VITA) {
        m->vita = vita;
    }
    
    if(vita < MIN_VITA) {
        m->vita = MIN_VITA;
    }
    
    if(vita > MAX_VITA) {
        m->vita = MAX_VITA;
    }
}

void setForza(Mostro *m, int forza) {
    if(forza >= MIN_FORZA && forza <= MAX_FORZA) {
        m->forza = forza;
    }

    if(forza < MIN_FORZA) {
        m->vita = MIN_FORZA;
    }
    
    if(forza > MAX_FORZA) {
        m->vita = MAX_FORZA;
    }
}

//ricava la forza del mostro
int getForza(Mostro m) {
    return m.forza;
}

//ricava la vita del mostro
int getVita(Mostro m) {
    return m.vita;
}

int getLancio(Mostro m) {
    int dado;
    
    dado = rand() % FACCE_DADO + 1;
    
    return dado * getForza(m);
}

void combattimento(Mostro *m1, Mostro *m2) {
    int l1, l2;
    
    while(getVita(*m1) > MIN_VITA && getVita(*m2) > MIN_VITA) {
        l1 = getLancio(*m1);
        l2 = getLancio(*m2);
        
        if(l1 > l2) {
            printf("\n%s si difende da %s con %d punti.", m1->nome, m2->nome, l2);
            
            setVita(m2, getVita(*m2) - (l1 - l2));
            
            printf("\n%s viene attaccato da %s e perde %d punti vita.\n\n", m2->nome, m1->nome, (l1 - l2));
        } else if(l2 > l1) {
            printf("\n%s si difende da %s con %d punti.", m2->nome, m1->nome, l1);
            
            setVita(m1, getVita(*m1) - (l2 - l1));
            
            printf("\n%s viene attaccato da %s e perde %d punti vita.\n\n", m1->nome, m2->nome, (l2 - l1));
        }
    }
    
    if(getVita(*m1) <= 0) {
        printf("%s ha perso contro %s!", m1->nome, m2->nome);
    } else if(getVita(*m2) <= 0) {
        printf("%s ha perso contro %s!", m2->nome, m1->nome);
    }
}

int chiediDim(int min, int max, const char *messaggio) {
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

void convertiInMaiuscolo(char string[]) {
    for(int k = 0; string[k] != '\0'; k++) {
        if(string[k] >= 'a' && string[k] <= 'z') {
            string[k] -= ('a' - 'A');
        }
    }
}

void creaMostroVoceMenu(Mostro *mazzo, int dim) {
    char nome[STRL];
    int k, j;
    bool giaInserito = false;
    
    k = 0;
    while(k < dim) {
        printf("\nInserire il nome del mostro %d: ", k + 1);
        scanf("%s", nome);
        
        convertiInMaiuscolo(nome);
        
        j = 0;
        giaInserito = false;
        while(j < k && giaInserito == false) {
            if(strcmp(mazzo[j].nome, nome) == 0) {
                printf("Hai gia' inserito questo nome!\n");
                giaInserito = true;
            }
            
            j++;
        }
        
        if(giaInserito == false) {
            mazzo[k] = creaMostroCasuale(nome);
            k++;
        }
    }
}

void gioca(Mostro *mazzo, int dim) {
    char nomGiocatore[STRL], nomAvversario[STRL];
    int posG = -1, posA = -1;
    int k = 0;
    
    do {
        printf("\nInserire il nome del giocatore: ");
        scanf("%s", nomGiocatore);
        
        convertiInMaiuscolo(nomGiocatore);
        
        printf("\nInserire il nome dell'avversario: ");
        scanf("%s", nomAvversario);
        
        convertiInMaiuscolo(nomAvversario);
    } while(strcmp(nomGiocatore, nomAvversario) == 0);
    
    k = 0;
    while(k < dim && (posG == -1 || posA == -1)) {
        if(strcmp(mazzo[k].nome, nomGiocatore) == 0) {
            posG = k;
        }
        
        if(strcmp(mazzo[k].nome, nomAvversario) == 0) {
            posA = k;
        }
        
        k++;
    }
    
    if(posG != -1 && posA != -1) {
        if(getVita(mazzo[posG]) == 0) {
            printf("\n%s e' morto, non puo' giocare!", mazzo[posG].nome);
        } else if(getVita(mazzo[posA]) == 0) {
            printf("\n%s e' morto, non puo' giocare!", mazzo[posA].nome);
        } else {
            combattimento(&mazzo[posG], &mazzo[posA]);
        }
    } else {
        printf("\nNon ho trovato tutti i mostri che mi hai chiesto!");
    }
}

void stampaMazzo(Mostro *mazzo, int dim) {
    printf("\n");
    
    for(int k = 0; k < dim; k++) {
        printf("mostro[%d]: %s(V: %d , F: %d)\n", k, mazzo[k].nome, getVita(mazzo[k]), getForza(mazzo[k]));
    }
}

int main() {
    Mostro mazzo[DIM_MAZZO];
    int scelta;
    int dim;
    
    srand(time(NULL));
    
    dim = chiediDim(0, DIM_MAZZO, "Inserire la dimensione del mazzo (0-100): ");
    
    do {
        menu();
        scanf("%d", &scelta);
        
        switch(scelta) {
            case 0:
                break; //uscita
                
            case 1:
                creaMostroVoceMenu(mazzo, dim);
                break;
                
            case 2:
                gioca(mazzo, dim);
                break;
                
            case 3:
                stampaMazzo(mazzo, dim);
                break;
                
            default:
                printf("\nOpzione %d non valida!", scelta);
        }
    } while(scelta != 0);

    return 0;
}