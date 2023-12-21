public class VettoriInteri {
    private int dim;
    private String string;

    public VettoriInteri(int dim) {
        this.dim = 0;
    }
    public VettoriInteri(String s){
        string = s;
    }

    public int getDim() {
        return dim;
    }

    public void setDim(int dim) {
        this.dim = dim;
    }

    public int cercaElemento(Vector e){
        int tro = -1;
        int cont = 0;
        while(tro == -1 && cont < Vector.values().length){
            if(e == Vector.values()[cont]){
                tro = cont;
            } else{

            }
            cont ++;
        }
        return tro;

    }
}
