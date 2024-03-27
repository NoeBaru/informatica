package serializzazioneCSV;

import originali.Autore;
import originali.Libreria;
import originali.Libro;

import java.io.*;
import java.util.Vector;

public class LibreriaCSV extends Libreria {
    private Vector<Libro> libri;
    private static final String INTESTAZIONE1 = "CostoPaginaFisso\n";
    private static final String INTESTAZIONE2 = "Titolo,Nome,Cognome,NumeroPagine\n";
    private static final char SEPARATORE = ',';
    public LibreriaCSV() {
        libri = new Vector<Libro>();
    }

    public void addVolume(Libro libro) {
        libri.add(libro);
    }

    //metodi necessari per la deserializzazione
    public Vector<Libro> getLibri() {
        return libri;
    }

    public void setLibri(Vector<Libro> libri) {
        this.libri = libri;
    }

    public float getValore(){
        float tot = 0;
        for(Libro l: libri){
            tot += l.getPrezzo();
        }
        return tot;
    }

    public void salvaSuFile(String nomeFile) throws IOException {
        FileWriter fw = new FileWriter(nomeFile);
        fw.write(INTESTAZIONE1);
        fw.write(Libro.getCostoPagina() + "\n");
        fw.write(INTESTAZIONE2);
        for(Libro l: libri) {
            fw.write(l.getTitolo() + SEPARATORE +
                    l.getAutore() + SEPARATORE +
                    l.getPrezzo() + "\n");
        }
        fw.close();
    }

    public void caricaDaFile(String nomeFile) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(nomeFile));
        String s = "";
        String[] line = null;
        if(br.readLine().equals(INTESTAZIONE1)) {
            s = br.readLine();
            Libro.setCostoPagina(Double.parseDouble(s));
            if(br.readLine().equals(INTESTAZIONE2)) {
                s = br.readLine();
                while (s != null) {
                    line = s.split(String.valueOf(SEPARATORE));
                    String titolo = line[0];
                    String nomeAutore = line[1];
                    String cognomeAutore = line[2];
                    int numeroPagine = Integer.parseInt(line[3]);
                    Autore autore = new Autore(nomeAutore, cognomeAutore);
                    Libro libro = new Libro(titolo, autore, numeroPagine);
                    libri.add(libro);
                    s = br.readLine();
                }
            } else {
                System.out.println("file non corretto");
            }
        } else {
            System.out.println("file non corretto");
        }
    }

    @Override
    public String toString() {
        return "Libreria = " + libri ;
    }
}
