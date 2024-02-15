import java.util.Vector;

//è una composizione VA DENTRO SUCCURSALE E PRIVATA (A MENO CHE TI SERVA NEL TEST)
public class Scaffale {
    private int numero;
    private TipoArticolo tipo;
    private final int MAX_ARTICOLI;
    private Articolo[] articoli;
    private int nArticoli = 0;

    public Scaffale(TipoArticolo tipo, int numero, int maxArticoli) {
        this.tipo = tipo;
        this.numero = numero;
        MAX_ARTICOLI = maxArticoli;
        articoli = new Articolo[MAX_ARTICOLI];
    }

    public int getNumero() {
        return numero;
    }
    //NON CAMBIA
    public void setNumero(int numero) {
        this.numero = numero;
    }

    public TipoArticolo getTipo() {
        return tipo;
    }
    //NON CAMBIA
    public void setTipo(TipoArticolo tipo) {
        this.tipo = tipo;
    }

    public int getMAX_ARTICOLI() {
        return MAX_ARTICOLI;
    }

    public int getnArticoli() {
        return nArticoli;
    }
    //NON CAMBIA
    public void setnArticoli(int nArticoli) {
        this.nArticoli = nArticoli;
    }

    void addArticolo(Articolo a){
        if((articoli != null) && nArticoli < MAX_ARTICOLI){
            if(a instanceof DVD && tipo.equals(TipoArticolo.DVD)){
                articoli[nArticoli] = a;
                nArticoli++;
            } else if(a instanceof Libro && tipo.equals(TipoArticolo.LIBRO)){
                articoli[nArticoli] = a;
                nArticoli++;
            }
        }
    }

    public Articolo cercaArticolo(int id){
        int cont = 0;
        Articolo a = null;
        while(cont < nArticoli && a == null){
            if(articoli[cont].getIdArticolo() == id){
                a = articoli[cont];
            }
        }
        return a;
    }

    public Articolo[] elencoArticoli(){
        return articoli;
    }
    public double complessivovalori(){
        double somma = 0;
        //NO DEVI ARRIVARE A NARTICOLI, LENGTH TI Dà MAX_ARTICOLI
        for(int cont = 0; cont < articoli.length; cont++) {
            somma += articoli[cont].getValore();
        }
        return somma;
    }

    public Articolo[] cercaArticolo(String titolo){
        Vector<Articolo> elenco = new Vector<>();
        for(int cont = 0; cont < articoli.length; cont++){
            if(articoli[cont].getTitolo().equals(titolo)){
                elenco.add(articoli[cont]);
            }
        }
        return (Articolo[]) elenco.toArray();
    }

}
