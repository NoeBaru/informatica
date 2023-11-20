/*
author: Noemi Baruffolo
date: 13/11/2023
es: esercitazione verifica caso A
text: Un oggetto della classe AgendaTelefonica permette di gestire una semplice agenda (rubrica) telefonica. Ogni utenza dell’agenda ha un nome,
un cognome, un numero di telefono e un'email facoltativa. L’agenda può gestire un numero limitato di utenze. Tale
numero deve essere scelto all’atto della creazione di un oggetto della classe AgendaTelefonica.
La classe ha il seguente scheletro:

Scrivere il corpo dei metodi della classe AgendaTelefonica. Scrivere inoltre una classe di test
che:
1 Permette all’utente di creare un’agenda di dimensione a sua scelta;
2. Inserimento di una nuova utenza nell’agenda;
3. Ricerca di una nuova utenza nell’agenda;
4. Visualizzazione di tutte le utenze dell’agenda
*/
public class Test{
    public static void main(String[] args) {
        AgendaTelefonica a = new AgendaTelefonica(5);

        a.inserisciUtenza("Mattia", "Bianchi", "123456789", "mattia@email.com");
        a.inserisciUtenza("Anna", "Verdi", "987654321", "anna@email.com");
        a.inserisciUtenza("Martina", "Rossi", "111222333", "martina@email.com");
        a.inserisciUtenza("Noemi", "Neri", "444555666", "noemi@email.com");

        if (a.cercaUtenza("Mattia", "Bianchi") == null) {
            System.out.println("Utenza non trovata:");
        } else {
            System.out.println("Utenza trovata.");
        }

        System.out.println(a.toString());
    }
}


