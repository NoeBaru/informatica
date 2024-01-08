/*
author: Noemi Baruffolo
es: 27 Ereditarietà
text: Creare una classe VettoriInteri che:
• Metodo costruttore con parametro un numero corrispondente alla dimensione desiderata che inizializza tutti gli elementi a 0
• Metodo costruttore che riceve una stinga con gli elementi separati dalla "|" e carica il vettore con essi dimensionandolo della lunghezza giusta. Se nella stringa ci sono dei dati non corretti deve generare una eccezione NumberFormatException
• Abbia un metodo che ritorna l’elemento minimo di un array, se il vettore è vuoto solleva l’eccezione personalizzata non controllata ErroreVettoreVuoto
• Metodo che cerca un elemento nell’array e ritorna la posizione (se l’elemento non esiste solleva l’eccezione controllata personalizzata ErroreElementoInesistente)
• Metodo che elimina la prima occorrenza nell’array, dato un numero (se l’elemento non esiste solleva l’eccezione controllata personalizzata ErroreElementoInesistente
• Metodo toString() che restituisce gli elementi separati da "|"
*/
public class TestNonControllato{
    public static void main(String[] args) throws ErroreVettorePieno { //si pianta e dice perché (non ottimale, meglio controllare sempre, vedi classe Test)
        VettoriInteri v = new VettoriInteri(1);
        v.add(6);
        v.add(8);
    }
}
