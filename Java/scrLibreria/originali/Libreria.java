package originali;
import java.util.Vector;


public class Libreria {
    private Vector<Libro> libri;

    public Libreria() {
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

    @Override
    public String toString() {
        return "Libreria = " + libri ;
    }


}