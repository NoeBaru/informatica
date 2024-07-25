public class Cubo extends Solido {
    private double lato;

    public Cubo(double pesoSpecifico, double lato) {
        super(pesoSpecifico);
        if (lato >= 0){
            this.lato = lato;
        }
        else this.lato = 1;
    }

    public double getLato() {
        return lato;
    }

    public double getSuperficie() {
        return 6 * lato * lato;
    }

    public double getVolume() {
        return lato * lato * lato;
    }

    @Override
    public String toString() {
        return "lato: " + lato + " ,superficie: "+ getSuperficie() +" ,volume: "+ getVolume();
    }
}