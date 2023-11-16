public class Veicolo {
    private int codice;
    private String targa;
    private String marca;
    private String modello;

    public Veicolo(int codice, String targa, String marca, String modello){
        if(codice > 0){
            this.codice = codice;
        } else{
            this.codice = 1;
        }
        this.targa = targa;
        this.marca = marca;
        this.modello = modello;
    }
    public void setTarga(String targa){

    }
    public String getTarga(){
        return targa;
    }
    public String getModello(){
        return modello;
    }
    public String toString(){
        String s = "";
        return s;
    }
}
