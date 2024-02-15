public class DVD extends Articolo{
    private double durata;
    private String[] registi;
    public DVD(String titolo, double valore, double durata, String[] registi) {
        super(titolo, valore);
        this.durata = durata;
        this.registi = registi;
    }

    public double getDurata() {
        return durata;
    }

    public String[] getRegisti() {
        return registi;
    }
}
