public class Auto {
    public String modello;
    public String colore;
    public float prezzo;
    private static final String[] coloriDisponibili = {"rosso", "nero", "grigio", "bianco"};

    public Auto(String modello, String colore, float prezzo){
        this.modello = modello;
        if(this.colore != coloriDisponibili) {
            this.colore = "grigio";
        }else{
            this.colore = colore;
        }
        this.prezzo = prezzo;
    }
    private void setModello(){

    }
    private void setColore(){

    }
    private void setPrezzo(){

    }
    private float getPrezzo(){
        return prezzo;
    }
    private String getModello(){
        return modello;
    }
    private String getColore(){
        return colore;
    }
    private String toString() {
        return ;
    }
}
