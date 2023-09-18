/*
                                                ⠀⠀⠀⠀⢀⣀⣠⣤⣤⣶⣶⣶⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀        
                                                ⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇    
                                                ⣿⣿⣿⠿⠿⠛⠛⠛⠉⠉⠉⠉⠛⠛⠛⠿⢿⣿⣿⡇
                                                ⣿⣿⡇⠀⠀⠀⠀⠀⣤⣴⣷⡄⠀⠀⠀⠀⠀ ⢸⣿⣿               
                                                ⣿⣿⡇⠀⠀⠀⢀⠴⡄⣸⣿⡏⠀⠀⠀⠀⠀⢸⣿⣿       
                                                ⢹⣿⣷⠀⠀⠀⠁⡤⢶⣿⣿⣁⠀⢠⠀⠀⠀⣿⣿⡏
                                                ⠈⢿⣿⣇⠀⠀⠀⢳⠀⢙⣿⣿⣷⠾⠀⠀⣸⣿⡿⠀
                                                ⠀⠘⣿⣿⣆⠀⠀⠠⠤⠾⢹⡏⠀⠀⠀⣰⣿⣿⠃⠀
                                                ⠀⠀⠘⢿⣿⣷⡀⠀⠀⠰⠟⠀⠀⢀⣾⣿⡿⠃⠀⠀
                                                ⠀⠀⠀⠈⠻⣿⣿⣦⡀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀
                                                ⠀⠀⠀⠀⠀⠈⠻⣿⣿⣷⣾⣿⣿⠟⠁⠀⠀⠀⠀⠀
                                                ⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⠿⠋⠀⠀⠀⠀⠀ 
                                ______________________________  _______  ______________       ______   
                                ___  ____/_  __ \__  __ \__   |/  /_  / / /__  /___    |      __<  /   
                                __  /_   _  / / /_  /_/ /_  /|_/ /_  / / /__  / __  /| |      __  /    
                                _  __/   / /_/ /_  _, _/_  /  / / / /_/ / _  /___  ___ |      _  /     
                                /_/      \____/ /_/ |_| /_/  /_/  \____/  /_____/_/  |_|      /_/    ⠀⠀⠀
*/

#include <conio.h>      //kbhit getc
#include <stdio.h>
#include <stdbool.h>
#include "baseGrafica_Baruffolo.h"
#include <time.h>

#define WIDTH 80 //larghezza
#define HEIGHT 30 //altezza

#define PLAYER_HEIGHT 10 //altezza  macchina giocatore
#define PLAYER_WIDTH 11 //larghezza macchina giocatore
#define ENEMY_HEIGHT 10 //altezza macchina nemica
#define ENEMY_WIDTH 8 //larghezza macchina nemica

#define STR_SIZE 26 //limite caratteri stringa nome giocatore

//TASTI
#define FUNZ 224
#define D 100
#define DX 77
#define A 97
#define SX 75
#define ESC 27
#define KEY_SPACE 32

#define STREET_COLOR 143 //colore strada
#define STREET_ROW 186 //righe strada

#define PLAYER_START_X 35 //coordinata x di partenza della macchina del giocatore
#define PLAYER_START_Y 19 //coordinata y di partenza della macchina del giocatore
#define PLAYER_COLOR 132 //colore macchina giocatore
#define PLAYER_SPEED 5 //spostamento macchina

#define NAME_FILE_RECORD "recordF1.txt" //nome file per il record
#define NAME_FILE_SCORE "scoreF1.txt" //nome file per punteggi partita

/*
Author: Noemi Baruffolo
date: summer 2023
es. Fomula 1
text: Realizzare un gioco tipo i seguenti, utilizzando: i tasti, le strutture, le funzioni (come indicato in classe con
creaOggetto(), disegnaOggetto()) e i file per salvare punteggi/record o
ripristinare la situazione: Formula 1 (un'auto ferma in basso, si sposta a destra e sinistra
tramite tasti per evitare gli ostacoli e stare nella pista che "scende"
delineandosi nello schermo) 
*/

typedef struct { 
    int x; //coordinata asse x
    int y; //coordinata asse y
} Position; //struttura delle posizioni x e y

typedef struct { 
    Position pos; //partend dal vertice in alto a sx
    int w, h; //larghezza e altezza
} CollisionRect; //struttura per le collisioni con posizioni e dimensione

typedef struct { 
    Position pos; //posizione coordinate del giocatore
    int color; //colore giocatore
    CollisionRect r; //rettangolo di collisione della macchina del giocatore
} Player; //struttura del giocatore

typedef struct {
    Position pos; //coordinate macchina "nemica"
    int color; //colore macchina "nemica"
    float timer; //tempo trascorso
    CollisionRect r; //rettangolo delle collisioni del veicolo "nemico"
    float wait; //dopo quanti sec si rigenera
    bool spawned; // se macchina creata o no
} Car; //struttura "nemico"

bool isColliding(CollisionRect *r1, CollisionRect *r2) { //controllo se i rettangoli di collisione delle macchine si incontrano
    //se ((x di r2 è compreso tra x di r1 e x + larghezza di r1) oppure ( stessa cosa per la larghezza di dx e di y con l'altezza dai sx e dx)) 
    return ((r1->pos.x <= r2->pos.x && r2->pos.x <= r1->pos.x + r1->w) || (r1->pos.x <= r2->pos.x + r2->w && r2->pos.x + r2->w<= r1->pos.x + r1->w)) &&
        ((r1->pos.y <= r2->pos.y && r2->pos.y <= r1->pos.y + r1->h) || (r1->pos.y <= r2->pos.y + r2->h && r2->pos.y + r2->h<= r1->pos.y + r1->h));
}

Player newPlayer(int x, int y, int color) { //nuovo giocatore
    Player p;

    p.pos.x = x;
    p.pos.y = y;
    p.color = color;

    p.r.pos.x = x + 1;
    p.r.pos.y = y;
    p.r.h = 9;
    p.r.w = 9;

    return p;
}

Car newCar(float wait) { //nuova macchina "nemica"
    Car c;

    c.pos.x = 0;
    c.pos.y = 0;
    c.color = 0;
    c.timer = 0;
    c.wait = wait;

    c.r.pos.x = 0;
    c.r.pos.y = 0;
    c.r.h = 9;
    c.r.w = 6;

    c.spawned = false;

    return c;
}

void setCar(Car *c, int x, int y, int color) { //per settare la macchina	
	c->pos.x = x;
    c->pos.y = y;

    c->color = color;
	
	c->r.pos.x = x + 1;
    c->r.pos.y = y + 1;
	
	c->spawned = true;
}

void resetCar(Car *c) {
	c->spawned = false;
	c->timer = 0;
}

void drawPlayer(Player *pl){ //disegna la macchina del giocatore
    char mat[PLAYER_HEIGHT][PLAYER_WIDTH] = {
        { 32,  47, 196, 196, 196, 194, 196, 196, 196,  92,  32}, 
        { 32,  32,  32,  32,  32, 179,  32,  32,  32,  32,  32},
        { 32,  32,  32,  32,  32, 179,  32,  32,  32,  32,  32},
        {184, 196, 196, 196, 196, 197, 196, 196, 196, 196, 184},
        { 32,  32,  32,  32,  32, 179,  32,  32,  32,  32,  32},
        { 32, 218, 196, 196, 196, 193, 196, 196, 196, 191,  32},
        { 32, 179, 219, 219, 219, 219, 219, 219, 219, 179,  32},
        { 32, 179, 219, 219, 219, 219, 219, 219, 219, 179,  32},
        {184, 193, 196, 196, 196, 194, 196, 196, 196, 193, 184},
        { 32,  32,  32, 195, 196, 193, 196, 180,  32,  32,  32}
    }; //modello macchina giocatore (vedi sotto il risultato)
    /* 
         /---+---\ 
             |     
             |     
        O----+----O
             |     
         +---+---+ 
         |       | 
         |       | 
        O+---+---+O
           |---|   
    */

    setTextColor(pl->color); //imposta il colore della macchina

   for(int k = 0; k < PLAYER_HEIGHT; k++) { //stampa la macchina del giocatore
    for(int j = 0; j < PLAYER_WIDTH; j++) {
        if(mat[k][j] != ' '){
            gotoxy(pl->pos.x + j, pl->pos.y + k);

            printf("%c", mat[k][j]);
        }  
    }
   }
}

void drawEnemy(Car *enemy) { //disegna la macchina "nemica"

    char mat[ENEMY_HEIGHT][ENEMY_WIDTH] = {
        { 32,  32,  32,  95,  95,  32,  32,  32}, 
        { 32,  32,  47, 219, 219,  92,  32,  32},
        { 32,  47, 219, 219, 219, 219,  92,  32},
        {184, 194, 196, 196, 196, 196, 194, 184},
        { 32, 179, 219, 219, 219, 219, 179,  32},
        { 32, 179, 219, 219, 219, 219, 179,  32},
        { 32, 179, 219, 219, 219, 219, 179,  32},
        { 32, 179, 219, 219, 219, 219, 179,  32},
        {184, 197, 196, 196, 196, 196, 197, 184},
        { 32, 192, 196, 196, 196, 196, 217,  32}
    }; //modello macchina nemica (vedi sotto il risultato)
    
    /*
    "   __   "
    "  /  \  "
    " /    \ "
    "O------O"
    " |    | "
    " |    | "
    " |    | "
    " |    | "
    "O------O"
    " |____| "
    */


   if(enemy->timer > enemy->wait){ //la differenza sono i sec passati
        setTextColor(enemy->color); //imposta il colore della macchina

        //stampa la macchina considerando che all'inizio deve vedersi la discesa graduale e lo stesso per l'uscita dallo schermo
        for(int k = ENEMY_HEIGHT - 1; k >= 0; k--) { //righe
            for(int j = 0; j < ENEMY_WIDTH; j++) { //colonne
                if(enemy->pos.y + k >= 0 && enemy->pos.y + k < HEIGHT) {
                    if(mat[k][j] != ' '){
                        gotoxy(enemy->pos.x + j, enemy->pos.y + k);

                        printf("%c", mat[k][j]);
                    }
                }
            }
        }       
    }
}

void drawStreet(int r1x, int r2x, int width, int height, int raw, int color) { //disegna la strada

    rettangoloPienoColore(0, 0, width, height, ' ', color); //base grigia della strada

    //strisce bianche divisorie
    colonnaColore(r1x, 0, height, raw, color);
    colonnaColore(r2x, 0, height, raw, color);
}

void keyHandler(Player *pl, bool *running, int speed, int w) { //rilevamento pressione tasti
    if(kbhit() == true) { //se un tasto viene premuto
        int ch = getch();

        if(ch == FUNZ) { //se e' una freccia o funzione
            ch = getch();
        } else if(ch >= 'A' && ch <= 'Z') { //se premuta una lettera maiuscola, diventa minuscola e non blocca il programma
            ch += 32;
        }

        if(ch == A || ch == SX){ //sposta la macchina a sinistra se premuta la freccia corrispondente o la lettera 'a'

            if(pl->pos.x - 1 - speed> 0) { //ruota sx
                pl->pos.x -= speed;
                pl->r.pos.x -= speed;
            }

        } else if(ch == D || ch == DX){ //sposta la macchina a destra se premuta la freccia corrispondente o la lettera 'd'

            if(pl->pos.x + 9 + speed < w - 1) { //ruota dx
                pl->pos.x += speed;
                pl->r.pos.x += speed;
            }
        } else if(ch == ESC) { //per uscire dal gioco
            *running = false; //interrompe il ciclo del game
        }
    }
}

int readRecord(char name[]) { //legge il record
    FILE *fp;
    fp = fopen(NAME_FILE_RECORD, "r"); //apre il file in lettura

    int record = 0; //record iniziale se nessuno ha ancora giocato

    if(fp == NULL) { //se il file non esiste lo crea
        fp = fopen(NAME_FILE_RECORD, "w"); //apre il file in scrittura
    } else {
        fscanf(fp, "%s %d", name, &record); //altrimenti legge il record
    }

    fclose(fp); //chiude il file

    return record;
}

void writeRecord(int *record, int score, char name[]) { //scrive il record
    FILE *fp;

    if(score > *record) { //se il punteggio della partita supera il record, diventa il nuovo record
        *record = score;
        fp = fopen(NAME_FILE_RECORD, "w"); //apre il file in scrittura

        fprintf(fp, "%s %d", name, score); //sovrascrive il vecchio record con quello nuovo

        fclose(fp); //chiude il file
    }
}

void writeScore(int score, char plName[]) { //scrive il punteggio
    FILE *fp;

    fp = fopen(NAME_FILE_SCORE, "a"); //apre il file in append

    fprintf(fp, "%s %d\n", plName, score); //stampa il nome e il punteggio corrispondente

    fclose(fp); //chiude il file
}

void moveEnemy(Car *enemy, CollisionRect *plRect, bool *running, int *score) { //movimento della macchina "nemica"
    enemy->timer += 0.1; //tempo trascorso

    if((enemy->timer >= enemy->wait) && (enemy->spawned == false)){//la differenza sono i sec passati
        setCar(enemy, (rand() % 3) * 30 + 9, -10, rand() % (143 - 137 + 1) + 137); //genera posizioni e colori casuali per le macchine
    } else if((enemy->timer >= enemy->wait) && (enemy->spawned == true)) {
        if(enemy->pos.y > HEIGHT) { //se fuori schermo
            resetCar(enemy);
            *score += 1; //incementa punteggio partita
        } else {
            enemy->pos.y += 2; //si muove di 2 in 2
            enemy->r.pos.y += 2; //si muove contemporaneamente alla macchina, di 2 in 2, il rettangolo di collisione 
            if(isColliding(&enemy->r, plRect)) { //se le macchine si scontrano
                *running = false; //finisce la partita
            }
        }
    }
}

void printScore(int score) { //stampa in alto a sinistra il punteggio in corso

    gotoxy(1, 0);
    setTextColor(112);
    //cornice superiore
    printf("%c", 201);
    for(int k = 0; k < 11; k++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    gotoxy(1, 1);
    printf("%c", 186);
    setTextColor(10);
    printf(" pt: %5d ", score);
    setTextColor(112);
    printf("%c", 186);

    gotoxy(1, 2);
    //cornice inferiore
    printf("%c", 200);
    for(int k = 0; k < 11; k++) {
        printf("%c", 205);
    }
    printf("%c", 188);

}

void printRecord(int record) { //stampa in alto a destra il numero del record
    gotoxy(66, 0);
    setTextColor(112);

    //cornice superiore
    printf("%c", 201);
    for(int k = 0; k < 11; k++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    gotoxy(66, 1);
    printf("%c", 186);
    setTextColor(10);
    printf(" mvp: %4d ", record);
    setTextColor(112);
    printf("%c", 186);

    gotoxy(66, 2);
    //cornice inferiore
    printf("%c", 200);
    for(int k = 0; k < 11; k++) {
        printf("%c", 205);
    }
    printf("%c", 188);

}

void game(int record, int *score, int x, int y, int plColor, int h, int w, int row, int streetColor, int speed) {
    Player pl = newPlayer(x, y, plColor);
    Car enemy1 = newCar(1.5), enemy2 = newCar(3);

    bool running = true; //partita in corso

    *score = 0; //reset punti

    clrscr(); //pulisce lo schermo

    gotoxy(0, 12); //imposta la posizione 
    setTextColor(134); //imposta il colore della scritta di inizio gioco

    printf(
       "                     _____________________________________\n"                                 
       "                     __  ___/__  __/__    |__  __ \\__  __/\n"                                 
       "                     _____ \\__  /  __  /| |_  /_/ /_  /  \n "                                 
       "                     ____/ /_  /   _  ___ |  _, _/_  /    \n"                                 
       "                     /____/ /_/    /_/  |_/_/ |_| /_/     \n"
       "\n"
       "                            (3...2...1...GO)\n"
    );

    delay(3000); //aspetta 3 sec e poi inizia la partita

    while(running){ //continua fino a che non si perde o si preme esc

        keyHandler(&pl, &running, speed, w); //rileva i tasti premuti da tastiera

        moveEnemy(&enemy1, &pl.r, &running, score); //sposta il nemico n1
        moveEnemy(&enemy2, &pl.r, &running, score); //sposta il nemico n2

        drawStreet(20 , 59, w, h, row, streetColor); //disegna la strada

        drawEnemy(&enemy1); //disegna il nemico n1
        drawEnemy(&enemy2); //disegna il nemico n2

        drawPlayer(&pl); //disegna il giocatore

        printScore(*score); //scrive il punteggio
        printRecord(record); //scrive il record

        gotoxy(0, 0);
    }

    gotoxy(0, 10); //imposta la posizione
    setTextColor(128); //imposta il colore della scritta di inizio gioco

    printf(
       "     _____________________  ____________   __________    __________________\n"
       "     __  ____/__    |__   |/  /__  ____/   __  __ \\_ |  / /__  ____/__  __ \\\n"
       "     _  / __ __  /| |_  /|_/ /__  __/      _  / / /_ | / /__  __/  __  /_/ /\n"
       "     / /_/ / _  ___ |  /  / / _  /___      / /_/ /__ |/ / _  /___  _  _, _/\n"
       "     \\____/  /_/  |_/_/  /_/  /_____/      \\____/ _____/  /_____/  /_/ |_|\n"
    ); //scirtta partita finita o persa

    delay(3000); //attende 3 sec
}

void printMenu(int width, int height, int Scolor, int tColor) { //stampa il menu' del gioco con titolo
    clrscr(); //pulisce lo schermo

    rettangoloPienoColore(0, 0, width, height, ' ', Scolor); //disegna lo sfondo grigio di base
    setTextColor(tColor); //imposta il colore scritta titolo del gioco

    gotoxy(0, 10);

    printf(
        "      ______________________________  _______  ______________       ______\n"   
        "      ___  ____/_  __ \\__  __ \\__   |/  /_  / / /__  /___    |      __<  /\n"  
        "      __  /_   _  / / /_  /_/ /_  /|_/ /_  / / /__  / __  /| |      __  /\n"
        "      _  __/   / /_/ /_  _, _/_  /  / / / /_/ / _  /___  ___ |      _  /\n"
        "      /_/      \\____/ /_/ |_| /_/  /_/  \\____/  /_____/_/  |_|      /_/\n"
        "\n"
        "               <<Premi SPACE per iniziare ed ESC per uscire>>\n"      
    );
}

int main() {
    int key = 0;
    int score = 0;
    int record = 0;

    char plName[STR_SIZE]; //nome giocatore
    char recName[STR_SIZE]; //nome giocatore con record

    srand(time(NULL)); //per la generazione casuale ogni volta

    record = readRecord(recName); //legge il record dal file

    setConsoleDimensions(WIDTH, HEIGHT); //imposta la dimensione dello schermo

    cursor_hide(); //nasconde il cursore

    while(key != ESC) {
        printMenu(WIDTH, HEIGHT, STREET_COLOR, PLAYER_COLOR); //stampa il menu' di gioco

        key = getch(); //aspetta che venga premuto un tasto (SPACE) per continuare e iniziare il gioco

        if(key == KEY_SPACE) { //se premuto il tasto spazio

            printf("\n");
            printf("\t");
            printf("Inserisci il nome del giocatore senza spazi, max 25 lettere \n\t\t(Es. noeBaru): "); //chiede il nome del giocatore
            printf("-->");
            scanf("%s", plName);

            game(record, &score, PLAYER_START_X, PLAYER_START_Y, PLAYER_COLOR, HEIGHT, WIDTH, STREET_ROW, STREET_COLOR, PLAYER_SPEED); //inizia il gioco

            writeScore(score, plName); //scrive il punteggio e chi lo ha raggiunto
            writeRecord(&record, score, plName); //scrive il record (aggiungo chi ha fatto il record e lo scrivo)

        }
    }
   
    setTextColor(7); //rimette il colore normale del terminale

    clrscr(); //pulisce lo schermo

    cursor_show(); //rimostra il cursore

    return 0;
}