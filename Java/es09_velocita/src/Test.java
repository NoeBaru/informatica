/*
author: Noemi Baruffolo 4^AROB
date: 19/10/2023
es: 09 velocità
text: Dichiarare una classe di nome “velocita” che ha come attributo la velocità in km/h (velKmH). Possiede solo il
costruttore senza parametri che inizializza la velocità a 0. Definire i 4 metodi get e set che restituiscono/impostano
la velocità in Km/h o in m/s.*/


public class Test {
    public static void main(String[] args) {
        Velocita misurazione;
        misurazione = new Velocita();
        System.out.println(misurazione.toString());
        misurazione.setVelKmH(10);
        System.out.println(misurazione.toString());
        misurazione.setVelMperS(10);
        System.out.println(misurazione.toString());
    }
}
