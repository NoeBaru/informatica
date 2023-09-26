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
es. 30
text:
In un concorso, i partecipanti sono sottoposti a 10 prove. I risultati del concorso sono memorizzati 
in un array di strutture, che contiene, per ogni concorrente, i seguenti dati:
• nome: stringa contenente al massimo 20 caratteri, compreso il terminatore;
• punteggi: una sequenza di 10 interi.
• totale: calcola la somma dei punteggi durante il caricamento e verrà usato per la classifica
 Caricare i dati da tastiera e visualizzare per ciascuna prova, chi è il vincitore e con quale punteggio 
e quindi la classifica finale.
Esempio di contenuto dell'array di struct:
{"Rossi", {4,6,1,2,0,4,0,1,2,2}},
{"Bianchi", {12,0,9,4,5,2,1,1,0,5}},
{"Verdi", {2,3,7,9,10,4,5,9,7,2}},
{"Astolfi", {0,2,6,1,8,5,9,10,7,8}},
{"Lorenzi", {6,9,7,1,0,0,4,5,2,1}},
{"Franchi", {1,10,11,19,4,7,2,0,2,7}}
*/

//vedi es14 compiti delle vacanze
//concorsoEs30.txt