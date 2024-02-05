import java.util.Vector;
public class Palazzo {
    private String nome;
    private Vector<Piano> piani;
    public Palazzo(String nome, double valoreMQ){
        if (nome != null){
            this.nome = nome;
            piani = new Vector<>();
            piani.add(new Piano(valoreMQ));
        }else{
            System.out.println("Inserisci un nome corretto");
        }
    }
    public void addPiano(double valoreMQ){
        piani.add(new Piano(valoreMQ));
    }
    public void addAppartamento(int num_piano, double lunghezza, double larghezza){
        if (num_piano < piani.size()){
            piani.elementAt(num_piano).addAppartamento(lunghezza, larghezza);
        }else{
            System.out.println("Il piano non esiste (parte da 0 che rappresenta il piano terra fino al numero di piani -1");
        }
    }
    public void addStanza(int num_piano, int num_appartamento, double lunghezza, double larghezza){
        if (num_piano < piani.size()){
            piani.elementAt(num_piano).addStanza(num_appartamento, lunghezza, larghezza);
        }else{
            System.out.println("Piano non esistente");
        }
    }
    public double getValoreMQPiano(int num_piano){
        if (num_piano < piani.size()){
            return piani.elementAt(num_piano).getValoreMQ();
        }else{
            System.out.println("Piano non esistente");
            return -1;
        }
    }
    public void setValoreMQPiano(int num_piano, double valoreMQ){
        if (num_piano < piani.size()){
            piani.elementAt(num_piano).setValoreMQ(valoreMQ);
        }else{
            System.out.println("Piano non esistente");
        }
    }
    public String getNome() {
        return nome;
    }
    public int getNumPiani(){
        return piani.size();
    }
    public int getNumAppartamenti(){
        int somma = 0;
        for (int k = 0; k < piani.size(); k++){
            somma += piani.elementAt(k).getNumAppartamenti();
        }
        return somma;
    }
    public double getLarghezzaPianoAppartamentoStanza(int num_piano, int num_appartamento, int num_stanza){
        if (num_piano < piani.size()){
            return piani.elementAt(num_piano).getLarghezzaAppartamentoStanza(num_appartamento, num_stanza);
        }else{
            System.out.println("Piano non esistente");
            return -1;
        }
    }
    public double getLunghezzaPianoAppartamentoStanza(int num_piano, int num_appartamento, int num_stanza){
        if (num_piano < piani.size()){
            return piani.elementAt(num_piano).getLunghezzaAppartamentoStanza(num_appartamento, num_stanza);
        }else{
            System.out.println("Piano non esistente");
            return -1;
        }
    }
    public void addProprietarioPianoAppartamento(int num_piano, int num_appartamento, Proprietario proprietario){
        if (num_piano < piani.size()){
            piani.elementAt(num_piano).addProprietarioAppartamento(num_appartamento, proprietario);
        }else{
            System.out.println("Piano non esistente");
        }
    }
    public double getValoreProprietarioPianiAppartamenti(Proprietario proprietario){
        double somma = 0;
        for (int k = 0; k < piani.size(); k++){
            somma += piani.elementAt(k).getValoreAppartamentiProprietario(proprietario);
        }
        return somma;
    }
    public double getValoreTotale(){
        double somma = 0;
        for (int k = 0; k < piani.size(); k++){
            somma += piani.elementAt(k).getValorePiano();
        }
        return somma;
    }
    public String toString(){
        String p = "";
        for (int k = 0; k < piani.size(); k++){
            p += piani.elementAt(k).toString() + " ";
        }
        return "Nome: " + nome + ", numero di piani: " + piani.size() + ", piani: " + p;
    }
    private class Piano{
        private double valoreMQ;
        private Vector<Appartamemto> appartamenti;
        public Piano(double valoreMQ){
            if (valoreMQ >= 0){
                this.valoreMQ = valoreMQ;
                appartamenti = new Vector<>();
            }else{
                System.out.println("Inserisci un valore almeno maggiore o uguale a zero");
            }
        }
        public double getValoreMQ() {
            return valoreMQ;
        }
        public double getValorePiano(){
            double somma = 0;
            for (int k = 0; k < appartamenti.size(); k++){
                somma += (valoreMQ * appartamenti.elementAt(k).getDimensioneTotale());
            }
            return somma;
        }
        public void setValoreMQ(double valoreMQ) {
            this.valoreMQ = valoreMQ;
        }
        public int getNumAppartamenti(){
            return appartamenti.size();
        }
        public void addAppartamento(double lunghezza, double larghezza){
            appartamenti.add(new Appartamemto(lunghezza, larghezza));
        }
        public void addStanza(int num_appartamento, double lunghezza, double larghezza){
            if (num_appartamento < appartamenti.size()){
                appartamenti.elementAt(num_appartamento).addStanza(lunghezza, larghezza);
            }else{
                System.out.println("Appartamento non esistente");
            }
        }
        public double getLarghezzaAppartamentoStanza(int num_appartamento, int num_stanza){
            if (num_appartamento < appartamenti.size()){
                return appartamenti.elementAt(num_appartamento).getLarghezzaStanza(num_stanza);
            }else{
                System.out.println("Appartamento non esistente");
                return -1;
            }
        }
        public double getLunghezzaAppartamentoStanza(int num_appartamento, int num_stanza){
            if (num_appartamento < appartamenti.size()){
                return appartamenti.elementAt(num_appartamento).getLunghezzaStanza(num_stanza);
            }else{
                System.out.println("Appartamento non esistente");
                return -1;
            }
        }
        public void addProprietarioAppartamento(int num_appartamento, Proprietario proprietario){
            if (num_appartamento < appartamenti.size()){
                appartamenti.elementAt(num_appartamento).addProprietario(proprietario);
            }else{
                System.out.println("Appartamento non esistente");
            }
        }
        public double getValoreAppartamentiProprietario(Proprietario proprietario){
            double somma = 0;
            for (int k = 0; k < appartamenti.size(); k++){
                if (appartamenti.elementAt(k).cercaPresenzaProprietario(proprietario) != null)
                    somma += appartamenti.elementAt(k).getDimensioneTotale()*valoreMQ;
            }
            return somma;
        }
        public String toString(){
            String s = "";
            for (int k = 0; k < appartamenti.size(); k++){
                s += appartamenti.elementAt(k).toString() + " ";
            }
            return "Valore al metro quadro: " + valoreMQ + ", numero di appartamenti: " + appartamenti.size() + ", appartamenti: " + s;
        }
        private class Appartamemto{
            private Vector<Stanza> stanze;
            private Vector<Proprietario> proprietari;
            public Appartamemto(double lunghezza, double larghezza){
                stanze = new Vector<>();
                proprietari = new Vector<>();
                stanze.add(new Stanza(lunghezza, larghezza));
            }
            public void addStanza(double lunghezza, double larghezza){
                stanze.add(new Stanza(lunghezza, larghezza));
            }
            public void addProprietario(Proprietario proprietario){
                if (proprietario != null && cercaPresenzaProprietario(proprietario) == null)
                    proprietari.add(proprietario);
                else
                    System.out.println("Inserisci un proprietario corretto che non sia già presente");
            }
            public Proprietario cercaPresenzaProprietario(Proprietario proprietario){
                int i = 0;
                int tro = -1;
                while (i < proprietari.size() && tro == -1){
                    if (proprietario == proprietari.elementAt(i)){
                        tro = i;
                    }else{
                        i++;
                    }
                }
                if (tro != -1)
                    return proprietari.elementAt(tro);
                else
                    return null;
            }
            public int getNumStanze(){
                return stanze.size();
            }
            public double getDimensioneTotale(){
                double somma = 0;
                for (int i = 0; i < stanze.size(); i++){
                    somma += stanze.elementAt(i).getDimensioneMQ();
                }
                return somma;
            }
            public double getLunghezzaStanza(int num_stanza){
                if (num_stanza < stanze.size()){
                    return stanze.elementAt(num_stanza).getLunghezza();
                }else{
                    System.out.println("Stanza non esistente");
                    return -1;
                }
            }
            public double getLarghezzaStanza(int num_stanza){
                if (num_stanza < stanze.size()){
                    return stanze.elementAt(num_stanza).getLarghezza();
                }else{
                    System.out.println("Stanza non esistente");
                    return -1;
                }
            }
            public String toString(){
                String s = "";
                String p = "";
                for (int i = 0; i < stanze.size(); i++){
                    s += stanze.elementAt(i).toString() + " ";
                }
                for (int k = 0; k < proprietari.size(); k++){
                    p += proprietari.elementAt(k).toString() + " ";
                }
                return "Numero di stanze: " + getNumStanze() + " Stanze: " + s + " Dimensione totale: " + getDimensioneTotale() + " Proprietari: " + p;
            }
            private class Stanza{
                private double lunghezza;
                private double larghezza;
                public Stanza(double lunghezza, double larghezza){
                    if (lunghezza >= 0.8 && larghezza >= 0.8){
                        this.lunghezza = lunghezza;
                        this.larghezza = larghezza;
                    }else{
                        System.out.println("Dimensione troppo piccola");
                    }
                }
                public double getDimensioneMQ(){
                    return larghezza * lunghezza;
                }
                public double getLunghezza() {
                    return lunghezza;
                }
                public double getLarghezza() {
                    return larghezza;
                }
                public String toString(){
                    return "Larghezza: " + larghezza + ", lunghezza: " + lunghezza;
                }
            }
        }
    }
}