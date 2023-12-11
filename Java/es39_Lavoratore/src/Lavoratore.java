public class Lavoratore {
    private String nome;
    private int livello;
    private final static int MIN_LIVELLO = 1;
    private final static int MAX_LIVELLO = 5;
    private float stipendio;
    public Lavoratore(String nome, int livello){
        this.nome = nome;
        this.livello = livello;
    }
    public String getNome(){return nome;}
    public int getLivello(){return livello;}
    public float getStipendio(){return stipendio}
    public String toString(){return "nome" + nome + "livello" + livello;}
}
