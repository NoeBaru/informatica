/*
author: Noemi Baruffolo 4^AROB
es: 22 Auto
date: 1/11/2023
text: Si vuole gestire un concessionario monomarca di autovetture. A tal fine creare la classe Auto con gli attributi:
modello, colore, prezzo; ha il costruttore con tutti e 3 gli attributi, il setPrezzo() e tutti i get oltre al toString(). I colori
possibili sono solo: "rosso", "nero", "grigio", "bianco", per cui verificare che la stringa colore sia corretta, se no
assegnare il colore "grigio". Si crei anche la classe Concessionaria con attributi un nome e un numero massimo di
auto che può contenere, oltre al vettore di auto. Il costruttore ha come parametri il nome il numero massimo di
auto. Alla concessionaria si possono aggiungere delle auto con il metodo add(auto) e devo poter stampare il parco
macchine e il valore totale delle auto presenti in concessionaria. Inoltre dato un modello, vedere i colori delle auto
presenti in concessionaria.
*/

public class Test {
    public static void main(String[] args) {
        Auto car = new Auto("lamborghini", "nero", 430.730);
        Concessionaria Lamborghini = new Concessionaria();

    }
}
