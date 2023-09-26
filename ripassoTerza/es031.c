#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRL 21
#define DIM 100
#define AZIONI 7

/*
Author: Noemi Baruffolo
date: 26/09/2023
es. 31
text:
Un negozio di alimentari ha un archivio in cui vengono memorizzati i prodotti presenti in 
magazzino. Per ogni prodotto in magazzino, si dispone dei seguenti dati:
● la descrizione (stringa di al massimo 20 caratteri, incluso il terminatore);
● la quantità disponibile in magazzino (int);
● data di scadenza (tipo struttura).
Il programma deve memorizzare in un altro SCADUTI.DAT tutti i prodotti che sono da cancellare 
dall'archivio perché scaduti rispetto alla data letta da tastiera.
I dati vengono letti da un file NEGOZIO.DAT e la tabella deve poi essere ordinata rispetto la 
descrizione
Esempio di contenuto del file e dell'array di struct dopo l'ordinamento:
melanzane 85 2019/7/3
olio 60 2025/5/28
pere 150 2026/11/3
arance 210 2020/4/12
tonno 48 2027/10/4
pasta 75 2021/4/12
pomodoro 61 2015/7/31
aceto 49 2022/4/30
{"aceto",49,2022,4,30},
{"arance",210, 2020,4,12},
{"melanzane",85, 2019,7,3},
{"olio",60,2025,5,28},
{"pasta",75, 2021,4,12},
{"pere",150,2026,11,3},
{"pomodoro",61,2015,7,31},
{"tonno",48, 2027,10,4}
*/

//.txt