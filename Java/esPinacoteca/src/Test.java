/*
author: Noemi Baruffolo 4AROB
date: 30/11/2023
es: Pinacoteca
Text: Fare l’UML con i soli attributi e le relazioni e creare un'applicazione JAVA per
gestire delle pinacoteche. Tutti i quadri possiedono: titolo, autore, tecnica (olio, acquerello, carboncino,…), valore assicurato. Le pinacoteche hanno un nome, un numero massimo di quadri contenuti.
Per le classi prevedere:
· Non il costruttore vuoto, solo costruttori con tutti i parametri che ritieni necessari, giustificando la scelta
· Tutti i metodi set e get che ritieni necessari, giustificando la scelta
· il metodo toString() per tutte le classi (con  valore complessivo)
· il metodo isParagonabile(Quadro q) in Quadro, che restituisce true se il quadro su cui è invocato ha lo stesso prezzo ed è dello stesso tipo (1)
in Pinacoteca i metodi:
i. add(Quadro q) che aggiunge un QUADRO (2)
ii. setPrezzo (titolo, perc) che aumenta il prezzo del quadro con quel titolo di quella
percentuale (2)
iii. double getValoreMedio() per ottenere il valore medio dei quadri della
pinacoteca (1)
*/

public class Test {
    public static void main(String[] args) {
        Quadro q1 = new Quadro();
        Quadro q2 = new Quadro();
        Pinacoteca p1 = new Pinacoteca();
        p1.add(q1);
        System.out.println(p1.toString());

    }
}
