import java.util.Vector;
public class Succursale {
    private String nome;
    private String indirizzo;
    private int progressivoScaffale = 0;
    private Vector<Scaffale> scaffali;
    private Vector<Utente> utenti;

    public Succursale(String nome, String indirizzo){
        this.nome = nome;
        this.indirizzo = indirizzo;
        //INIZIALIZZA I DUE VECTOR
    }

    public void addScaffale(TipoArticolo tipo, int maxArticoli){
        if(scaffali == null){
            scaffali = new Vector<>();
        }
        //PROGRESSIVO GESTITO IN AUTOMATICO, NON LO PASSI AL COSTRUTTORE
        Scaffale s = new Scaffale(tipo, progressivoScaffale, maxArticoli);
        progressivoScaffale++;
        scaffali.add(s);
        //ANCHE DIRETTAMENTE
        // scaffali.add(new Scaffale(tipo, MAX_ARTICOLI));
    }

    void addArticolo(Articolo a){
        for(int cont = 0; cont < scaffali.size(); cont++){
            Scaffale s = scaffali.get(cont);
            if(s.getnArticoli() < s.getMAX_ARTICOLI()) {
                if (a instanceof DVD && s.getTipo().equals(TipoArticolo.DVD)) {
                    s.addArticolo(a);
                }else if (a instanceof Libro && s.getTipo().equals(TipoArticolo.LIBRO)) {
                    s.addArticolo(a);
                }
            }
        }
        //DEVI CAPIRE SE ALLA FINE LO HAI AGGIUNTO O MENO E GESTIRE L'ECCEZIONE


    }

    public String getNome() {
        return nome;
    }

    //NON CAMBIA
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }
    //NON CAMBIA
    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public int getProgressivoScaffale() {
        return progressivoScaffale;
    }
    //GESTITO IN AUTOMATICO
    public void setProgressivoScaffale(int progressivoScaffale) {
        this.progressivoScaffale = progressivoScaffale;
    }

    public Vector<Scaffale> getScaffali() {
        return scaffali;
    }

    public void setScaffali(Vector<Scaffale> scaffali) {
        this.scaffali = scaffali;
    }

    public Vector<Utente> getUtenti() {
        return utenti;
    }
//NO!
    public void setUtenti(Vector<Utente> utenti) {
        this.utenti = utenti;
    }

    public Articolo cercaArticolo(int id){
        int cont = 0;
        Articolo a = null;
        while(cont < scaffali.size() && a == null){
            a = scaffali.get(cont).cercaArticolo(id);
        }
        return a;
    }

    public Articolo[] elencoArticoli(){
        Vector<Articolo> elenco = new Vector<>();
        for(int cont = 0; cont < scaffali.size();cont++){
            Articolo[] articoliScaffale = scaffali.get(cont).elencoArticoli();
            for(int k = 0; k < articoliScaffale.length; k++) {
                elenco.add(articoliScaffale[k]); //elenco.addAll(Arrays.asList(articoliScaffale));
            }
        }
        return (Articolo[]) elenco.toArray(); //PERCHè LO TRASFORMI UN UN ARRAY?
    }

    public double valoreComplessivo(){
        double somma = 0;
        for(int cont = 0; cont < scaffali.size(); cont++) {
            somma += scaffali.get(cont).complessivovalori();
        }
        return somma;
    }
    public Articolo[] cercaArticoli(String titolo)throws ErroreArticoloNonTrovato{
        Vector<Articolo> elenco = new Vector<>();
        for(int cont = 0; cont < scaffali.size();cont++){
            Articolo[] articoliScaffale = scaffali.get(cont).cercaArticolo(titolo);
            for(int k = 0; k < articoliScaffale.length; k++) {
                elenco.add(articoliScaffale[k]); //elenco.addAll(Arrays.asList(articoliScaffale));
            }
        }
        if(elenco.size() == 0){
            throw new ErroreArticoloNonTrovato();

        }
        return (Articolo[]) elenco.toArray();
    }

    public void addUtente(Utente u){
        for(int cont = 0; cont < utenti.size();cont++){
            if(u.getCodiceFiscale().equals(utenti.get(cont).getCodiceFiscale())){
                throw new ErroreUtenteGiaPresente();
            }
        }
        utenti.add(u);
    }
//FAI UN CERCA UTENTE PER CF
    public void presta(String codiceF, int idA){
        Utente u = null;
        for(int cont = 0; cont < utenti.size();cont++){
            if(codiceF.equals(utenti.get(cont).getCodiceFiscale())) {
                u = utenti.get(cont);
                //USCITA ANTICIPATA
            }
        }
        if(u != null){
            Articolo a = cercaArticolo(idA);
            if(a != null){
                if(a.getInPrestitoA() == null){
                    a.setInPrestitoA(u);
                }
            }
        }
    }

    public void restituisci(int idA){
        Articolo a = cercaArticolo(idA);
        if(a != null && a.getInPrestitoA() != null){
            //NON è BELLO ASSEGNARE NULL FAI IL METODO CHE LO FA
            a.setInPrestitoA(null);
        }
    }
}
