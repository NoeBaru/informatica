public class Nominativo {
    private String cognome;
    private String nome;
    private int giorno;
    private int mese;
    private int anno;

    public boolean omocodice;

    private final int ANNO_ATTUALE = 2023;
    private char sesso;

    public Nominativo(String cognome, String nome, int giorno, int mese, int anno, char sesso) {
        this.cognome = cognome;
        this.nome = nome;
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
        this.sesso = sesso;
    }
    public void setNomeCognome(){

    }
    public String getNomeCognome(){
        return cognome;
    }
    public void setSesso(){

    }
    public String getSesso(){
        return sesso;
    }
    public void setData(){

    }
    public String getNomeCognome() {
        return nome + " " + cognome;
    }

    public char getSesso() {
        return sesso;
    }

    public String getDataDiNascita() {
        return "data: " + giorno + "/" + mese + "/" + anno);
    }
    public char iniziali(){
        return inizialiNome + inizialiCognome;
    }
    public char IniziailiCF() {

        return inizialiCognome + inizialiNome + dataNascita;
    }
    public boolean eOmocodice(Nominativo nome){

        return this.inizialiCF().equals(nome.inizialiCF());

    }

    public String toString(){
        return "Nome: " + nome + "\nCognome: " + cognome + "\nData di Nascita: " + getDataDiNascita() + "\nSesso: " + sesso;
    }
}
