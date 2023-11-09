public class Carburante {
    public float prezzo;
    public String tipo;
    private TipoCarburante tipoC;
    private final static String[] POS_TIPI = ["benzina", "diesel", "GPL", "metano"];
    private final static TipoCarburante DEFAULT_TIPO_C = TipoCarburante.BENZINA;
    private final static String DEFAULT_TIPO = "benzina"; //static costante condiviso per tutti, SENZA ENUM
    private final static float DEFAULT_PREZZO = 1.3f; //ci va la f sennò lo prende come double
    public final int MAX = 10;
    public Carburante(){
        tipo = DEFAULT_TIPO;
        tipoC = DEFAULT_TIPO_C;
        prezzo = DEFAULT_PREZZO;
    }
    private int isTipo(){
    int cont = 0;
    int tro = 0;
        while(cont < POS_TIPI.length && tro == -1){
            if(tipo.equals(POS_TIPI[k])) {
                tro = cont;
            }
            cont++;
        }
        return tro;
    }

    public Carburante(String tipo, float prezzo){
        if(isTipo(tipo) != -1){
            this.tipo = tipo;
        } else{
            this.tipo = DEFAULT_TIPO;
        }
        if(prezzo >= 0){
            this.prezzo = prezzo;
        } else{
            this.prezzo = DEFAULT_PREZZO;
        }
    }
    private void setPrezzo(float prezzo){ //se devo cambiare il prezzo, se sbaglio tiene quello vecchio
        if(prezzo >= 0){
            this.prezzo = prezzo;
        }
    }
    public void setTipo(String tipo){
        if(this.tipo != null && isTipo(tipo) != -1){ //attenzione all'ordine di importanza
            this.tipo = tipo;
        } //no else perché ha già un valore corretto

    }
    private float getPrezzo(){
        return prezzo;
    }
    private String getTipo(){
        return tipo;
    }
    private boolean equals(Carburante c){
        return (prezzo == c.getPrezzo());
    }
    private String toString(){
        return "tipo: " + tipo + "prezzo: " + prezzo;
    }
}
