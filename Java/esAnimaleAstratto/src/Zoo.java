public class Zoo {
    private String nome;
    private final int DIM;
    private int nAnimali;
    private Animale[] gabbie;
    public Zoo(String nome, int dim){
        DIM = dim;
        nAnimali = 0;
        gabbie = new Animale[DIM];
    }
    public void add(Animale a){
        if(nAnimali < DIM ){
            for(int cont = 0; cont < nAnimali; cont++){
                gabbie[cont] = a;
                nAnimali++;
            }
        }
    }

    private presentatevi(){
        //ogni gabbia stampo chi ha dentro e cosa fa
    }
}
