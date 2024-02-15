/*
author/: Noemi Baruffolo
date: 8/02/2024
es: succursale biblioteca
*/

public class Test {
    public static void main(String[] args) {
        Succursale s = new Succursale("Cuneo", "CorsoNizza");
        s.addScaffale(TipoArticolo.LIBRO, 25);
        s.addScaffale(TipoArticolo.LIBRO, 25);
        s.addScaffale(TipoArticolo.DVD, 25);
        s.addScaffale(TipoArticolo.DVD, 25);
        Libro l1 = new Libro("HarryPotter", 19.99, 200, "JKRowling");
        Libro l2 = new Libro("HarryPotter2", 19.99, 200, "JKRowling");
        DVD dvd1 = new DVD("Avatar", 29.99, 250, "Marvel"+"Boh"); //DEVI CREARE UN VETTORE DI STRINGHE
        DVD dvd2 = new DVD("Avatar2", 29.99, 250, "Marvel"+"boh");
        s.addArticolo(l1);
        s.addArticolo(l2);
        s.addArticolo(dvd1);
        s.addArticolo(dvd2);
        System.out.println(s.elencoArticoli());
        System.out.println(s.valoreComplessivo());
        Utente u1 = new Utente("BRE", "Noemi", "baruffolo");
        Utente u2 = new Utente("BRF", "Noemi", "baruffolo");
        Utente u3 = new Utente("BRG", "Noemi", "baruffolo");
        s.presta(u1.getCodiceFiscale(), l1.getIdArticolo());
        s.presta(u2.getCodiceFiscale(), l2.getIdArticolo());
        s.restituisci(l2.getIdArticolo());
    }
}
