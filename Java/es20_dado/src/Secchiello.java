public class Secchiello {
    private static final int MAX_DADI = 10;
    private int numDadi;
    private Dado[] vettDadi;
    public Secchiello(int numMaxDadi){
        numDadi = 0;
        somma = 0;
        if(numMaxDadi > 0){
            vettDadi = new Dado[numMaxDadi];
        } else{
            vettDadi = new Dado[MAX_DADI];
        }
    }

    public void add(Dado d){
        if(d != null) {
            if (numDadi < vettDadi.length) {
                vettDadi[numDadi] = d;
                numDadi++;
            }
        }
    }

    public void lancio(){
        for(int cont = 0; cont < numDadi; cont++){
            vettDadi[cont].lanciaDado();
        }
    }

    public int getSomma(){
        int somma = 0;
        for(int cont  = 0; cont < numDadi; cont++){
            somma += vettDadi[cont].getLancio();
        }
        return somma;
    }

    public String toString() {
        String s = "";
        for(Dado dado: vettDadi) {
            if(dado != null) {
                s += "[" + dado.toString() + "]";
            }
        }
        return s += "\nLa somma totale: " + getSomma();
    }
}