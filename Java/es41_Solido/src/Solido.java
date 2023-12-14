public abstract class Solido {
    private double pesoSpecifico;

    public Solido(double pesoSpecifico) {
        if(pesoSpecifico < 0){
            this.pesoSpecifico = 100;
        }
        else{
            this.pesoSpecifico = pesoSpecifico;
        }
    }
    public double getPesoSpecifico() {
        return pesoSpecifico;
    }
    public double getPeso(){
        return pesoSpecifico * getVolume();
    }
    public abstract double getSuperficie();
    public abstract double getVolume();
    public String toString(){
        return "pesoSpecifico: " + pesoSpecifico;
    }
}