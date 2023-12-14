public class CD extends Cassetta{
    private static double prezzo;
    private int nBrani;

    public CD(String titolo, int durataSec, int nBrani) {
        super(titolo,durataSec);
        if(nBrani > 0)
            this.nBrani = nBrani;
    }

    public int getnBrani() {
        return nBrani;
    }

    public void setnBrani(int nBrani) {
        this.nBrani = nBrani;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public static void setPrezzo(double prezzo) {
        if(prezzo >= 0)
            CD.prezzo = prezzo;
    }
    public double getPrezzoScontato(){return prezzo - (prezzo/100) * getSconto();}

    public String toString() {
        return  super.toString() + "nBrani=" + nBrani;
    }
}
