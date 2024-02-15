public class Libro extends Articolo{
    private int numeroPagine;
    private String autori; //AUTORE SINGOLARE

    public Libro(String titolo, double valore, int numeroPagine, String autori) {
        super(titolo, valore);
        this.numeroPagine = numeroPagine;
        this.autori = autori;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }

    //NON CAMBIA
    public void setNumeroPagine(int numeroPagine) {
        this.numeroPagine = numeroPagine;
    }

    public String getAutori() {
        return autori;
    }

   //NON CAMBIA
    public void setAutori(String autori) {
        this.autori = autori;
    }
}
