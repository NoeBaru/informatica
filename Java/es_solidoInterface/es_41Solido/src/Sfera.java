public class Sfera extends Solido{
    private double raggio;

    public Sfera(double pesoSpecifico, double raggio) {
        super(pesoSpecifico);
        if(raggio >= 0)
            this.raggio = raggio;
        else this.raggio = 1;
    }

    public double getRaggio() {
        return raggio;
    }

    public double getSuperficie() {
        return 4 * Math.PI * (raggio * raggio);
    }

    public double getVolume() {return (4/3) * (Math.PI) * (raggio*raggio*raggio);
        }

    @Override
    public String toString() {
        return "raggio: " + raggio +" ,superficie: "+ getSuperficie() +" ,volume: "+ getVolume();
    }
}