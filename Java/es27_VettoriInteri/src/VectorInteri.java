import java.util.Vector;

public class VectorInteri {
    private int dim;
    private Vector<Integer> vett;
    public VectorInteri(int dim) {
        vett = new Vector<>();
        if(dim > 0) {
            for (int cont = 0; cont < dim; cont++) {
                vett.add(0);
            }
        } else{
            vett = new Vector<>();
            vett.add(0);
        }
    }

    public int getDim(){return vett.size();}
    public int cercaMinimo(){
        int min;
        if(vett.size() > 0){
            min = vett.elementAt(0);
            for (int cont = 0; cont < dim; cont++) {
                if(vett.elementAt(cont) < min){
                    min = vett.elementAt(cont);
                }
            }
            return min;
        } else{
            throw  new ErroreVettoreVuoto();
        }
    }
    public void elimina(int elem) throws ErroreElementoInesistente{
        if(!vett.removeElement(elem)){
            throw new ErroreElementoInesistente();
        }
    }

    public String toString(){
        String s = "";
        for(int cont: vett){
            s += cont + "|";
        }
        return s;
    }
}
