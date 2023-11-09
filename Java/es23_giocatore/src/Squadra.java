public class Squadra {
    private String nome;
    private int nGiocatori;
    private Giocatore[] giocatori;
    private final int N_MAX_GIOCATORI = 30;

    public Squadra(String nome){
        this.nome = nome;
        giocatori = new Giocatore[N_MAX_GIOCATORI];
        nGiocatori = 0;
    }

    public void addGiocatore(Giocatore g){
        if(nGiocatori < N_MAX_GIOCATORI) {
            giocatori[nGiocatori] = g;
            nGiocatori++;
        }
    }

    public void setPunteggio(String nome, double punteggio){
        for(int cont = 0; cont < nGiocatori; cont++) {
            if(nome.equals(giocatori[cont].getNome())) {
                giocatori[cont].setPunteggio(punteggio);
            }
        }
    }

    public double getPunteggioMedio(){
        double somma = 0;
        double media;
        for(int cont = 0; cont < nGiocatori; cont++) {
            somma += giocatori[cont].getPunteggio();
        }
        media = somma/nGiocatori;

        return media;
    }

    public void passatoAnno(){
        for(int cont = 0; cont < nGiocatori; cont++) {
            giocatori[cont].setEta(giocatori[cont].getEta() + 1);
        }
    }
    public String toString(){
        String s = "nome: " + nome + "\n";
        for(int cont = 0; cont < nGiocatori; cont++) {
            s += giocatori[cont].toString() + "\n";
        }
        return s;
    }
}
