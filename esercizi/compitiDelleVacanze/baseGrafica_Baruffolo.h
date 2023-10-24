#include "utility.h"  //inserire il percorso relativo corretto

//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car);

//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoPieno(int x, int y, int l, char car);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoPienoColore(int x, int y, int l, char car, int color);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoVuoto(int x, int y, int l, char car);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoVuotoColore(int x, int y, int l, char car, int color);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloVuoto(int x, int y, int b, int h, char car);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloVuotoColore(int x, int y, int b, int h, char car, int color);


//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
void triangolo(int x, int y, int h, char car);

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void triangoloColore(int x, int y, int h, char car, int color);

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
//ma invertito
void triangoloInverso(int x, int y, int h, char car);

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
//ma invertito
void triangoloInversoColore(int x, int y, int h, char car, int color);
///////////////////////////////////////////////////////DEFINIZIONE DELLE PROCEDURE:////////////////////////////////////////////////////////////////////

//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car) {
    gotoxy (x, y);
    printf("%c", car);
}

//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color) {
    int current = getTextColor();
    setTextColor(color);
    punto(x,y,car);
    setTextColor(current);
}

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car) {
    int k;

    gotoxy(x, y);
    for (k = 0; k <lung; k++) {
        printf("%c", car);
    }
}

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color) {
    int current = getTextColor();
    srand(time(NULL));

    setTextColor(color);
    riga(x,y,lung,car);
    setTextColor(current);
}

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase) {
    int k = 0;
    int current = getTextColor();

    gotoxy(x,y);
    for (k = 0; k < lung; k++) {
        setTextColor(coloreBase + rand () % 16);
        printf("%c", car);
    }
    setTextColor(current);

}

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car) {
    int k = 0;

    for(k = 0; k < lung; k++) {
        punto(x, y++, car);
    }
}

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    colonna(x,y,lung,car);
    setTextColor(current);
}

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoPieno(int x, int y, int l, char car) {
    int k = 0;

    for(k = 0; k < l; k++) {
        colonna(x + k, y, l, car);
    }
}

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoPienoColore(int x, int y, int l, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    quadratoPieno(x, y, l, car);
    setTextColor(current);
}

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoVuoto(int x, int y, int l, char car) {
    riga(x, y, l, car);
    colonna(x, y, l, car);
    riga(x, y + l -1, l, car);
    colonna(x + l -1, y, l, car);
}

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoVuotoColore(int x, int y, int l, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    quadratoVuoto(x, y, l, car);
    setTextColor(current);
}

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car) {
    int k = 0;

    for(k = 0; k < b; k++) {
        colonna(x + k, y, h, car);
    }
}

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    rettangoloPieno(x, y, b, h, car);
    setTextColor(current);
}

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloVuoto(int x, int y, int b, int h, char car) {
    riga(x, y, b, car);
    colonna(x, y, h, car);
    riga(x, y + h -1, b, car);
    colonna(x + b -1, y, h, car);
}

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloVuotoColore(int x, int y, int b, int h, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    rettangoloVuoto(x, y, b, h, car);
    setTextColor(current);
}

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
void triangolo(int x, int y, int h, char car) {
    int k = 0;

    for(k = 0; k < h; k++) {
        riga(x - k, y +k, k * 2 + 1, car);
    }
}

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void triangoloColore(int x, int y, int h, char car, int color) {
    int current = getTextColor();

    setTextColor(color);
    triangolo(x, y, h, car);
    setTextColor(current);
}

void triangoloInverso(int x, int y, int h, char car){
    int k = 0;

    for(k = 0; k < h; k++) {
        riga(x + k, y +k, (h - k - 1) * 2 + 1, car);
    }
}

void triangoloInversoColore(int x, int y, int h, char car, int color){
    int current = getTextColor();

    setTextColor(color);
    triangoloInverso(x, y, h, car);
    setTextColor(current);
}
