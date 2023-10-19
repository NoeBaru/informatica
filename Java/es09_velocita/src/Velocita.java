public class Velocita {
    private float velKmH;

    public Velocita(){
        this.velKmH = 0;
    }

    public void setVelKmH(float velKmH){
        this.velKmH = velKmH;
    }
    public float getVelKmH(){
        return velKmH;
    }
    //definisco e restituisco i m/s
    public void setVelMs(float velMs){
        this.velKmH = velMs * 3.6f;
    }
    public float getVelMs(){

        return velKmH / 3.6f;
    }
}
