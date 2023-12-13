public class DVD extends Cassetta {
    private static double prezzo = 0.0;
    private int nLingue;
    private TipoLingua[] lingue;
    private final static int MAX_LINGUE = 5;

    public DVD(String nome, int durataSec) {
        super(nome, durataSec);
        lingue = new TipoLingua[MAX_LINGUE];
        nLingue = 0;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public static void setPrezzo(double prezzo) {
        if(prezzo >= 0)
            DVD.prezzo = prezzo;
    }
    private int cercaLingua(TipoLingua l){
        int cont = 0;
        int tro = -1;
        while(tro == -1 && cont < nLingue){
            if(lingue[cont].equals(l))
                tro = cont;
            cont++;
        }
        return tro;
    }

    void addLingua(TipoLingua l) {
        if(lingue != null){
            if (nLingue < MAX_LINGUE) {
                lingue[nLingue] = l;
                nLingue++;
            }
        }

    }

    public String getLingue() {
        String s = "";
        for(int cont = 0; cont <nLingue; cont++){
            s += lingue[cont];
        }
        return s;
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
