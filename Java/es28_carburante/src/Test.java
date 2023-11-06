/*
author: Noemi Baruffolo 4^AROB
es: 28 carburante
date: 3/11/2023
text: Dichiarare una classe di nome Carburante che ha come attributi: prezzo float e un tipo che può essere "benzina",
"diesel", "GPL", "metano" (utilizzare un vettore opportuno che contiene i valori possibili o un'enum). I metodi sono:
• Costruttore vuoto che imposta tipo= "benzina" prezzo = 1.5
• Costruttore con i due attributi (controlla il valore del prezzo)
• Set/get di tutti gli attributi
• equals(carburante c) che restituisce true se il carburante su cui è applicato il metodo ha lo stesso prezzo del
carburante c passato come parametro
• toString()
Creare anche la classe Distributore che contiene più pompe di carburante. Ha come attributo il nome e l'indirizzo e il
vettore con le pompe di carburante. Realizzare i metodi;
• add(Carburante),
• i set/get opportuni e il toString()
• aumenta(tipo, percentuale) che aumenta il carburante di quel tipo della percentuale indicata
• getStatistiche() che stampa il prezzo min, max e il medio tra i carburanti del distributore.
*/

public class Test {
    public static void main(String[] args) {
        Carburante c1 = new Carburante();
        System.out.println(c1.toString());


    }

}
