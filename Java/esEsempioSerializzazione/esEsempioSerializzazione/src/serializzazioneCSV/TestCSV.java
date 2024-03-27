package serializzazioneCSV;

import originali.Autore;
import originali.Libreria;
import originali.Libro;

import java.io.File;
import java.io.IOException;

public class TestCSV {
    public static void main (String[] args) throws IOException {
        //nome del file in cui andare a salvare nella directory del progetto
        String nomeFile = "libri.csv";
        File f = new File(nomeFile);
        //est sarà = .bin per chi utilizza il file di byte
        //         = .json
        //         = .csv
        if (f.exists())
            System.out.println("\nIl file " + nomeFile + " esiste");

        if (f.createNewFile())
            System.out.println("Il file " + nomeFile + " è stato creato");
        else
            System.out.println("Il file " + nomeFile + " esiste già e non è stato creato");

        Autore collodi = new Autore("Carlo", "Collodi");
        Autore perrault = new Autore("Charles","Perrault");

        Libro l1 = new Libro("Pinocchio", collodi, 150);
        Libro l2 = new Libro("Pollicino", perrault, 80);
        Libro l3 = new Libro("La bella addormentata nel bosco", perrault, 50);

        //instanziare un tipo di libreria appropriato
        LibreriaCSV libreria = new LibreriaCSV();
        // inserimento volumi
        libreria.addVolume(l1);
        libreria.addVolume(l2);
        libreria.addVolume(l3);
        //cambio il prezzo a pagina
        Libro.setCostoPagina(0.01);
        System.out.println(libreria);

        // SERIALIZZAZIONE salvataggio libreria su file METODO DA IMPLEMENTARE
        libreria.salvaSuFile (nomeFile);

        // creazione nuova libreria vuota
        LibreriaCSV l = new LibreriaCSV();
        System.out.println("Prima " + l);
        // DESERIALIZZAZIONE caricamento libreria da file METODO DA IMPLEMENTARE
        l.caricaDaFile("libreria.csv");
        System.out.println(l.toString());
    }
}
