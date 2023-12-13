public class DVD extends Cassetta {
    private static double prezzo;
    private int nLingue;
    private TipoLingua[] lingue;
    private final static int MAX_LINGUE = 5;

    public DVD(String nome, String indirizzo, int nLingue) {
        super(nome, indirizzo);
        lingue = new TipoLingua[MAX_LINGUE];
        this.nLingue = nLingue;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public static void setPrezzo(double prezzo) {
        DVD.prezzo = prezzo;
    }

    void addLingua(Tipolingua lingua) {
        if (nLingue < MAX_LINGUE) {
            for (int cont = 0; cont < nLingue; cont++) {
                this.lingua[cont] = lingua;
                nLingue++;
            }
        }
    }

    public TipoLingua getLingue() {
        return lingue;
    }

    public void setLingue(TipoLingua lingue) {
        this.lingue = lingue;
    }

    public int getnLingue() {
        return nLingue;
    }

    public void setnLingue(int nLingue) {
        this.nLingue = nLingue;
    }
}
