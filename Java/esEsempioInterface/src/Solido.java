public abstract class Solido implements FiguraSolida, CorpoSolido{
    private double pesoSpecifico;
    @Override
    public double getPeso() {
        return 0;
    }

    public Solido(double pesoSpecifico) {
        this.pesoSpecifico = pesoSpecifico;
    }

    public double getPesoSpecifico() {
        return pesoSpecifico;
    }
    public double getPeso(){
        return getVolume() + getPesoSpecifico();
    }
}
