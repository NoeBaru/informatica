public class Sfera extends Solido{
    private double raggio;

    public Sfera(double ps, double raggio) {
        super(ps);
        if(raggio >= 0)
            this.raggio = raggio;
        else
            this.raggio = 10;
    }
    public double getRaggio() {
        return raggio;
    }
    public double getSuperficie(){
        return 4 * Math.PI * raggio * raggio;
    }
    public double getVolume(){
        return (getSuperficie() * raggio) / 3;
    }
    public String toString(){
        return "raggio: " + raggio + " superficie: " + getSuperficie() + " volume: " + getVolume();
    }
}