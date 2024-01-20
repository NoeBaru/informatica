public class Piano {
    private int numero;
    private boolean occupato;
    private final static float COSTO;
    private class Posto{
        private boolean occupato;
        private int biglietto;

        public Posto(boolean occupato, int biglietto) {
            this.occupato = occupato;
            this.biglietto = biglietto;
        }

        public boolean isOccupato() {
            return occupato;
        }

        public int getBiglietto() {
            return biglietto;
        }

        @Override
        public String toString() {
            return "occupato: " + occupato +
                    " biglietto: " + biglietto;
        }
    }

    public Piano(int numero, boolean occupato) {
        this.numero = numero;
        this.occupato = occupato;
    }

    public int getNumero() {
        return numero;
    }

    public boolean isOccupato() {
        return occupato;
    }

    @Override
    public String toString() {
        return "numero: " + numero +
                " occupato: " + occupato;
    }
}
