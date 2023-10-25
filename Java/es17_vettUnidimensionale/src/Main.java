/*
author: Noemi Baruffolo
es: 17 vettore unidimensionale
date: 25/10/2023
text:
Utilizzate un array unidimensionale per risolvere questo problema: creare 20 numeri casuali compresi tra 10 e 100.
Per ogni numero creato, inseritelo solo se esso non è già stato immesso in precedenza.
*/

import java.util.Random;
public class Main {
    public static void main(String[] args) {
        int quant = 20;
        int[] numCasuale = new int[quant];
        int min = 10;
        int max = 100;

        Random rand = new Random();

        System.out.println("Ecco 20 numeri casuali tra 10 e 100:");

        for (int cont = 0; cont < quant; cont++) {
            if(cont == 1) {
                for (int j = 0; j < cont; j++) {
                    int numCasuale[cont] = rand.nextInt(max - min + 1) + min;
                    if (numCasuale[cont] == numCasuale[j]){
                        numCasuale[cont] = rand.nextInt(max - min + 1) + min;
                    }
                }
            }
            System.out.println(numCasuale);
        }

    }
}
