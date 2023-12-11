public class Lavoratore {
    private String nome;
    private int livello;
    private final static int MIN_LIVELLO = 1;
    private final static int MAX_LIVELLO = 5;
    private final int MIN_STIPENDIO = 0;
    private float stipendio;
    public Lavoratore(String nome, int livello){
        this.nome = nome;
        if(livello >= MIN_LIVELLO && livello < MAX_LIVELLO)
            this.livello = livello;
        else
            livello = MIN_LIVELLO;
        stipendio = MIN_STIPENDIO;
    }
    public String getNome(){return nome;}
    public void setLivello(int livello){
        if(livello >= MIN_LIVELLO && livello < MAX_LIVELLO)
            this.livello = livello;
        else
            livello = MIN_LIVELLO;
    }
    public int getLivello(){return livello;}
    public float getStipendio(){return stipendio;}

    public void setStipendio(float stipendio) {
        if(stipendio > 0)
            this.stipendio = stipendio;
    }

    //public String toString(){return "nome" + nome + "livello" + livello;}
}
