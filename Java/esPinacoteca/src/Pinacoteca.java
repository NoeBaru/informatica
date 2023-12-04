public class Pinacoteca {
    private String nome;
    private int nQuadri;
    private final int N_MAX;
    private final static int DEFAULT_MAX  = 100;
    private Quadro[] quadri;
    public Pinacoteca(){

    }
    //Add controlla che non sia vuoto, controllare che non superi il massimo e incrementare il num di quadri inseriti
    public void add(Quadro q){
        if(q != null){
            if(nQuadri < N_MAX){
                quadri[nQuadri] = q;
                nQuadri++;
            }
        }
    }
    public String toString(){
        String s = "";
        return s;
    }
}
