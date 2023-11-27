public class Sito {
    private String nome;
    private String url;
    private final int NUM_MAX = 15;
    private Video[] elenco;
    private int nVideo;

    public Sito(String nome, String url){
        this.nome = nome;
        this.url = url;
        elenco = new Video[NUM_MAX];
        nVideo = 0;
    }

    public void addVideo(Video video){
        if(nVideo < NUM_MAX){
            elenco[nVideo] = video;
            nVideo++;
        }
    }

    public void aumentaPrezzo(String titolo, float perc){
        int cont = 0;
        float aumento, prezzo;
        boolean trovato = false;
        while(cont < nVideo && !trovato) {
            if (elenco[cont].getTitolo().equals(titolo)){
                trovato = true;
                prezzo = elenco[cont].getPrezzo();
                aumento = (prezzo * perc)/100;
                elenco[cont].setPrezzo(prezzo + aumento);
            }
            cont++;
        }
    }

    public void filmNoleggiati(){
        for(int cont = 0; cont < nVideo; cont++){
            if(elenco[cont].isNoleggiato()){
                System.out.println(elenco[cont].toString());
            }
        }
    }
    public String toString(){
        String s = "nome: " + nome + "url: " + url + "\n";
        for(int cont = 0; cont < nVideo; cont++){
            s += elenco[cont].toString() + "\n";
        }
        return s;
    }
}
