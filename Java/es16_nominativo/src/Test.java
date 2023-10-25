/*
author: Noemi baruffolo
date: 24/10/2023
es: 16 nominativo
text:
Scrivere una classe Java Nominativo che possiede gli attributi cognome, nome, giorno mese e anno di nascita, sesso
e oltre ai soliti set/get e toString, anche i metodi:
• iniziali() che restituisce: le prime tre lettere del nome in minuscolo concatenate con le prime tre lettere del
cognome in maiuscolo. Utilizzare il metodo concat ed il metodo substring. Se non ci sono 3 lettere aggiungere
delle X finali.

• inizialiCF() che restituisce i primi 11 caratteri del Codice Fiscale in maiuscolo (cercare su internet le regole).
• eOmocodice (Nominativo altroNom) che restituisce true se l'oggetto su cui è invocato genera lo stesso CF
dell'oggetto altroNom passato per parametro
*/

public class Test {
    public static void main(String[] args) {
        Nominativo mio;

        mio = new Nominativo();

        mio.setNome("S");
        System.out.println("il nome è: " + mio.getNome());
        mio.setCognome("A");
        System.out.println("Il cognome è: " + mio.getCognome());
        mio.setSesso('F');
        System.out.println("Il sesso è: " + mio.getSesso());
        //mio.setNascita(15, 01, 2016);
        System.out.println("Il giorno di nascita è: " + mio.getGiorno() + " Il mese di nascita è: " + mio.getMese() + " L' anno di nascita è: " + mio.getAnno());

        System.out.println(mio.toString());

        System.out.println("le prime tre iniziali sono: " + mio.iniziali());

        System.out.println("Il codice fiscale è: " + mio.inizialiCF());

        Nominativo tuo = new Nominativo();

        tuo.setNome("Simone");
        tuo.setCognome("Arrigoni");
        tuo.setSesso('m');
        //tuo.setNascita(15, 11, 2019);

        if(mio.isOmocodice(tuo)){
            System.out.println("il codice fiscale è lo stesso");
        }else{
            System.out.println("Il codice fiscale non è lo stesso");
        }


    }
}