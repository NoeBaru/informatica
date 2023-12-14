public class Cubo extends Solido{
    private double lato;

    public Cubo(double pesoSpecifico, double lato) {
        super(pesoSpecifico);
        if(lato >= 0)
            this.lato = lato;
        else
            this.lato = 1;
    }

    public double getLato() {
        return lato;
    }
    public double getSuperficie(){
        return lato * lato * 6;
    }
    public double getVolume(){
        return lato * lato * lato;
    }

    @Override
    public String toString() {
        return super.toString() + "lato: " + lato + " superficie: " + getSuperficie() +
                " volume: " + getVolume();
    }

}