package serializzazioneJSON;

import originali.Libreria;

import java.io.FileWriter;

public class LibreriaJSON extends Libreria {
    public LibreriaJSON() {
    }

    public void salvaSuFile(String nomeFile) throws IOException {
        FileWriter fw = new FileWriter(nomeFile, false);
        char virgolette = '"';
        fw.write("{" + virgolette + "libri" + virgolette + ": [");
        for(originali.Libro l : getLibri()){
            if(l.equals(getLibri().lastElement())){
                fw.write("{" + virgolette + "titolo"+ virgolette + ": " + virgolette + l.getTitolo() + virgolette + "," +
                        virgolette + "autore" + virgolette + ": {"+ virgolette +"nome" + virgolette + ": " + virgolette + l.getAutore().getNome() + virgolette + "," +
                        virgolette + "cognome" + virgolette + ": " + virgolette + l.getAutore().getCognome() + virgolette + "}," +
                        virgolette + "numeroPagine" + virgolette + ": " + virgolette + l.getNumeroPagine() + virgolette + "}"
                );
            }else{
                fw.write("{" + virgolette + "titolo"+ virgolette + ": " + virgolette + l.getTitolo() + virgolette + "," +
                        virgolette + "autore" + virgolette + ": {"+ virgolette +"nome" + virgolette + ": " + virgolette + l.getAutore().getNome() + virgolette + "," +
                        virgolette + "cognome" + virgolette + ": " + virgolette + l.getAutore().getCognome() + virgolette + "}," +
                        virgolette + "numeroPagine" + virgolette + ": " + virgolette + l.getNumeroPagine() + virgolette + "}, "
                );
            }

        }
        fw.write("]}");
        fw.close();
    }
}
