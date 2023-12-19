public class Libro {
    private String titolo;
    private String autore;
    private Generi genere;
    private int numP;
    private float prezzovendita;
    private static final int PAGINE_DEF = 100;
    private static final float PREZZO_DEF = 9.99f;

    public Libro(String titolo, String autore, Generi genere, int numP, float prezzovendita) {
        this.titolo = titolo;
        this.autore = autore;
        this.genere = genere;
        if(numP < 0)
            this.numP = PAGINE_DEF;
        else
            this.numP = numP;
        this.prezzovendita = prezzovendita;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public Generi getGenere() {
        return genere;
    }

    public int getNumP() {
        return numP;
    }

    public float getPrezzovendita() {
        return prezzovendita;
    }

    public void setPrezzovendita(float prezzovendita) {
        if(prezzovendita >= 0)
            this.prezzovendita = prezzovendita;
    }

    public int compareTo(Libro l){
        int ris;
        float prezzoP1 = 0.0f;
        float prezzoP2 = 0.0f;
        prezzoP1 = prezzovendita / numP;
        prezzoP2 = l.getPrezzovendita()/l.getNumP();

        if(prezzoP1 > prezzoP2)
            ris = 1;
        else if (prezzoP1 == prezzoP2)
            ris = 0;
        else ris = -1;
        return ris;
    }

    public String toString() {
        return "titolo: " + titolo +
                " autore: " + autore +
                " genere: " + genere +
                " numP: " + numP +
                " prezzovendita: " + prezzovendita;
    }
}
