import java.util.Vector;

public class Sito {
    private String nome;
    private String nazione;
    private Vector<Pozzo> vPozzi;
    private int progressivoPozzi;
    private Responsabile responsabile;

    public Sito(String nome, String nazione, Responsabile responsabile) {
        this.nome = nome;
        this.nazione = nazione;
        this.responsabile = responsabile;
        progressivoPozzi = 1;
        vPozzi = new Vector<Pozzo>();
    }

    private abstract class Pozzo{
        private int codice;
        private boolean attivo;
        private int capacitaEstrattiva; //litri

        public Pozzo(int capacitaEstrattiva) throws ErroreValoreNonValido {
            if(capacitaEstrattiva > 0){
                this.capacitaEstrattiva = capacitaEstrattiva;
            }else{
                throw new ErroreValoreNonValido("Capicita estrattiva deve essere positiva!");
            }

            attivo = false; //tutti i pozzi nuovi non sono attivi
            codice = progressivoPozzi++;
        }

        public int getCodice() {
            return codice;
        }

        public boolean isAttivo() {
            return attivo;
        }

        public int getCapacitaEstrattiva() {
            return capacitaEstrattiva;
        }

        public void setCapacitaEstrattiva(int capacitaEstrattiva) throws ErroreValoreNonValido {
            if(capacitaEstrattiva > 0){
                this.capacitaEstrattiva = capacitaEstrattiva;
            }else{
                throw new ErroreValoreNonValido("Capicita estrattiva deve essere positiva!");
            }
        }

        public void switchAttivo(){
            attivo = !attivo;
        }

        @Override
        public String toString() {
            return "Pozzo{" +
                    "codice=" + codice +
                    ", attivo=" + attivo +
                    ", capacitaEstrattiva=" + capacitaEstrattiva +
                    '}';
        }
    }//Pozzo

    private class Terrestre extends Pozzo{
        private TipoTerra tipoTerreno;

        public Terrestre(int capacitaEstrattiva, TipoTerra tipoTerra) throws ErroreValoreNonValido {
            super(capacitaEstrattiva);
            this.tipoTerreno = tipoTerra;
        }

        public TipoTerra getTipoTerra() {
            return tipoTerreno;
        }
    }
}