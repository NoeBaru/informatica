public abstract class Cassetta {
    private static int codice = 0;
    private int mioCodice;
    private String titolo;
    private int durataSec;
    private double sconto;
    private int nCopie;

    public Cassetta(String titolo, int durataSec) {
        this.titolo = titolo;
        if(durataSec > 0)
            this.durataSec = durataSec;
        else
            this.durataSec = 1;
        this.mioCodice = codice++;
        nCopie = 0;
        sconto = 0;
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
          if(nCopie >= 0)
            this.nCopie = nCopie;
    }

    public double getSconto() {
        return sconto;
    }

    public void setSconto(double sconto) {
        if(sconto >= 0)
            this.sconto = sconto;
    }
    public int getMioCodice() {
        return mioCodice;
    }

    public void setMioCodice(int mioCodice) {
        this.mioCodice = mioCodice;
    }

    public String toString() {
        return "mioCodice: " + mioCodice + ", titolo: " + titolo + ", durataSec: " + durataSec + ", sconto: " + sconto + ", nCopie: " + nCopie;
    }
}
