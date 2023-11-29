public class Giocatore {
    private String nome;
    private double punteggio;
    private int eta;
    private Ruolo ruoli;
    private final int VALORE_MIN = 1;
    private final int VALORE_MAX = 10;

    public Giocatore(String nome, int eta, Ruolo ruoli){
        this.nome = nome;
        if(eta > 0) {
            this.eta = eta;
        }
        this.punteggio = VALORE_MIN;
        this.ruoli = ruoli;
    }

    public Giocatore(String nome, int eta, double valore, Ruolo ruoli){
        this.nome = nome;
        if(eta > 0) {
            this.eta = eta;
        }
        if(valore > VALORE_MIN && valore < VALORE_MAX) {
            this.punteggio = valore;
        } else{
            this.punteggio = VALORE_MIN;
        }
        this.ruoli = ruoli;
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
    public void setRuolo(Ruolo ruoli){
        this.ruoli = ruoli;
    }
    public Ruolo getRuolo(){
        return ruoli;
    }

    public String toString(){
        return "nome:" + nome + " pt: " + punteggio + " età: " + eta + "ruolo: " + ruoli;
    }

}
