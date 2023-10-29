/*
author: Noemi Baruffolo 4^AROB
es: 20 Dado
date: 26/10/2023
text: Creare la classe Dado e la classe Secchiello che contiene N dadi. Simulare il lancio dei dadi
di un secchiello in grado di visualizzare i valori usciti e la loro somma. Deve essere possibile, per ogni dado
stabilire il numero di facce di un dado.
*/
public class Test {
    public static void main(String[] args) {
        Dado dado1 = new Dado();
        Dado dado2 = new Dado(10);

        dado1.lanciaDado();
        System.out.println("dado1:" + dado1.getLancio());

        dado2.lanciaDado();
        System.out.println("dado2:" + dado2.getLancio());

        Secchiello sec1 = new Secchiello(2);
        sec1.add(dado1);
        sec1.add(dado2);
        sec1.lancio();
        System.out.println("sec1:" + sec1);
    }
}
