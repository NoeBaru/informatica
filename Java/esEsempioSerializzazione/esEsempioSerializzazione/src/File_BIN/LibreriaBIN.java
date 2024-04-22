package File_BIN;

import java.io.*;
import java.util.Vector;

public class LibreriaBIN extends Libreria implements Serializable{
    //Devo rendere tutte le classi serializable

    //funzione per il caricamneto da file DESERIALIZZAZIONE
    public void caricaDaFile(String nomeFile) throws IOException {
        ObjectInputStream objectInputStream = new ObjectInputStream(
                new FileInputStream(nomeFile));
        try {
            LibreriaBIN l = (LibreriaBIN) objectInputStream.readObject();
            this.setLibri(l.getLibri());
        } catch (ClassNotFoundException e) { //se nel file è stata salvato
            // un'oggetto di un'altra classe
            System.out.println("Classe inesistente");
        }catch (IOException e){
            System.out.printf("File non trovato\n");
        } finally { //clausola eseguita sia che ci sia stata un'eccezione o no
            try {
                // se tutto va a buon fine chiudo lo stream
                if (objectInputStream != null)
                    objectInputStream.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    //funzione per la scrittura su file SERIALIZZAZIONE
    public void salvaSuFile(String nomeFile) throws IOException {
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(
                new FileOutputStream(nomeFile));

        objectOutputStream.writeObject(this);
        objectOutputStream.close();
    }
}
