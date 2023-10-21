public class Velocita {
    private float velKmH;

    public Velocita(){
        velKmH = 0;
    }
    private float convertiKmHinMperS(float velKmH){

        return (float)(velKmH / 3.6);
    }
    private float convertiMperSinKmH(float velKmH){

        return (float)(velKmH * 3.6);
    }
    public void setVelKmH(float velKmH) {

        this.velKmH = velKmH;
    }
    public float getVelKmH() {

        return velKmH;
    }
    public void setVelMperS(float velMperS){

        velKmH = convertiMperSinKmH(velMperS);
    }
    public float getVelMperS(){

        return convertiKmHinMperS(velKmH);
    }
    public String toString(){
        return "velocita in kmH: " + velKmH + " velocita in m/s: " + convertiKmHinMperS(velKmH);
    }
}
