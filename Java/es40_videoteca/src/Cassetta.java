public abstract class Cassetta {
    private static int codice;
    private int mioCodice;
    private String titolo;
    private int durataSec;
    private double sconto;
    private int nCopie;

    public Cassetta(String titolo, int durataSec) {
        this.titolo = titolo;
        this.durataSec = durataSec;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public int getDurataSec() {
        return durataSec;
    }

    public void setDurataSec(int durataSec) {
        this.durataSec = durataSec;
    }


    public static void setCodice(int codice) {
        Cassetta.codice = codice;
    }

    public static int getCodice() {
        return codice;
    }

    public int getnCopie() {
        return nCopie;
    }

    public void setnCopie(int nCopie) {
        this.nCopie = nCopie;
    }

    public double getSconto() {
        return sconto;
    }

    public void setSconto(double sconto) {
        this.sconto = sconto;
    }

    public String toString() {
        return "Cassetta" + "mioCodice: " + mioCodice + ", titolo: " + titolo + ", durataSec: " + durataSec + ", sconto: " + sconto + ", nCopie: " + nCopie;
    }
}
