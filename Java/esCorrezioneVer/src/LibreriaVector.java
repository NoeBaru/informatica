import java.util.Vector;

public class LibreriaVector {
    private String nome;
    private String citta;
    private Vector <Libro> libri;

    public LibreriaVector(String nome, String citta, Vector<Libro> libri) {
        this.nome = nome;
        this.citta = citta;
        this.libri = libri;
    }
    public String getNome() {
        return nome;
    }
    public String getCitta() {
        return citta;
    }
    public Vector<Libro> getLibri() {
        return libri;
    }
    public int getNLibri(){return libri.size();}
    public void add(Libro l){
        if(l != null){
            libri.add(l); //size++;
        }
    }
    public void cambiaPrezzo(String titolo, float perc, char tipoOperaz){
        int tro = -1;
        int cont = 0;
        while(tro == -1 && cont < libri.size()){
            if(titolo.equals(libri.get(cont).getTitolo())){
                if(tipoOperaz == 'a'){
                    libri[cont].setPrezzovendita(libri.get(cont).getPrezzovendita() + libri.get(cont).getPrezzovendita()*perc/100);
                } else if(tipoOperaz == 's'){
                    libri[cont].setPrezzovendita(libri.get(cont).getPrezzovendita() - libri.get(cont).getPrezzovendita()*perc/100);
                }
                tro = cont;
            }
            cont++;
        }
    }
    public void statistica() {
        int contH = 0;
        int contG = 0;
        int contR = 0;
        float prezzoH = 0;
        float prezzoG = 0;
        float prezzoR = 0;

        /*for(int cont = 0; cont < libri.size(); cont++){
            switch(libri.get(cont).getGenere()){
                case HORROR:
                    if(contH == 0){
                        prezzoH = libri.get(cont).getPrezzovendita();
                    } else if(libri.get(cont).getPrezzovendita() < prezzoH){
                        prezzoH = libri.get(cont).getPrezzovendita();
                    }
                    contH++;
                case GIALLO:
                    if(contG == 0){
                        prezzoG = libri.get(cont).getPrezzovendita();
                    } else if(libri.get(cont).getPrezzovendita() < prezzoG){
                        prezzoG = libri.get(cont).getPrezzovendita();
                    }
                    contG++;
                case ROMANZO:
                    if(contR == 0){
                        prezzoR = libri.get(cont).getPrezzovendita();
                    } else if(libri.get(cont).getPrezzovendita() < prezzoR){
                        prezzoR = libri.get(cont).getPrezzovendita();
                    }
                    contR++;
            }
        }
        System.out.println("Horror:" + contH + "prezzo minimo: " + prezzoH + "gialli: " + contG + "prezzo minimo: " + prezzoG + "romanzi:" + contR + "prezzo minimo: " + prezzoR );*/

        for (Libro l : libri) { //l ricevein automatico tutti gli elementi dentro libri e li scorre uno alla volta
            case Generi.HORROR:
                if (contH == 0) {
                    prezzoH = libri[l].getValore();
                } else if (libri[l].getValore() < prezzoH) {
                        prezzoH = libri[l].getValore();
                    }
                    contH++;
            break;
            case Generi.GIALLO:
                if (contH == 0) {
                    prezzoG = libri[l].getValore();
                } else if (libri[l].getValore() < prezzoG) {
                    prezzoG = libri[l].getValore();
                }
                contG++;
            break;
            case Generi.ROMANZO:
                if (contR == 0) {
                    prezzoR = libri[l].getValore();
                } else if (libri[l].getValore() < prezzoR) {
                    prezzoR = libri[l].getValore();
                }
                contR++;
            break;
        }
    }
    public String toString(){
        String s = "";
        float somma = 0.0f;
        float media = 0.0f;

        for (int cont = 0; cont < libri.size(); cont++){
            s += libri[cont].toString() + "\n";
            somma += libri[cont].getPrezzovendita();
        }
        if(libri.size() > 0)
            media = somma / libri.size();
        s += "La media dei prezzi e': " + media;
        return s;
    }
}
