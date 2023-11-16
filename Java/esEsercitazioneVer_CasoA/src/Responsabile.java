public class Responsabile {
    private String nome;
    private String cognome;
    private String data;
    private String codiceFisc;
    private Autonoleggio[] autonoleggio;

    public Responsabile(){

    }
    public Responsabile(String nome, String cognome, String data, String codiceFisc){
        this.nome = nome;
        this.cognome = cognome;
        this.data = data;
        if(codiceFisc.length() == 16){
            this.codiceFisc = codiceFisc;
        } else{
            this.codiceFisc = "XXXXXXXXXXXXXXXX";
        }
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return nome;
    }
    public void setCognome(String cognome){
        this.cognome = cognome;
    }
    public String getCognome(){
        return cognome;
    }
    public void setData(String data){
        if(data != ""){
            this.data = data;
        } else{
            this.data = 1/1/1;
        }
    }
    public String getData(){
        return data;
    }
    public void setCodiceFIsc(String codiceFisc){
        if(codiceFisc.length() == 16){
            this.codiceFisc = codiceFisc;
        }
    }
    public String getCodiceFisc(){
        return codiceFisc;
    }
    public String toString(){
        String s = "";
        s = "Il tuo nome e': " + nome + "il suo cognome e': " + cognome + "la sua data di nascita e': " + data + "il suo codice fiscale e': " + codiceFisc;
        return s;
    }
}
