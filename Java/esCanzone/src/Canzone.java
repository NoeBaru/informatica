public class Canzone {
    private String titolo;
    private String autore;
    private int durataSec;

    public Canzone(String titolo, String autore, int durataSec) {
        this.titolo = titolo;
        this.autore = autore;
        //da controllare
        this.durataSec = durataSec;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public int getDurataSec() {
        return durataSec;
    }

    @Override
    public String toString() {
        return "titolo: " + titolo + '\'' +
                "autore: " + autore + '\'' +
                " durataSec: " + durataSec;
    }
}
