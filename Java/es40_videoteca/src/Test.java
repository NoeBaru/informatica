/*
author: Noemi Baruffolo 4^AROB
es: 40 videoteca
date: 13/12/2023
text: Si vogliono gestire delle videoteche, che commerciano film in DVD e CD musicali. Il prezzo dei DVD è unico per tutti i DVD, lo stesso per i CD.
Ogni cassetta ha un codice numerico gestito in automatico dal sistema, può avere o meno uno sconto da applicare al prezzo base (inizialmente 0), ha una
durata complessiva in secondi e un numero di copie presenti in negozio (questa quantità inizialmente è 0, ma si modifica di 1 vendendo o comprando delle copie con i
rispettivi metodi). I DVD sono caratterizzati dalle lingue possibili per il film (al massimo 5), che vengono aggiunte con il metodo addLingua() e sono visualizzabili
con il metodo getLingue(). I CD sono caratterizzati dal numero di brani presenti. Si vuole in ogni momento conoscere il valore complessivo delle cassette presenti in
negozio con il metodo getValoreNegozio() (tenendo conto del numero di copie e degli eventuali sconti). Questa realtà è rappresentata dal seguente UML. Aggiungere le
eccezioni necessarie. Realizzare una classe Test in cui si istanzia una videoteca con almento 2 DVD e 2 CD, si vendano e si comprino delle cassette e si visualizzi
il valore complessivo
*/
public class Test {
    CD c1 = new CD("Ciao", 120, 10);
    CD.setPrezzo(49.99);
    System.out.println(c1);
    DVD d1 = new DVD("Tarzan", 7200);
    d1.addLingua(TipoLingua.ITA);
    d1.addLingua(TipoLingua.ITA);
    System.out.println(c1);
    VideotecaVector v1 = new VideotecaVector("Baruffolo", "ViaRoma");
    v1.add(c1);
    v1.add(d1);
    System.out.println(v1.getValoreNegozio());
    v1.compro(1);
    v1.vendo(0);
}
