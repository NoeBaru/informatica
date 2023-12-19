public class Libreria {
    private String nome;
    private String citta;
    private final int MAXLIBRI;
    private static final int MAXLIBRI_DEF = 1000;
    private Libro[] libri;
    private int nLibri;

    public Libreria(String nome, String citta, int MAXLIBRI, int nLibri) {
        this.nome = nome;
        this.citta = citta;
        if(MAXLIBRI > 0)
            this.MAXLIBRI = MAXLIBRI;
        else
            this.MAXLIBRI = MAXLIBRI_DEF;
        libri = new Libro[this.MAXLIBRI];
        this.nLibri = nLibri;

    }

    public void add(Libro l){
        if (l != null && nLibri < MAXLIBRI){
            libri[nLibri] = l;
            nLibri++;
        }
    }

    public void cambiaPrezzo(String titolo, float perc, char tipoOperaz){
        int tro = -1;
        int cont = 0;
        while(tro == -1 && cont < nLibri){
            if(titolo.equals(libri[cont].getTitolo())){
                if(tipoOperaz == 'a'){
                    libri[cont].setPrezzovendita(libri[cont].getPrezzovendita() + libri[cont].getPrezzovendita()*perc/100);
                } else if(tipoOperaz == 's'){
                    libri[cont].setPrezzovendita(libri[cont].getPrezzovendita() - libri[cont].getPrezzovendita()*perc/100);
                }
                tro = cont;
            }
            cont++;
        }
    }

    public String getNome() {
        return nome;
    }

    public String getCitta() {
        return citta;
    }

    public int getMAXLIBRI() {
        return MAXLIBRI;
    }

    public Libro[] getLibri() {
        return libri;
    }

    public int getnLibri() {
        return nLibri;
    }
    public void statistica(){
        int contH = 0;
        int contG = 0;
        int contR = 0;
        float prezzoH = 0;
        float prezzoG = 0;
        float prezzoR = 0;
        for(int cont = 0; cont < nLibri; cont++){
            switch(libri[cont].getGenere()){
                case HORROR:
                    if(contH == 0){
                        prezzoH = libri[cont].getPrezzovendita();
                    } else if(libri[cont].getPrezzovendita() < prezzoH){
                        prezzoH = libri[cont].getPrezzovendita();
                    }
                    contH++;
                case GIALLO:
                    if(contG == 0){
                        prezzoG = libri[cont].getPrezzovendita();
                    } else if(libri[cont].getPrezzovendita() < prezzoG){
                        prezzoG = libri[cont].getPrezzovendita();
                    }
                    contG++;
                case ROMANZO:
                    if(contR == 0){
                        prezzoR = libri[cont].getPrezzovendita();
                    } else if(libri[cont].getPrezzovendita() < prezzoR){
                        prezzoR = libri[cont].getPrezzovendita();
                    }
                    contR++;
            }
        }
        System.out.println("Horror:" + contH + "prezzo minimo: " + prezzoH + "gialli: " + contG + "prezzo minimo: " + prezzoG + "romanzi:" + contR + "prezzo minimo: " + prezzoR );
    }

    public String toString(){
        String s = "";
        float somma = 0.0f;
        float media = 0.0f;

        for (int cont = 0; cont < nLibri; cont++){
            s += libri[cont].toString() + "\n";
            somma += libri[cont].getPrezzovendita();
        }
        if(nLibri > 0)
            media = somma / nLibri;
        s += "La media dei prezzi e': " + media;
        return s;
    }
}
