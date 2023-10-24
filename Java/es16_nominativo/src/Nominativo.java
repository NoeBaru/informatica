public class Nominativo {
    private char cognome;
    private char nome;
    private int giorno;
    private int mese;
    private int anno;

    public boolean omocodice;

    private final int ANNO_ATTUALE = 2023;
    private char sesso;

    public Nominativo(){

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
    public int getData(){
        return giorno + mese + anno;
    }
    public char iniziali(){
        return caratteri;
    }
    public char IniziailiCF() {
        return inizialiCF;
    }
    public boolean eOmocodice(){
        return omocodice;
    }
}
