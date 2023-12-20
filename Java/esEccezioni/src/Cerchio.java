public class Cerchio {
    private float raggio;
    public Cerchio(){raggio = 0;}
    public float getRaggio(){return raggio;}
    public void setRaggio(float raggio){
        if(raggio >= 0){
            this.raggio = raggio;
        } else{
            throw new IllegalArgumentException("Raggio negativo!"); //solleva l'eccezione
        }
    }
    public Cerchio(float raggio) {
        this(); //invoca il costruttore senza parametri
        setRaggio(raggio);
    }
}
