public class Punto {
    private float x;
    private float y;

    public Punto(float x, float y){
        this.x = x;
        this.y = y;

    }
    public Punto(){
        this.x = 0;
        this.y = 0;

    }
    public void setX(float x){
        this.x = x;
    }
    public void setY(float y){
        this.y = y;
    }
    public float getX(){

        return x;
    }
    public float getY() {

        return y;
    }
    public float getDistanza(Punto p){

        return (float)(Math.sqrt((this.x - p.getX())*(this.x - p.getX()) +
                (this.y - p.getY())*(this.y - p.getY()))); //formula distanza tra due punti
    }
    public String toString(){

        return "( " + this.x + ", " + this.y + ")"; //NO GET
    }
}
