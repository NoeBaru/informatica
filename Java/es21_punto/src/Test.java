/*
author: Noemi Baruffolo 4^AROB
es: 21 Punto
date: 30/10/2023
text: Creare la classe Punto caratterizzata dai valori delle sue coordinate. Possiede, oltre ai set/get e al toString(), il
costruttore senza parametri che inizializza le coordinate a 0 e un costruttore con due parametri. Creare quindi la
classe Figura che ha come attributo il nome e il numero di vertici. Deve essere possibile aggiungere i suoi vertici e
ottenere il valore del suo perimetro.
*/

public class Test {
    public static void main(String[] args) {
        Punto p1 = new Punto();
        System.out.println(p1.toString());

        Punto p2 = new Punto(2, 5);

        Figura f1 = new Figura("triangolo", 3);
        f1.add(p1);
        f1.add(p2);
        System.out.println("Il suo perimetro e': " + f1.getPerimetro());
        f1.add(new Punto(4, 8)); //se non uso p3 come nome
        System.out.println(f1.toString());
        System.out.println("Il perimetro f1 e': " + f1.getPerimetro());

        //prova con un segmento
        Figura f2 = new Figura("segmento", 2);
        f2.add(new Punto());
        f2.add(new Punto(0,1));
        System.out.println("Il perimetro della f2 e': " + f2.getPerimetro());
    }
}
