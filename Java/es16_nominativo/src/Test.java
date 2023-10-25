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
        Nominativo nominativo = new Nominativo("Rossi", "Mario", 15, 6, 1980, 'M');
        System.out.println(nominativo.toString());
        System.out.println("Iniziali: " + nominativo.iniziali());
        System.out.println("Iniziali CF: " + nominativo.inizialiCF());
    }

}
