public class Temperatura {
    private float gradi;

    public Temperatura(){
        this.gradi = 0;
    }
    //definisco e restituisco i celsius
    public void setTempC(float gradi){
        this.gradi = gradi;
    }
    public float getTempC(){
        return gradi;
    }
    //definisco e restituisco i fahrenheit
    public void setTempF(float gradi){
        this.gradi = 32 + (9 * gradi / 5f);
    }
    public float getTempF(){

        return (gradi - 32) * 5/9f ;
    }
}
