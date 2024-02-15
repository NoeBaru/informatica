public abstract class Articolo {
    private int idArticolo;
    private String titolo;
    private double valore;
    private Utente inPrestitoA;
    private static int progressivoArticolo = 0;

    public Articolo(String titolo, double valore){
        this.titolo = titolo;
        this.valore = valore;
        idArticolo = progressivoArticolo;
        progressivoArticolo++;
    }

    public int getIdArticolo() {
        return idArticolo;
    }

    public String getTitolo() {
        return titolo;
    }

    public double getValore() {
        return valore;
    }

    public Utente getInPrestitoA() {
        return inPrestitoA;
    }

    public static int getProgressivoArticolo() {
        return progressivoArticolo;
    }

    public void setIdArticolo(int idArticolo) {
        this.idArticolo = idArticolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public void setValore(double valore) {
        this.valore = valore;
    }

    public void setInPrestitoA(Utente inPrestitoA) {
        this.inPrestitoA = inPrestitoA;
    }

    public static void setProgressivoArticolo(int progressivoArticolo) {
        Articolo.progressivoArticolo = progressivoArticolo;
    }
}
