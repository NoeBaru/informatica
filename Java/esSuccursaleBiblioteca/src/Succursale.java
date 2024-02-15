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
    }

    public void addScaffale(TipoArticolo tipo, int maxArticoli){
        if(scaffali == null){
            scaffali = new Vector<>();
        }
        Scaffale s = new Scaffale(tipo, progressivoScaffale, maxArticoli);
        progressivoScaffale++;
        scaffali.add(s);
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

    }

    public String getNome() {
        return nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public int getProgressivoScaffale() {
        return progressivoScaffale;
    }

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
        return (Articolo[]) elenco.toArray();
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

    public void presta(String codiceF, int idA){
        Utente u = null;
        for(int cont = 0; cont < utenti.size();cont++){
            if(codiceF.equals(utenti.get(cont).getCodiceFiscale())) {
                u = utenti.get(cont);
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
            a.setInPrestitoA(null);
        }
    }
}
