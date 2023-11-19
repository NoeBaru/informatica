public class AgendaTelefonica {
    private final int MAX_DIM = 5;
    private int dim;
    private Utenza[] rubrica;

    public AgendaTelefonica(int dim) {
        if(dim < MAX_DIM) {
            this.dim = dim;
            this.rubrica = new Utenza[dim];
        } else{
            this.rubrica = new Utenza[MAX_DIM];
        }
    }

    public boolean inserisciUtenza(String nome, String cognome, String numero, String email) {
        if (rubrica.length < MAX_DIM) {
            rubrica[rubrica.length] = new Utenza(nome, cognome, numero, email);
            return true;
        } else {
            return false; // Agenda piena, impossibile aggiungere un'altra utenza
        }
    }

    public Utenza cercaUtenza(String nome, String cognome) {
        int cont = 0;
        while (cont < rubrica.length) {
            if (rubrica[cont].getNome().equalsIgnoreCase(nome) && rubrica[cont].getCognome().equalsIgnoreCase(cognome)) {
                return rubrica[cont];
            }
            cont++;
        }
        return null;
    }


    public void visualizzaTutteUtenze() {
        for (int i = 0; i < rubrica.length; i++) {
            System.out.println("Utenza " + (i + 1) + ": " + rubrica[i]);
        }
    }

    public int getDimensione() {
        return dim;
    }

    public void setDimensione(int dim) {
        if(dim < MAX_DIM) {
            this.dim = dim;
        }
    }
}
