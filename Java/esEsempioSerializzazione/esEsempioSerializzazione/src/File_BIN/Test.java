package File_BIN;

import java.io.IOException;

public class Test {
    public static void main (String[] args) throws IOException {
        //nome del file in cui andare a salvare nella directory del progetto
        String nomeFile = "libreria.bin";
        //est sarà = .bin per chi utilizza il file di byte
        //         = .json
        //         = .csv

        Autore collodi = new Autore("Carlo", "Collodi");
        Autore perrault = new Autore("Charles","Perrault");

        Libro l1 = new Libro("Pinocchio", collodi, 150);
        Libro l2 = new Libro("Pollicino", perrault, 80);
        Libro l3 = new Libro("La bella addormentata nel bosco", perrault, 50);

        //instanziare un tipo di libreria
        LibreriaBIN libreria = new LibreriaBIN();
        // inserimento volumi
        libreria.addVolume(l1);
        libreria.addVolume(l2);
        libreria.addVolume(l3);
        //cambio il prezzo a pagina
        Libro.setCostoPagina(0.01);
        System.out.println(libreria);

        // SERIALIZZAZIONE salvataggio libreria su file METODO DA IMPLEMENTARE
        libreria.salvaSuFile (nomeFile);

        Libro.setCostoPagina(1); //non mantiene il vecchio valore
        // creazione nuova libreria vuota
        LibreriaBIN l = new LibreriaBIN();
        System.out.println("Prima " + l);
        // DESERIALIZZAZIONE caricamento libreria da file METODO DA IMPLEMENTARE
        l.caricaDaFile(nomeFile);
        System.out.println("Dopo: " + l);
    }
}
