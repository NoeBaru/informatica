public class Libro extends Articolo{
    private int numeroPagine;
    private String autore;

    public Libro(String titolo, double valore, int numeroPagine, String autore) {
        super(titolo, valore);
        this.numeroPagine = numeroPagine;
        this.autore = autore;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }


    public String getAutore() {
        return autore;
    }
}
