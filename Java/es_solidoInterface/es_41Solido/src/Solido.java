public abstract class Solido {
    private double pesoSpecifico;

    public Solido(double ps) {
        if(ps > 0)
            pesoSpecifico = ps;
        else ps = 0;
    }

    public double getPesoSpecifico() {
        return pesoSpecifico;
    }
    public abstract double getSuperficie();
    public abstract double getVolume();
    public double getPeso(){
        return pesoSpecifico * getVolume();
    }

}
