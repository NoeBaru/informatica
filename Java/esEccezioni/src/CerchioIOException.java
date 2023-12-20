public class CerchioIOException {
    private float raggio;
    public CerchioIOException(){
        raggio = 0;
    }
    public float getRaggio(){return raggio;}
    public void setRaggio(float raggio) throws ValoreNonValido { //obbliga a controllare, lo dice
        if(raggio >= 0){
            this.raggio = raggio;
        } else{
            throw new ValoreNonValido(); //solleva l'eccezione
        }
    }
    public CerchioIOException(float raggio) throws ValoreNonValido {
        this(); //invoca il costruttore senza parametri
        setRaggio(raggio);
    }
}
