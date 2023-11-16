/*
author: Noemi Baruffolo
date: 13/11/2023
es: esercitazione verifica caso A
text: Gestione di un autonoleggio. Una catena di autonoleggio deve gestire con un sistema
informatico i propri veicoli. Per ciascun veicolo vengono salvate le seguenti
informazioni: Codice, Targa, Marca, Modello. L’autonoleggio può ospitare al
massimo 2000 vetture. Ogni autonoleggio ha un responsabile che lo gestisce. Si
chiede di progettare un sistema informatico che permetta di gestire le seguenti
funzionalità:
● aggiunta di un nuovo veicolo;
● ricerca di un veicolo data la targa;
● ricerca di tutti i veicoli presenti nell’autonoleggio;
Il sistema deve anche prevedere la possibilità di stampare i dati del responsabile che lo
gestisce.
Prevedere le seguenti classi:
● Autonoleggio caratterizzata dalle seguenti proprietà:
○ Nome
○ Indirizzo
○ Responsabile autonoleggio
○ Elenco veicoli
● Responsabile caratterizzata dalle seguenti proprietà:
○ Nome
○ Cognome
○ Data di nascita
○ Codice fiscale
● Veicolo caratterizzata dalle seguenti proprietà:
○ Codice
○ Targa
○ Marca
○ Modello

Per ciascuna classe prevedere i metodi costruttori, i metodi get e set ed i metodi
toString. Nella classe Autonoleggio prevedere inoltre i seguenti metodi:

a. boolean aggiungiVeicolo(Veicolo veicolo)
b. Veicolo trovaVeicolo(String targa)
c. Veicolo[] trovaTuttiIVeicoli()

Scrivere una classe TestAutonoleggio che:
I. crea un oggetto di tipo autonoleggio;
II. aggiunge due veicoli;
III. stampa i dati del responsabile;
IV. stampa i dati di tutti i veicoli presenti nell’autonoleggio
(FACOLTATIVO: usare il costrutto foreach).
 */
public class Test {
    public static void main(String[] args) {
        Autonoleggio a1 = new Autonoleggio();
        Veicolo v1 = new Veicolo();
        Veicolo v2 = new Veicolo();
        System.out.println();
    }

}
