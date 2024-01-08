import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class VettoriInteri {
    private final int DIM;
    private int[] vett;
    private int num;
    public VettoriInteri(int dim) {
        if(dim > 0) {
            DIM = dim;
        } else {
            DIM = 1;
        }
        vett = new int[DIM];
        num = 0;
    }

    public VettoriInteri(String str) throws NumberFormatException{
        //str es. 1|2|3|
        //d (intero) +(si ripete, ma almeno uno) * ( si ripete, ma anche nessuno)
        //(d+|)+

        String regex = "(\\d+\\|)+";
        Pattern p = Pattern.compile(regex); //controlla che la regex sia giusta
        Matcher m = p.matcher(str); //crea un oggetto che controlli sia formatta correttamente la stringa
        if (m.matches()){
           String[] campi = str.split("\\|");

           DIM = campi.length;
           vett = new int[DIM];

           for(int cont = 0; cont < DIM; cont++){
               vett[cont] = Integer.parseInt(campi[cont]);
           }
           num = DIM;
        } else{
            throw new NumberFormatException();
        }

    }
    public void add(int elem) throws ErroreVettorePieno { //il metodo add può sollevare un'eccezione di vettore pieno
        if(num < DIM){
            vett[num] = elem;
            num++;
        } else{
            throw new ErroreVettorePieno();
        }
    }
    public int minimo(){
        int min;
        if(num > 0) {
            min = vett[0];
            for (int cont = 1; cont < num; cont++) {
                if (vett[cont] < min) {
                    min = vett[cont];
                }
            }
        }else{
            throw new ErroreVettoreVuoto(); //non controllate, quindi non sei obbligato a gestirle
        }
        return min;
    }
    public int getDim() {return DIM;}
    public int cercaElemento(int e){
        int tro = -1;
        int cont = 0;
        while(tro == -1 && cont < num){
            if(e == vett[cont]){
                tro = cont;
            }
            cont ++;
        }
        return tro;

    }

    public void eliminaElemento(int num) throws ErroreElementoInesistente{
        int pos = cercaElemento(num);
        if(pos != -1){
            for(int cont = pos; cont < this.num-1; cont++){
                vett[cont] = vett[cont + 1];
            }
            this.num -= 1;
        } else{
            throw new ErroreElementoInesistente();
        }
    }

    public String toString(){
        String s = "";

        for(int cont = 0; cont < num; cont++){
            s += vett[cont] + "|";
        }

        return s;
    }
}
