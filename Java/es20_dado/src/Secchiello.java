public class Secchiello {
    private static final int MAX_DADI = 10;
    private int numDadi;
    private Dado[] vettDadi;
    private int somma;
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
        if(numDadi < vettDadi.length){
            vettDadi[numDadi] = d;
            numDadi++;
        }
    }

    public void lancio(){
        for(int cont = 0; cont < numDadi; cont++){
            somma += vettDadi[cont].lanciaDado();
        }
    }

    public int getSomma(){
        return somma;
    }

    public String toString() {
        String s = "Secchiello " + "somma: " + somma + ' ';
        for(int cont = 0; cont < numDadi; cont++){
            s = s.concat(vettDadi[cont].getLancio() + " ");
        }
        return s;
    }
}
