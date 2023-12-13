public class CD extends Cassetta{
    private static double prezzo;
    private int nBrani;

    public CD(String titolo, int durataSec, int nBrani) {
        super(titolo,durataSec);
        this.nBrani = nBrani;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public static void setPrezzo(double prezzo) {
        CD.prezzo = prezzo;
    }
    public duble getValoreNegozio()
        return ;
}
