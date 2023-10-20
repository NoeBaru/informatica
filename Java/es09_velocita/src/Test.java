/*
author: Noemi Baruffolo 4^AROB
date: 19/10/2023
es: 09 velocità
text: Dichiarare una classe di nome “velocita” che ha come attributo la velocità in km/h (velKmH). Possiede solo il
costruttore senza parametri che inizializza la velocità a 0. Definire i 4 metodi get e set che restituiscono/impostano
la velocità in Km/h o in m/s.*/


public class Test {
    public static void main(String [] args){
        Velocita velKmH;
        velKmH = new Velocita();
        velKmH.setVelKmH(44);
        System.out.println(velKmH.getVelKmH());
        Velocita velMs;
        velMs = new Velocita();
        velMs.setVelMs(velKmH.getVelKmH());
        System.out.println(velMs.getVelMs());
    }
}
