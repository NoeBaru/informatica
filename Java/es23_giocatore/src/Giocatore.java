public class Giocatore {
    private String nome;
    private double punteggio;
    private int eta;
    private Ruolo ruolo;
    private final int VALORE_MIN = 1;
    private final int VALORE_MAX = 10;

    public Giocatore(String nome, int eta, Ruolo ruolo){
        this.nome = nome;
        if(eta > 0) {
            this.eta = eta;
        }
        this.punteggio = VALORE_MIN;
        this.ruolo = ruolo;
    }

    public Giocatore(String nome, int eta, double valore, Ruolo ruolo){
        this.nome = nome;
        if(eta > 0) {
            this.eta = eta;
        }
        if(valore > VALORE_MIN && valore < VALORE_MAX) {
            this.punteggio = valore;
        } else{
            this.punteggio = VALORE_MIN;
        }
        this.ruolo = ruolo;
    }
    public String getNome(){
        return nome;
    }

    public double getPunteggio(){
        return punteggio;
    }

    public void setPunteggio(double nPunt){
        if(nPunt > VALORE_MIN && nPunt < VALORE_MAX) {
            this.punteggio = nPunt;
        } else{
            this.punteggio = VALORE_MIN;
        }
    }

    public int getEta(){
        return eta;
    }

    public void setEta(int nEta){
        if(nEta > 0) {
            this.eta = nEta;
        }
    }
    public void setRuolo(Ruolo ruolo){
        this.ruolo = ruolo;
    }
    public Ruolo getRuolo(){
        return ruolo;
    }

    public String toString(){
        return "nome:" + nome + " pt: " + punteggio + " età: " + eta + "ruolo: " + ruolo;
    }

}
