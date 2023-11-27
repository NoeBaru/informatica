public class ElencoPersone {
    private Persona [] elenco;
    private final int NUM_MAX;
    private int nUsati;

    public ElencoPersone(int maxPersone){
        nUsati = 0;
        //controllo
        NUM_MAX = maxPersone;
        elenco = new Persona[NUM_MAX];
    }

    public void add(Persona p){
        if(p != null && nUsati < NUM_MAX){
            elenco[nUsati] = p;
            nUsati++;
        }
    }

    public String toString(){
        String s = "";
        for(int cont = 0; cont < nUsati; cont++){
            s += elenco[cont].toString() + "\n";
        }
        return s;
    }
}
