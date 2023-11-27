public class Video {
    private String titolo;
    private Genere genere;
    private float prezzo;
    private boolean noleggiato;

    public Video(String titolo, Genere genere, float prezzo){
        this.titolo = titolo;
        this.genere = genere;
        if(prezzo > 0){
            this.prezzo = prezzo;
        }
        noleggiato = false;
    }

    public Genere getGenere(){
        return genere;
    }

    public boolean isNoleggiato(){
        return noleggiato;
    }

    public void setNoleggiato(){
        if(this.noleggiato){
            this.noleggiato = false;
        } else{
            this.noleggiato = true;
        }
    }
    public void setPrezzo(float prezzo){
        if(prezzo > 0){
            this.prezzo = prezzo;
        }
    }
    public float getPrezzo(){
        return prezzo;
    }

    public String getTitolo(){
        return titolo;
    }

    public String toString(){
        return "Titolo:" + titolo + "genere: " + genere + "prezzo: " + prezzo + "noleggiato: " + noleggiato;
    }
}
