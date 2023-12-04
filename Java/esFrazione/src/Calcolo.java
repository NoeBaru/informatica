public class Calcolo {
    private int nFraz;
    private Frazione[] frazioni;
    private final int TOT;
    private Operatore operazione;

    public Calcolo(){
        frazioni = new Frazione[TOT];
        nFraz = 0;

    }
    public void add(Frazione f){
        if(f != null){
            if(nFraz < TOT){
                frazioni[nFraz] = f;
                nFraz++;
            }
        }
    }
    public float getValore(){

    }
    public String toString(){
        String s = "" + "\n";
        for(int cont = 0; cont < nFraz; cont++){
            s += frazioni[cont].toString() + "\n";
        }
        return s;
    }
}
