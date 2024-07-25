public abstract class Solido1 implements CorpoSolido, FiguraSolido {
    private double pesoSpecifico;

    public Solido1(double pesoSpecifico) {
        this.pesoSpecifico = pesoSpecifico;
    }

    public double getPesoSpecifico(){
        return pesoSpecifico;
    }
    @Override
    public double getPeso() {
        return getVolume() * pesoSpecifico;
    }

    public void setPesoSpecifico(double pesoSpecifico) {
        this.pesoSpecifico = pesoSpecifico;
    }

    @Override
    public String toString() {
        return "pesoSpecifico=" + pesoSpecifico;
    }
}
