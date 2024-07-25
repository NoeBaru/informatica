public class Sfera extends Solido1{
    private double raggio;

    public Sfera(double pesoSpecifico, double raggio) {
        super(pesoSpecifico);
        this.raggio = raggio;
    }

    public double getRaggio() {
        return raggio;
    }

    @Override
    public double getSuperficie() {
        return 4 * Math.PI * raggio;
    }

    @Override
    public double getVolume() {
        return 4/3 * Math.PI * raggio;
    }

    @Override
    public String toString() {
        return "Sfera: " + super.toString() + " raggio=" + raggio;
    }
}
