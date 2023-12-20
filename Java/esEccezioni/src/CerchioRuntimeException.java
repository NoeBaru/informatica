public class CerchioRuntimeException extends RuntimeException{

    private float raggio;
    public CerchioRuntimeException(){
        raggio = 0;
    }
    public float getRaggio(){return raggio;}
    public void setRaggio(float raggio){ //obbliga a controllare, lo dice
        if(raggio >= 0){
            this.raggio = raggio;
        } else{
            throw new ValoreNonValidoNONcontrollata("Raggio negativo NON"); //solleva l'eccezione
        }
    }
    public CerchioRuntimeException(float raggio){
        this(); //invoca il costruttore senza parametri
        setRaggio(raggio);
    }
}
