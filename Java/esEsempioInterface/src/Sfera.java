public class Sfera extends Solido{
    private double raggio;

    public Sfera(double pesoSpecifico, double raggio) {
        super(pesoSpecifico);
    }

    public double getVolume(){
            return (raggio * raggio) * Math.PI;
    }
    public double getPeso(){
        return getVolume() + getPesoSpecifico();
    }
}
