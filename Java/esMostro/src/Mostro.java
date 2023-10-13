public class Mostro {
    private String nome;
    private int vita;
    private int forza;

    private static final int MIN_VITA = 0;
    private static final int MAX_VITA = 100;
    private static final int MIN_FORZA = 5;
    private static final int MAX_FORZA = 10;

    public Mostro(String nome, int forza, int vita){
        this.nome = nome; //this rappresenta l'oggetto su cui si sta applicando il metodo
        if (forza >= MIN_FORZA&& forza <= MAX_FORZA){
            this.forza = forza;
        } else
            this.forza = MIN_FORZA
        this.vita = vita;
    }
    public String toString() { //over reading, riscrittura di un metodo che già esiste
    return nome + ": forza = " + forza + ", vita = " + vita ; //restituisce nome, vita e forza del mostro
    }
}
